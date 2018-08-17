{"filter":false,"title":"tinyPascal.lex","tooltip":"/FinalProject/tinyPascal.lex","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":108,"column":0},"action":"insert","lines":["%{","","/*-------------------------------------------------------------------------*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t\ttinyPascal.y\t\t\t\t\t\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t    This file defines a tokenizer used to parser a subset of\t---*"," *---\tPascal.\t\t\t\t\t\t\t\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\t----\t----\t----\t----\t----\t----\t----\t----\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *---\tVersion 1a\t\t2017 June 1\t\tJoseph Phillips\t---*"," *---\t\t\t\t\t\t\t\t\t---*"," *-------------------------------------------------------------------------*/","","  //  Compile with:","  //  $ flex -o pascalLex.c pascal.lex","  //  $ gcc pascalLex.c -o pascalLex","","#include\t\"tinyPascal.h\"","#include\t\"tinyPascal.tab.h\"","","%}","%%","[ \\t\\n\\r]\t\t\t{ /* Ignore spaces */ }","\"{\"[^\"}\"]*\"}\"\t\t\t{ /* Ignore comments */ }","(\"+\"|\"-\")?[0-9]+\".\"[0-9]*\t{","\t\t\t\t  yylval.real_ = strtod(yytext,NULL);","\t\t\t\t  return(REAL);","\t\t\t\t}","(\"+\"|\"-\")?[0-9]*\".\"[0-9]+\t{","\t\t\t\t  yylval.real_ = strtod(yytext,NULL);","\t\t\t\t  return(REAL);","\t\t\t\t}","(\"+\"|\"-\")?[0-9]+\t\t{","\t\t\t\t  yylval.integer_ = strtol(yytext,NULL,10);","\t\t\t\t  return(INTEGER);","\t\t\t\t}","\"'\"[^\"'\"\\n]*\"'\"\t\t\t{","\t\t\t\t  yytext[strlen(yytext)-1]\t= '\\0';","\t\t\t\t  yylval.charPtr_ \t= strdup(yytext+1);","\t\t\t\t  return(STRING);","\t\t\t\t}","\":=\"\t\t\t\t{ return(ASSIGN); }","\"=\"\t\t\t\t{ return(EQUAL); }","\";\"\t\t\t\t{ return(SEMICOLON); }","\",\"\t\t\t\t{ return(COMMA); }","\":\"\t\t\t\t{ return(COLON); }","\".\"\t\t\t\t{ return(PERIOD); }","\"(\"\t\t\t\t{ return(BEGIN_PAREN); }","\")\"\t\t\t\t{ return(END_PAREN); }","PROGRAM|Program|program\t\t{ return(PROGRAM); }","VAR|Var|var\t\t  \t{ return(VAR); }","BEGIN|Begin|begin\t\t{ return(BEGIN_); }","END|End|end\t\t\t{ return(END_); }","IF|If|if\t\t\t{ return(IF); }","THEN|Then|then\t\t\t{ return(THEN); }","ELSE|Else|else\t\t\t{ return(ELSE); }","NOT|Not|not\t\t\t{ return(NOT); }","AND|And|and\t\t\t{ return(AND); }","OR|Or|or\t\t\t{ return(OR); }","REPEAT|Repeat|repeat\t\t{ return(REPEAT); }","UNTIL|Until|until\t\t{ return(UNTIL); }","FOR|For|for\t\t\t{ return(FOR); }","TO|To|to\t\t\t{ return(TO); }","DOWNTO|Downto|downto\t\t{ return(DOWNTO); }","WHILE|While|while\t\t{ return(WHILE); }","DO|Do|do\t\t\t{ return(DO); }","WRITE|Write|write\t\t{ return(WRITE); }","WRITELN|Writeln|writeln\t\t{ return(WRITELN); }","\"<\"\t\t\t\t{ return(LESSER); }","\"<=\"\t\t\t\t{ return(LESSER_EQUAL); }","\">\"\t\t\t\t{ return(GREATER); }","\">=\"\t\t\t\t{ return(GREATER_EQUAL); }","\"<>\"\t\t\t\t{ return(NOT_EQUAL); }","\"+\"\t\t\t\t{ return(PLUS); }","\"-\"\t\t\t\t{ return(MINUS); }","\"*\"\t\t\t\t{ return(STAR); }","DIV|Div|div\t\t\t{ return(INT_DIV); }","\"/\"\t\t\t\t{ return(REAL_DIV); }","BOOLEAN|Boolean|boolean\t\t{","\t\t\t\t  yylval.simpleType_ = BOOLEAN_ST;","\t\t\t\t  return(SIMPLE_TYPE);","\t\t\t\t}","INTEGER|Integer|integer\t\t{","\t\t\t\t  yylval.simpleType_ = INTEGER_ST;","\t\t\t\t  return(SIMPLE_TYPE);","\t\t\t\t}","REAL|Real|real\t\t\t{","\t\t\t\t  yylval.simpleType_ = REAL_ST;","\t\t\t\t  return(SIMPLE_TYPE);","\t\t\t\t}","FALSE|False|\"false\"\t\t{","\t\t\t\t  yylval.bool_\t= false;","\t\t\t\t  return(BOOLEAN);","\t\t\t\t}","TRUE|True|\"true\"\t\t{","\t\t\t\t  yylval.bool_\t= true;","\t\t\t\t  return(BOOLEAN);","\t\t\t\t}","[A-Za-z_][A-Za-z_0-9]*\t\t{","\t\t\t\t  yylval.strPtr_ = new std::string(yytext);","\t\t\t\t  return(IDENTIFIER);","\t\t\t\t}",".\t\t\t\t{ return(\"Weird char %c\\n\",yytext[0]); }","%%","","int\tyywrap\t()\t{ return(1); }",""],"id":1}]]},"ace":{"folds":[],"scrolltop":1075,"scrollleft":0,"selection":{"start":{"row":83,"column":5},"end":{"row":83,"column":5},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":527,"mode":"ace/mode/text"}},"timestamp":1511149961068,"hash":"971c596af0d612dce1a744153f0cb1f6e349e16c"}