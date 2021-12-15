class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bsf;
        vector<int> vis(V+1,0);
        // for(int i=0; i<V; i++){
            // if(!vis[i]){
                queue<int> st;
                st.push(0);
                vis[0]=1;
                while(!st.empty()){
                    int node=st.front();
                    st.pop();
                    bsf.push_back(node);
                   for(auto it: adj[node]){
                        if(!vis[it]){
                            st.push(it);
                            vis[it]=1;
                        }
                    } 
                }
        //     }
        // }
        return bsf;
    }
};