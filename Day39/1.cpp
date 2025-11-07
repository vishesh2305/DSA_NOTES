#include <iostream>
#include <vector>
using namespace std;

class Graph{
    private:
    int V;
    vector<vector<int>> adjList;
    public:
    Graph(int vertices){
        V= vertices;

        adjList.resize(V);
    };

    void addEdge(int u, int v){
        if(u>=0 && v >=0 && u < V && v < V){
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }else{
            cout << "Invalid vertices!" << endl;
        }
    };

    void printGraph(){
        for(int i=0; i<V; i++){
            cout << i << " -> ";
            for(int neighbor : adjList[i]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    };

    void removeEdge(int u, int v){

        if(u>=0 && v>=0 && u < V && v < V){
            for(int i=0; i < adjList[u].size(); i++){
                if(adjList[u][i] == v){
                    adjList[u].erase(adjList[u].begin() + i);
                    break;
                }
            }

            for(int i=0; i < adjList[v].size(); i++){
                if(adjList[v][i] == u){
                    adjList[v].erase(adjList[v].begin() + i);
                    break;
                }
            }

        }


    }

    bool hasEdge(int u, int v){
        for(int node: adjList[u]){
            if(node == v){
                return true;
            }
        }
        return false;
    }

};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.printGraph();
    return 0;
}