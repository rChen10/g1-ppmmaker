all: picmaker
	./a.out

picmaker: ppm_maker.cpp pixel
	g++ ppm_maker.cpp

pixel: pixel.cpp
	g++ pixel.cpp -c

run: all
	./a.out
