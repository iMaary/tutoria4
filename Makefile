FILE_NAME=main.cpp
TYPE_COMPILER=g++

bin:
	$(TYPE_COMPILER) $(FILE_NAME) -o $@

.PHONY: run clean

clean:
	rm bin

run:
	./bin