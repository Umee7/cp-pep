#include<bits/stdc++.h>
using namespace std;

// Breadth First Search
class Solution {
  public:
    bool bfs(vector<int> &visited, vector<vector<int>> &adj, int startNode) {
        queue<pair<int, int>> q;
        q.push({startNode, -1});
        visited[startNode] = 1;
        while(!q.empty()) {
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neighbour : adj[front]) {
                if(visited[neighbour] != 1) {
                    visited[neighbour] = 1;
                    q.push({neighbour, front});
                } else if(neighbour != parent) {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V);
        
        for(int i = 0; i < V; i++) {
            if(visited[i] != 1) {
                if(bfs(visited, adj, i)) {
                return true;
            }
            }
            
        }
        
        return false;
    }
};

// Depth First Search
class Solution {
  public:
    bool dfs(vector<int> &visited, vector<vector<int>> &adj, pair<int, int> startNode) {
        
        visited[startNode.first] = 1;
        for(auto neighbour : adj[startNode.first]) {
                if(visited[neighbour] != 1) {
                    if(dfs(visited, adj, {neighbour, startNode.first})) return true;
                } else if(neighbour != startNode.second) {
                    return true;
                }
            }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V);
        
        for(int i = 0; i < V; i++) {
            if(visited[i] != 1) {
                if(dfs(visited, adj, {i, -1})) {
                return true;
                }
            }
            
        }
        
        return false;
    }
};