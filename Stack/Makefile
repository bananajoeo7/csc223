CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_lists: build/Stack_Infix.o build/test_Infix.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test clean

test: build/test_Infix
	./build/test_Infix

clean:
	rm -rf build