/* Definition section */
%{
	#include "global.h"
	#include "y.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void C_comment();
	void CPP_comment();
	void str_const();
	int line_cnt=2;
	int comm_cnt=0;

	extern YYSTYPE yylval; //YYSTYPE
	extern int printline_or_not;
	extern int right_compound;
	extern int err;
	extern char errmsg[64];
	extern int syntax_err;
	char buf[256];

	/* This macro is used to record code line */
	#define CONCAT { strncat(buf, yytext, 256 - strlen(buf) - 1); }
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+

%option yylineno

%x COMMENT STRING_STATE

/* Rules section */
%%

"+" 	{ /*printf("%s \t ADD\n", yytext);printf("%s",yytext);*/CONCAT;return '+';}
"-"		{ /*printf("%s \t SUB\n", yytext);printf("%s",yytext);*/CONCAT;return '-';}
"*"		{ /*printf("%s \t MUL\n", yytext);printf("%s",yytext);*/CONCAT;return '*';}
"/"		{ /*printf("%s \t DIV\n", yytext);printf("%s",yytext);*/CONCAT;return '/';}
"%"		{ /*printf("%s \t MOD\n", yytext);printf("%s",yytext);*/CONCAT;return '%';}
"++"		{ /*printf("%s \t INC\n", yytext);printf("%s",yytext);*/CONCAT;return INC;}
"--"		{ /*printf("%s \t DEC\n", yytext);printf("%s",yytext);*/CONCAT;return DEC;}
">"		{ /*printf("%s \t MT\n", yytext);printf("%s",yytext);*/CONCAT;return '>';}
"<"		{ /*printf("%s \t LT\n", yytext);printf("%s",yytext);*/CONCAT;return '<';}
">="		{ /*printf("%s \t MTE\n", yytext);printf("%s",yytext);*/CONCAT;return MTE;}
"<="		{ /*printf("%s \t LTE\n", yytext);printf("%s",yytext);*/CONCAT;return LTE;}
"=="		{ /*printf("%s \t EQ\n", yytext);printf("%s",yytext);*/CONCAT;return EQ;}
"!="		{ /*printf("%s \t NE\n", yytext);printf("%s",yytext);*/CONCAT;return NE;}
"="		{ /*printf("%s \t ASGN\n", yytext);printf("%s",yytext);*/CONCAT;return '=';}
"+="		{ /*printf("%s \t ADDASGN\n", yytext);printf("%s",yytext);*/CONCAT;return ADDASGN;}
"-="		{ /*printf("%s \t SUBASGN\n", yytext);printf("%s",yytext);*/CONCAT;return SUBASGN;}
"*="		{ /*printf("%s \t MULASGN\n", yytext);printf("%s",yytext);*/CONCAT;return MULASGN;}
"/="		{ /*printf("%s \t DIVASGN\n", yytext);printf("%s",yytext);*/CONCAT;return DIVASGN;}
"%="		{ /*printf("%s \t MODASGN\n", yytext);printf("%s",yytext);*/CONCAT;return MODASGN;}
"&&"		{ /*printf("%s \t AND\n", yytext);printf("%s",yytext);*/CONCAT;return AND;}
"||"		{ /*printf("%s \t OR\n", yytext);printf("%s",yytext);*/CONCAT;return OR;}

"!"		{ /*printf("%s \t NOT\n", yytext);printf("%s",yytext);*/CONCAT;return '!';}
"("		{ /*printf("%s \t LB\n", yytext);printf("%s",yytext);*/CONCAT;return '(';}
")"		{ /*printf("%s \t RB\n", yytext);printf("%s",yytext);*/CONCAT;return ')';}
"{"		{ /*printf("%s \t LCB\n", yytext);printf("%s",yytext);*/CONCAT;return '{';}


"}"		{ /*printf("%s \t RCB\n", yytext);printf("%d teeeeeeeeest%s",line_cnt,yytext)*/;CONCAT;return '}';}


"["		{ /*printf("%s \t LSB\n", yytext);printf("%s",yytext);*/CONCAT;return '[';}
"]"		{ /*printf("%s \t RSB\n", yytext);printf("%s",yytext);*/CONCAT;return ']';}
","		{ /*printf("%s \t COMMA\n", yytext);printf("%s",yytext);*/CONCAT;return ',';}
";"		{ /*printf("%s \t SEMICOLON\n", yytext);printf("%s",yytext);*/CONCAT;return ';';}

"string"		{ /*printf("%s \t STRING\n", yytext);  printf("%s",yytext);*/CONCAT;yylval.val.type = S_T;return STR_TYPE;}
"print"		{ /*printf("%s \t PRINT\n", yytext);printf("%s",yytext);*/CONCAT;return PRINT;}
"if"		{ /*printf("%s \t IF\n", yytext);printf("%s",yytext);*/CONCAT;return IF;}
"else"		{ /*printf("%s \t ELSE\n", yytext);printf("%s",yytext);*/CONCAT;return ELSE;}
"for"		{ /*printf("%s \t FOR\n", yytext);printf("%s",yytext);*/CONCAT;return FOR;}
"while"		{ /*printf("%s \t WHILE\n", yytext);printf("%s",yytext);*/CONCAT;return WHILE;}

"int"		{ /*printf("%s \t INT\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.type = I_T;return INT;}
"float"		{ /*printf("%s \t FLOAT\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.type = F_T;return FLOAT;}
"void"		{ /*printf("%s \t VOID\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.type = V_T;return VOID;}
"bool"		{ /*printf("%s \t BOOL\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.type = B_T;return BOOL;}
"true"		{ /*printf("%s \t TRUE\n", yytext);printf("%s",yytext);*/CONCAT;return TRUE;}
"false"		{ /*printf("%s \t FALSE\n", yytext);printf("%s",yytext);*/CONCAT;return FALSE;}
"return"		{ /*printf("%s \t RET\n", yytext);printf("%s",yytext);*/CONCAT;return RET;}
"continue"		{ /*printf("%s \t CONT\n", yytext);printf("%s",yytext);*/CONCAT;return CONT;}
"break"		{ /*printf("%s \t BREAK\n", yytext);printf("%s",yytext);*/CONCAT;return BREAK;}
{number}		{ /*printf("%s \t I_CONST\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.i_val=atoi(yytext); return I_CONST;}
{number}"."{number}		{ /*printf("%s \t F_CONST\n", yytext);printf("%s",yytext);*/CONCAT;yylval.val.f_val=atof(yytext); return F_CONST;}

"/*"        { 
				BEGIN(COMMENT); 
				CONCAT;
				//printf("/*");
			}
<COMMENT>"*/"   { 
					BEGIN(INITIAL);
					CONCAT;
					//printf("*/");
				}
<COMMENT>\n     {/*printf("\n");printf("%d: ",yylineno);*/ line_cnt++;printf("%d: %s\n",yylineno,buf);strcpy(buf,"");}
<COMMENT>. {/*printf("%s", yytext);*/CONCAT;}

"//".*		{ /*CPP_comment();printf("%s", yytext);*/CONCAT;}

"\""				        { BEGIN(STRING_STATE); /*printf("\"");*/CONCAT;return '"'; }
<STRING_STATE>"\""		{ BEGIN(INITIAL); /*printf("\"");*/CONCAT;return '"'; }
<STRING_STATE>[^\"]*		{ /*printf("%s",yytext);*/ yylval.val.string=strdup(yytext);yylval.val.type = S_T; CONCAT;return STRING;}

{id}	{ /*printf("%s \t ID\n", yytext); printf("%s",yytext);*/ yylval.val.id_name=strdup(yytext);yylval.val.type = ID_T; CONCAT;return ID;}
\n			{ 
				/*printf("\n"); printf("%d: ",yylineno);*/ 
				line_cnt++;
				if(printline_or_not==1)
				{
					printf("%d:",yylineno);
					if(strcmp(buf,"")!=0)
					{
						printf(" %s\n",buf);
					}
					else
					{
						printf("\n");
					}
				}
				if(right_compound==1)
				{
					dump_scope();
				}
				if(err==1)
				{
					yyerror_overloading(errmsg,yylineno);
				}
				if(syntax_err==1)
				{
    				printf("\n|-----------------------------------------------|\n");
    				printf("| Error found in line %d: %s\n", yylineno, buf);
    				printf("| syntax error");
    				printf("\n|-----------------------------------------------|\n\n");
					remove("java_assembly_code.j");
					exit(1);
				}
				strcpy(buf,""); 
				printline_or_not=1;
				right_compound=0;
				err=0;
			} 
[ \t]		{/*printf("%s", yytext);*/ CONCAT;}
.			{ /* ignore bad characters */ }



%%

/* C Code section */
void C_comment()
{
	char c, c1;
	printf("/*");

loop:
	while ((c = input()) != '*' && c != 0)
	{
		putchar(c);
		if(c=='\n')
		{
			comm_cnt++;
		}
	}

	if ((c1 = input()) != '/' && c != 0) /*	註解內部的星號 */
	{
		unput(c1);
		putchar(c);
		goto loop;
	}

	if (c != 0)
	{
		printf("*/ \t C Comment\n");
		comm_cnt++;
		line_cnt--;
	}
}

void CPP_comment()
{
	char c;
	printf("//");
	while ((c = input()) != '\n' && c != 0)
	{
		putchar(c);
	}
	comm_cnt++;

	printf(" \t C++ Comment\n");
}

void str_const()
{
	printf("\" \t QUOTA\n");

	char c;
	while ((c = input()) != '\"' && c != 0)
	{
		putchar(c);
	}
	printf(" \t STR_CONST\n");

	printf("\" \t QUOTA\n");
}

int yywrap(void)
{
    return 1;
}

/*int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n",comm_cnt+line_cnt);
	printf("comment: %d lines\n\n",comm_cnt);

	return 0;
}*/
