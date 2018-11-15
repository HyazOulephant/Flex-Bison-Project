all:
	flex -o projet.flex.cpp projet.flex
	bison -d projet.bison -o projet.bison.cpp
	g++ -o projet projet.flex.cpp projet.bison.cpp -w
	./projet doc.txt
