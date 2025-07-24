class Solution {
  public:
    void dfs(vector<int> &visited, vector<vector<int>> &adj, int startNode, stack<int> &s) {
        visited[startNode] = 1;
        for(auto neighbour : adj[startNode]) {
        if(!visited[neighbour]) dfs(visited, adj, neighbour, s);
        }
        s.push(startNode);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
    
        stack<int> s;
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(visited, adj, i, s);
            }
        }
        
        vector<int> result;
        
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};