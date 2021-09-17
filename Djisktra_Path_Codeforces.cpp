
#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
#define vi  vector<int>
#define vll vector<long long int>

#define INF 1e12
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

int main(){
  

    std::ios::sync_with_stdio(false);
    
    int n,m;

    cin >> n >> m;

    vector<vii> AL(n+1, vii());
    int u, v, w;
    
    for (int i = 0; i < m; ++i)
    {   
        cin >> u >> v >> w;
        // The graph here is undirected:
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }

    vll dist(n+1, INF);
    dist[1] = 0;
    
    vi pred(n+1, -1);
    pred[1] = 1;



    priority_queue<ii, vector<ii>, greater<ii>> pq; 
    pq.push({0, 1});


    while (!pq.empty()) {                          
        auto [d, u] = pq.top(); pq.pop();          

        if (d > dist[u]) continue;                 

        for (auto &[v, w] : AL[u]) {               
            if (dist[u]+w >= dist[v]) continue;    
        
            dist[v] = dist[u]+w;                   
            pred[v] = u;
            pq.push({dist[v], v});                 
        
        }
    }
    if(dist[n] == INF)
        cout << "-1";
    else{
        stack<int> st;
        int current=n;
        while(current!=1){
        	st.push(current);
        	current = pred[current];
        }
        st.push(1);
        while(!st.empty()){
        	cout<<st.top()<<" ";
        	st.pop();
        }
    }

 return 0;   
}
