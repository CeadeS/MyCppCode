/*
 * Tests.hpp
 *
 *  Created on: Mar 8, 2016
 *      Author: maho9219
 */

#ifndef TESTS_HPP_
#define TESTS_HPP_
#include <memory>
#include <functional>

class Tests : public std::enable_shared_from_this<Tests>
{
	int a,b;
	std::function<int()> magicNumber;
	char* ca;// = new char[5];
	int doMagic(int* g){
		return *g+magicNumber();
	}
	public:
	 std::shared_ptr<Tests> getptr() {
	         return shared_from_this();
	     }
	 int getA(){return a;};
	 std::function<int(int*)> getFunctPtr(){
		 return std::bind( &Tests::doMagic, this, std::placeholders::_1 );
	 }
	 char getCharAt(int i)
	 {
		if (i<b) return ca[i];
		return -1;
	 }
	 char* getCharRefAt(int i)
	 	 {
	 		if (i>b) return &(ca[b-1]);
	 		return &(ca[i]);
	 	 }
	 bool setCharAt(int i, int c){
		 if (i>b) return false;
		 ca[i] = c;
		 return true;
	 }
	 Tests(int a,int b)
	 : a(a)
	 , b(b)
	 , magicNumber([a,b]()->int{return a*b;})
	 , ca(new char[b])
	{ }

	 ~Tests(){
		 delete[] ca;
		 ca =nullptr;
	 }

};




#endif /* TESTS_HPP_ */
