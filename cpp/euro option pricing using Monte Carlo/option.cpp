/*
 * option.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: Vince Ji
 */
#include "option.h"
#include "rdnorm.h"
#include <iostream>
#include <cmath>


template<typename T>
option<T>::option(T t, T spot,T K, T sig, T r, OptionType tp){
	reset(t,spot,K,sig,r,tp);
}
//template double option::option(double,double,double,double,double,OptionType);
//template float option::option(float,float,float,float,float,OptionType);

template<typename T>
void option<T>::reset(T t, T spot,T K, T sig, T r, OptionType tp){
	expire=t;
	S0=spot;
	strike=K;
	vol=sig;
	RFR=r;
	optiontype=tp;
}


template<typename T>
T option<T>::Stgen(){
	T sttemp = S0*exp((RFR-0.5*vol*vol)*expire);
	T factor = vol*sqrt(expire);
	float a=boxmullergen();
	T St = sttemp*exp(factor*a);

	return St;
}


template<typename T>
T option<T>::MCprice(unsigned long numofpath){
	T result = 0;
	for(int i=0; i< numofpath;i++){
		T st=Stgen();
		if(optiontype == call){
			st=st-strike;
		}
		else{
			st=strike-st;
		}
		st=st>0? st:0;
		result +=st;
		}
		return result/numofpath;
}

template class option <float>;
template class option <double>;
