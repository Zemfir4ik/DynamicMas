CC = g++

all out:

out: 
	$(CC) *.cpp -lncurses -o out

clean:
	rm out
