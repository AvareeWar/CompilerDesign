# ------------------------------------------------------------------------- #
# ---									--- #
# ---		Makefile						--- #
# ---									--- #
# ---	    This file details the dependencies upon the source, object	--- #
# ---	and executable files of the laundry language program.		--- #
# ---									--- #
# ---	----	----	----	----	----	----	----	----	--- #
# ---									--- #
# ---	Version 1a		2017 October 25		Joseph Phillips	--- #
# ---									--- #
# ------------------------------------------------------------------------- #

laundryLang		: laundryLang.tab.o laundryLang.o
			g++ -o $@ laundryLang.tab.o laundryLang.o -g

laundryLang.o		: laundryLang.cpp laundryLang.h laundryLang.tab.h
			g++ -c laundryLang.cpp -g

laundryLang.tab.o	: laundryLang.tab.c laundryLang.h laundryLang.tab.h
			g++ -c laundryLang.tab.c -g

laundryLang.cpp		: laundryLang.lex
			flex -o $@ laundryLang.lex

laundryLang.tab.c	: laundryLang.y
			bison -d laundryLang.y --debug --verbose

laundryLang.tab.h	: laundryLang.y
			bison -d laundryLang.y --debug --verbose

clean			:
			rm laundryLang.tab.? laundryLang.cpp laundryLang.o \
			   laundryLang laundryLang.output