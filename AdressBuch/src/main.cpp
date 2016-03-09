/*
 * main.cpp

 *
 *  Created on: Mar 8, 2016
 *      Author: maho9219
 */
#include <iostream>
#include "adressbuch.hpp"

int main(int argc, char **argv){
	AdressBuch book;
	book.insert("foo");
	book.insert("bar");
	book.insert("baz");
	book.insert("foo bar");

	auto startsWithFelix = book.findAddresses(
		"bar"
	);

	for (const auto a : startsWithFelix) {
		std::cout << a << std::endl;
	}

}
