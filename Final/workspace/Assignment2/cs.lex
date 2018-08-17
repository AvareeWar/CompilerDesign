%{
  #include	<stdlib.h>
  #include	<stdio.h>
%}

%%

[ \t\n\r]                       { }

([0-9]+)                          { printf("INTEGER\t\t%d\n",atoi(yytext)); }
(?i:nil)                        { printf("NIL\n"); }
":="                            { printf("ASSIGNMENT\n"); }
"="                             { printf("EQUALS\n"); }
";"                             { printf("SEMICOLON\n"); }
","                             { printf("COMMA\n"); }
":"                             { printf("COLON\n"); }
".."                            { printf("RANGE\n"); }
"."                             { printf("PERIOD\n"); }
"("                             { printf("BEGIN PAREN\n"); }
")"                             { printf("END PAREN\n"); }
"["                             { printf("BEGIN BRACKET\n"); }
"]"                             { printf("END BRACKET\n"); }
PROGRAM|Program|program         { printf("PROGRAM\n"); }
CONST|Const|const               { printf("CONST\n"); }
TYPE|Type|type                  { printf("TYPE\n"); }
VAR|Var|var                     { printf("VAR\n"); }
PROCEDURE|Procedure|procedure   { printf("PROCEDURE\n"); }
FUNCTION|Function|function      { printf("FUNCTION\n"); }
BEGIN|Begin|begin               { printf("BEGIN\n"); }
(?i:end)                        { printf("END\n"); }
(?i:if)                         { printf("IF\n"); }
(?i:then)                       { printf("THEN\n"); }
(?i:else)                       { printf("ELSE\n"); }
(?i:not)                        { printf("NOT\n"); }
(?i:and)                        { printf("AND\n"); }
(?i:or)                         { printf("OR\n"); }
(?i:repeat)                     { printf("REPEAT\n"); }
(?i:until)                      { printf("UNTIL\n"); }
(?i:for)                        { printf("FOR\n"); }
(?i:to)                         { printf("TO\n"); }
(?i:downto)                     { printf("DOWNTO\n"); }
(?i:while)                      { printf("WHILE\n"); }
(?i:do)                         { printf("DO\n"); }
(?i:with)                       { printf("WITH\n"); }
(?i:case)                       { printf("CASE\n"); }
(?i:of)                         { printf("OF\n"); }
"<" { printf("LESS THAN\n"); }
"<=" { printf("LESS THAN EQUAL TO\n"); }
">" { printf("GREATER THAN\n"); }
">=" { printf("GREATER THAN EQUAL TO\n"); }
"<>" { printf("NOT EQUAL TO\n"); }
"+" { printf("PLUS\n"); }
"-" { printf("MINUS\n"); }
"*" { printf("MULTIPLICATION\n"); }
"/" { printf("DIVISION\n"); }
(?i:div) { printf("INTEGER DIVISION\n"); }
(?i:mod) { printf("INTEGER MODULUS\n"); }
(?i:in) { printf("IN\n"); }
(?i:packed) { printf("PACKED\n"); }
(?i:array) { printf("ARRAY\n"); }
(?i:set) { printf("SET\n"); }
(?i:record)       { printf("RECORD\n"); }
\"[^\"]*\"|'[^']*'                   { printf("STRING CONSTANT %s\n",yytext); }
([A-Za-z_][A-Za-z_0-9]*)          { printf("IDENTIFIER\t%s\n",yytext); }
"{"[^"}"]*"}"                   { }

%%

int yywrap () { return(1); }
int main ()
{
yylex();
return(EXIT_SUCCESS);
}