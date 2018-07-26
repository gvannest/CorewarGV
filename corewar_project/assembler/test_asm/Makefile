all: clean test

clean :
	@rm ./unvalid/*.cor 2> /dev/null || true
	@rm ./valid/*.cor 2> /dev/null || true
	@echo "files removed\n"
	@make -C ..
	@cp ../asm .
	@echo "asm duplicated\n"

test :
	@sh test_unvalid.sh
