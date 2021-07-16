#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  string name;
  list<string> nbrs;
  Node(string name){
    this->name = name;
  }

};
class Graph{

  unordered_map<string,Node*> m;
public:
  Graph(vector<string> cities){
    for(auto city : cities){
      m[city] = new Node(city);

    }
  } 



  void addEdge(string x, string y, bool undir = false){
    m[x] -> nbrs.push_back(y);                                                     
    if(undir){
      m[y]-> nbrs.push_back(x);
    }


  }

  void printAdjList(){
    for (auto cityPair:m)
    {
     auto city = cityPair.first; 
     Node *node = cityPair.second;
     cout<<city<<"--->";
     for(auto nbr : node-> nbrs){
      cout<<nbr<<",";
    }
    cout<<'\n';
  }
}

};
int main()
{
  vector<string> cities = {"Delhi","London","Paris","New York"};
  Graph g(cities);
  g.addEdge("Delhi", "London");
  g.addEdge("New York","London");
  g.addEdge("Delhi","Paris");
  g.addEdge("Paris","New York");
  g.addEdge("London","New York");
  g.printAdjList();

}














// class Graph
//   {
//      int V;
//      list<int> *l;

//     public:
//       Graph(int v){
//        V=v;
//        l= new list<int>[V];              
//        }

//        void addEdge(int i,int j, bool undir=true)
//        {
//          l[i].push_back(j);
//          if(undir)
//            l[j].push_back(i); 
//         }
//         void printAdjList()
//         {
//            for(int i=0;i<V;i++)
//            {
//             cout<<i<<"-->";
//               for(auto node:l[i])
//                 cout<<node<<",";
//               cout<<"\n";
//             }

//          }

//      };
//      int main()

//      {
//        Graph  g(6);
//        g.addEdge(0,1);
//        g.addEdge(0,4);
//        g.addEdge(2,1);
//        g.addEdge(3,4);
//        g.addEdge(4,5);
//        g.addEdge(2,3);
//        g.addEdge(3,5);
//        g.printAdjList();
//        return 0;
//       }
//    