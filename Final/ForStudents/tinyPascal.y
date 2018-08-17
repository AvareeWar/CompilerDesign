%{

/*-------------------------------------------------------------------------*
 *---									---*
 *---		tinyPascal.y						---*
 *---									---*
 *---	    This file defines a parser used to parser a subset of	---*
 *---	Pascal.								---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 1		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*

				Compile with:
bison -d --debug tinyPascal.y
g++ -c tinyPascal.tab.c -g
flex -o tinyPascal.cpp tinyPascal.lex 
g++ -c tinyPascal.cpp -g
g++ -o tinyPascal tinyPascal.tab.o tinyPascal.o

 *-------------------------------------------------------------------------*/


#include	"tinyPascal.h"

%}

%union
{
  std::list<std::string*>*	identifierPtrListPtr_;
  Node*				nodePtr_;
  StatementListNode*		statementListNodePtr_;
  std::string*			strPtr_;
  bool				bool_;
  int				integer_;
  float				real_;
  char*				charPtr_;
  simpleType_ty			simpleType_;
};

%start		program

%nonassoc	PROGRAM VAR BEGIN_ END_
%nonassoc	IF THEN FOR TO DOWNTO DO WHILE REPEAT UNTIL WRITE WRITELN
%nonassoc	ELSE
%nonassoc	COMMA SEMICOLON COLON PERIOD
%left		LESSER LESSER_EQUAL GREATER GREATER_EQUAL EQUAL NOT_EQUAL
%left		PLUS MINUS OR
%right		STAR INT_DIV REAL_DIV AND
%nonassoc	NOT
%nonassoc	ASSIGN
%nonassoc				BEGIN_PAREN END_PAREN
%token<strPtr_>				IDENTIFIER
%token<simpleType_>			SIMPLE_TYPE
%token<bool_>				BOOLEAN
%token<integer_>			INTEGER
%token<real_>				REAL
%token<charPtr_>			STRING
%type<statementListNodePtr_>		program
%type<identifierPtrListPtr_>		varList
%type<statementListNodePtr_>		beginBlock
%type<statementListNodePtr_>		statementList
%type<nodePtr_>				statement
%type<nodePtr_>				expression
%type<nodePtr_>				simpleExpression
%type<nodePtr_>				term
%type<nodePtr_>				factor
%%

program		:	PROGRAM
			IDENTIFIER
			SEMICOLON
			optionalVarDeclaration
			beginBlock
			PERIOD
			{
			  programRoot = $$ = $5;
			};

optionalVarDeclaration:	VAR
			varDeclarationList
			{
			}
		|	
			{
			   // Lambda
			};

varDeclarationList :	varDeclarationList
		   	varDeclarationSeq
			{
			}
		|
			{
			   // Lambda
			};

varDeclarationSeq :	varList
		  	COLON
			SIMPLE_TYPE
			SEMICOLON
			{
			  std::list<std::string*>::iterator iter = $1->begin();
			  std::list<std::string*>::iterator end  = $1->end();

			  for  ( ; iter != end;  iter++)
			  {
			    symbolTable.declare(**iter,$3);
			    delete(*iter);
			    *iter	= NULL;
			  }

			};

varList :		varList
			COMMA
			IDENTIFIER
			{
			  $$ = $1;
			  $$->push_back($3);
			}
		|	IDENTIFIER
			{
			  $$ = new std::list<std::string*>;
			  $$->push_back($1);
			};

beginBlock :		BEGIN_
	   		statementList
			END_
			{
			  $$ = $2;
			}
		|	BEGIN_
	   		statementList
	      		SEMICOLON
			END_
			{
			  $$ = $2;
			};

statementList :		statementList
	      		SEMICOLON
	      		statement
			{
			  $$	= $1;

			  if  ($3 != NULL)
			    $$->append($3);
			}
		|	statement
			{
			  $$	= new StatementListNode;

			  if  ($1 != NULL)
			    $$->append($1);
			};

statement :		beginBlock
	  		{
			  $$	= $1;
			}
		|	IF
			expression
			THEN
			statement
			{
			  $$	= new IfNode($2,$4);
			}
		|	IF
			expression
			THEN
			statement
			ELSE
			statement	%prec ELSE
			{
			  $$	= new IfNode($2,$4,$6);
			}
		|	FOR
			IDENTIFIER
			ASSIGN
			expression
			TO
			expression
			DO
			statement
			{
			  $$	= new ForNode
					(new VariableNode(*$2),
					 $4,
					 $6,
					 $8,
					 +1
					);
			  delete($2);
			}
		|	FOR
			IDENTIFIER
			ASSIGN
			expression
			DOWNTO
			expression
			DO
			statement
			{
			  $$	= new ForNode
					(new VariableNode(*$2),
					 $4,
					 $6,
					 $8,
					 -1
					);
			  delete($2);
			}
		|	IDENTIFIER
			ASSIGN
			expression
			{
			  $$	= new AssignmentNode(new VariableNode(*$1),$3);
			  delete($1);
			}
		|	WRITELN
			{
			  $$	= new WriteNode(true);
			}
		|	WRITE
			BEGIN_PAREN
			expression
			END_PAREN
			{
			  $$	= new WriteNode(false,$3);
			};
		|	WRITELN
			BEGIN_PAREN
			expression
			END_PAREN
			{
			  $$	= new WriteNode(true,$3);
			};

expression :		simpleExpression
	   		{
			  $$	= $1;
			}
		|	simpleExpression
			LESSER
			simpleExpression
			{
			  $$	= new ComparisonOpNode(LESSER_CO,$1,$3);
			}
		|	simpleExpression
			LESSER_EQUAL
			simpleExpression
			{
			  $$	= new ComparisonOpNode(LESSER_EQUAL_CO,$1,$3);
			}
		|	simpleExpression
			GREATER
			simpleExpression
			{
			  $$	= new ComparisonOpNode(GREATER_CO,$1,$3);
			}
		|	simpleExpression
			GREATER_EQUAL
			simpleExpression
			{
			  $$	= new ComparisonOpNode(GREATER_EQUAL_CO,$1,$3);
			}
		|	simpleExpression
			EQUAL
			simpleExpression
			{
			  $$	= new ComparisonOpNode(EQUAL_CO,$1,$3);
			}
		|	simpleExpression
			NOT_EQUAL
			simpleExpression
			{
			  $$	= new ComparisonOpNode(NOT_EQUAL_CO,$1,$3);
			};

simpleExpression :	term
	   		{
			  $$	= $1;
			}
		|	simpleExpression
			PLUS
			term
			{
			  $$	= new BinaryMathOpNode(ADD_BMO,$1,$3);
			}
		|	simpleExpression
			MINUS
			term
			{
			  $$	= new BinaryMathOpNode(SUBTRACT_BMO,$1,$3);
			}
		|	simpleExpression
			OR
			term
			{
			  $$	= new BinaryLogicOpNode(OR_BLO,$1,$3);
			};

term	:		factor
			{
			  $$	= $1;
			}
		|	term
			STAR
			factor
			{
			  $$	= new BinaryMathOpNode(MULTIPLY_BMO,$1,$3);
			}
		|	term
			INT_DIV
			factor
			{
			  $$	= new BinaryMathOpNode(INT_DIVIDE_BMO,$1,$3);
			}
		|	term
			REAL_DIV
			factor
			{
			  $$	= new BinaryMathOpNode(REAL_DIVIDE_BMO,$1,$3);
			}
		|	term
			AND
			factor
			{
			  $$	= new BinaryLogicOpNode(AND_BLO,$1,$3);
			};

factor :		IDENTIFIER
       			{
			  $$	= new VariableNode(*$1);
			  delete($1);
			}
		|	BOOLEAN
			{
			  $$	= new BooleanConstantNode($1);
			}
		|	INTEGER
			{
			  $$	= new IntegerConstantNode($1);
			}
		|	REAL
			{
			  $$	= new RealConstantNode($1);
			}
		|	STRING
			{
			  $$	= new StringConstantNode($1);
			}
		|	BEGIN_PAREN
			expression
			END_PAREN
			{
			  $$	= $2;
			};
			

%%



//  PURPOSE:  To hold the address of the root of the parse tree.
Node*		programRoot	= NULL;


int		yyerror		(const char*	cPtr)
{
  printf("%s, sorry!\n",cPtr);
  return(0);
}


int		yylex		();


//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryLogicOp_ty' value.
const char*	binaryLogicOpName[]
				= { "",
				    "or",
				    "and"
				  };


//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryMathOp_ty' value.
const char*	binaryMathOpName[]
      				= { "",
				    "add",
				    "sub",
				    "mul",
				    "div"
				  };

//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'comparisonOp_ty' value.
const char*	comparisonOpName[]
      				= { "",
				    "lesser",
				    "lesserEqual",
				    "greater",
				    "greaterEqual",
				    "equal",
				    "not_equal"
				  };

//  PURPOSE:  To hold the names of boolean constants.
const char*	booleanConstName[]
				= {"false", "true"};


//  PURPOSE:  To point to the stream to which output should be written
std::ofstream*	outputStreamPtr	= NULL;

//  PURPOSE:  To hold the next label number to use:
int		LabelMention::nextLabelId__
				= 0;


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention*	toPrint
				)
{
  os << LABEL_COMMON_PREFIX << toPrint->getId() << LABEL_COMMON_POSTFIX;
}


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention&	toPrint
				)
{
  os << LABEL_COMMON_PREFIX << toPrint.getId() << LABEL_COMMON_POSTFIX;
}


//  PURPOSE:  To hold the next auto-generated variable number to use:
int		VariableMention::nextAutoVarId__
				= RETURN_VAR + 1;


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention*	toPrint
				)
{
  os << VAR_PREFIX_CHAR << toPrint->getName();
}


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention&	toPrint
				)
{
  os << VAR_PREFIX_CHAR << toPrint.getName();
}



//  PURPOSE:  To hold defintions of symbols (e.g. variables)
SymbolTable	symbolTable;


//  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
//	value.
Node::~Node			()
				{ }


//  PURPOSE:  To make '*this' mention the variable named 'cPtr'.
//  	No parameters.  No return value.
VariableMention::VariableMention(const char*	cPtr
  				) :
				name_(NULL)
				{
				  std::stringstream	strm;

				  strm << symbolTable.getOffset(cPtr);
				  name_	= strm.str();
				}

//  PURPOSE:  To make '*this' mention the variable named 'newName'.
//  	No parameters.  No return value.
VariableMention::VariableMention(const std::string&	newName
				) :
				name_(newName)
				{
				  std::stringstream	strm;

				  strm << symbolTable.getOffset(newName);
				  name_	= strm.str();
				}

//  PURPOSE:  To do compile-time checks of '*this' node.  'simpleType' is
//  	set to the type that the code generated by '*this' node returns (or
//	 to 'NO_TYPE_ST' if it does not return a value).  Returns the address
//	 of a VariableMention that the code generated by '*this' node updates
//	(or 'NULL' if there is no such variable).
VariableMention*
		VariableNode::compile
				(simpleType_ty&	simpleType
				)
{
  //  Set 'simpleType' to the type returned by 'symbolTable.getType()' when
  //	you give it the name of the variable.
  //  If this type is 'NO_TYPE_ST' then do:
  //
  //	throw "Undeclared variable";
  //
  //  otherwise, set 'varPtr_' to a new VariableMention for this variable
  //	(just say 'new VariableMention(getName()') and return 'varPtr_'.
  return(NULL);		// <-- change that NULL
}


int		main		(int		argc,
				 char*		argv[]
				)
{
  //  I.  Application validity check:
  if  (argc < 2)
  {
    fprintf(stderr,"Usage:\t%s <pascalProg> <assemblyOutFile>\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  //  II.  Parse and execute program:
  //  II.A.  Initialize files:
  const char*	pascalFilepath	= argv[1];
  const char*	assemblyFilepath= argv[2];
  std::ofstream	output(assemblyFilepath);

  outputStreamPtr	= &output;

  if  ( (yyin = fopen(pascalFilepath,"r")) == NULL )
  {
    fprintf(stderr,"Error opening %s.\n",pascalFilepath);
    exit(EXIT_FAILURE);
  }

  if  ( !output.is_open() )
  {
    fprintf(stderr,"Error opening %s.\n",assemblyFilepath);
    fclose(yyin);
    exit(EXIT_FAILURE);
  }

  //  II.B.  Attempt to parse and assemble 'filename':
  int	status	= EXIT_SUCCESS;

  try
  {
    yyparse();

    if  (programRoot != NULL)
    {
      simpleType_ty	simpleType;
      VariableMention*	nodePtr	= programRoot->compile(simpleType);

      programRoot->writeAssembly(output);

      if  (nodePtr == NULL)
        output << "  load " << RETURN_VAR_NAME
	       << ","  << RETURN_VAR
	       << std::endl;
      else
      {
        output << "  copy " << RETURN_VAR_NAME
	       << "," << *nodePtr
	       << std::endl;
      }

      output << "  stopWSuccess" << std::endl;
    }

  }
  catch  (const char* cPtr)
  {
    fprintf(stderr,"Error: %s\n",cPtr);
    status	= EXIT_FAILURE;
  }

  //  II.C.  Clean up:
  delete(programRoot);
  output.close();
  fclose(yyin);

  //  III.  Finished:
  return(status);
}
