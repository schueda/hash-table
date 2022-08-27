CFLAGS = -Wall
EXEC_NAME = myht
OBJS = main.o table.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(EXEC_NAME)

main.o: main.c
table.o: table.c table.h

clean:
	rm -f $(OBJS) *~

purge: clean
	rm -f $(EXEC_NAME)