class Solution {
  public:
    void dfstraversal(int node, vector<int> &dfs, vector<int> &vis, vector<int> adj[]){
        dfs.push_back(node);
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfstraversal(it, dfs, vis, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> vis(V+1,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfstraversal(i, dfs, vis, adj);
            }
        }
        return dfs;
    }
};