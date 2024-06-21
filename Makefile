VPATH = src

FOENIX = module/Calypsi-65816-Foenix

MODEL = --code-model=large --data-model=small
LIB_MODEL = lc-sd

FOENIX_LIB = $(FOENIX)/Foenix-$(LIB_MODEL).a
FOENIX_LINKER_RULES = $(FOENIX)/linker-files/c256-u-plain.scm

ttt816.pgz:
	-cc65816 --target=foenix -o ttt816.o $(MODEL) -I$(FOENIX) -c src/ttt816.c
	-ln65816 --target=foenix -o ttt816.pgz $(FOENIX_LINKER_RULES) $(FOENIX_LIB) --output-format=pgz --list-file=ttt816-Foenix.lst --cross-reference --rtattr printf=reduced --rtattr cstartup=Foenix

$(FOENIX_LIB):
	(cd $(FOENIX) ; make all)

clean:
	-rm ttt816.pgz ttt816-Foenix.lst
	-(cd $(FOENIX) ; make clean)