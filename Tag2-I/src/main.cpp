/*
 * main.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: maho9219
 */
#include<stdio.h>
#include<iostream>
#include <vector>
#include <initializer_list>
#include<string>
#include"main.h"
struct Base1{
	explicit Base1(int i){};
};
struct Base2{
	explicit Base2(int i){};
};
struct Derived
	:public Base1 {
	using Base1::Base1;
	Derived(int i) : Base1(i){};
};

int main(int argc, char** argv){
	return -1;
}
// adressbuch programmieren, mit der Möglichkeit darin zu suchen
// klasse schreiben, die zeichenketten speichern kann
//

