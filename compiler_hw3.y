/*	Definition section */
%{
    #include <stdio.h>
    #include <string.h>
	#include "global.h"
    #include <stdbool.h>
	#include <stdlib.h>

typedef struct Entry Entry;
struct Entry {  //表中的一行
    int index;
    Value *id_ptr;
    Entry *next;
	char Kind[50];
	int Scope;
	char Attribute[50];
	char type[50];
};

typedef struct Header Header;
struct Header { //一張表
    int depth;
	int entry_num;
    Entry *table_root;
    //Entry *table_tail;
    Header *pre;
};

struct label_node{
	char label_name[50];
	struct label_node* next;
};

struct label_node* Q_HEAD=NULL;
struct label_node* Q_TAIL=NULL;

struct arg_node{
	char arg_name[50];
	struct arg_node* next;
};

struct arg_node* A_HEAD=NULL;
struct arg_node* A_TAIL=NULL;
arg_num=0;

Header *header_root = NULL;
Header *cur_header = NULL;
Header *header_rec = NULL;
int depth = 0;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
int printline_or_not=1;
int right_compound=0;
int err=0;
char errmsg[64];
int syntax_err=0;
int yacc_handle_syntax=1;
FILE *java_assembly_code;
char fun_content[1000000]="";
int rm_jFile_or_not=0;
int integer_or_not=1;
int label_lock=0;
char label_content[100000]="";
char item[50]={'\0'}; //use to Pop label name
char item_arg[50]={'\0'}; //use to Pop arg type for calling function checking
int arg_type=-1; // 0 for int,1 for float,2 for bool,3 for variable
char b[200]="";
int arg_not_cast=0;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
int lookup_symbol_type(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();
void yyerror_overloading(char *s,int line);
void Push(char d[],int len);
char* Pop();
void Push_arg(char d[],int len);
char* Pop_arg();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    struct Value val;
}

/* Token without return */
%token INC DEC MTE LTE EQ 
%token NE ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR STR_TYPE
%token PRINT IF ELSE FOR WHILE INT FLOAT VOID BOOL
%token TRUE FALSE RET CONT BREAK

/* Token with return, which need to sepcify type */
%token <val> I_CONST F_CONST STRING ID

/* Nonterminal with return, which need to sepcify type */
%type <val> primary_expression postfix_expression argument_expression_list unary_expression cast_expression 
%type <val> multiplicative_expression additive_expression shift_expression relational_expression
%type <val> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <val> logical_or_expression conditional_expression assignment_expression expression constant_expression declaration 
%type <val> init_declarator_list init_declarator declarator direct_declarator parameter_type_list parameter_list
%type <val> parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer
%type <val> initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement
%type <val> selection_statement iteration_statement jump_statement external_declaration function_definition
%type <val> type_specifier declaration_specifiers print_arg postfix_expression_forfun primary_expression_forfun

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

primary_expression
	: ID 
	  {
		arg_type=3;
		int symbol_exist_or_not = -10; //not exist
		$$ = yylval.val;
		Header *tmp=cur_header;
		symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
		while(tmp->pre!=NULL)
		{
			if(symbol_exist_or_not!=-10)
			{
				if(lookup_symbol_type(tmp,$$.id_name)==0) //int
				{
					if(arg_not_cast==0)
						sprintf(b,"\tiload %d\n\ti2f\n",symbol_exist_or_not);
					else
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
				}
					
				else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
					sprintf(b,"\tfload %d\n",symbol_exist_or_not);
				else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
					sprintf(b,"\tiload %d\n\ti2f\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
				break;

			}
			tmp=tmp->pre;
			symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
			if(symbol_exist_or_not!=-10)
			{
				if(tmp->depth==0)
				{
					if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						sprintf(b,"\tgetstatic compiler_hw3/%s I\n\ti2f\n",$$.id_name);
					else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						sprintf(b,"\tgetstatic compiler_hw3/%s F\n",$$.id_name);
					else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
						sprintf(b,"\tgetstatic compiler_hw3/%s Z\n\ti2f\n",$$.id_name);
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}

				if(lookup_symbol_type(tmp,$$.id_name)==0) //int
				{
					if(arg_not_cast==0)
						sprintf(b,"\tiload %d\n\ti2f\n",symbol_exist_or_not);
					else
						sprintf(b,"\tiload %d\n",symbol_exist_or_not);
				}
					
				else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
					sprintf(b,"\tfload %d\n",symbol_exist_or_not);
				else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
					sprintf(b,"\tiload %d\n\ti2f\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
				break;
			}
		}
		if(symbol_exist_or_not == -10)
		{
			err=1;
        	sprintf(errmsg, "Undeclared variable %s", $$.id_name);
		} 
	  }
	| I_CONST 
		{
			arg_type=0;
			$$=yylval.val;
			float a=(float)$$.i_val;
			if(arg_not_cast==0)
				sprintf(b,"\tldc %f\n",a);
			else
				sprintf(b,"\tldc %d\n",$$.i_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
    | F_CONST 
		{
			arg_type=1;
			$$=yylval.val;
			integer_or_not=0;

			sprintf(b,"\tldc %f\n",$$.f_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
	| '"' STRING '"' 
		{
			arg_type=4;
			$$=yylval.val;
			sprintf(b,"\tldc \"%s\"\n",$$.string);
			strcat(fun_content,b);
			strcpy(b,"");
		}
	| '('expression ')'
	;

primary_expression_forfun
	: ID {$$=yylval.val;}
	| I_CONST {$$=yylval.val;}
    | F_CONST {$$=yylval.val;}
	| '"' STRING '"' {$$=yylval.val;}
	| '('expression ')'
	;

postfix_expression_forfun
	: primary_expression_forfun {$$=$1;}

para_arg
	: '(' ')'
	| '('argument_expression_list ')'
postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression '[' expression ']'
	| postfix_expression_forfun {arg_not_cast=1;} para_arg {arg_not_cast=0;}
	{
		$$ = $1;
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,$$.id_name)==-10)
		{
			err=1;
        	sprintf(errmsg, "Undeclared function %s", $$.id_name);
		} 

		char attr[51]="";
		//lookup function attribute
		Header *t=cur_header;
		while(t->pre!=NULL)
		{
			t=t->pre;
		}
		//t is header root
		Entry *cur = t->table_root;
    	while (cur != NULL)
		{
        	if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, $$.id_name) == 0)
			{
				if(strcmp(cur->Attribute,"")!=0)
				{
					char a[20];
					if(arg_num>0)
					{
						strcpy(a,Pop_arg());
					}
					else
					{
						err=1;
        				sprintf(errmsg, "function formal parameter is not the same");
					}

					if(cur->Attribute[0]=='i')
					{
						strcat(attr,"I");
						if(strcmp(a,"int")!=0&&strcmp(a,"int_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}
					else if(cur->Attribute[0]=='f')
					{ 
						strcat(attr,"F");
						if(strcmp(a,"float")!=0&&strcmp(a,"float_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}
					else if(cur->Attribute[0]=='b')
					{ 
						strcat(attr,"Z");
						if(strcmp(a,"bool")!=0&&strcmp(a,"bool_var")!=0)
						{
							err=1;
        					sprintf(errmsg, "function formal parameter is not the same");
						}
					}		
					int next_will_write_or_not=0;
					for(int i=1;cur->Attribute[i]!='\0';i++)
					{ 
						if(next_will_write_or_not==1)
						{
							char aa[20];
							if(arg_num>0)
							{
								strcpy(aa,Pop_arg());
							}
							else
							{
								err=1;
        						sprintf(errmsg, "function formal parameter is not the same");
							}

							next_will_write_or_not=0;
							if(cur->Attribute[i]=='i')
							{ 
								strcat(attr," I");
								if(strcmp(aa,"int")!=0&&strcmp(aa,"int_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
							else if(cur->Attribute[i]=='f')
							{ 
								strcat(attr," F");
								if(strcmp(aa,"float")!=0&&strcmp(aa,"float_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
							else if(cur->Attribute[i]=='b')
							{ 
								strcat(attr," Z");
								if(strcmp(aa,"bool")!=0&&strcmp(aa,"bool_var")!=0)
								{
									err=1;
        							sprintf(errmsg, "function formal parameter is not the same");
								}
							}
						}
						if(cur->Attribute[i]==',')
						{
							next_will_write_or_not=1;
						}
					}
				}
				else
				{
					strcpy(attr,"");
				}
       		}
        	cur = cur->next;
    	}
		if(arg_num>0)
		{
			err=1;
        	sprintf(errmsg, "function formal parameter is not the same");
			while(arg_num!=0)
			{
				Pop_arg(); //Pop out all the parameter
			}
		}

		if(lookup_symbol_type(t,$$.id_name)==0)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)I\n\ti2f\n",$$.id_name,attr);
		else if(lookup_symbol_type(t,$$.id_name)==1)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)F\n",$$.id_name,attr);
		else if(lookup_symbol_type(t,$$.id_name)==2)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)Z\n",$$.id_name,attr);
		else if(lookup_symbol_type(t,$$.id_name)==3)
			sprintf(b,"\tinvokestatic compiler_hw3/%s(%s)V\n",$$.id_name,attr);

		strcat(fun_content,b);
		strcpy(b,"");

		if(strcmp(attr,"")==0)
		{
			//lookup function attribute
			Header *tt=cur_header;
			while(tt->pre!=NULL)
			{
				tt=tt->pre;
			}
			//tt is header root
			Entry *cc = tt->table_root;
    		while (cc != NULL)
			{
        		if (cc->id_ptr!=NULL&&strcmp(cc->id_ptr->id_name, $$.id_name) == 0)
				{
					if(strcmp(cc->Attribute,"")!=0)
					{
						err=1;
        				sprintf(errmsg, "function formal parameter is not the same");
					}
					break;
       			}
        		cc = cc->next;
    		}
		}
	}
	| postfix_expression '.' ID
	| postfix_expression INC
		{
			Value *v1=&$1; //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s I\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s F\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",$$.id_name);
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1.000000\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tfadd\n\tf2i\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
	| postfix_expression DEC 
		{
			Value *v1=&$1; //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s I\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s F\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",$$.id_name);
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1.000000\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tfsub\n\tf2i\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
	;

argument_expression_list
	: assignment_expression
		{
			Value *v1=&$1;
			if(arg_type==0) //int
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("int",strlen("int"));
			}
			else if(arg_type==1) //float
			{
				//sprintf(b,"\tldc %f\n",v1->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("float",strlen("float"));
			}
			else if(arg_type==2) //bool
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("bool",strlen("bool"));
			}
			else if(arg_type==3) //var.
			{
				int symbol_exist_or_not = -10; //not exist
				Header *tmp=cur_header;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				while(tmp->pre!=NULL)
				{
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}	
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						break;
					}
					tmp=tmp->pre;
					symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}							
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						break;
					}
				}
			}
			else if(arg_type==4) //string
			{
				//sprintf(b,"\tldc \"%s\"\n",v1->string);
				strcat(fun_content,b);
				Push_arg("string",strlen("string"));
			}
			arg_type=-1;
		}
	| argument_expression_list ',' assignment_expression
		{
			Value *v1=&$3;
			if(arg_type==0) //int
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("int",strlen("int"));
			}
			else if(arg_type==1) //float
			{
				//sprintf(b,"\tldc %f\n",v1->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("float",strlen("float"));
			}
			else if(arg_type==2) //bool
			{
				//sprintf(b,"\tldc %d\n",v1->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				Push_arg("bool",strlen("bool"));
			}
			else if(arg_type==3) //var.
			{
				int symbol_exist_or_not = -10; //not exist
				Header *tmp=cur_header;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				while(tmp->pre!=NULL)
				{
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}	
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					tmp=tmp->pre;
					symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
					if(symbol_exist_or_not!=-10)
					{
						if(lookup_symbol_type(tmp,v1->id_name)==0) //int
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							Push_arg("int_var",strlen("int_var"));
						}							
						else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
						{
							//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("float_var",strlen("float_var"));
						}
						else if(lookup_symbol_type(tmp,v1->id_name)==2) //bool
						{
							//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
							integer_or_not=0;
							Push_arg("bool_var",strlen("bool_var"));
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
				}
			}
			else if(arg_type==4) //string
			{
				//sprintf(b,"\tldc \"%s\"\n",v1->string);
				strcat(fun_content,b);
				Push_arg("string",strlen("string"));
			}
			arg_type=-1;
		}
	;

unary_expression
	: postfix_expression {$$=$1;}
	| INC unary_expression
		{
			Value *v2=&$2; //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s I\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s F\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",$$.id_name);
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1.000000\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tfadd\n\tf2i\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfadd\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
	| DEC unary_expression
		{
			Value *v2=&$2; //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s I\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s F\n",$$.id_name);
						}
						else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
						{
							//sprintf(b,"\tgetstatic compiler_hw3/%s Z\n",$$.id_name);
						}
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			strcat(fun_content,"\tldc 1.000000\n");
			if(integer_or_not==1)
			{
				sprintf(b,"\tfsub\n\tf2i\n\tistore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				sprintf(b,"\tfsub\n\tfstore %d\n",symbol_exist_or_not);
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
	| unary_operator cast_expression
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression {$$=$1;}
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression
		{
			strcat(fun_content,"\tfmul\n");
		}
	| multiplicative_expression '/' cast_expression
		{
			strcat(fun_content,"\tfdiv\n");
		}
	| multiplicative_expression '%' cast_expression
		{
			strcat(fun_content,"\tirem\n");
		}
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression
		{
			Value *v3=&$3; //6
			if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n",v3->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tfadd\n");
			}
			else if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n",v3->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tfadd\n");
			}
			integer_or_not=1;
		}
	| additive_expression '-' multiplicative_expression
		{
			Value *v3=&$3; //6
			if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n",v3->f_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tfsub\n");
			}
			else if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n",v3->i_val);
				strcat(fun_content,b);
				strcpy(b,"");
				strcat(fun_content,"\tfsub\n");
			}
			integer_or_not=1;
		}
	;

shift_expression
	: additive_expression {$$=$1;}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression
		{
			Value *v1=&$1; //a
			Value *v3=&$3; //6
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->i_val);
				sprintf(b,"\tfsub\n\tf2i\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n");
				strcat(fun_content,b);
				strcpy(b,"");
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n",v3->f_val);
				sprintf(b,"\tfsub\n\tiflt LABEL_TRUE\n\tgoto LABEL_FALSE\nLABEL_TRUE:\n");
				strcat(fun_content,b);
				strcpy(b,"");
			}
			integer_or_not=1;
		}
	| relational_expression '>' shift_expression
		{
			Value *v1=&$1; //a
			Value *v3=&$3; //6
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tifgt LABEL_GT\n",v3->i_val);
				sprintf(b,"\tfsub\n\tf2i\n\tifgt LABEL_GT\n");
				strcat(fun_content,b);
				strcpy(b,"");
				Push("\tgoto EXIT_0\nLABEL_GT:\n",strlen("\tgoto EXIT_0\nLABEL_GT:\n"));
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tifgt LABEL_GT\n",v3->f_val);
				sprintf(b,"\tfsub\n\tifgt LABEL_GT\n");
				strcat(fun_content,b);
				strcpy(b,"");
				Push("\tgoto EXIT_0\nLABEL_GT:\n",strlen("\tgoto EXIT_0\nLABEL_GT:\n"));
			}
			integer_or_not=1;
		}
	| relational_expression LTE shift_expression
	| relational_expression MTE shift_expression
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ relational_expression
		{
			Value *v1=&$1; //a
			Value *v3=&$3; //40
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v1->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v1->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v1->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
				//sprintf(b,"\tldc %d\n\tisub\n\tifeq LABEL_EQ\n",v3->i_val);
				sprintf(b,"\tfsub\n\tf2i\n\tifeq LABEL_EQ\n");
				strcat(fun_content,b);
				strcpy(b,"");
				label_lock=1;
				Push("\tgoto EXIT_0\nLABEL_EQ:\n",strlen("\tgoto EXIT_0\nLABEL_EQ:\n"));
			}
			else if(integer_or_not==0)
			{
				//sprintf(b,"\tldc %f\n\tfsub\n\tifeq LABEL_EQ\n",v3->f_val);
				sprintf(b,"\tfsub\n\tifeq LABEL_EQ\n");
				strcat(fun_content,b);
				strcpy(b,"");
				label_lock=1;
				Push("\tgoto EXIT_0\nLABEL_EQ:\n",strlen("\tgoto EXIT_0\nLABEL_EQ:\n"));
			}
			integer_or_not=1;
		}
	| equality_expression NE relational_expression
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression {$$=$1;}
	| logical_and_expression AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR logical_and_expression
	;

conditional_expression
	: logical_or_expression {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression {$$=$1;}
	| unary_expression '=' assignment_expression
		{
			Value *v1=&$1; //d
			int reg_num=lookup_symbol(cur_header,v1->id_name);

			sprintf(b,"\tf2i\n\tistore %d\n", reg_num);
			strcat(fun_content,b);
			strcpy(b,"");
		}
	| unary_expression ADDASGN assignment_expression
		{
			// a += 6
			Value *v1=&$1; //a
			Value *v3=&$3; //6
			int reg_num=lookup_symbol(cur_header,v1->id_name);

			if(integer_or_not==1)
			{
				//sprintf(b,"\tiload %d\n\tldc %d\n\tiadd\n\tistore %d\n", reg_num,v3->i_val,reg_num);
				sprintf(b,"\tfadd\n\tf2i\n\tistore %d\n",reg_num);
				strcat(fun_content,b);
				strcpy(b,"");
			}
		}
	| unary_expression SUBASGN assignment_expression
	| unary_expression MULASGN assignment_expression
	| unary_expression DIVASGN assignment_expression
	| unary_expression MODASGN assignment_expression
	;

expression
	: expression {err=1; yacc_handle_syntax=0;} error
	| assignment_expression
	| expression ',' assignment_expression
	| TRUE
	| FALSE
	| PRINT '(' print_arg ')'
	;

print_arg
	: '"' STRING '"' 
		{
			$$ = yylval.val;
			sprintf(b,"\tldc \"%s\"\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n",$$.string);
			if(label_lock!=0)
			{
				strcat(label_content,b);
				strcpy(b,"");
			}
			else
			{
				strcat(fun_content,b);
				strcpy(b,"");
			}
		}
	| I_CONST
		{
			$$ = yylval.val;
			sprintf(b,"\tldc %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",$$.i_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
	| F_CONST
		{
			$$ = yylval.val;
			sprintf(b,"\tldc %f\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",$$.f_val);
			strcat(fun_content,b);
			strcpy(b,"");
		}
	| ID 	
		{
			$$ = yylval.val;
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,$$.id_name)==0) //int
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(tmp->depth==0)
					{
						if(lookup_symbol_type(tmp,$$.id_name)==0) //int
							sprintf(b,"\tgetstatic compiler_hw3/%s I\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",$$.id_name,symbol_exist_or_not);
						else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
							sprintf(b,"\tgetstatic compiler_hw3/%s F\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",$$.id_name,symbol_exist_or_not);
						else if(lookup_symbol_type(tmp,$$.id_name)==2) //bool
							sprintf(b,"\tgetstatic compiler_hw3/%s Z\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",$$.id_name,symbol_exist_or_not);
						strcat(fun_content,b);
						strcpy(b,"");
						break;
					}
					if(lookup_symbol_type(tmp,$$.id_name)==0) //int
					{
						sprintf(b,"\tiload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,$$.id_name)==1) //float
						sprintf(b,"\tfload %d\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n",symbol_exist_or_not);
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(symbol_exist_or_not == -10)
			{
				err=1;
        		sprintf(errmsg, "Undeclared variable %s", $$.id_name);
			} 
		}
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';' 
	| declaration_specifiers init_declarator_list ';' 
	  	{
			Value *v1=&$1; //int
		  	Value *v2=&$2; //a
			insert_symbol(cur_header,v1,v2,"variable");

			if(cur_header->depth==0) //global var
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I\n",v2->id_name);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F\n",v2->id_name);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z\n",v2->id_name);
			}
			else //local var
			{
				int reg_num=lookup_symbol(cur_header,v2->id_name);
				if(v1->type==I_T)
				{
					sprintf(b,"\tldc 0\n\tistore %d\n",reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
				else if(v1->type==F_T)
				{
					sprintf(b,"\tfload 0.0\n\tfstore %d\n",reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
			}
		}
	| declaration_specifiers declarator '=' initializer ';'
		{
			Value *v1=&$1; //int 
			Value *v2=&$2; //a
			Value *v4=&$4; //3
			insert_symbol(cur_header,v1,v2,"variable");

			if(cur_header->depth==0) //global var
			{
				if(v1->type==I_T)
				{
					if(integer_or_not==1)
						fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,v4->i_val);
					else
					{
						int a=(int)v4->f_val;
						fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,a);
						integer_or_not=1;
					}
				}
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F = %f\n\n",v2->id_name,v4->f_val);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z = %d\n",v2->id_name,v4->i_val);
			}
			else //local var
			{
				int reg_num=lookup_symbol(cur_header,v2->id_name);
				if(v1->type==I_T)
				{
					if(integer_or_not==1)
					{
						//sprintf(b,"\tldc %d\n\tistore %d\n",v4->i_val,reg_num);
						sprintf(b,"\tf2i\n\tistore %d\n",reg_num);
					}
						
					else
					{
						//int a=(int)v4->f_val;
						//sprintf(b,"\tldc %d\n\tistore %d\n",a,reg_num);
						sprintf(b,"\tf2i\n\tistore %d\n",reg_num);
						integer_or_not=1;
					}
					strcat(fun_content,b);
					strcpy(b,"");
				}
				else if(v1->type==F_T)
				{
					sprintf(b,"\tfstore %d\n",v4->f_val,reg_num);
					strcat(fun_content,b);
					strcpy(b,"");
				}
			}
		}
	|
	;

declaration_specifiers
	: type_specifier {$$=$1;}
	| type_specifier declaration_specifiers  
	;

init_declarator_list
	: init_declarator {$$=$1;}
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator {$$=$1;}
	;

type_specifier
	: VOID { $$ = yylval.val; }
	| INT { $$ = yylval.val; }
	| FLOAT { $$ = yylval.val; }
	| BOOL  { $$ = yylval.val; }
	| STR_TYPE { $$ = yylval.val; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list 
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator {$$=$1;}
	;

direct_declarator
	: ID {$$ = yylval.val;}
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' {new_scope();} parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' {new_scope();}  ')'
	;

pointer
	: '*'
	| '*' pointer
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator {Value *v1=&$1;Value *v2=&$2; insert_symbol(cur_header,v1,v2,"parameter");}
	| declaration_specifiers abstract_declarator 
	| declaration_specifiers 
	;

identifier_list
	: ID 
	| identifier_list ',' ID
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression {$$=$1;}
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: ID ':' statement
	;

compound_statement
	: '{' {new_scope();} after_LCB {right_compound=1;header_rec=cur_header;}

after_LCB
	: '}'
	| statement_list '}'
	| declaration_list '}'
	| declaration_list statement_list '}'

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement declaration
	| statement_list statement declaration
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' {if(label_lock!=0) strcat(label_content,Pop());} statement else_or_not 

else_or_not
	: ELSE statement 
		{
			if(strcmp(label_content,"")==0) 
			{
				strcat(fun_content,"\tgoto EXIT_0\nEXIT_0:\n");
			}
			strcat(fun_content,label_content); 
			strcpy(label_content,"");
			label_lock=0;
		}
	| 

iteration_statement
	: WHILE {strcat(fun_content,"LABEL_BEGIN:\n");} '(' expression ')' statement {strcat(fun_content,"\tgoto LABEL_BEGIN\nLABEL_FALSE:\n\tgoto EXIT_0\nEXIT_0:\n");}
	| FOR '(' expression_statement expression_statement ')' {/*new_scope();*/} statement {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	| FOR '(' expression_statement expression_statement expression ')' {/*new_scope();*/} statement {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	;

jump_statement
	: CONT ';'
	| BREAK ';'
	| RET ';' {strcat(fun_content,"\treturn\n");}
	| RET expression ';'
		{
			Value *v2=&$2; //a
			int symbol_exist_or_not = -10; //not exist
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,v2->id_name);
				if(symbol_exist_or_not!=-10)
				{
					if(lookup_symbol_type(tmp,v2->id_name)==0) //int
					{
						//sprintf(b,"\tiload %d\n",symbol_exist_or_not);
					}
					else if(lookup_symbol_type(tmp,v2->id_name)==1) //float
					{
						//sprintf(b,"\tfload %d\n",symbol_exist_or_not);
						integer_or_not=0;
					}
					strcat(fun_content,b);
					strcpy(b,"");
					break;
				}
			}
			if(integer_or_not==1)
			{
					strcat(fun_content,"\tf2i\n\tireturn\n");
			}
			else if(integer_or_not==0)
			{
				strcat(fun_content,"\tfreturn\n");
				integer_or_not=1;
			}
		}
	;

program
	: external_declaration
	| program external_declaration
	;

external_declaration
	: function_definition{/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	| declaration
	;

function_definition
	: declaration_specifiers declarator {strcpy(fun_content,"");} compound_statement_fun 
		{ 
			Value *v1=&$1; //void
			Value *v2=&$2; //main
			insert_symbol_forfun(cur_header,v1,v2,"function");
			if(strcmp(v2->id_name,"main")==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)I\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)F\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)Z\n.limit stack 50\n.limit locals 50\n");
				else if(v1->type==V_T)
					fprintf(java_assembly_code,".method public static main([Ljava/lang/String;)V\n.limit stack 50\n.limit locals 50\n");
			}
			else
			{
				char attr[51]="";
				//lookup function attribute
				Header *t=cur_header;
				while(t->pre!=NULL)
				{
					t=t->pre;
				}
				//t is header root
				Entry *cur = t->table_root;
    			while (cur != NULL)
				{
        			if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, v2->id_name) == 0)
					{
						if(strcmp(cur->Attribute,"")!=0)
						{
							if(cur->Attribute[0]=='i')
								strcat(attr,"I");
							else if(cur->Attribute[0]=='f')
								strcat(attr,"F");
							else if(cur->Attribute[0]=='b')
								strcat(attr,"Z");
							
							int next_will_write_or_not=0;
							for(int i=1;cur->Attribute[i]!='\0';i++)
							{
								if(next_will_write_or_not==1)
								{
									next_will_write_or_not=0;
									if(cur->Attribute[0]=='i')
										strcat(attr," I");
									else if(cur->Attribute[0]=='f')
										strcat(attr," F");
									else if(cur->Attribute[0]=='b')
										strcat(attr," Z");
								}
								if(cur->Attribute[i]==',')
								{
									next_will_write_or_not=1;
								}
							}
						}
						else
						{
							strcpy(attr,"");
						}
       				}
        			cur = cur->next;
    			}
				if(v1->type==I_T)
					fprintf(java_assembly_code,".method public static %s(%s)I\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".method public static %s(%s)F\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".method public static %s(%s)Z\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
				else if(v1->type==V_T)
					fprintf(java_assembly_code,".method public static %s(%s)V\n.limit stack 50\n.limit locals 50\n",v2->id_name,attr);
			}
			fprintf(java_assembly_code,"%s",fun_content);
			strcpy(fun_content,"");
			fprintf(java_assembly_code,".end method\n");	
		}
	| declarator declaration_list compound_statement_fun
	| declarator compound_statement_fun
	;

compound_statement_fun
	: '{' '}' {right_compound=1;header_rec=cur_header;}
	| '{' statement_list '}' {right_compound=1;header_rec=cur_header;}
	| '{' declaration_list '}' {right_compound=1;header_rec=cur_header;}
	| '{' declaration_list statement_list '}' {right_compound=1;header_rec=cur_header;}
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    extern FILE *yyin;
    yyin = fopen(argv[1],"r");

	java_assembly_code=fopen("java_assembly_code.j","w");
	fprintf(java_assembly_code,".class public compiler_hw3\n.super java/lang/Object\n");


	yylineno = 0;
	new_scope();
    yyparse();
    extern int line_cnt;

	dump_all_scopes();
	printf("\nTotal lines: %d \n",yylineno);

	if(rm_jFile_or_not==1)
	{
		remove("java_assembly_code.j");
	}

    return 0;
}

void yyerror_overloading(char *s,int line) //semantic
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", line, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	rm_jFile_or_not=1;
}

void yyerror(char *s) //sytax
{
	if(yacc_handle_syntax==1)
	{
		int line=yylineno+1;
		printf("%d: %s\n",line,buf);
    	printf("\n|-----------------------------------------------|\n");
    	printf("| Error found in line %d: %s\n", line, buf);
    	printf("| %s", s);
    	printf("\n|-----------------------------------------------|\n\n");
		remove("java_assembly_code.j");
		exit(1);
	}
	else
	{
		syntax_err=1;
	}	
}

Header* create_symbol() 
{
	Header *ptr = malloc(sizeof(Header)); //創新的table
	ptr->depth=depth;
	depth++;
	ptr->table_root=malloc(sizeof(Entry));
	ptr->table_root=NULL;
	//ptr->table_root->next = NULL;
	//ptr->table_tail = ptr->table_root;
	ptr->pre = NULL;
	ptr->entry_num=-1;
	return ptr;
}
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);

	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);

	if (cur_header == NULL) //無table
	{
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header, id_ptr->id_name) == -10) 
	{
        
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a symbol: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		/*
		if(strcmp(kind,"function")==0)
		{

		}
		else //只有kind為function的,Attribute才有內容
		{
			strcat(tmp->Attribute,"");
		}
		*/

		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}
		Entry *e=cur_header->table_root;
		if(e==NULL)
		{
			cur_header->table_root=tmp;
		}
		else
		{
			while(e->next!=NULL)
			{
				e=e->next;
			}
			e->next=tmp;
		}

		//insert Attribute in previous table
		if(strcmp(kind,"parameter")==0)
		{
			Header* p=cur_header->pre;
			Entry* e=p->table_root;
			if(e!=NULL)
			{
				while(e->next!=NULL)
				{
					e=e->next;
				}
				if(e->index!=-8)
				{
					Entry *t = malloc(sizeof(Entry));
					t->next=NULL;
					t->index=-8; // use to identify that this entry hasn't had function name yet
					strcat(t->Attribute,tmp->type);
					e->next=t;
				}
				else
				{
					strcat(e->Attribute,", ");
					strcat(e->Attribute,tmp->type);
				}
			}
			else
			{
				Entry *t = malloc(sizeof(Entry));
				t->next=NULL;
				t->index=-8; // use to identify that this entry hasn't had function name yet
				strcat(t->Attribute,tmp->type);
				p->table_root=t;
			}
			
		}
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared variable %s", id_ptr->id_name);
        yyerror_overloading(errmsg,lineno);
    }
}

void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);
	int table_or_not=1; //have table yet
	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);

	if (cur_header == NULL) //無table
	{
		table_or_not=0; //not have table yet
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header->pre, id_ptr->id_name) == -10) 
	{
        if(table_or_not==1)
		{
			header=header->pre;
		}
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a function: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		
		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}

		//要去檢查前一個table的最後一個entry是不是有Attribute存在,如果有,則直接使用該entry,若無,則須創新的entry
		if(cur_header->pre!=NULL&&cur_header->pre->table_root!=NULL) 
		{
			Entry *tr=cur_header->pre->table_root;
			while(tr->next!=NULL)
			{
				tr=tr->next;
			}
			
			if(strcmp(tr->Attribute,"")!=0&&tr->index==-8) //有Attribute存在
			{
				tr->index=tmp->index;
				tr->id_ptr=tmp->id_ptr;
				strcpy(tr->Kind,tmp->Kind);
				strcat(tr->type,tmp->type);
				tr->Scope=tmp->Scope;
			}
			else //無Attribute存在
			{
				Entry *e=header->table_root;
				if(e==NULL)
				{
					header->table_root=tmp;
				}
				else
				{
					while(e->next!=NULL)
					{
						e=e->next;
					}
					e->next=tmp;
				}

			}
		}
		else
		{
			Entry *e=header->table_root;
			if(e==NULL)
			{
				header->table_root=tmp;
			}
			else
			{
				while(e->next!=NULL)
				{
					e=e->next;
				}
				e->next=tmp;
			}
		}	
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared function %s", id_ptr->id_name);
        yyerror_overloading(errmsg,lineno);
    }
}
int lookup_symbol(const Header *header, const char *id) 
{
	if (header->table_root == NULL) 
	{
        return -10;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		/*
		printf("\nindex:%d\n",cur->index);
		printf("%s\n",id);
		if(cur->id_ptr!=NULL)
			printf("%s\n",cur->id_ptr->id_name);
		*/

        if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return -10;
}

int lookup_symbol_type(const Header *header, const char *id) 
{
	//return 0 for int
	//return 1 for float
	//return 2 for bool
	//return 3 for void
	//return 4 for string
	if (header->table_root == NULL) 
	{
        return -10;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
        if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, id) == 0)
		{
            //return cur->index;
			if(strcmp(cur->type,"int")==0)
				return 0;
			else if(strcmp(cur->type,"float")==0)
				return 1;
			else if(strcmp(cur->type,"bool")==0)
				return 2;
			else if(strcmp(cur->type,"void")==0)
				return 3;
			else if(strcmp(cur->type,"string")==0)
				return 4;
        }
        cur = cur->next;
    }
    return -10;
}

void dump_symbol(Header *header) 
{
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	if (header->table_root == NULL) 
	{
        return;
    }

    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d",
		cur->index, cur->id_ptr->id_name, cur->Kind, cur->type, cur->Scope);

		if(strcmp(cur->Attribute,"")==0)
		{
			Entry *tmp = cur;
        	cur = cur->next;
			free(tmp);
        	tmp = NULL;
			continue;
		}
		else
		{
			//printf("ATTRIBUTE LEN:%d\n",strlen(cur->Attribute));
			printf("%-s",cur->Attribute);
		}
		//printf("\n%d %s\n",cur->index, cur->id_ptr->id_name);
        Entry *tmp = cur;
        cur = cur->next;
		
		/*free(tmp->id_ptr->val_ptr);
        tmp->id_ptr->val_ptr = NULL;
		
		free(tmp->id_ptr);
        tmp->id_ptr = NULL;*/
		
		free(tmp);
        tmp = NULL;
    }
	printf("\n\n");
}

void new_scope()
{
    Header *ptr = create_symbol();
    ptr->pre = cur_header;
    cur_header = ptr;
}

void dump_scope()
{
	Header *tmp;
	if(header_rec!=NULL && cur_header->depth != header_rec->depth)
	{
		//printf("cur_header->depth=%d\n",cur_header->depth);
		//printf("header_rec->depth=%d\n",header_rec->depth);
		tmp = header_rec;
		cur_header->depth=cur_header->depth-1;
		cur_header->pre=header_rec->pre;
		header_rec=NULL;
		//depth--;
	}
	else
	{
		tmp = cur_header;
		//printf("\ndump_scope: %d\n",tmp->depth);
    	cur_header = cur_header->pre;
	}
    
	if(tmp->table_root!=NULL)
	{
		dump_symbol(tmp);
	}
    free(tmp);
    tmp = NULL;
    depth--;
}

void dump_all_scopes()
{
	while (cur_header != NULL) 
	{
        dump_scope();
    }
}

void Push(char d[],int len)
{
	if(Q_HEAD==NULL)
	{
		Q_HEAD = (struct label_node*)malloc(sizeof(struct label_node));
		for(int i=0;i<len;i++)
		{
			Q_HEAD->label_name[i]=d[i];
		}
		Q_HEAD->label_name[len]='\0';
		Q_HEAD->next=NULL;
		Q_TAIL=Q_HEAD;
	}
	else
	{
		struct label_node* ptr=(struct label_node*)malloc(sizeof(struct label_node));
		for(int i=0;i<len;i++)
		{
			ptr->label_name[i]=d[i];
		}
		ptr->label_name[len]='\0';
		ptr->next=NULL;
		Q_TAIL->next=ptr;
		Q_TAIL=ptr;
	}
}

char* Pop()
{
	struct label_node* ptr=Q_HEAD;
	for(int i=0;i<50;i++)
	{
		item[i]=ptr->label_name[i];
	}
	Q_HEAD=ptr->next;
	free(ptr);
	return item;
}

void Push_arg(char d[],int len)
{
	if(A_HEAD==NULL)
	{
		A_HEAD = (struct arg_node*)malloc(sizeof(struct arg_node));
		for(int i=0;i<len;i++)
		{
			A_HEAD->arg_name[i]=d[i];
		}
		A_HEAD->arg_name[len]='\0';
		A_HEAD->next=NULL;
		A_TAIL=A_HEAD;
	}
	else
	{
		struct arg_node* ptr=(struct arg_node*)malloc(sizeof(struct arg_node));
		for(int i=0;i<len;i++)
		{
			ptr->arg_name[i]=d[i];
		}
		ptr->arg_name[len]='\0';
		ptr->next=NULL;
		A_TAIL->next=ptr;
		A_TAIL=ptr;
	}
	arg_num++;
}

char* Pop_arg()
{
	struct arg_node* ptr=A_HEAD;
	for(int i=0;i<50;i++)
	{
		item_arg[i]=ptr->arg_name[i];
	}
	A_HEAD=ptr->next;
	free(ptr);
	arg_num--;
	return item_arg;
}