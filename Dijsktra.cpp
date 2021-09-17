#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int u,v,w;
void solve(){

	int n,m,s,t;
	cin>>n>>m>>s>>t;

	vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());

	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}

	vector<int> dist(n, INT_MAX);
	dist[s]=0;
	set<pair<int,int>> pq;
	for(int u=0;u<n;++u)
		pq.insert({dist[u],u});

	while(!pq.empty()){

		auto[d,u]= *pq.begin(); // closest unvisited u
		pq.erase(pq.begin()); //popping out 

		for(auto&[v,w]: graph[u]){

			if(dist[u]+w>=dist[v]) continue; 

			pq.erase(pq.find({dist[v],v}));
			dist[v] = dist[u] + w;
			pq.insert( {dist[v], v});
		}
	}
	if(dist[t]!=INT_MAX)
		cout<<dist[t];
	else cout<<"unreachable";
	cout<<'\n';

}

int main(){
	 std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	for(int i =1 ; i <=tc ;i ++){
		cout<<"Case #"<<i<<": ";
		solve();
	}

	return 0;

}




