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
	cp $(BIN) /var/www/cgi-bin/
	cp ../BigInt_Html/index.html /var/www/html/
uninstall:
	rm -fr /var/www/cgi-bin/$(BIN)
	rm -fr /var/www/html/index.html