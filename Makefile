objects = main.o util.o aes.o
output = bin

compile: $(objects) mkoutput
	cc -o $(output)/main $(objects)

main.o: main.h
util.o: util.h
aes.o: aes.h


.PHONY: mkoutput clean help

mkoutput:
	mkdir -p $(output)

clean:
	rm -rf $(output) *.o

help:
	@echo "make \
       \nmake clean"
