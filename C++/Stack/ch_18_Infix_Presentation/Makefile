
CC=g++
STD=c++11

default:
	clear
	@make clean
	@make test

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	@$(CC) -c -o $@ $< -std=$(STD)

build/%: build/%.o
	$(CC) -o $@ $^ -std=$(STD)

build/testEval: build/testEval.o build/Evaluator.o
	@$(CC) -o $@ $^ -std=$(STD)

.PHONY: test clean includeDoctest

test: build/testEval
	@./build/testEval

clean:
	@rm -rf build

includeDoctest:
	export CPLUS_INCLUDE_PATH=/opt/homebrew/include/doctest
