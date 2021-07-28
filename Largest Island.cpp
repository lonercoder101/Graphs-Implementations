// largest island 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define print_arr(arr, n) for (int i = 0; i < n; i++) std::cout << arr[i] << ' '; std::cout << '\n';
#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

int dfs(vector<vector<int> > &matrix, vector<vector<bool>> &visited, int i, int j, int m, int n ){

	visited[i][j] = true;

	int cs = 1;

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	for(int k=0; k<4; k++){

		int nx = i + dx[k];
		int ny = j + dy[k];

		if(nx>=0 and nx<m and ny>=0 and ny<n and matrix[nx][ny]==1 and !visited[nx][ny]){
			int subcomponent = dfs(matrix,visited,nx,ny,m,n);
			cs += subcomponent;
		}
	}
	return cs;
}

int largest_island ( vector<vector<int> > matrix){

	int m = matrix.size();
	int n = matrix[0].size();

	// visited matrix
	vector<vector<bool> >  visited (m, vector<bool>(n,false));
	int largest = 0;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if( !visited [i][j] and matrix[i][j]==1){

				int size = dfs(matrix,visited,i,j,m,n);
				if(size > largest ) 
					largest = size;
			}
		}
	}
	return largest;

}


int main(){
	vector<vector<int> > grid = {
		{1,0,0,1,0},
		{1,0,1,0,0},
		{0,0,1,0,1},
		{1,0,1,1,1},
		{1,0,1,1,0},
	};

	cout<< largest_island (grid) << endl; 
}
