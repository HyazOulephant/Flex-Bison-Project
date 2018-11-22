all:
	flex -o compilation/projet.flex.cpp projet.flex
	bison -t -d projet.y -o compilation/projet.y.cpp
	g++ -o compilation/projet compilation/projet.flex.cpp compilation/projet.y.cpp -w `sdl2-config --cflags --libs`
	./compilation/projet test.txt
