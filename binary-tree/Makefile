INCLUDES := ./src/binarytree.c
FLAGS := -Wall -Wextra -pedantic -std=c99

.PHONY: test clean

test:
	@gcc ./test/main.c ${INCLUDES} -o ./test/test ${FLAGS}
	@./test/test

clean: ./test/test
	@rm -fr ./test/test
