CC = g++

CFLAGS = -Wall -g

INCLUDES = -I/usr/include/libxml2

LDFLAGS = -L/usr/local/lib

SRCS += \
		main.cpp
		
LIBS += \
		
OBJS = $(SRCS:.cpp=.o)

TARGET = tempsensor

.PHONY: depend clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)
	
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	$(RM) *.o *~ $(TARGET)
