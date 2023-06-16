/*
 * rdnorm.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Vince Ji
 */
#include<cmath>
#include<iostream>

float boxmullergen(){
	float result;
	float x;
	float y;
	float w;
	do{
		x=2.0*rand()/static_cast<double>(RAND_MAX)-1;
		y=2.0*rand()/static_cast<double>(RAND_MAX)-1;
		w=x*x+y*y;
	}while(w>=1);
	result=x*sqrt(-2*log(w)/w);
	return result;
}


