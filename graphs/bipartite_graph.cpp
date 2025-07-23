#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(vector<int> &colors, queue<int> &q, vector<vector<int>> &adj, int startNode) {
        q.push(startNode);
        colors[startNode] = 0;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]) {
                if(colors[neighbour] == -1) {
                    q.push(neighbour);
                    colors[neighbour] = 1 - colors[front];
                } else {
                    if(colors[neighbour] == colors[front]) return false;
                } 
                 
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> colors(V, -1);
        queue<int> q;
        
        for(int i = 0; i < colors.size(); i++) {
            if(colors[i] == -1) {
             if(!bfs(colors, q, adj, i)) return false;   
            }
        }
        
        return true;
    }
};