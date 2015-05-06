CC = g++
CFLAGS = -std=c++0x -I/opt/boost/boost_1_57_0
LFLAGS = -L/opt/boost/boost_1_57_0/stage/lib -lboost_serialization

#all:vector_ser

vector_ser: vector_ser.o
	$(CC) -o $@ $< $(LFLAGS)

%.o : %.cpp
	$(CC) -c $(CFLAGS) $^

#vector_ser.o:vector_ser.cpp
#	$(CC) -c $(CFLAGS) vector_ser.cpp


clean:
	rm *.o vector_ser
