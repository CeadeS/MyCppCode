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
struct classparam{
	int a,b;
	std::string s;
	classparam(int a,int b,std::string s):a(a),b(b),s(s){};
	classparam():a(5),b(5),s("lol")
	{ };
};


class Tests : public std::enable_shared_from_this<Tests>
{
	int a,b;
	std::string s;
	std::function<int()> magicNumber;
	char* ca;

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
	 Tests(const classparam& p){
		 printf("Test const& Param\n");
	 }
	 Tests(classparam&& p){
		 printf("Test const&& Param\n");
	 }
	 Tests(int a,int b)
	 : a(a)
	 , b(b)
	 , magicNumber([a,b]()->int{return a*b;})
	 , ca(new char[b])
	{
		 printf("Normaler Konstruktor \n")
	}

	 ~Tests(){
		 delete[] ca;
		 ca =nullptr;
		 printf("Destruktor");
	 }

};

class Testsfactory{
	public:
	static std::unique_ptr<Tests> makeunique_Tests(classparam param)
	{
		return std::unique_ptr<Tests>(new Tests(param));
	}
	template<typename Product, typename... P>
			static std::unique_ptr<Product> makeunique(P... param){
			return std::unique_ptr< Product >(new Product( param...) );
		}

	Testsfactory() = delete;
};



#endif /* TESTS_HPP_ */
