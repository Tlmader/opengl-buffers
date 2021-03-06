#
# Makefile for csci4631-hw5
# Author: Ted Mader
# Date: 2016-11-14
#

CC = g++
CFLAGS = -std=c++0x
OFLAGS = -lglu32 -lfreeglut -lopengl32 -Wl,--subsystem,windows
TARGETS = render.exe

all: $(TARGETS)

render.exe: line.o triangle.o mesh_buffer.o triangle_buffer.o exceptions.o generalio.o main.o
	$(CC) -o render.exe line.o triangle.o mesh_buffer.o triangle_buffer.o exceptions.o generalio.o main.o $(OFLAGS)

line.o: line.cpp
	$(CC) -c line.cpp $(CFLAGS)

triangle.o: triangle.cpp
	$(CC) -c triangle.cpp $(CFLAGS)

mesh_buffer.o: mesh_buffer.cpp
	$(CC) -c mesh_buffer.cpp $(CFLAGS)

triangle_buffer.o: triangle_buffer.cpp
	$(CC) -c triangle_buffer.cpp $(CFLAGS)

exceptions.o: exceptions.cc
	$(CC) -c exceptions.cc $(CFLAGS)

generalio.o: generalio.cc
	$(CC) -c generalio.cc $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm -rf *.o *.exe
