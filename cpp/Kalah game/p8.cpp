//============================================================================
// Name        : p8.cpp
// Author      : Vince Ji
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"kala.h"
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> cups;
	int disc;
	int trigger;
	while(true){
		cout<<"new game press 1, exit press 0:";
		cin>>disc;
		if(disc==0){
			break;
		}
		else{
			newgame(cups);
			printkala(cups);
			while(!isend(cups)){
				do{
					cout<<"choose cup#:";
					cin>>disc;
					trigger=move(cups,disc,6);
					printkala(cups);
				}while(trigger==7);
				do{
					int a=strategy(cups);
					cout<<"compueter choose:"<<a<<endl;
					trigger=move(cups,a,13);
					printkala(cups);
				}while(trigger==14);
			}
			int score1=cups[0]+cups[1]+cups[2]+cups[3]+cups[4]+cups[5]+cups[6];
			int score2=cups[7]+cups[8]+cups[9]+cups[10]+cups[11]+cups[12]+cups[13];
			string winner;
			if(score1>score2){winner="player1";}
			else{winner="player2";}
			cout<<"winner is:"<<winner<<endl;
		}
	}


	return 0;
}
