.PHONY: run test clean

test: build-test
	./test/test

build-test: ./test/main.c
	@gcc ./test/main.c ./src/list.c -o ./test/test -Wall -Wextra -pedantic -std=c99

clean: ./test/test
	@rm -fr ./test/test
