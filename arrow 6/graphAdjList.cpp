#include<bits/stdc++.h>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T>

class graph {
public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u,T v, bool dir){
        // if dir is 1 then directed graph 
        // if dir is 0 then undirected graph
        adj[u].push_back(v);
        if(dir==0){
            adj[v].push_back(u);
        }
    }


    void printgraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }


};

int main(){
    int n;
    cout<<"nodes: ";
    cin>>n;
    int m;
    cout<<"edges: ";
    cin>>m;

    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printgraph();

    return 0;
}