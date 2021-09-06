#include<bits/stdc++.h>
using namespace std;
const int N = 100;

int a[N][N], vis[N][N];
int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void flood_fill(int x,int y,int col){
		a[x][y]=col;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx>=0 and xx<n and yy>=0 and yy<n and a[xx][yy]==1 and !vis[xx][yy])
		flood_fill(xx,yy,col);
	}

}


int main(){
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++)
			cin>>a[i][j];
	}
	int col = 1;
	int total = 0 ;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1 and !vis[i][j]){
				
				flood_fill(i,j,(col++));

			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<a[i][j];
		cout<<'\n';
	}
	return 0;
}

