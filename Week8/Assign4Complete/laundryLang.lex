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
[ \t\n\r]             {}                
lights                {return(lights);}
darks                 {return(darks);}
delicates             {return(delicates);}
hot                   {return(hot);}
warm                  {return(warm);}
cold                  {return(cold);}
trousers              {return(trousers);}
shirts                {return(shirts);}
underwear             {return(underwear);}
sheets                {return(sheets);}
Machine|machine       {return(machine);}
Hand|hand             {return(hand);}
wash                  {return(wash);}
Line|line             {return(line);}
Tumble|tumble         {return(tumble);}
dry                   {return(dry);}
.                     {return(period);}

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