CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi addc.cgi addG.cgi modG.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi

install:
		cp *.cgi /usr/lib/cgi-bin/sx
		sudo cp -r public/ index.html indexG.html /var/www/html
		sudo cp head.html footer.html /usr/lib/cgi-bin/sx
