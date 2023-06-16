//============================================================================
// Name        : euro_option.cpp
// Author      : Vince Ji
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "option.cpp"
#include "option.h"
using namespace std;


int main() {
	float t;
	float s0;
	float k;
	float s;
	float r;
	int tp1;
	OptionType tp;
	unsigned long path;
	option <float>option1(1,1,1,1,1,call);
	bool key1 =1;
	bool key2 =1;
	while(key1){
		cout<<"enter expire time: ";
		cin>>t;
		cout<<"enter current price: ";
		cin>>s0;
		cout<<"enter strike price: ";
		cin>>k;
		cout<<"enter volatility: ";
		cin>>s;
		cout<<"enter return: ";
		cin>>r;
		cout<<"enter option type(0-call/1-put): ";
		cin >> tp1;
		if(tp1==0){
			tp=call;
		}
		else{
			tp=put;
		}
		option1.reset(t,s0,k,s,r,tp);
		while(key2){
			cout<<"enter # of path: ";
			cin>>path;
			float price=option1.MCprice(path);
			cout << "price is" << price << endl;
			cout << "press 1 calculate again, 0 exit: ";
			cin>>key2;
		}
		cout << "press 1 for next option, 0 exit: ";
		cin>>key1;
	}
	return 0;
}
