// Bipartite Graph ? Two coloring problem

// -> Divide all vertices of the graph in two sets 
// 	such that all edges of the graph are from set1 to set2


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

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color){
	visited[node] = color;

	for(auto nbr : graph[node]){
		if(visited[nbr]==0)
		{
			bool sb = dfs_helper(graph, nbr, visited,node, 3-color );
			if(sb == false)
				return false;
		}
	
		else if(nbr!=parent and color==visited[nbr])
			return false;
	}
	return true;


}



bool dfs(vector<int> graph[], int n, int m){
	int visited[n] = {0}; 
	int color = 1;//  -> 0 - not visited, 1 - visited color 1 and same for 2
	// bool ans = dfs_helper(graph, 0 , visited, -1, color);

	bool ans;
	for(int i = 0 ; i < n; i++  ){
		if(visited[i]==0)
		{
			ans = dfs_helper(graph,i,visited,-1,color);
			if(ans==false) return false;
		}
	}
	for(int i=0; i<n;i++)
		cout << i << "-->" << visited[i] << '\n';

	return ans;
}

int main(){
	int n,m;

	cin >> n >> m;

	vector<int> graph[n];
	while(m--){
		int x,y;
		cin >> x >> y;
		x--,y-- ;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	if( dfs(graph,n,m) ){
		cout << "Bi"<<'\n';
	}
	else cout << "Nah" << '\n';
	// bfs or dfs, by coloring the nodes at each step current node hsa color 1, nbr should have color 2
}


