//============================================================================
// Name        : p5.cpp
// Author      : Vince Ji
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

int main() {
	enum Direction{EAST,WEST,NORTH,SOUTH,UP,DOWN};
	vector<vector<vector<char> > > grid;
	vector<char> dum1;
	vector<vector<char> > dum;
	dum1.push_back('o');dum1.push_back('.');dum1.push_back('o');
	dum.push_back(dum1);dum.push_back(dum1);dum.push_back(dum1);
	grid.push_back(dum);grid.push_back(dum);grid.push_back(dum);
	grid[2][0][0]='1';grid[2][2][2]='2';grid[2][1][2]='.';
	//below is the code for problem 5*************************************
	vector<vector<vector<bool> > > visited(grid.size(), vector<vector<bool> >(grid[0].size(),vector<bool>(grid[0][0].size())));
	for(int i=0;i<visited.size();i++)
		for(int j=0;j<visited[0].size();j++)
			for(int k=0;k<visited[0][0].size();k++){
				visited[i][j][k]=false;
			}
	struct point{
		int x,y,z;
	};
	struct tools{
		static point move(Direction i){
			point a;
			a.x=0;a.y=0;a.z=0;
			if(i==EAST){a.x=1;}
			else if(i==WEST){a.x=-1;}
			else if(i==NORTH){a.y=1;}
			else if(i==SOUTH){a.y=-1;}
			else if(i==UP){a.z=-1;}
			else if(i==DOWN){a.z=1;}

			return a;
		}
		static bool reachable(char a){
			if(a=='o'){
				return false;
			}
			return true;
		}
		static void shortestpath(vector<vector<vector<char> > >& grid,vector<vector<vector<bool> > >& visited,vector<Direction>& path,vector<Direction>& truepath,point a){
			visited[a.x][a.y][a.z]=true;
			if(grid[a.x][a.y][a.z]=='2'){
				if(truepath.size()>path.size()||truepath.size()==0){
						truepath=path;
						visited[a.x][a.y][a.z]=false;
				}
			}
			else{
				for(int i=0;i<6;i++){
					point temp;
					temp.x=a.x+move((Direction) i).x;
					temp.y=a.y+move((Direction) i).y;
					temp.z=a.z+move((Direction) i).z;
					if((temp.x>=0)&&(temp.y>=0)&&(temp.z>=0)&&(temp.x<visited.size())&&(temp.y<visited[0].size())&&(temp.z<visited[0][0].size())){

						if((!visited[temp.x][temp.y][temp.z])&&reachable(grid[temp.x][temp.y][temp.z])){
							path.push_back((Direction) i);
							shortestpath(grid,visited,path,truepath,temp);
							path.pop_back();
							visited[temp.x][temp.y][temp.z]=false;
						}
					}

				}

			}

		}
	};
	point prince;
	for(int x=0;x<visited.size();x++)
			for(int y=0;y<visited[0].size();y++)
				for(int z=0;z<visited[0][0].size();z++){
					if(grid[x][y][z]=='1'){
						prince.x=x;
						prince.y=y;
						prince.z=z;

					}
				}
	vector<Direction> path;
	vector<Direction> truepath;
	tools::shortestpath(grid,visited,path,truepath,prince);
	int time=5*truepath.size();
	bool isPossible=truepath.size();

	cout<<time;


	return 0;
}
