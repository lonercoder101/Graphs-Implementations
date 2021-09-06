#include<bits/stdc++.h>
using namespace std;
const int N = 100;

int a[N][N], vis[N][N];
int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void flood_fill(int x,int y){

	a[x][y]=0;

	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx>=0 and xx<n and yy>=0 and yy<n and a[xx][yy]==1)
		flood_fill(xx,yy);
	}

}


int main(){
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++)
			cin>>a[i][j];
	}
	int total = 0 ;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1){
				total++;
				flood_fill(i,j);

			}
		}
	}
	cout << total << '\n';
	return 0;
}

