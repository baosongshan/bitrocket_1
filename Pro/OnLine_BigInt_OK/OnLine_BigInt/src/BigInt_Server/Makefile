.PHONY:clean install
OBJECT=./BigInt/BigInt.o
BigIntSer.cgi:$(OBJECT) BigIntSer.o
	g++ -o BigIntSer.cgi BigIntSer.o $(OBJECT)
BigIntSer.o:BigIntSer.cpp
	g++ -o BigIntSer.o -c BigIntSer.cpp
clean:
	rm BigIntSer.cgi *.o
install:
	cp BigIntSer.cgi ../httpd/htdocs/ -fr
