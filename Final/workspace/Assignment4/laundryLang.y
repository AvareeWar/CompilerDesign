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


%start s
%token lights darks delicates
%token hot warm cold
%token trousers shirts underwear sheets
%token machine hand wash
%token line tumble dry
%token period

%%

s       : WASH period DRY period
    {
        $$.howWash_ = $1.howWash_;
        $$.howDry_ = $3.howDry_;
        result = $$;
    };
WASH    : machine wash TEMP WHAT
    {
        $$.howWash_ = MACHINE_WASH;
        $$.temp_ = $3.temp_;
        $$.washWhatBitVector_ = $4.washWhatBitVector_;
    }
| hand wash WHAT
    {
        $$.howWash_ = HAND_WASH;
        $$.washWhatBitVector_ = $3.washWhatBitVector_;
    };
WHAT    : TYPE
                  {
                          $$.washWhatBitVector_ = $1.washWhatBitVector_;
                  }
| ITEMLIST
    {
        $$.washWhatBitVector_ = $1.washWhatBitVector_;
    };
TYPE    : lights
                  {
                          $$.clear();
                  $$.record(LIGHTS_WASHED);
                  }
| darks
    {
        $$.clear();
        $$.record(DARKS_WASHED);
    }
| delicates
    {
        $$.clear();
        $$.record(DELICATES_WASHED);
    };
ITEMLIST: ITEM ITEMLIST
    {
        $$.washWhatBitVector_ = $1.washWhatBitVector_ | $2.washWhatBitVector_;
    }
| ITEM
    {
        $$.washWhatBitVector_ = $1.washWhatBitVector_;
    };
TEMP    : hot
                  {
                          $$.clear();
                  $$.temp_ = HOT_TEMP;
                  }
| warm
    {
        $$.clear();
        $$.temp_ = WARM_TEMP;
    }
| cold
    {
        $$.clear();
        $$.temp_ = COLD_TEMP;
    };
ITEM    : trousers
                  {
                          $$.clear();
                  $$.record(TROUSERS_WASHED);
                  }
| shirts
    {
        $$.clear();
        $$.record(SHIRTS_WASHED);
    }
| underwear
    {
        $$.clear();
        $$.record(UNDERWEAR_WASHED);
    }
| sheets
    {
        $$.clear();
        $$.record(SHEETS_WASHED);
    };
DRY     : DHOW dry
    {
        $$.howDry_ = $1.howDry_;
    };
DHOW    : line
                  {
                          $$.clear();
                  $$.howDry_ = LINE_DRY;
                  }
| tumble
    {
        $$.clear();
        $$.howDry_ = TUMBLE_DRY;
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
    char	Line[LINE_LEN];

    if  (argc >= 2)
        textPtr	= argv[1];
    else
    {
        printf("Please enter an expression: ");
        textPtr = fgets(Line,LINE_LEN,stdin);
    }

    textEndPtr	= textPtr + strlen(textPtr);

    if  (yyparse() == 0)
    {
        print(result);
    }

    return(EXIT_SUCCESS);
}