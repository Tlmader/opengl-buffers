#
# Makefile for csci4631-hw5
# Author: Ted Mader
# Date: 2016-11-14
#

CC = clang++
CFLAGS = -stdlib=libc++ -std=c++11 -g -Wall -Werror -I.
TARGETS = render.exe

all: $(TARGETS)

render.exe: line.o triangle.o mesh_buffer.o triangle_buffer.o main.o
	$(CC) $(CFLAGS) -o render.exe line.o triangle.o mesh_buffer.o triangle_buffer.o main.o  -framework OpenGL -framework GLUT

line.o: line.cpp
	$(CC) $(CFLAGS) -c line.cpp

triangle.o: triangle.cpp
	$(CC) $(CFLAGS) -c triangle.cpp

mesh_buffer.o: mesh_buffer.cpp
	$(CC) $(CFLAGS) -c mesh_buffer.cpp

triangle_buffer.o: triangle_buffer.cpp
	$(CC) $(CFLAGS) -c triangle_buffer.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o render.exe
