/*
 * kala.h
 *
 *  Created on: Jun 15, 2015
 *      Author: Vince Ji
 */

#ifndef KALA_H_
#define KALA_H_
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void newgame(vector<int>&);
void printkala(const vector<int>);
int move(vector<int>&, int,int);
int trial(vector<int>, int,int);
int strategy(vector<int>);
bool isend(vector<int>&);




#endif /* KALA_H_ */
