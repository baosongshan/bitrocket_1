.PYHONY:clean install uninstall

CC=g++
OBJS=./BigInt/bigint.o bigintser.o
CFLAGS=-Wall -g
LIBS=
BIN=bigintser.cgi

$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(BIN)
install:
	cp $(BIN) ../httpd/htdocs/
	cp ../BigInt_Html/*.html ../httpd/htdocs/
	cp ./sqlite/*.cgi ../httpd/htdocs/
uninstall:
	rm -fr ../httpd/htdocs/$(BIN)
	rm -fr ../httpd/htdocs/*.html