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

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();
void yyerror_overloading(char *s,int line);

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
		int symbol_exist_or_not = -10; //not exist
		$$ = yylval.val;
		Header *tmp=cur_header;
		symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
		while(tmp->pre!=NULL)
		{
			if(symbol_exist_or_not!=-10)
			{
				break;
			}
			tmp=tmp->pre;
			symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
			if(symbol_exist_or_not!=-10)
			{
				break;
			}
		}
		if(symbol_exist_or_not == -10)
		{
			err=1;
        	sprintf(errmsg, "Undeclared variable %s", $$.id_name);
		} 
	  }
	| I_CONST {$$=yylval.val;}
    | F_CONST {$$=yylval.val;}
	| '"' STRING '"' {$$=yylval.val;}
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

postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression '[' expression ']'
	| postfix_expression_forfun '(' ')' 
	  {
		$$ = $1;
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,$$.id_name)==-10)
		{
			//printf("8888888888\n");
			err=1;
        	sprintf(errmsg, "Undeclared function %s", $$.id_name);
		}
	  }
    | postfix_expression_forfun '('argument_expression_list ')' 
	  {
		$$ = $1;
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,$$.id_name)==-10)
		{
			//printf("8888888888\n");
			err=1;
        	sprintf(errmsg, "Undeclared function %s", $$.id_name);
		} 
	  }
	| postfix_expression '.' ID
	| postfix_expression INC
	| postfix_expression DEC 
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression {$$=$1;}
	| INC unary_expression
	| DEC unary_expression
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
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression {$$=$1;}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LTE shift_expression
	| relational_expression MTE shift_expression
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ relational_expression
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
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MULASGN
	| DIVASGN
	| MODASGN
	| ADDASGN
	| SUBASGN
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
	| ID 	
		{
			int symbol_exist_or_not = -10; //not exist
			$$ = yylval.val;
			Header *tmp=cur_header;
			symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
			while(tmp->pre!=NULL)
			{
				if(symbol_exist_or_not!=-10)
				{
					break;
				}
				tmp=tmp->pre;
				symbol_exist_or_not = lookup_symbol(tmp,$$.id_name);
				if(symbol_exist_or_not!=-10)
				{
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
			if(cur_header->depth==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I\n",v2->id_name);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F\n",v2->id_name);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z\n",v2->id_name);
			}
		 	insert_symbol(cur_header,v1,v2,"variable");
		}
	| declaration_specifiers declarator '=' initializer ';'
		{
			Value *v1=&$1; //int 
			Value *v2=&$2; //a
			Value *v4=&$4; //3
			if(cur_header->depth==0)
			{
				if(v1->type==I_T)
					fprintf(java_assembly_code,".field public static %s I = %d\n",v2->id_name,v4->i_val);
				else if(v1->type==F_T)
					fprintf(java_assembly_code,".field public static %s F = %d\n\n",v2->id_name,v4->f_val);
				else if(v1->type==B_T)
					fprintf(java_assembly_code,".field public static %s Z = %d\n",v2->id_name,v4->i_val);
			}
			insert_symbol(cur_header,v1,v2,"variable");
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
	: VOID { $$ = yylval.val;/*printf("222");*/ }
	| INT { $$ = yylval.val;/*printf("222");*/ }
	| FLOAT { $$ = yylval.val;/*printf("222");*/ }
	| BOOL  { $$ = yylval.val;/*printf("222");*/}
	| STR_TYPE { $$ = yylval.val;/*printf("222");*/ }
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
	: IF '(' expression ')' {/*new_scope();*/} else_or_not

else_or_not
	: statement
	| statement ELSE {/*new_scope();*/} statement

iteration_statement
	: WHILE '(' expression ')' {/*new_scope();*/} statement {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	| FOR '(' expression_statement expression_statement ')' {/*new_scope();*/} statement {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	| FOR '(' expression_statement expression_statement expression ')' {/*new_scope();*/} statement {/*int lineno=yylineno+1;printf("%d: %s\n", lineno, buf);printline_or_not=0;dump_scope();*/}
	;

jump_statement
	: CONT ';'
	| BREAK ';'
	| RET ';'
	| RET expression ';'
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
	: declaration_specifiers declarator declaration_list compound_statement_fun
	| declaration_specifiers declarator compound_statement_fun 
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
    return 0;
}

void yyerror_overloading(char *s,int line) //semantic
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", line, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
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
			//printf("7777777\n");
			Entry *tr=cur_header->pre->table_root;
			//printf("17171717\n");
			while(tr->next!=NULL)
			{
				//printf("767676\n");
				tr=tr->next;
			}
			
			if(strcmp(tr->Attribute,"")!=0&&tr->index==-8) //有Attribute存在
			{
				
				//printf("88888888\n");
				tr->index=tmp->index;
				tr->id_ptr=tmp->id_ptr;
				strcpy(tr->Kind,tmp->Kind);
				strcat(tr->type,tmp->type);
				tr->Scope=tmp->Scope;
			}
			else //無Attribute存在
			{
				//printf("999999\n");
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
		//printf("NULLLLLLLL\n");
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
    else
	{
		//printf("EEEEEEEEE\n");
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