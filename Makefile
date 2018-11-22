all:
	flex -o projet.flex.cpp projet.flex
	bison -d projet.y -o projet.y.cpp
	g++ -o projet projet.flex.cpp projet.y.cpp -w
	./projet doc.txt
