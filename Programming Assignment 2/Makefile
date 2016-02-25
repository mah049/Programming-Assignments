#
# Makefile template for CSE 30 -- PA2
#

#
# You need to change these next lines for each assignment
#

HEADERS		= pa2.h pa2_strings.h

C_SRCS		= main.c displayBCDClock.c tm_hourOffset.c tm_minOffset.c \
		  tm_secOffset.c updateBCDClock.c pa2gettimeofday.c usage.c \
		  parseStartTime.c

ASM_SRCS	= checkRange.s setBCDClock.s updateBCDValue.s printChar.s

C_OBJS		= main.o displayBCDClock.o tm_hourOffset.o tm_minOffset.o \
		  tm_secOffset.o updateBCDClock.o pa2gettimeofday.o usage.o \
		  parseStartTime.o

ASM_OBJS	= checkRange.o setBCDClock.o updateBCDValue.o printChar.o

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= BCDclock

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= ${GCC}
LINT		= lint

GCC_FLAGS	= -c -g -W -Wall -D__EXTENSIONS__
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -W -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	${ASM} ${ASM_FLAGS} $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	${LINT} ${LINT_FLAGS1} $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	${GCC} ${GCC_FLAGS} $<
	@echo ""

#
# Simply have our project target be a single default ${EXE} executable.
#

${EXE}:	${OBJS}
	@echo "2nd phase lint on all C source files ..."
	${LINT} ${LINT_FLAGS2} *.ln
	@echo ""
	@echo "Linking all object modules ..."
	${GCC} -o ${EXE} ${LD_FLAGS} ${OBJS}
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}


unitTest_checkRange: test.h pa2.h checkRange.s unitTest_checkRange.c
	@echo "Compiling unitTest_checkRange.c"
	gcc -g -o unitTest_checkRange unitTest_checkRange.c checkRange.s
	@echo "Done."

run_unitTest_checkRange: unitTest_checkRange
	@echo "Running unitTest_checkRange"
	@./unitTest_checkRange


unitTest_setBCDClock: test.h pa2.h tm_hourOffset.c tm_minOffset.c \
	tm_secOffset.c setBCDClock.s unitTest_setBCDClock.c
	@echo "Compiling unitTest_setBCDClock.c"
	gcc -g -o unitTest_setBCDClock unitTest_setBCDClock.c setBCDClock.s \
	tm_hourOffset.c tm_minOffset.c tm_secOffset.c
	@echo "Done."

run_unitTest_setBCDClock: unitTest_setBCDClock
	@echo "Running unitTest_setBCDClock"
	@./unitTest_setBCDClock


unitTest_updateBCDValue: test.h pa2.h updateBCDValue.s unitTest_updateBCDValue.c
	@echo "Compiling unitTest_updateBCDValue.c"
	gcc -g -o unitTest_updateBCDValue unitTest_updateBCDValue.c updateBCDValue.s
	@echo "Done."

run_unitTest_updateBCDValue: unitTest_updateBCDValue
	@echo "Running unitTest_updateBCDValue"
	@./unitTest_updateBCDValue

unitTest_parseStartTime: test.h pa2.h parseStartTime.c checkRange.s unitTest_parseStartTime.c
	@echo "Compiling unitTest_parseStartTime.c"
	gcc -g -o unitTest_parseStartTime unitTest_parseStartTime.c parseStartTime.c \
	checkRange.s
	@echo "Done."

run_unitTest_parseStartTime: unitTest_parseStartTime
	@echo "Running unitTest_parseStartTime"
	@./unitTest_parseStartTime

clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o ${EXE} *.ln core a.out \
	unitTest_updateBCDValue unitTest_setBCDClock unitTest_parseStartTime \
	unitTest_checkRange
	@echo ""
	@echo "Clean."

new:
	make clean
	make

