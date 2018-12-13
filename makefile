all: except cache

except:
	gcc except.c -o except

cache:
	gcc cache.c -o cache

clean:
	rm except
	rm cache

