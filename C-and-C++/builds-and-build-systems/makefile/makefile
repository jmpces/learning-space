# ========================== BASIC MAKEFILE RULE STRUCTURE ==========================

# target: [dependencies]
#	<shell command>
#	<shell command>

# ========================== STRICTLY SET WORD ONLY AS TARGET ==========================

.PHONY: files1 files2

# ========================== FINDING FILES ==========================

files1:
	@echo $(wildcard include/*.hpp)

# or assigning it to a variable

HEADERS := $(wildcard include/*.hpp)
SRC := $(wildcard src/*.cpp)

files2:
	@echo HEADERS = [$(HEADERS)]
	@echo SRC = [$(SRC)]

# ========================== VARIABLE SUBSTRING REPLACEMENT ==========================

# $(var:pattern=replacement)
OBJ=$(SRC:.cpp=.o)

# equivalent to

# $(patsubst pattern,replacement,$(var))
OBJ2=$(patsubst .cpp, .o,$(OBJ))

files3:
	@echo SRC  = [$(SRC)]
	@echo OBJ  = [$(OBJ)]
	@echo OBJ2 = [$(OBJ2)]

# ========================== AUTOMATIC VARIABLES ==========================

av1:
	@echo get target name : $@

av2: main.cpp src/example.cpp src/sample.cpp include/example.hpp include/sample.hpp
	@echo get all recently changed dependencies :
	@echo $?

av3: main.cpp src/example.cpp src/sample.cpp include/example.hpp include/sample.hpp
	@echo get all dependencies \(no duplicates\) :
	@echo $^

av4: main.cpp src/example.cpp src/sample.cpp include/example.hpp include/sample.hpp
	@echo get all dependencies \(w/ possible duplicates\) :
	@echo $+

av5: main.cpp src/example.cpp src/sample.cpp include/example.hpp include/sample.hpp
	@echo get the first dependency : $<

av6: main.cpp src/example.cpp src/sample.cpp include/example.hpp include/sample.hpp
	@echo only get the directory part of the dependencies
	@echo \(NOTE: can be used with any automatic variables\) :
	@echo
	@echo original : $^
	@echo result : $(^D)

av7: $(SRC)
	@echo only get the filename part of the dependencies
	@echo \(NOTE: can be used with any automatic variables\) :
	@echo
	@echo original : $^
	@echo result : $(^F)

# ========================== COMPILE & RUN MILTIPLE EXECUTABLES ==========================

# THE STATIC PATTERN RULES

# targets …: target-pattern: prereq-patterns …
# 	recipe
# 	…

EXECUTABLES=$(SRC:.cpp=.out)

# runs the compiled executable dependencies.
run: $(EXECUTABLES)
	echo tttt
# $(foreach EXECUTABLE, $^,\
# 	./$(EXECUTABLE) ;\
# )

# compiles the sources needed by the executable targets.
$(EXECUTABLES): %.out : %.cpp $(HEADERS)
	$(CXX) $< -o $@

# EXPLANATION OF EACH PARTS

# TARGETS PART
# $(EXECUTABLES): - using a text array as a target, will loop the
# current rule for each element of that text array. each loop iteration
# will use the current iterated text array element as the target.
# note: see line 1 to know what a "rule" is.

# TARGET PATTERN PART
# %.out - this extracts the '%' part in the current iterated target $(EXECUTABLES)
# for example if the current target is 'main.out' if we used the target-pattern '%.out'
# we will be able to extract the 'main' part of the that target, we can use that 'main'
# part in the PREREQ-PATTERN PART.

# PREREQ-PATTERN PART
# %.cpp - catches the extracted value of '%.out' then used it a the first dependency.
# On our example above since we extracted 'main' using the '%.out' in the "target pattern"
# part... that value will be substituted to the '%' of the "prereq-pattern" part
# making the value of '%.cpp' into 'main.cpp'.

# '$@' get the current iterated target which is an element of $(EXECUTABLES)
# '$<' get the first dependency, which in this case '%.cpp.

# ========================== GNU/MAKE FUNCTIONS ==========================

fn1:
	@echo get only the directory part \(an alternative to D\) :
	@echo
	@echo original: $(SRC) $(HEADERS)
	@echo result : $(dir $(SRC) $(HEADERS))


fn2:
	@echo get only the filename part \(an alternative to F\) :
	@echo
	@echo original: main.cpp src/example.cpp src/sample.cpp include/example.hpp
	@echo result : $(notdir main.cpp src/example.cpp src/sample.cpp include/example.hpp)

fn3: $(SRC) $(HEADERS)
	@echo get matching sub string using :
	@echo
	@echo original: $^
	@echo
	@echo display only words with .cpp
	@echo result : $(filter %.cpp, $^)
	@echo
	@echo display only words with .hpp
	@echo result : $(filter %.hpp, $^)
	@echo
	@echo display only words with 'xamp'
	@echo result : $(findstring xamp, $^)


# When using characters that are special to make as function arguments, you may need to hide them.
# GNU make doesn’t support escaping characters with backslashes or other escape sequences; however,
# because arguments are split before they are expanded you can hide them by putting them into variables.

# Here the subst function replaces each space with a comma, through the value of foo, and substitutes the result.

comma:= ,
empty:=
space:= $(empty) $(empty)
foo:= a b c
bar:= $(subst $(space),$(comma),$(foo))

fn4:
	@echo foo = $(foo)
	@echo bar = $(bar)
# bar is now ‘a,b,c’.


# ============ SOME STRING FUNCTIONS THAT MIGHT BE USEFULL =========

# string/word - group of characters without any whitespace
# text/list/words/names - collection of word or string separated by whitespaces

# STRING FUNCTIONS

# $(subst from,to,text)
# Performs a textual replacement on the text : each occurrence of from is replaced by to.

# $(patsubst pattern,replacement,text)
# Finds whitespace-separated words in text that match pattern and replaces them with replacement.
# can use % inside the pattern an replacement

# $(strip string)
# > Removes leading and trailing whitespace from string and replaces each
# internal sequence of one or more whitespace characters with a single space.

# $(findstring find,in)
# > Searches in for an occurrence of find.
# If it occurs, the value is find; otherwise, the value is empty. 

# FILTERING TEXT FUNCTIONS

# $(filter pattern…,text)
# > Returns all whitespace-separated words in text that do match any of the
# pattern words, removing any words that do not match.

# $(filter-out pattern…,text)
# > Returns all whitespace-separated words in text that do not match any of
# the pattern words, removing the words that do match one or more. 

# SORT FUNCTION

# $(sort list)
# > Sorts the words of list in lexical order, removing duplicate words.
# The output is a list of words separated by single spaces. 

# INDEXING TEXT FUNCTIONS

# $(word n,text)
# > Returns the nth word of text. The legitimate values of n start from 1.
# If n is bigger than the number of words in text, the value is empty.

# $(wordlist s,e,text)
# > Returns the list of words in text starting with word s and ending with word e (inclusive).
# The legitimate values of s start from 1; e may start from 0. If s is bigger than the number
# of words in text, the value is empty. If e is bigger than the number of words in text, words
# up to the end of text are returned. If s is greater than e, nothing is returned.
# s and e are the index/position of the word in the text

# $(words text)
# Returns the number of words in text.

# $(firstword names…) & $(lastword names…)
# returns the first and last word in a text


# CONDITIONAL FUNCTIONS

# $(if condition,then-part[,else-part])
# The first argument, condition, first has all preceding and trailing whitespace stripped,
# then is expanded. If it expands to any non-empty string, then the condition is considered to be true.
# If it expands to an empty string, the condition is considered to be false.

FALSE:=
TRUE:=ANYTHING_THAT_HAVE_VALUE

fn6:
	@echo $(if $(FALSE), the result is true, the result is false)
	@echo $(if $(TRUE), the result is true, the result is false)

fn7:
	@echo $(and $(TRUE), $(TRUE), $(TRUE), RESULT)
	@echo $(and $(TRUE), $(FALSE), $(TRUE), RESULT)
# The and function provides a “short-circuiting” AND operation. Each argument is expanded, in order.
# If an argument expands to an empty string the processing stops and the result of the expansion is the empty string.
# If all arguments expand to a non-empty string then the result of the expansion is the expansion of the last argument.

# $(intcmp lhs,rhs[,lt-part[,eq-part[,gt-part]]])
# Else if the left-hand side is strictly less than the right-hand side,
# the intcmp function evaluates to the expansion of the third argument, lt-part.
# If both sides compare equal, then the intcmp function evaluates to the expansion of the fourth argument, eq-part.
# If the left-hand side is strictly greater than the right-hand side,
# then the intcmp function evaluates to the expansion of the fifth argument, gt-part.

# $(foreach var,list,text)
fn8: $(SRC) $(HEADERS)
	@echo Display all dependencies using for each.
	@echo by using \'\;\' it will create a new line:
	@$(foreach x, $^, echo $(x);)
	@echo
	@echo Filter out words that don\'t have the \'xamp\' substring :
	@$(foreach x, $^, $(if $(findstring xamp, $(x)), echo $(x);))



