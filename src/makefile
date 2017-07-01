CC = gcc

PROG = sorting
HDRS = functions.h 
SRCS = main.c functions.c 

OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

clean :
	rm -f $(OBJS) $(PROG)