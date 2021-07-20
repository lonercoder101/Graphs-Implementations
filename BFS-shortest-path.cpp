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

	void bfs(int source, int destination){

		queue<int> q;
		bool *visited = new bool [V]{false};
		int *dist = new int[V]{0};
		int *parent = new int[V];

		for(int i=0;i<V;i++){
			parent[i] = -1 ; 
		} 

		q.push(source);
		visited[source] = true;
		parent[source] = source;
		dist[source] = 0;

		while(!q.empty()){
			// for every node do something
			int f = q.front();
			cout<<f<<'\n';
			q.pop();
			// push nbrs of the presen node inside queue if not visited
			for(auto nbr:l[f]){
				if(!visited[nbr]){
				q.push(nbr);
				//parent and distance update
				parent[nbr] = f;
				dist[nbr] = dist[f] + 1;
				visited[nbr] = true; 
			}
		}


		}
		//single source shortest path for undirected graph

		// print path from source to any node which is shortest
		// print the shortest distance

		for(int i = 0 ; i< V; i++){
			cout<<"shortest distance to "<< i<< " is "<< dist[i] << '\n';
		}
		cout<<endl;

		if(destination!=-1){

			int temp = destination;
			while(temp!=source){

				cout<<temp<<"-->";

				temp = parent[temp];



			}
			cout<<source<<'\n';




	}
}
};




int main()
{
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.bfs(1,6);

	return 0;
}
