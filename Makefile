all: spawner hello

spawner: spawner.c
	$(CC) spawner.c -o spawner

hello: hello.c
	$(CC) hello.c -o hello

clean:
	rm -f spawner hello
