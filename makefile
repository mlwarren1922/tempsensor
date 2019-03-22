CC = g++

CFLAGS = -Wall -g 

INCLUDES = -I/usr/lib/x86_64-linux-gnu/ \
		   -I/usr/include/postgresql

LDFLAGS = 

SRCS += \
		DBINTERFACE.cpp \
		TEMPMEASUREMENT.cpp \
		main.cpp 
		
LIBS += \
		
OBJS = $(SRCS:.cpp=.o)

TARGET = tempsensor

.PHONY: depend clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS) -lpqxx -lpq
	
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c $< -o $@ -lpqxx -lpq
	
clean:
	$(RM) *.o *~ $(TARGET)
