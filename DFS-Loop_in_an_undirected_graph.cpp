#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *l;

public:
	Graph(int v){
		V=v;
		l = new list<int> [V];
	}
	void addEdge(int i,int j, bool undir=true){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}


		bool dfsHelper(int node, vector<bool> &visited, int parent){

			visited[node] = true;
			// call dfs on unvisiited neighbours
			// cout<<node<<" ";

			for(auto nbr: l[node]){
				if(!visited[nbr]){
					bool nbrcycle = dfsHelper(nbr,visited,node);
					if(nbrcycle) {
						
							return true;
				}
			}
				else if(parent!=nbr)
				{
					
					return true;
				}
			
			
		}
		return false;
	}
	
		bool dfs(int source){
			std::vector<bool> visited(V,false);
			return dfsHelper(source,visited,-1);
		}



};
int main()
{
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	
	cout<<g.dfs(0)<<'\n';
	return 0;
}