//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include "Test.hpp"
#include "fak-test.cpp"
int testFunc (const std::string& param){
	return 23;
}
int  main(int argc, char* argv[]){
	int a=6;
	int b=5;
	#ifdef mal5
	a=5;
	#endif
	for (int i=0;i<argc;i++){
		printf("argv[%d] = %s \n",i,argv[i]);
	}
	printf("hallo welt!, ich heiße %s \n das Ergebnis lautet: \n %d \n",__FILE__,a+b+testFunc("s"));
return a+b;
}

