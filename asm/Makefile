ROOT = $(shell pwd)/

PRGS = $(ROOT)/asm/

.PHONY: all clean fclean re

all :
	@sh init.sh
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) -C $$dir; \
		done


clean :
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) $@ -C $$dir; \
		done

fclean :
	@for dir in $(PRGS) ; \
		do \
		$(MAKE) $@ -C $$dir; \
		done
	@sh uninit.sh

re :
	@$(MAKE) fclean
	@$(MAKE) all

prog :
	@$(MAKE) $(ROOT)/asm
