CC=gcc
DIR=/home/saurabh/Desktop/academic/sem3/services/fsys/encode_decode
CFLAGS=-g -Wall -Wextra -lm


$(DIR)/main: $(DIR)/encode.o  $(DIR)/decode.o $(DIR)/main.c $(DIR)/memprint.o $(DIR)/litTobigEnd.o
	$(CC) $(DIR)/encode.o $(DIR)/decode.o -o $(DIR)/main $(DIR)/main.c $(CFLAGS) $(DIR)/memprint.o $(DIR)/litTobigEnd.o

$(DIR)/decode.o: $(DIR)/decode.c
	$(CC) $(DIR)/decode.c -c $(CFLAGS)

$(DIR)/encode.o: $(DIR)/encode.c
	$(CC) encode.c -c $(CFLAGS)

$(DIR)/memprint.o: $(DIR)/memprint.c
	$(CC) $(DIR)/memprint.c -c

$(DIR)/litTobigEnd.o: $(DIR)/litTobigEnd.c
	$(CC) $(DIR)/litTobigEnd.c -c

clean: 
	rm -r $(DIR)/*.o
