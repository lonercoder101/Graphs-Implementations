// EPAM Djikstra

/* input    // output 24 3 15
4 4
1
1 2 24
1 4 20
3 1 3
4 3 12
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m >> source;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	

	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> distTo(n+1,INT_MAX); 	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		

		for( auto it : g[prev]){
	
			auto [next, nextDist] = it;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	for(int i = 2; i<=n ; i++)	
		{
			if (distTo[i] == INT_MAX)
				cout<<-1<<" ";
			else cout<<distTo[i]<<" ";
		}

	cout << "\n";
	
	return 0;
}
