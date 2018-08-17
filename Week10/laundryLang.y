%{

/*-------------------------------------------------------------------------*
 *---									---*
 *---		laundryLang.y						---*
 *---									---*
 *---	    This file defines a grammar for the laundry language.	---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 October 25		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/


//  $ bison --verbose -d --debug laundryLang.y
//  $ gcc laundryLang.tab.c -c

#include  "laundryLang.h"

%}


%start		s
%token		HAND MACHINE WASH COLD WARM HOT LIGHTS DARKS DELICATES TROUSERS SHIRTS UNDERWEAR SHEETS LINE TUMBLE DRY PERIOD
%nonassoc	ERROR

%%

s	: wash PERIOD dry PERIOD
	  {
	    $$		= $1;
	    $$.howDry_	= $3.howDry_;	
	    result	= $$;
	  };

wash	: MACHINE WASH temp what
	  {
	    $$.clear();
	    $$.howWash_			= MACHINE_WASH;
	    $$.temp_			= $3.temp_;
	    $$.washWhatBitVector_	= $4.washWhatBitVector_;
	  }
	| HAND WASH what
	  {
	    $$.clear();
	    $$.howWash_			= HAND_WASH;
	    $$.temp_			= NO_TEMP;
	    $$.washWhatBitVector_	= $3.washWhatBitVector_;
	  };

what 	: type
	  {
	    $$	= $1;
	  };

what 	: itemList
	  {
	    $$	= $1;
	  };

type 	: LIGHTS
	  {
	    $$.clear();
	    $$.record(LIGHTS_WASHED);
	  }
 	| DARKS
	  {
	    $$.clear();
	    $$.record(DARKS_WASHED);
	  }
 	| DELICATES
	  {
	    $$.clear();
	    $$.record(DELICATES_WASHED);
	  };

itemList: item itemList
	  {
	    $$				 = $1;
	    $$.washWhatBitVector_	|= $2.washWhatBitVector_;
	  }
 	| item
	  {
	    $$	= $1;
	  };

temp 	: HOT
	  {
	    $$.temp_	= HOT_TEMP;
	  }
 	| WARM
	  {
	    $$.temp_	= WARM_TEMP;
	  }
 	| COLD
	  {
	    $$.temp_	= COLD_TEMP;
	  };

item	: TROUSERS
	  {
	    $$.clear();
	    $$.record(TROUSERS_WASHED);
	  }
	| SHIRTS
	  {
	    $$.clear();
	    $$.record(SHIRTS_WASHED);
	  }
	| UNDERWEAR
	  {
	    $$.clear();
	    $$.record(UNDERWEAR_WASHED);
	  }
	| SHEETS
	  {
	    $$.clear();
	    $$.record(SHEETS_WASHED);
	  };

dry	: dHow DRY
	  {
	    $$.clear();
	    $$	= $1;
	  };

dHow	: LINE
	  {
	    $$.clear();
	    $$.howDry_	= LINE_DRY;
	  }
	| TUMBLE
	  {
	    $$.clear();
	    $$.howDry_	= TUMBLE_DRY;
	  };


%%

//  PURPOSE:  To name the values of 'washWhat_ty'.
const char* washWhatNameArray[]	= {
      				    "lights",
      				    "darks",
				    "delicates",
				    "trousers",
				    "shirts",
				    "underwear",
				    "sheets"
      				  };


//  PURPOSE:  To point to the current position at which tokenizing should be
//	done.
char*		textPtr		= NULL;

//  PURPOSE:  To point to the end of the tokenizing input.
char*		textEndPtr	= NULL;

//  PURPOSE:  To hold the result computed by the parser
LaundrySummary	result;



//  PURPOSE:  To print the result of the laundry order 'toPrint'.  No return
//	value.
void		print		(const LaundrySummary&	toPrint
				)
{

  for  (int i = (int)LIGHTS_WASHED;  i <= (int)SHEETS_WASHED;  i++)
  {
    washWhat_ty	washWhat	= (washWhat_ty)i;

    if  ( !toPrint.isMentioned(washWhat) )
    {
      continue;
    }

    switch  (toPrint.howWash_)
    {
    case NO_WASH :
      continue;

    case HAND_WASH :
      printf("Hand wash ");
      break;

    case MACHINE_WASH :
      printf("Machine wash ");
      break;
    }

    printf("%s ",washWhatNameArray[washWhat]);

    switch  (toPrint.temp_)
    {
    case NO_TEMP :
      break;

    case COLD_TEMP :
      printf("in cold water.");
      break;

    case WARM_TEMP :
      printf("in warm water.");
      break;

    case HOT_TEMP :
      printf("in hot water.");
      break;
    }

    switch  (toPrint.howDry_)
    {
    case NO_DRY :
      break;

    case LINE_DRY :
      printf("  Line dry.");
      break;

    case TUMBLE_DRY :
      printf("  Tumble dry.");
      break;
    }

    printf("\n");
  }
}


//  PURPOSE:  To print parse-time error 'cPtr'.  No return value.
int	yyerror	(const char *cPtr)
{
  printf("%s, sorry!\n",cPtr);
  return(0);
}


//  PURPOSE:  To get input, run the parser, and display the result if the
//	parse was successful.
int	main	(int argc, char* argv[])
{
  char	line[LINE_LEN];

  if  (argc >= 2)
    textPtr	= argv[1];
  else
  {
    printf("Please enter an expression: ");
    textPtr = fgets(line,LINE_LEN,stdin);
  }

  textEndPtr	= textPtr + strlen(textPtr);

  if  (yyparse() == 0)
  {
    print(result);
  }

  return(EXIT_SUCCESS);
}
