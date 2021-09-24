#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

typedef tuple<int,int,int> iii;

#define MXNODES 1005
#define MXEDGES 2005

vector<iii> graph(MXEDGES);
int dist[MXNODES], pred[MXNODES];
int n,m;

int BellmanFord(int source){


		for(int i =0 ; i < n; i++){

			dist[i] = INT_MAX;
			pred[i] = -1;
		}

		dist[source] = 0;


		for(int  i = 0; i < (n-1) ; i++){

			for(auto &[u,v,w] : graph){

				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					pred[v] = u;
				}


			}

		}

		for(const auto&[u,v,w] : graph)
			if(dist[v] > dist[u]+w) return 0;

		return 1;



}



void sol() {


 	cin >> n >> m;

 	int u,v,w;
 	graph.clear();
 	graph.resize(m);

 	 for(int i = 0 ; i < m ; i++){
 	 	cin >> u >> v >> w;
 	 	graph[i] = tie(u,v,w);
 	 }

 	 if(BellmanFord(0))
 	 	cout<< "not possible\n";

 	else 
 	cout << "possible\n";		 
 	

}


int main()
{
	std::ios::sync_with_stdio(false);
		int tc;
		cin>>tc;
		while(tc--)
			sol();
		return 0;
}
