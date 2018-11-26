all:
	flex -o projet.flex.cpp projet.flex
	bison -t -d projet.y -o projet.y.cpp
	g++ -o projet projet.flex.cpp projet.y.cpp instruction.cpp -w `sdl2-config --cflags --libs`
	./projet test.txt
