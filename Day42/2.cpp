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

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
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

    void bfsSingleComponent(int start, vector<bool> &visited)
    {

        queue<int> q;

        visited[start] = true;

        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void BFS()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < adj.size(); i++)
        {
            if (!visited[i])
            {
                bfsSingleComponent(i, visited);
            }
        };
    }



    bool isCycleDFS(int node, int parent, vector<bool> & visited){

        visited[node] = true;
        for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            if(isCycleDFS(neighbor, node, visited)){
                return true;
            }
        }
        else if(neighbor != parent){
            return true;
        }
    }
    return false;
    };



    void dfsHelper(int node, vector<bool> &visited)
    {

        visited[node] = true;

        cout << node << " ";

        for (int neighbor : adj[node])
        {

            if (!visited[neighbor])
            {

                dfsHelper(neighbor, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);

        int count =0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i, visited);
                count++;
            }
        }
        cout << endl;
        // cout << count<< endl;
    }
};



int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3,2);
    g.addEdge(2,0);

    // g.printGraph();
    g.DFS(0);

    return 0;
}