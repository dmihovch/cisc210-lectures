all: 01-unsigned 02-secret-messages 03-ascii 04-binary 05-hex

01-unsigned: 01-unsigned.c
	cc 01-unsigned.c -o 01-unsigned

02-secret-messages: 02-secret-messages.c
	cc 02-secret-messages.c -o 02-secret-messages

03-ascii: 03-ascii.c
	cc 03-ascii.c -o 03-ascii

04-binary: 04-binary.c
	cc 04-binary.c -o 04-binary

05-hex: 05-hex.c piemulator.c
	cc 05-hex.c piemulator.c -pthread -o 05-hex

clean:
	rm -f 01-unsigned 02-secret-messages 03-ascii 04-binary 05-hex