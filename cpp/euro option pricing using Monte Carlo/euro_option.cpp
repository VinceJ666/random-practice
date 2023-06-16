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
		cout << "\033[2J\033[1;1H";
		cout<<"Enter Expire Time/Duration (Days): ";
		cin>>t;
		cout<<"Enter Current Price $: ";
		cin>>s0;
		cout<<"Enter Strike Price $: ";
		cin>>k;
		cout<<"Enter Volatility: ";
		cin>>s;
		cout<<"Enter Return: ";
		cin>>r;
		cout<<"Enter Option Type (0-call/1-put): ";
		cin >> tp1;
		if(tp1==0){
			tp=call;
		}
		else{
			tp=put;
		}
		option1.reset(t,s0,k,s,r,tp);
		while(key2){
			cout<<"Eter # of Path: ";
			cin>>path;
			float price=option1.MCprice(path);
			cout << "Price is $ " << price << endl;
			cout << "Press 1 Calculate Again, 0 Exit: ";
			cin>>key2;
		}
		cout << "\033[2J\033[1;1H";
		cout << "Press 1 for Next Option, 0 Exit: ";
		cin>>key1;
		key2=1;
	}
	return 0;
}
