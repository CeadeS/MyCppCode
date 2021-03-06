/*
 * adressbuch.hpp
 *
 *  Created on: Mar 8, 2016
 *      Author: maho9219
 */

#ifndef ADRESSBUCH_HPP_
#define ADRESSBUCH_HPP_


#include <string>
#include <vector>

class AdressBuch{
public:
	void insert (const std::string& address){
		addresses.push_back (address);
	}

	std::vector<std::string>
	findAddresses(const std::string& s)const
	{
		std::vector<std::string> result;
		for(const std::string& a: addresses){
			if (a.find(s) == 0) result.push_back(a);
		}
		return result;
	}
	std::vector<std::string>addresses;
};






#endif /* ADRESSBUCH_HPP_ */
