//optimized

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> st;
        int rows=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    pair<int,int> p;
                    p.first=i; p.second=j;
                    st.push_back(p);
                }
            }
        }
        for(auto i=0;i<st.size();i++){
            for(int j=0;j<col;j++){
                matrix[st[i].first][j]=0;
            }
            for(int j=0;j<rows;j++){
                matrix[j][st[i].second]=0;
            }
        }
    }
};