#
# Makefile for csci4631-hw5
# Author: Ted Mader
# Date: 2016-11-14
#

CC = clang
TARGETS = render.exe

all: $(TARGETS)

render.exe: vertex.o line.o triangle.o mesh_buffer.o triangle_buffer.o main.o
	$(CC) -o render.exe vertex.o line.o triangle.o mesh_buffer.o triangle_buffer.o main.o -lstdc++ -framework OpenGL -framework GLUT

vertex.o: vertex.cpp
	$(CC) -c vertex.cpp

line.o: line.cpp
	$(CC) -c line.cpp

triangle.o: triangle.cpp
	$(CC) -c triangle.cpp

mesh_buffer.o: mesh_buffer.cpp
	$(CC) -c mesh_buffer.cpp

triangle_buffer.o: triangle_buffer.cpp
	$(CC) -c triangle_buffer.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o render.exe
