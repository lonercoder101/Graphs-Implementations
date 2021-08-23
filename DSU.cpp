#include <bits/stdc++.h>
using namespace std;


class UnionFind {
	private:
		vector<int> p,rank,setSize;
		int numSets;

	public:
		UnionFind(int N){
			p.assign(N,0);

			for(int i = 0; i < N; i++)
				p[i] = i;

			rank.assign(N,0);
			setSize.assign(N,1);
			numSets = N;
		}

		int findSet(int i){
			if(p[i]==i) return i;
			else return p[i] = findSet(p[i]);
		}

		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}

		int sizeOfSet(int i){
			return setSize[findSet(i)];
		}
		int numDisjointSets(){
			return numSets;
		}
		void unionSet(int i, int j){
			if (isSameSet(i,j))
				return;
			int x = findSet(i);
			int y = findSet(j);

			if( rank[x] > rank[y] )
				swap(x,y);
			p[x]=y;

			if( rank[x] == rank[y] )
				rank[y]++;

			setSize[y] += setSize[x];
			numSets--;
		}

};
int x,y;
int main(){


	int n,m;
	cin >> n >> m;
	UnionFind obj(n+1);

	while(m--){
		string s; cin >> s;
		cin >> x >> y;
		if(s=="union"){
			obj.unionSet(x,y);
		}
		else{
			if( obj.isSameSet(x,y) )
				cout << "YES\n";
			else cout << "NO\n";
		}


	}


}
