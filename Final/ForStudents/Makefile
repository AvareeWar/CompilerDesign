tinyPascal		: tinyPascal.tab.o tinyPascal.o
			g++ -o $@ tinyPascal.tab.o tinyPascal.o

tinyPascal.o		: tinyPascal.cpp tinyPascal.h tinyPascal.tab.h \
			  LabelMention.h VariableMention.h Node.h
			g++ -c tinyPascal.cpp -g

tinyPascal.cpp		: tinyPascal.lex
			flex -o tinyPascal.cpp tinyPascal.lex 

tinyPascal.tab.o	: tinyPascal.tab.c tinyPascal.h \
			  LabelMention.h VariableMention.h Node.h
			g++ -c tinyPascal.tab.c -g

tinyPascal.tab.c	: tinyPascal.y
			bison -d --debug tinyPascal.y

tinyPascal.tab.h	: tinyPascal.y
			bison -d --debug tinyPascal.y