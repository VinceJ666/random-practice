/*
 * kala.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: Vince Ji
 */
#include"kala.h"


void newgame(vector<int>& cups){
	for(int i=0;i<6;i++){
			cups.push_back(5);
		}
		cups.push_back(0);
		for(int i=0;i<6;i++){
			cups.push_back(5);
		}
		cups.push_back(0);
}
void printkala(const vector<int> cups){
	string bound(28,'-');
		cout<<endl;cout<<bound<<bound<<"----------------"<<endl;
		cout<<"                cup#: | ";
		for(int i=0;i<6;i++){
			cout<<i+1<<" | ";
		}
		cout<<endl;cout<<"player2' store:| "<<cups[13]<<" |"<<bound;
		cout<<endl;
		cout<<"               seeds: | ";
		for(int i=12;i>6;i--){
			cout<<cups[i]<<" | ";
		}
		cout<<endl;cout<<bound<<bound<<"----------------"<<endl;
		cout<<"                cup#: | ";
		for(int i=0;i<6;i++){
			cout<<i+1<<" | ";
		}
		cout<<endl;cout<<bound<<"----------------------player1's store:| "<<cups[6]<<" | ";
		cout<<endl;
		cout<<"               seeds: | ";
		for(int i=0;i<6;i++){
			cout<<cups[i]<<" | ";
		}
		cout<<endl;cout<<bound<<bound<<"----------------"<<endl;
}

int move(vector<int>& cups,int num,int p){
	int temp=cups[num-1];
	cups[num-1]=0;
	int i;
	for(i=num;i<num+temp;i++){
		if(i<=13){
			cups[i]=cups[i]+1;
		}
		else{
			int j=i-14;
			if(j==19-p){j++;i++;}
			cups[j]=cups[j]+1;
		}
	}
	if(i>14){i=i-14;}
	if((cups[i-1]==1)&&(i!=14)&&(i!=7)){
		int a=cups[13-i]+1;
		cups[i-1]=0;
		cups[13-i]=0;
		cups[p]=cups[p]+a;
	}

	return i;
}
int trial(vector<int> cups,int num,int p){
	int temp=cups[num-1];
	cups[num-1]=0;
	int i;
	for(i=num;i<num+temp;i++){
			if(i<=13){
				cups[i]=cups[i]+1;
			}
			else{
				int j=i-14;
				if(j==19-p){j++;i++;}
				cups[j]=cups[j]+1;
			}
		}
	if(i>14){i=i-14;}
	if((cups[i-1]==1)&&(i!=14)&&(i!=7)){
			int a=cups[13-i]+1;
			cups[i-1]=0;
			cups[13-i]=0;
			cups[p]=cups[p]+a;
	}
	return cups[13];
}
int strategy(vector<int> cups){
	int opt=0;
	int step=0;
	for(int i=8;i<14;i++){
		int temp =trial(cups,i,13);
		if(temp>opt){
			opt=temp;
			step=i;
		}
	}
	return step;
}
bool isend(vector<int>& cups){
	bool flag=false;
	if((cups[0]==0)&&(cups[1]==0)&&(cups[2]==0)&&(cups[3]==0)&&(cups[4]==0)&&(cups[5]==0)){
		flag=true;
	}
	if((cups[7]==0)&&(cups[8]==0)&&(cups[9]==0)&&(cups[10]==0)&&(cups[11]==0)&&(cups[12]==0)){
		flag=true;
	}
	return flag;
}
