OBJS=mymemory.o main.o
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

all: mymemory.o main.o main

main: $(OBJS)
	$(CC) $(CFlags) -o $@  $^ 

valgrind: main
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }

%: %.c mymemory.h
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

clean:
	rm -f main *.o