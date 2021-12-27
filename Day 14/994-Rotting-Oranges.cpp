class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        int days=0;
        queue<pair<int,int>> st;
        int tot=0, rooten=0;
        int len = grid[0].size();
        int hei = grid.size();
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0)tot++;
                if(grid[i][j]==2){
                    st.push({i, j});
                    rooten++;
                }
            }
        }
        int prevrotten = rooten;
        if(tot==0)return 0;
        while(!st.empty()){
            int k = st.size();
            days++;
            while(k--){
                rooten++;
                int i = st.front().first;
                int j = st.front().second;
                // vis[i][j]=1;
                // cout<<"("<<i<<","<<j<<")"<<" ";
                if(i-1>=0 && grid[i-1][j]==1){
                    st.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(i+1<hei && grid[i+1][j]==1){
                    st.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    st.push({i,j-1});
                    grid[i][j-1]=2;
                }
                if(j+1<len && grid[i][j+1]==1){
                    st.push({i,j+1});
                    grid[i][j+1]=2;
                }
                st.pop();
            }
        }
        // cout<<rooten<<" "<<tot<<" "<<days;
        if(rooten-prevrotten==tot)return days-1;
        return -1;
    }
};