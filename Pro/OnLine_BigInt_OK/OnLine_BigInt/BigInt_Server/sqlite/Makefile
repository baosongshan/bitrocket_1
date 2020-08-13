all:login.cgi reg.cgi
OBJS=sqlite3.c
LIBS=-lpthread -ldl

login.cgi:login.c
	gcc -o login.cgi login.c $(OBJS) $(LIBS)
reg.cgi:register.c
	gcc -o reg.cgi register.c $(OBJS) $(LIBS)

.PHONY:clean
clean:
	rm -fr *.cgi 