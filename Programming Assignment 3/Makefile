#
# Makefile template for CSE 30 -- PA3
#

HEADERS		= pa3.h pa3_strings.h

C_SRCS		= makeAnagramTable.c displayAnagrams.c findAnagrams.c\
		  pa3_globals.c main.c

ASM_SRCS	= anagramCompare.s charCompare.s sortedMemberCompare.s usage.s

C_OBJS		= makeAnagramTable.o displayAnagrams.o findAnagrams.o\
		  pa3_globals.o main.o

ASM_OBJS	= anagramCompare.o charCompare.o sortedMemberCompare.o usage.o

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= anagrams

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default "anagrams" executable.
#
$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo "Done."

${C_OBJS}:      ${HEADERS}


clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o $(EXE) *.ln core unitTest_anagramCompare\
		unitTest_makeAnagramTable unitTest_charCompare\
		unitTest_findAnagrams unitTest_sortedMemberCompare
	@echo ""
	@echo "Clean."

new:
	make --no-print-directory clean
	make --no-print-directory

unitTest_anagramCompare: anagramCompare.s unitTest_anagramCompare.c\
		pa3_globals.c
	@echo "Compiling unitTest_anagramCompare"
	gcc -g -o unitTest_anagramCompare anagramCompare.s\
		unitTest_anagramCompare.c pa3_globals.c
	@echo "Done."

run_unitTest_anagramCompare: unitTest_anagramCompare
	@echo "Running unitTest_anagramCompare"
	@./unitTest_anagramCompare

unitTest_makeAnagramTable: anagramCompare.s makeAnagramTable.c charCompare.s\
		pa3_globals.c unitTest_makeAnagramTable.c
	@echo "Compiling unitTest_makeAnagramTable"
	gcc -g -o unitTest_makeAnagramTable anagramCompare.s\
		makeAnagramTable.c charCompare.s pa3_globals.c\
		unitTest_makeAnagramTable.c
	@echo "Done."

run_unitTest_makeAnagramTable: unitTest_makeAnagramTable
	@echo "Running unitTest_makeAnagramTable"
	@./unitTest_makeAnagramTable

unitTest_charCompare: charCompare.s unitTest_charCompare.c
	@echo "Compiling unitTest_charCompare"
	gcc -g -o unitTest_charCompare charCompare.s unitTest_charCompare.c
	@echo "Done."

run_unitTest_charCompare: unitTest_charCompare
	@echo "Running unitTest_charCompare"
	@./unitTest_charCompare

unitTest_findAnagrams: anagramCompare.s makeAnagramTable.c charCompare.s\
		pa3_globals.c findAnagrams.c sortedMemberCompare.s\
		unitTest_findAnagrams.c
	@echo "Compiling unitTest_sortedMemberCompare"
	gcc -g -o unitTest_findAnagrams anagramCompare.s\
		makeAnagramTable.c charCompare.s\
		pa3_globals.c findAnagrams.c sortedMemberCompare.s\
		unitTest_findAnagrams.c
	@echo "Done."

run_unitTest_findAnagrams: unitTest_findAnagrams
	@echo "Running unitTest_findAnagrams"
	@./unitTest_findAnagrams

unitTest_sortedMemberCompare: sortedMemberCompare.s\
		unitTest_sortedMemberCompare.c pa3_globals.c
	@echo "Compiling unitTest_sortedMemberCompare"
	gcc -g -o unitTest_sortedMemberCompare pa3_globals.c\
		sortedMemberCompare.s unitTest_sortedMemberCompare.c
	@echo "Done."

run_unitTest_sortedMemberCompare: unitTest_sortedMemberCompare
	@echo "Running unitTest_sortedMemberCompare"
	@./unitTest_sortedMemberCompare


