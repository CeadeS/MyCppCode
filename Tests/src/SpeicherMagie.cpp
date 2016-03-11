/*
 * SpeicherMagie.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: maho9219
 */
#include "Tests.hpp"
#include <memory>
#include <stdio.h>
#include  <utility>

int main(int argc, char **argv) {
	std::shared_ptr<Tests> foo = std::make_shared< Tests >(5,5);
	//foo.reset();
	foo-> setCharAt(2,'Z');
	char* c= foo->getCharRefAt(3);
	*c ='@';
	printf("Test mit shared_ptr\n");
	printf("Array der Länge %d \nArray an Stelle 2 %c \nan Stelle 3 %c \n",foo->getA(),foo->getCharAt(2),foo->getCharAt(3));
	printf ("in c steht? %c \n",*c);
	foo.reset();
	printf ("Nach dem reset: %c \n",*c);
	printf ("Tests direkt new \n");
	Tests* bar = new Tests(5,5);
	Tests*  tangel =  std::move(bar);
	c= bar->getCharRefAt(3);
	*c ='@';
	printf("Array der Länge %d \nArray an Stelle 2 %c \nan Stelle 3 %c \n",bar->getA(),bar->getCharAt(2),bar->getCharAt(3));
	printf ("in c steht? %c \n",*c);
	auto baz = bar->getFunctPtr();

	int i = 6;
	printf("Das steht in Tangel: %d \n",tangel->getA());

	delete bar;
	printf("Das steht in Tangel Auswirkung, wenn bar gelöscht wird: %d \n",tangel->getA());
	printf ("Nach dem reset: %c",*c);
	printf ("\n %d\n",baz(&i));
    classparam p;
    std::unique_ptr<Tests> neu = Testsfactory::makeunique_Tests(p);
	std::unique_ptr<Tests> ne2 = Testsfactory::makeunique<Tests>(p);
	return -1;
}




