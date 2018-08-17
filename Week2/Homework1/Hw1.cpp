#include	<cstdlib>
#include	<cstdio>
#include	<iostream>
#include	<string>
#include	<list>
#include	<map>


//  PURPOSE:  To tell the length of a global string.
const int	TEXT_LEN		= 256;


//  PURPOSE:  To represent the different lexemes in the language.
typedef		enum
		{
		  END_OF_INPUT_SYM,

		  STRING_SYM,
		  NUMBER_SYM,

		  COMMA_SYM,
		  PERIOD_SYM,
		  BEGIN_PAREN_SYM,
		  END_PAREN_SYM,

		  WASH_KEYWORD_SYM,
		  DRY_KEYWORD_SYM,

		  LIGHTS_KEYWORD_SYM,
		  DARKS_KEYWORD_SYM,
		  DELICATES_KEYWORD_SYM,

		  MACHINE_KEYWORD_SYM,
		  HAND_KEYWORD_SYM,
		  BY_KEYWORD_SYM,

		  HOT_KEYWORD_SYM,
		  WARM_KEYWORD_SYM,
		  COLD_KEYWORD_SYM,

		  LINE_KEYWORD_SYM,
		  TUMBLE_KEYWORD_SYM,

		  TROUSERS_KEYWORD_SYM,
		  SHIRTS_KEYWORD_SYM,
		  UNDERWEAR_KEYWORD_SYM,
		  SHEETS_KEYWORD_SYM
		}
		symbol_ty;

//  PURPOSE:  To represent the string delimitor character.
const char	QUOTE_CHAR		= 0x22;


//  PURPOSE:  To represent the decimal point character.
const char	DECIMAL_PT_CHAR		= '.';


//  PURPOSE:  To represent the period character.
const char	PERIOD_CHAR		= '.';


/*  PURPOSE:  To implement an interface that manages the character source.
 */
class	InputCharStream
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the input.
  std::string		input_;

  //  PURPOSE:  To hold where the cursor is.
  int			index_;

  //  II.  Disallowed auto-generated methods:
  
  //  III.  Protected methods:
protected :

public:
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To
  InputCharStream	(std::string&	newInput
  			) :
			input_(newInput),
			index_(0)
			{ }

  //  V.  Accessors:

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To return the current char, or '\0' if there are no more.
  //	No parameters.
  char		peek	()
  			const
			{ return
			  ( (index_ >= input_.length())
			    ? '\0' : input_[index_]
			  );
			}

  //  PURPOSE:  To return 'true' if at eof-of-input, or 'false' otherwise.
  bool		isAtEnd	()
  			const
			{ return(index_ >= input_.length()); }

  //  PURPOSE:  To advance to the next char (if not already at end).  No
  //	parameters.  No return value.
  void		advance	()
			{
			  if  (index_ < input_.length())  index_++;
			}

};


//  PURPOSE:  To represent a parsed symbol, and any associated data.
class		Symbol
{
  //  I.  Member vars:
  //  PURPOSE:  To tell the type of symbol that '*this' represents.
  symbol_ty			symbol_;

  //  PURPOSE:  To hold the address of a string associated with '*this' symbol
  //	(if there is one).
  std::string*			stringPtr_;

  //  PURPOSE:  To hold the number associated with '*this' symbol (if there
  //	is one).
  double			number_;

  //  II.  Disallowed auto-generated methods:
  //  No default constructor:
  Symbol			();

  //  No copy constructor:
  Symbol			(const Symbol&
				);

  //  No copy assignment op:
  Symbol&	operator=	(const Symbol&
				);

protected :
  //  III.  Protected methods:

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To initialize '*this' to hold symbol 'newSymbol'.  No return
  //	value.
  Symbol			(symbol_ty	newSymbol
				) :
				symbol_(newSymbol),
				stringPtr_(NULL),
				number_(0.0)
				{ }

  //  PURPOSE:  To initialize '*this' to hold string 'newString'.  No return
  //	value.
  Symbol			(const std::string&	newString
  				) :
				symbol_(STRING_SYM),
				stringPtr_(new std::string(newString)),
				number_(0.0)
				{ }
				
  //  PURPOSE:  To initialize '*this' to hold number 'newNumber'.  No return
  //	value.
  Symbol			(double	newNumber
				) :
				symbol_(NUMBER_SYM),
				stringPtr_(NULL),
				number_(newNumber)
				{ }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //	value.
  ~Symbol			()
				{
				  delete(stringPtr_);
				}

  //  V.  Accessors:
  //  PURPOSE:  To return the type associated with '*this' Symbol.  No
  //  	parameters.
  symbol_ty	getType		()
				const
				{ return(symbol_); }

  //  PURPOSE:  To return a reference to the string stored at '*this' Symbol,
  //	or a reference to the empty string if '*this' is not a string.
  const std::string&
		getString	()
				const
				{
				  static std::string	empty("");

				  return( (stringPtr_ == NULL)
				  	  ? empty
					  : *stringPtr_
					);
				}

  //  PURPOSE:  To return the number stored at '*this' Symbol, or '0' if
  //	'*this' does not represent a number.
  double	getNumber	()
				const
				{ return(number_); }

};


//  PURPOSE:  To hold a shared global array of characters.
char				text[TEXT_LEN];


//  PURPOSE:  To implement an interface that gathers characters into lexemes.
class	TokenStream
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the source of the character input.
  InputCharStream&	inputCharStream_;

  //  PURPOSE:  To hold the lastest lexeme parsed.
  Symbol*	   	lastParsedPtr_;

  //  PURPOSE:  To hold the keyword string to symbol_ty mapping.
  std::map<std::string,symbol_ty>
			keywordToSymbolTMap_;

  //  II.  Disallowed auto-generated methods:
  //  No default constructor:
  TokenStream		();

  //  No copy constructor:
  TokenStream		(const TokenStream&
			);

  //  No copy assignment op:
  TokenStream&		operator=
			(const TokenStream&
			);

protected :
  //  III.  Protected methods:
  //  PURPOSE:  To return a pointer representing a scanned string constant.
  //	No parameters.
  Symbol*	scanString	()
				{
				  std::string	lex("");
				  bool		haveFoundEnd	= false;

				  //  Advance past first quote:
				  inputCharStream_.advance();

				  while  ( !inputCharStream_.isAtEnd() )
				  {
				    char	c = inputCharStream_.peek();

				    inputCharStream_.advance();

				    if  (c == QUOTE_CHAR)
				    {
				      haveFoundEnd	= true;
				      break;
				    }

				    lex	+= c;
				  }

				  if  (!haveFoundEnd)
				    throw "Non-terminated string constant";

				  return(new Symbol(lex));
				}

  //  PURPOSE:  To return a pointer representing a scanned number.  No
  //	parameters.
  Symbol*   	scanNumber	()
				{
				  bool		haveSeenDecimalPt	= false;
				  std::string	lex("");
				  char		c;

				  while  ( c = inputCharStream_.peek(),
				  	   isdigit(c)
				  	   || ( (c == DECIMAL_PT_CHAR)
						&&
						!haveSeenDecimalPt
					      )
				  	 )
				  {
				    lex		       += c;
				    haveSeenDecimalPt	= (c==DECIMAL_PT_CHAR);
				    inputCharStream_.advance();
				  }

				  return(new Symbol(atof(lex.c_str())));
				}


  //  PURPOSE:  To return a pointer to a Symbol instance representing an
  //	address.
  Symbol*	scanIdentifier	()
  				{
				  std::string	lex("");
				  char		c;

				  lex	+= tolower(inputCharStream_.peek());
				  inputCharStream_.advance();

				  while  (c = inputCharStream_.peek(),
				  	   isalnum(c) || (c == '_')
				  	 )
				  {
				    lex		       += tolower(c);
				    inputCharStream_.advance();
				  }

				  std::map<std::string,symbol_ty>::iterator
				    iter = keywordToSymbolTMap_.find(lex);

				  if  (iter != keywordToSymbolTMap_.end())
				    return(new Symbol(iter->second));

				  std::string	keywords;
				  bool		isFirst	= true;

				  for  (iter  = keywordToSymbolTMap_.begin();
				        iter != keywordToSymbolTMap_.end();
					iter++
				       )
				  {
				    if  (isFirst)
				      isFirst	 = false;
				    else
				      keywords	+= ", ";

				    keywords += iter->first;
				  }

				  snprintf
					(text,TEXT_LEN,
					 "Expected one of %s, not %s",
					 keywords.c_str(),lex.c_str()
					);
				  throw text;
				}

  //  PURPOSE:  To return a pointer representing a scanned Symbol, or to return
  //	'new Symbol(END_OF_INPUT_SYM)' if the '*this' is at the end-of-input.
  //	No parameters.
  Symbol*	scanner		()
  				{
				  while  ( isspace(inputCharStream_.peek()) )
				    inputCharStream_.advance();

				  if  ( inputCharStream_.isAtEnd() )
				    return( new Symbol(END_OF_INPUT_SYM) );

				  if  ( inputCharStream_.peek() == QUOTE_CHAR )
				    return( scanString() );

				  if  ( isdigit(inputCharStream_.peek()) )
				    return( scanNumber() );

				  if  ( isalpha(inputCharStream_.peek())
				        || (inputCharStream_.peek() == '_')
				      )
				    return( scanIdentifier() );

				  char	  ch	    = inputCharStream_.peek();
				  Symbol* symbolPtr = NULL;

				  inputCharStream_.advance();

				  switch  (ch)
				  {
				  case '(' :
				    symbolPtr	= new Symbol(BEGIN_PAREN_SYM);
				    break;

				  case ')' :
				    symbolPtr	= new Symbol(END_PAREN_SYM);
				    break;

				  case ',' :
				    symbolPtr	= new Symbol(COMMA_SYM);
				    break;

				  case PERIOD_CHAR :
				    symbolPtr	= new Symbol(PERIOD_SYM);
				    break;

				  default :
				    throw "Unexpected character in input";
				  }

				  return(symbolPtr);
				}

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To initialize '*this' to tokenize given characters read from
  //  	'newInputCharStream'.  No parameters.
  TokenStream			(InputCharStream&	newInputCharStream
				) :
				inputCharStream_(newInputCharStream),
				lastParsedPtr_(NULL)
				{
				  keywordToSymbolTMap_["."]
					= PERIOD_SYM;
				  keywordToSymbolTMap_["wash"]
					= WASH_KEYWORD_SYM;
				  keywordToSymbolTMap_["dry"]
					= DRY_KEYWORD_SYM;
				  keywordToSymbolTMap_["lights"]
					= LIGHTS_KEYWORD_SYM;
				  keywordToSymbolTMap_["darks"]
					= DARKS_KEYWORD_SYM;
				  keywordToSymbolTMap_["delicates"]
					= DELICATES_KEYWORD_SYM;
				  keywordToSymbolTMap_["machine"]
					= MACHINE_KEYWORD_SYM;
				  keywordToSymbolTMap_["hand"]
					= HAND_KEYWORD_SYM;
				  keywordToSymbolTMap_["by"]
					= BY_KEYWORD_SYM;
				  keywordToSymbolTMap_["hot"]
					= HOT_KEYWORD_SYM;
				  keywordToSymbolTMap_["warm"]
					= WARM_KEYWORD_SYM;
				  keywordToSymbolTMap_["cold"]
					= COLD_KEYWORD_SYM;
				  keywordToSymbolTMap_["line"]
					= LINE_KEYWORD_SYM;
				  keywordToSymbolTMap_["tumble"]
					= TUMBLE_KEYWORD_SYM;
				  keywordToSymbolTMap_["trousers"]
					= TROUSERS_KEYWORD_SYM;
				  keywordToSymbolTMap_["shirts"]
					= SHIRTS_KEYWORD_SYM;
				  keywordToSymbolTMap_["underwear"]
					= UNDERWEAR_KEYWORD_SYM;
				  keywordToSymbolTMap_["sheets"]
					= SHEETS_KEYWORD_SYM;
				  advance();
				}

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //	value.
  ~TokenStream			()
				{ }

  //  V.  Accessors:

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To return the 'symbol_ty' of the 'Symbol' instance that is next
  //	in the symbol stream.  No parameters.
  symbol_ty   	peek		()
				{
				  if  (lastParsedPtr_ == NULL)
				    lastParsedPtr_	= scanner();

				  return(lastParsedPtr_->getType());
				}

  //  PURPOSE:  To return the pointer to the old Symbol at that was at the
  //	front of the symbol stream, and then to internally advance to the next
  //	Symbol instance (if not already at the end).  No parameters.
  Symbol*	advance		()
				{
				  Symbol* toReturn	= lastParsedPtr_;

				  lastParsedPtr_	= scanner();
				  return(toReturn);
				}

};


void		parseDHow	(TokenStream&	tokenizer)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

  while  ( isspace(inputCharStream_.peek()) ) 
  	inputCharStream_.advance();
  		switch(tokenizer);
  			case (LINE_KEYWORD_SYM);
  				delete(LINE_KEYWORD_SYM);
  			
  			case (TUMBLE_KEYWORD_SYM);
  				delete(LINE_KEYWORD_SYM);
  			
  			case (default);
  				throw("Expected \"line\" or \"tumble\".");
  			

  //  III.  Finished:
}


void		parseDry	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE


  //  III.  Finished:
}
  

void		parseItem	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

}

void		parseItemList	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

  //  III.  Finished:
}


void		parseTemp	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

  //  III.  Finished:
}


void		parseWHow	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

  //  III.  Finished:
}


void		parseType	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

  //  III.  Finished:
}

void		parseWhat	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE

}


void		parseWash	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  // YOUR CODE HERE
}


//  PURPOSE:  To return a 'DirectionCount' corresponding to the directions
//  	read for starting non-terminal 'S' (for 'Sentence') from 'tokenizer'.
void		parseSentence	(TokenStream&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse sentence:
  parseWash(tokenizer);

  if  (tokenizer.peek() != PERIOD_SYM)
    throw "Expected \".\"";

  delete(tokenizer.advance());

  parseDry(tokenizer);

  if  (tokenizer.peek() != PERIOD_SYM)
    throw "Expected \".\"";

  delete(tokenizer.advance());


  if  (tokenizer.peek() != END_OF_INPUT_SYM)
    throw "Expected end-of-input";

  delete(tokenizer.advance());

  //  III.  Finished:
}


//  PURPOSE:  To return a string with the expression to compute, either from
//	the command line or the keyboard.  'argc' tells how many arguments
//	were on the command line and 'argv[]' points to those arguments.
std::string	getInput	(int		argc,
				 char*		argv[]
				)
{
  //  I.  Application validity check:

  //  II.  Get input:
  //  II.A.  Handle command line input:
  if  (argc > 1)
    return(std::string(argv[1]));

  //  II.B.  Handle keyboard input:
  std::string	input;

  std::cout << "Expression to compute: ";
  std::getline(std::cin,input);

  //  III.  Finished:
  return(input);
}


//  PURPOSE:  To get, and attempt to compute, the expression.  The expression
//	may either come from the command line or the keyboard.  'argc' tells
//	how many arguments were on the command line and 'argv[]' points to
//	those arguments.  Returns 'EXIT_SUCCESS' if the expression was
//	successfully parsed and computed or 'EXIT_FAILURE' otherwise.
int		main		(int		argc,
				 char*		argv[]
				)
{
  std::string		input(getInput(argc,argv));
  InputCharStream	charStream(input);
  int			status	= EXIT_SUCCESS;

  try
  {
    TokenStream		tokenizer(charStream);

    parseSentence(tokenizer);
    std::cout << "Thank you for your laundry order!" << std::endl;

  }
  catch  (const char*  messageCPtr
	 )
  {
    std::cerr << messageCPtr << std::endl;
    status	= EXIT_FAILURE;
  }

  return(status);
}	