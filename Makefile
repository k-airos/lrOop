CC = @g++
CFLAGS = -g -Wall

SRCS = src/main.cpp src/meteo.cpp

OBJS = $(@SRCS:.cpp=.o)

INCLUDES= includes/meteo.h
EXECUTABLE = laba

RM = @rm -rf


all:    $(EXECUTABLE)


$(EXECUTABLE): $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@ 

clean:
	$(RM) src/*.o $(EXECUTABLE)
