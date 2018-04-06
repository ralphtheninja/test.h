CFLAGS=-Wall -g -fsanitize=address

examples:
	$(CC) $(CFLAGS) example-fail.c -o example-fail
	$(CC) $(CFLAGS) example-success.c -o example-success

clean:
	rm -fv example-fail example-success
