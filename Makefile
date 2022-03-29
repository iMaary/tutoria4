FILE_NAMES=main.c
COMPLIER=gcc

bin:
	$(COMPLIER) $(FILE_NAMES) -o $@

.PHONY: run clean

clean:
	rm bin

run:
	./bin