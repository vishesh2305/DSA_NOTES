#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// vector<int> bfs(vector<vector<int>> &adj, int start){
//     int V = adj.size();
//     vector<bool> visited(V, false);

//     queue<int> q;
//     vector<int> result;

//     visited[start] = true;
//     q.push(start);


//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         result.push_back(node);

//         for(int neighbour: adj[node]){
//             if(!visited[neighbour]){
//                 visited[neighbour] = true;
//                 q.push(neighbour);
//             }
//         }

//     }





// }





class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // void BFS(int start) {
    //     vector<bool> visited(V, false);
    //     queue<int> q;
    //     visited[start] = true;
    //     q.push(start);
    //     while (!q.empty()) {
    //         int node = q.front();
    //         q.pop();
    //         cout << node << " ";
    //         for (int neighbor : adj[node]) {
    //             if (!visited[neighbor]) {
    //                 visited[neighbor] = true;
    //                 q.push(neighbor);
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

void bfsSingleComponent(int start, vector<bool> & visited){

    queue<int> q;

    visited[start] = true;

    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        }
}


void BFS(){
    vector<bool> visited(V, false);
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
        bfsSingleComponent(i, visited);
        }
    };
}




void dfsHelper(int node, vector<bool>& visited) {

visited[node] = true;

cout << node << " ";

for (int neighbor : adj [node]) {

if (!visited[neighbor]) {

dfsHelper (neighbor, visited);
}
}
}



void DFS(int start){
    vector<bool> visited(V, false);

    cout << "DFS traversal starting from "<< start<< " ";


    dfsHelper(start, visited);
    cout << endl;

}




};







