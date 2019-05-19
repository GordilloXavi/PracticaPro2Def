OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

practica.tar:
	tar -cvf practica.tar program.cc Idiom.cc Idiom.hh Idiom_Set.cc Idiom_Set.hh Treecode.cc Treecode.hh Makefile

program.exe: program.o Idiom_Set.o Idiom.o Treecode.o
	g++ -o program.exe *.o 

Idiom_Set.o: Idiom_Set.cc Idiom_Set.hh
	g++ -c Idiom_Set.cc $(OPCIONS) 

Idiom.o: Idiom.cc Idiom.hh
	g++ -c Idiom.cc $(OPCIONS) 

Treecode.o: Treecode.cc Treecode.hh BinTree.hh
	g++ -c Treecode.cc $(OPCIONS) 

program.o: program.cc
	g++ -c program.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
