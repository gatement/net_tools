objects = main.o
output = bin

compile: $(objects) mkoutput
	cc -o $(output)/main $(objects)

main.o: main.h


.PHONY: mkoutput clean help

mkoutput:
	mkdir -p $(output)

clean:
	rm -rf $(output) *.o

help:
	@echo "make \
       \nmake clean"
