#include <iostream>
#include <vector>
using namespace std;


class Graph{
    private:
    int V;
    vector<vector<pair<int, int>>> adjList;
    public:
    Graph(int vertices){
        V = vertices;
        adjList.resize(V);
    }

    
    void addEdge(int u, int v, int w){
        if(u>=0 && v >=0 && u < V && v < V){
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w} ); 
        }else{
            cout << "Invalid vertices!" << endl;
        }
    };
    void printGraph(){
        for(int i=0; i<V; i++){
            cout << i << " -> ";
            for(auto neighbor : adjList[i]){
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    };
};


int main(){
    Graph g(4);
    g.addEdge(0, 1,4);
    g.addEdge(0, 2,3);
    g.addEdge(1, 2,2);
    g.addEdge(2,3,5);

    g.printGraph();

    return 0;
}