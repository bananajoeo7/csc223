CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

-include build/*.d

.PHONY: test clean

test: build/test_queue
	./build/test_queue

clean:
	rm -rf build
