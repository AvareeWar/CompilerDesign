%{

/*-------------------------------------------------------------------------*
 *---									---*
 *---		tinyPascal.y						---*
 *---									---*
 *---	    This file defines a tokenizer used to parser a subset of	---*
 *---	Pascal.								---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 1		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

  //  Compile with:
  //  $ flex -o pascalLex.c pascal.lex
  //  $ gcc pascalLex.c -o pascalLex

#include	"tinyPascal.h"
#include	"tinyPascal.tab.h"

%}
%%
[ \t\n\r]			{ /* Ignore spaces */ }
"{"[^"}"]*"}"			{ /* Ignore comments */ }
("+"|"-")?[0-9]+"."[0-9]*	{
				  yylval.real_ = strtod(yytext,NULL);
				  return(REAL);
				}
("+"|"-")?[0-9]*"."[0-9]+	{
				  yylval.real_ = strtod(yytext,NULL);
				  return(REAL);
				}
("+"|"-")?[0-9]+		{
				  yylval.integer_ = strtol(yytext,NULL,10);
				  return(INTEGER);
				}
"'"[^"'"\n]*"'"			{
				  yytext[strlen(yytext)-1]	= '\0';
				  yylval.charPtr_ 	= strdup(yytext+1);
				  return(STRING);
				}
":="				{ return(ASSIGN); }
"="				{ return(EQUAL); }
";"				{ return(SEMICOLON); }
","				{ return(COMMA); }
":"				{ return(COLON); }
"."				{ return(PERIOD); }
"("				{ return(BEGIN_PAREN); }
")"				{ return(END_PAREN); }
PROGRAM|Program|program		{ return(PROGRAM); }
VAR|Var|var		  	{ return(VAR); }
BEGIN|Begin|begin		{ return(BEGIN_); }
END|End|end			{ return(END_); }
IF|If|if			{ return(IF); }
THEN|Then|then			{ return(THEN); }
ELSE|Else|else			{ return(ELSE); }
NOT|Not|not			{ return(NOT); }
AND|And|and			{ return(AND); }
OR|Or|or			{ return(OR); }
REPEAT|Repeat|repeat		{ return(REPEAT); }
UNTIL|Until|until		{ return(UNTIL); }
FOR|For|for			{ return(FOR); }
TO|To|to			{ return(TO); }
DOWNTO|Downto|downto		{ return(DOWNTO); }
WHILE|While|while		{ return(WHILE); }
DO|Do|do			{ return(DO); }
WRITE|Write|write		{ return(WRITE); }
WRITELN|Writeln|writeln		{ return(WRITELN); }
"<"				{ return(LESSER); }
"<="				{ return(LESSER_EQUAL); }
">"				{ return(GREATER); }
">="				{ return(GREATER_EQUAL); }
"<>"				{ return(NOT_EQUAL); }
"+"				{ return(PLUS); }
"-"				{ return(MINUS); }
"*"				{ return(STAR); }
DIV|Div|div			{ return(INT_DIV); }
"/"				{ return(REAL_DIV); }
BOOLEAN|Boolean|boolean		{
				  yylval.simpleType_ = BOOLEAN_ST;
				  return(SIMPLE_TYPE);
				}
INTEGER|Integer|integer		{
				  yylval.simpleType_ = INTEGER_ST;
				  return(SIMPLE_TYPE);
				}
REAL|Real|real			{
				  yylval.simpleType_ = REAL_ST;
				  return(SIMPLE_TYPE);
				}
FALSE|False|"false"		{
				  yylval.bool_	= false;
				  return(BOOLEAN);
				}
TRUE|True|"true"		{
				  yylval.bool_	= true;
				  return(BOOLEAN);
				}
[A-Za-z_][A-Za-z_0-9]*		{
				  yylval.strPtr_ = new std::string(yytext);
				  return(IDENTIFIER);
				}
.				{ return("Weird char %c\n",yytext[0]); }
%%

int	yywrap	()	{ return(1); }
