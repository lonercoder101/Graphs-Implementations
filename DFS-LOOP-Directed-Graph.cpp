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
	void addEdge(int i,int j, bool undir=false){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}

	bool dfs(int node, vector<bool> &visited, vector<bool> &stack){
		visited[node] = true;
		stack[node] = true;

		//return true if backedge found 

		for(int nbr : l[node]){
			if(stack[nbr]==true)
				return true; 

			else if(!visited[nbr]){
				bool nbrCycle = dfs(nbr,visited,stack);
				if(nbrCycle) return true;
			}
		}	



		// going back
		stack[node] = false;
		return false;
	}


	bool contains_cycle(){
		vector<bool> visited(V,false);
		vector<bool> stack(V,false);
		for (int i=0;i<V;i++){
			if(!visited[i]){
				if(dfs(i,visited,stack))
					return true;
			}
		}
		return false;

	}



};
int main()
{
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	cout << g.contains_cycle();
	
	
	return 0;
}


