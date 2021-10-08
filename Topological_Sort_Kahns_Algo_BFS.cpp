// indegree based
// loop detection is possible 
//BFS implementation 

/* Start with a queue and initialize some nodes, popout one node 
(completed task 1, then dependencies realted will get removed and indegrees reduced)
*/

// Kahn's algo

#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *l;

public:
	Graph(int v){
		V= v;
		l = new list<int> [V];
	}
	void addEdge(int i,int j){
		l[i].push_back(j);
	}

	void topological_sort(){
		vector<int> indegree(V,0);
		// iterating over edges and finding indegrees

		for(int i = 0; i < V; i ++ ){
			for (auto y : l[i])
				indegree[y]++;
			}
			// bfs
			queue<int> q;
			//initialize q with 0 indegree nodes
			for(int i=0;i<V;i++)
				if(indegree[i]==0) q.push(i);

			while(!q.empty()){
				int node = q.front();
				cout << node << " ";
				q.pop();
				// interate over nbrs and reduce indegree by 1
				for(auto nbr : l[node]){

					indegree[nbr]--;
					if(indegree[nbr]==0)
						q.push(nbr);
				}
			}




	}
}; 
// class based implementaion, not preferred but meh
int main()
{
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,4);
	g.addEdge(1,2);

	g.topological_sort();	
	
	return 0;
}
