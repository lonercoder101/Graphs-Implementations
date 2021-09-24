#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

typedef tuple<ll,ll,ll> iii;

#define MXNODES 3000
#define MXEDGES 6000
const ll INF = (1e17);
const ll NINF = INF*(-1);
vector<iii> graph(MXEDGES);
ll dist[MXNODES], pred[MXNODES];
ll n,m;

void BellmanFord(long long int source){


		for(long long int i =0 ; i < n; i++){

			dist[i] = INF;
			pred[i] = -1;
		}

		dist[source] = 0;


		for(long long int  i = 0; i < (n-1) ; i++){

			for(auto &[u,v,w] : graph){
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], w+dist[u]);
			dist[v] = max(dist[v], NINF);					
		}


	}

		
		for(long long int  i = 0; i < (n-1) ; i++){

			for(auto &[u,v,w] : graph){

			if(dist[u] == INF) continue;
			// dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
			if(dist[u]+ w < dist[v])					
				dist[v] = NINF;
			}	


	}
}





void sol() {


 	cin >> n >> m;

 	long long int u,v,w;
 	graph.clear();
 	graph.resize(m);

 	 for(long long int i = 0 ; i < m ; i++){
 	 	cin >> u >> v >> w;
          u--,v--;
          w=-w;
 	 	graph[i] = tie(u,v,w);
 	 }
 	BellmanFord(0);
 	if(dist[n-1] == NINF)
	{
		cout << -1 << endl;
		return;
	} 
	cout << dist[n-1] * (-1) << endl;	 
 	

}


int main()
{
	std::ios::sync_with_stdio(false);
		int tc=1;
		// cin>>tc;
		while(tc--)
			sol();
		return 0;
}
