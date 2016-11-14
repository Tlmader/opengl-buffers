#
# Makefile for csci4631-hw5
#
# Author: Ted Mader
# Date: 2016-11-14
#

CC = clang
TARGETS = render.exe

all: $(TARGETS)

render.exe: triangle_buffer.o mesh_buffer.o main.o
	$(CC) -o render.exe triangle_buffer.o mesh_buffer.o main.o -lstdc++ -framework OpenGL -framework GLUT

triangle_buffer.o: triangle_buffer.cpp
	$(CC) -c triangle_buffer.cpp

mesh_buffer.o: mesh_buffer.cpp
	$(CC) -c mesh_buffer.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o render.exe
