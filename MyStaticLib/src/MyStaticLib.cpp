/*
 * MyStaticLib.cpp
 *
 *  Created on: Mar 10, 2016
 *      Author: maho9219
 */
#include <stdio.h>
#include "MyStaticLib.hpp"

int versionStatic(){return 2000;}
int a=42;
void setzeA(int b){
	a=b;
}

void text_stat(){
	printf("Ich bin eine static Library!\n %d \n",a);
}


