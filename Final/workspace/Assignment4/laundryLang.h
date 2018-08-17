/*-------------------------------------------------------------------------*
 *---									---*
 *---		laundryLang.h						---*
 *---									---*
 *---	    This file includes files, defines types and declares	---*
 *---	variables and functions used in common for both the lex/flex	---*
 *---	and YACC/Bison source files.					---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 October 25		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/


#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>


//  PURPOSE:  To distinguish among the different ways something can be washed.
typedef enum
        {
	  NO_WASH,
	  HAND_WASH,
	  MACHINE_WASH
	}
	howWash_ty;


//  PURPOSE:  To distinguish among the temperatures at which something is
//	washed. 
typedef enum
        {
	  NO_TEMP,
	  COLD_TEMP,
	  WARM_TEMP,
	  HOT_TEMP		
	}
	temperature_ty;


//  PURPOSE:  To distinguish among the different ways something can be dried.
typedef enum
        {
	  NO_DRY,
	  LINE_DRY,
	  TUMBLE_DRY
	}
	howDry_ty;


//  PURPOSE:  To distinguish among the things that can be washed.
typedef	enum
	{
	  LIGHTS_WASHED,
	  DARKS_WASHED,
	  DELICATES_WASHED,
	  TROUSERS_WASHED,
	  SHIRTS_WASHED,
	  UNDERWEAR_WASHED,
	  SHEETS_WASHED
	}
	washWhat_ty;


//  PURPOSE:  To keep track of what is washed and dried, and how they are
//	washed and dried.
struct LaundrySummary
{
  howWash_ty		howWash_;
  temperature_ty 	temp_;
  howDry_ty		howDry_;
  int			washWhatBitVector_;


  //  PURPOSE:  To initialize '*this' to its default values.  No parameters
  //	No return value.
  LaundrySummary	()
  {
    howWash_		= NO_WASH;
    temp_		= NO_TEMP;
    howDry_		= NO_DRY;
    washWhatBitVector_	= 0;
  }


  //  PURPOSE:  To set '*this' equal to 'source'.  Returns reference to
  //	 '*this'.
  LaundrySummary&
		operator=	(const LaundrySummary&	source
				)
  {
    if  (this != &source)
    {
      howWash_		= source.howWash_;
      temp_		= source.temp_;
      howDry_		= source.howDry_;
      washWhatBitVector_= source.washWhatBitVector_;
    }

    return(*this);
  }


  //  PURPOSE: To erase everything in '*this', like a default constructor.
  //	No parameters.  No return value.
  void		clear		()
  {
    temp_		= NO_TEMP;
    howWash_		= NO_WASH;
    howDry_		= NO_DRY;
    washWhatBitVector_	= 0;
  }


  //  PURPOSE:  To note that 'washWhat' was processed.  No return value.
  void		record		(washWhat_ty	washWhat
				)
  {
    washWhatBitVector_	|= (1 << washWhat);
  }


  //  PURPOSE:  To return 'true' if 'washWhat' was laundered, or 'false'
  //	otherwise.
  bool		isMentioned	(washWhat_ty	washWhat
				)
				const
  {
    return( (washWhatBitVector_ & (1 << washWhat)) != 0 );
  }

};


//  PURPOSE:  To note that the parser manipulates 'LaundrySummary' instances.
#define		YYSTYPE		struct LaundrySummary


const int	LINE_LEN	= 256;


//  PURPOSE:  To point to the current position at which tokenizing should be
//	done.
extern
char*		textPtr;

//  PURPOSE:  To point to the end of the tokenizing input.
extern
char*		textEndPtr;

//  PURPOSE:  To hold the result computed by the parser
extern
LaundrySummary	result;


//  PURPOSE:  To print parse-time error 'cPtr'.  No return value.
extern
int		yyerror		(const char*
				);

extern
int		yylex		();