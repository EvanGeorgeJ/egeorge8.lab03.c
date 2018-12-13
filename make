all: except loader cache
	
except: except.c
	gcc except.c -o except -Wall -Wextra

clean:
	rm -f except
	rm -f loader
	rm -f cache
