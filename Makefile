derlecalistir:uygulama calistir

uygulama:Bst.o Test.o
	g++ ./lib/Bst.o ./lib/Test.o -o ./bin/uygulama

Bst.o:
	g++ -I "./include" -c ./src/Bst.cpp -o ./lib/Bst.o
	
Test.o:
	g++ -I "./include" -c ./src/Test.cpp -o ./lib/Test.o

calistir:
	./bin/uygulama.exe