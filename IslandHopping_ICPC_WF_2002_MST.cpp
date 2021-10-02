//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3454

// https://www.spoj.com/problems/BLINNET/

#include <bits/stdc++.h>
using namespace std;


#define ll  long long int
#define vi  vector<int>
#define vll vector<long long int>
#define iii tuple<double, int, int>

const int MAXN = 64;
double X[MAXN], Y[MAXN], M[MAXN];
double inhabitants[MAXN];

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

            if (setSize[x] > setSize[y]) {
                p[y] = x;
                inhabitants[x] += inhabitants[y];
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                inhabitants[y] += inhabitants[x];
                setSize[y] += setSize[x];
            }
            numSets--;
        }


};

    vector<iii> EL;
    int main(){
        int cases =0, n=0;
        cout << fixed << setprecision(2);
        while(true){
            cin >> n;
            if(n){
                for(int i=0; i < n ; i++)
                    cin>>X[i]>>Y[i]>>M[i];

                EL.clear();


                for (int i=0;i<n; i++){
                    for(int j= 0; j<n; j++){
                        double wt = hypot( X[i]-X[j], Y[i]-Y[j]);
                        EL.push_back({wt,i,j});
                    }
                }

                sort(EL.begin(),EL.end());

                double div = 0, sum = 0;
                int u,v;

                UnionFind UF(n);
                for(int i =0; i<n; i++){
                    inhabitants[i] = M[i];
                    div+=M[i];
                }

                for(auto&[w,u,v] : EL){
                    if(UF.findSet(u)!=UF.findSet(v)){
                        if(UF.findSet(u)==UF.findSet(0))
                            sum+=inhabitants[UF.findSet(v)]*w;
                    if(UF.findSet(v)==UF.findSet(0))
                        sum+=inhabitants[UF.findSet(u)]*w;

                        UF.unionSet(u,v);
                    }

                }
                cases++;

                cout << "Island Group: " << cases << " Average " << (sum / div) << endl << endl; 


            }
            else break;
        }
        return 0;
    }
