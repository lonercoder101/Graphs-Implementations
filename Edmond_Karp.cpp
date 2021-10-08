//Edmonds Karp's algorithm, in the context of,
//Internet Bandwidth - UVA 820
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=761
// I hope I can understand this 2 months down the line

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef tuple<int,ll,ll> edge;
typedef vector<int> vi;
typedef pair<int,int> ii;

const ll INF = 1e18;

class max_flow{
private:
        int V;
        vector<edge> EL;   // edge list
        vector<vi> AL;          // adjacency list
        vi d, last;             // used in dinic's algo,useless here
        vector<ii> p;           // parent 


        bool BFS(int s, int t){         // find augmenting path with BFS

            d.assign(V,-1);             // assign parent and set distance/level
            d[s] = 0; 

            queue<int> q({s});              //push source

            p.assign(V,{-1,-1});            // usual assignment

            while(!q.empty()){

                int u = q.front();

                q.pop();

                if(u==t) break;   // if sink is reached, stop

                for(auto &idx : AL[u]){   // nbrs of u
                    auto &[v,cap,flow] = EL[idx];  // stored in EL[idx]

                    if( (cap-flow >0) and ( d[v] == -1) ){ // positive residual edge + not explored
                         d[v] = d[u] +  1;  // level set
                        q.push(v);   
                        p[v] = {u , idx}; // parent info
                    } 
                }
            }

            return d[t] != -1; // has augmenting path


        }

    ll send_one_flow(int s, int t, ll f = INF){ // send one flow from source to sink

        if(s==t) return f;   // bottleneck edge

        auto &[u,idx] = p[t];

        auto &cap = get<1>(EL[idx]), &flow=get<2>(EL[idx]);

        // cap = 2nd element from EL[idx] and flow is 3rd element EL[idx] 
        // EL[idx] is a tuple of 3 integers
        // Z --> T  with flow 9 then, EL --> T 9 0 and as a result,
        // cap = 9 and flow = 0;

        ll pushed = send_one_flow(s,u, min(f,cap-flow));  // recursive send a flow with a residual capacity cap

        flow += pushed;   // increment the flow of the current edge

        auto &rflow = get<2>(EL[idx^1]); // back edge 

                                            // edge list comes in pairs, XOR-ing the idx with 1 (idx^1).
                                            //  flip the last bit 

        rflow -= pushed;        // decrement the flow of that backedge, i don't really this though (XD)


        return pushed;


    }





public:
    max_flow(int initialV): V(initialV){
        EL.clear();
        AL.assign(V,vi());
    }

    //  if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)

    void add_edge(int u, int v, ll w, bool directed = true){
        if(u==v) return;  // no self loop

        EL.emplace_back(v,w,0); // u->v, capped at W, flow is zero

        AL[u].push_back(EL.size()-1); // remember this idx 

        EL.emplace_back(u,directed ? 0 : w, 0);  // back edge

        AL[v].push_back(EL.size()-1); // remember idx
    }

    ll edmonds_karp(int s, int t){

        ll maxf= 0;             // max flow

        while(BFS(s,t)){        // O(V x (E)^2) algo

            ll f = send_one_flow(s,t);  // find and send one flow to f

            if(f==0) break;         // stop when f = 0

            maxf+=f;            // if (f>0), add to maxf

        } 

        return maxf;

    }

};



int main(){


    int c = 0;

    while(true){
        int n;
        cin>>n;
        if(not n) break;

        int s,t,m;

        cin >> s >> t >> m ;

        max_flow maxf(n+1);             // initialize class

        for(int i =0;i < m; i++){
            int u,v,cap;
            cin >> u >> v >> cap;

            maxf.add_edge(u,v,cap,false);

        }
        c++;

        cout << "Network " << c << '\n' << "The bandwidth is " << maxf.edmonds_karp(s,t) << "." << '\n' << endl;

    }
    return 0;
}
