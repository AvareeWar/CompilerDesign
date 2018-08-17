%{

/*-------------------------------------------------------------------------*
 *---									---*
 *---		laundryLang.lex						---*
 *---									---*
 *---	    This file defines a tokenizer for the laundry language.	---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 October 25		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/


//  laundryLang.lex
//  unix> flex -o laundryLang.c laundryLang.lex
//  unix> gcc laundryLang.c -c
//  unix> gcc -o laundryLang laundryLang.tab.o laundryLang.o

#include	"laundryLang.h"
#include	"laundryLang.tab.h"

#undef		YY_INPUT
#define		YY_INPUT(buffer,result,maxSize)		\
		{ result = ourInput(buffer,maxSize); }

extern
int		ourInput(char* buffer, int maxSize);

#define		MIN(x,y)	(((x)<(y)) ? (x) : (y))

%}

%%

[ \t\n]			{ /* ignore whitespace */ }
Hand			{ return(HAND); }
hand			{ return(HAND); }
Machine			{ return(MACHINE); }
machine			{ return(MACHINE); }
wash			{ return(WASH); }
cold			{ return(COLD); }
warm			{ return(WARM); }
hot			{ return(HOT); }
lights			{ return(LIGHTS); }
darks			{ return(DARKS); }
delicates		{ return(DELICATES); }
trousers		{ return(TROUSERS); }
shirts			{ return(SHIRTS); }
underwear		{ return(UNDERWEAR); }
sheets			{ return(SHEETS); }
Line			{ return(LINE); }
line			{ return(LINE); }
Tumble			{ return(TUMBLE); }
tumble			{ return(TUMBLE); }
dry			{ return(DRY); }
"."			{ return(PERIOD); }
.			{
			  printf("What's '%c'?\n",yytext[0]);
			  return(ERROR);
			}

%%

//  PURPOSE:  To return the next char of input.
int		ourInput(char* buffer, int maxSize)
{
  int	n	= MIN(maxSize,textEndPtr - textPtr);

  if  (n > 0)
  {
    memcpy(buffer,textPtr,n);
    textPtr	+= n;
  }

  return(n);
}

int		yywrap	()	{ return(1); }
