/*
 * option.h
 *
 *  Created on: Apr 29, 2015
 *      Author: Vince Ji
 */

#ifndef OPTION_H_
#define OPTION_H_

enum OptionType{call,put};

template<typename T>
class option{
protected:
	T expire;
	T S0;
	T strike;
	T vol;
	T RFR;
	OptionType optiontype;
public:
	option(T t,T spot,T K,T sig,T r, OptionType tp);
	void reset(T t,T spot, T K, T sig, T r, OptionType tp);
	T Stgen();
	T MCprice(unsigned long path);
	//T BSprice();

};




#endif /* OPTION_H_ */
