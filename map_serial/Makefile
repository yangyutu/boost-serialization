CC = g++
CFLAGS = -std=c++0x -I/opt/boost/boost_1_57_0
LFLAGS = -L/opt/boost/boost_1_57_0/stage/lib -lboost_serialization

#all:map_ser

map_ser: map_ser.o
	$(CC) -o $@ $< $(LFLAGS)

%.o : %.cpp
	$(CC) -c $(CFLAGS) $^

#map_ser.o:map_ser.cpp
#	$(CC) -c $(CFLAGS) map_ser.cpp


clean:
	rm *.o map_ser
