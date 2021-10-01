// https://www.spoj.com/problems/BLINNET/

#include <bits/stdc++.h>
using namespace std;


#define ll  long long int
#define vi  vector<int>
#define vll vector<long long int>
#define iii tuple<int, int, int>


class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:

        // Initialization

        UnionFind(int N){
            // The goal here is to create N singleton sets.

            p.assign(N, 0);
            // To begin with, everyone is their own parent:
            for(int i = 0; i < N; i++)
                p[i] = i;
            
            // the height of all trees are zero:
            rank.assign(N, 0);

            // the sizes of the individual sets are one:
            setSize.assign(N, 1);

            // the number of sets is N:
            numSets = N;
        }

        // FindSet(i): return the representative element of the set that i belongs to.

        int findSet(int i){
            // if already at a representative element,
            // signified by the fact that the parent pointer points to the element itself,
            // return;

            if(p[i] == i)
                return i;

            // otherwise find the representative of the parent,
            // but also perform path compression by pointing the current element
            // to the final representative:

            else
                return p[i] = findSet(p[i]);
        }

        // isSameSet(i,j): returns true if and only if i and j belong to the same set.

        bool isSameSet(int i, int j){
            // Observe that i and j belong to the same set
            // if and only if they have the same representative.
            return findSet(i) == findSet(j); 
        }

        // sizeOfSet(i): returns the size of the set that the element i belongs to.

        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }
        
        // numDisjointSets(): returns the number of sets being maintained currently.

        int numDisjointSets(){
            return numSets; 
        }

        void unionSet(int i, int j){
            if(isSameSet(i,j)) 
                return; 
            
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y])
                swap(x,y);
            
            p[x] = y; 

            if (rank[x] == rank[y])
                rank[y]++;
            
            setSize[y] += setSize[x];
            numSets--;

        }


};


    int main(){

        int s;
        cin >> s;

        vector<iii> El;
        while(s--){
            El.clear();

            int n;
            cin >> n;
            for(int i =0; i<n; i++){
                string temp;
                cin >> temp;

                int degree;
                cin >> degree;

                while(degree--){
                    int j,w;
                    cin >> j >> w;
                    El.push_back({w,i,j-1});
                }
            }

            sort(El.begin(), El.end());

            int mst_cost= 0;
            int takenEdges = 0;

            UnionFind UF(n);

            for ( auto&[w,u,v]: El){
                if(UF.isSameSet(u,v)) continue;

                mst_cost+=w;

                UF.unionSet(u,v);
                takenEdges++;
                if(takenEdges==n-1) break;
            }

            cout <<mst_cost<<'\n';


        }


    }
