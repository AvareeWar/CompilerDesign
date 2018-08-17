/*-------------------------------------------------------------------------*
 *---									---*
 *---		tinyPascal.h						---*
 *---									---*
 *---	    This file includes common headers and declares common	---*
 *---	variables used through-out the tiny pascal parser.		---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	<cstdlib>
#include	<cstdio>
#include	<cstring>
#include	<iostream>
#include	<fstream>
#include	<sstream>
#include	<string>
#include	<vector>
#include	<list>
#include	<map>

const int	LINE_LEN		= 256;

const char	COMMENT_CHAR		= ';';

const char	LABEL_POSTFIX_CHAR	= ':';
#define		LABEL_COMMON_PREFIX	"label"
#define		LABEL_COMMON_POSTFIX	"%"

const char	VAR_PREFIX_CHAR		= '%';
#define		AUTO_VAR_NAME_PREFIX	""
#define		RETURN_VAR_NAME		"%0"

const int	RETURN_VAR		= 0;


//  PURPOSE:  To represent the basic types in tiny Pascal.
typedef		enum
		{
		  NO_TYPE_ST,
		  BOOLEAN_ST,
		  INTEGER_ST,
		  REAL_ST,
		  STRING_ST
		}
		simpleType_ty;


//  PURPOSE:  To represent Pascal binary logic operations.
typedef		enum
		{
		  NO_BLO,
		  OR_BLO,
		  AND_BLO
		}
		binaryLogicOp_ty;

//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryLogicOp_ty' value.
extern
const char*	binaryLogicOpName[];

//  PURPOSE:  To represent Pascal binary integer operations.
typedef		enum
		{
		  NO_BMO,
		  ADD_BMO,
		  SUBTRACT_BMO,
		  MULTIPLY_BMO,
		  INT_DIVIDE_BMO,
		  REAL_DIVIDE_BMO
		}
		binaryMathOp_ty;

//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'binaryMathOp_ty' value.
extern
const char*	binaryMathOpName[];


//  PURPOSE:  To represent Pascal integer comparisons.
typedef		enum
		{
		  NO_CO,
		  LESSER_CO,
		  LESSER_EQUAL_CO,
		  GREATER_CO,
		  GREATER_EQUAL_CO,
		  EQUAL_CO,
		  NOT_EQUAL_CO
		}
		comparisonOp_ty;

//  PURPOSE:  To hold the names of SPVM assembly language instructions that
//	implement the operations of the corresponding 'comparisonOp_ty' value.
extern
const char*	comparisonOpName[];


//  PURPOSE:  To hold the names of boolean constants.
extern
const char*	booleanConstName[];


//  PURPOSE:  To point to the stream to which output should be written
extern
std::ofstream*	outputStreamPtr;


#include	"LabelMention.h"
#include	"VariableMention.h"
#include	"SymbolTable.h"
#include	"Node.h"


//  PURPOSE:  To hold the address of the root of the parse tree.
extern		Node*		programRoot;
extern		FILE*		yyin;

extern		int		yyerror		(const char*	cPtr);
extern		int		yylex		();


//  PURPOSE:  To hold defintions of symbols (e.g. variables)
extern		SymbolTable	symbolTable;
