examples:
	$(CC) example-fail.c -o example-fail
	$(CC) example-success.c -o example-success

clean:
	rm -f example
