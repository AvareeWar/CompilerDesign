{"filter":false,"title":"tinyPascal.h","tooltip":"/FinalProject/tinyPascal.h","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":127,"column":32},"action":"insert","lines":["/*-------------------------------------------------------------------------*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t\ttinyPascal.h\t\t\t\t\t\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t    This file includes common headers and declares common\t---*"," *---\tvariables used through-out the tiny pascal parser.\t\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t----\t----\t----\t----\t----\t----\t----\t----\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\tVersion 1a\t\t2017 June 2\t\tJoseph Phillips\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *-------------------------------------------------------------------------*/","","#include\t<cstdlib>","#include\t<cstdio>","#include\t<cstring>","#include\t<iostream>","#include\t<fstream>","#include\t<sstream>","#include\t<string>","#include\t<vector>","#include\t<list>","#include\t<map>","","const int\tLINE_LEN\t\t= 256;","","const char\tCOMMENT_CHAR\t\t= ';';","","const char\tLABEL_POSTFIX_CHAR\t= ':';","#define\t\tLABEL_COMMON_PREFIX\t\"label\"","#define\t\tLABEL_COMMON_POSTFIX\t\"%\"","","const char\tVAR_PREFIX_CHAR\t\t= '%';","#define\t\tAUTO_VAR_NAME_PREFIX\t\"\"","#define\t\tRETURN_VAR_NAME\t\t\"%0\"","","const int\tRETURN_VAR\t\t= 0;","","","//  PURPOSE:  To represent the basic types in tiny Pascal.","typedef\t\tenum","\t\t{","\t\t  NO_TYPE_ST,","\t\t  BOOLEAN_ST,","\t\t  INTEGER_ST,","\t\t  REAL_ST,","\t\t  STRING_ST","\t\t}","\t\tsimpleType_ty;","","","//  PURPOSE:  To represent Pascal binary logic operations.","typedef\t\tenum","\t\t{","\t\t  NO_BLO,","\t\t  OR_BLO,","\t\t  AND_BLO","\t\t}","\t\tbinaryLogicOp_ty;","","//  PURPOSE:  To hold the names of SPVM assembly language instructions that","//\timplement the operations of the corresponding 'binaryLogicOp_ty' value.","extern","const char*\tbinaryLogicOpName[];","","//  PURPOSE:  To represent Pascal binary integer operations.","typedef\t\tenum","\t\t{","\t\t  NO_BMO,","\t\t  ADD_BMO,","\t\t  SUBTRACT_BMO,","\t\t  MULTIPLY_BMO,","\t\t  INT_DIVIDE_BMO,","\t\t  REAL_DIVIDE_BMO","\t\t}","\t\tbinaryMathOp_ty;","","//  PURPOSE:  To hold the names of SPVM assembly language instructions that","//\timplement the operations of the corresponding 'binaryMathOp_ty' value.","extern","const char*\tbinaryMathOpName[];","","","//  PURPOSE:  To represent Pascal integer comparisons.","typedef\t\tenum","\t\t{","\t\t  NO_CO,","\t\t  LESSER_CO,","\t\t  LESSER_EQUAL_CO,","\t\t  GREATER_CO,","\t\t  GREATER_EQUAL_CO,","\t\t  EQUAL_CO,","\t\t  NOT_EQUAL_CO","\t\t}","\t\tcomparisonOp_ty;","","//  PURPOSE:  To hold the names of SPVM assembly language instructions that","//\timplement the operations of the corresponding 'comparisonOp_ty' value.","extern","const char*\tcomparisonOpName[];","","","//  PURPOSE:  To hold the names of boolean constants.","extern","const char*\tbooleanConstName[];","","","//  PURPOSE:  To point to the stream to which output should be written","extern","std::ofstream*\toutputStreamPtr;","","","#include\t\"LabelMention.h\"","#include\t\"VariableMention.h\"","#include\t\"SymbolTable.h\"","#include\t\"Node.h\"","","","//  PURPOSE:  To hold the address of the root of the parse tree.","extern\t\tNode*\t\tprogramRoot;","extern\t\tFILE*\t\tyyin;","","extern\t\tint\t\tyyerror\t\t(const char*\tcPtr);","extern\t\tint\t\tyylex\t\t();","","","//  PURPOSE:  To hold defintions of symbols (e.g. variables)","extern\t\tSymbolTable\tsymbolTable;"],"id":1}]]},"ace":{"folds":[],"scrolltop":726,"scrollleft":0,"selection":{"start":{"row":115,"column":17},"end":{"row":115,"column":17},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":527,"mode":"ace/mode/c_cpp"}},"timestamp":1511149959224,"hash":"0f3f1ccb1800521725fc155f037888535b466b86"}