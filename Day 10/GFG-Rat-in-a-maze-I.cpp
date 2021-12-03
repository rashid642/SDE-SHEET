class Solution{
    public:
    vector<string> ans;
    void helper(vector<vector<int>> &m, string &s, int i, int j){
        if(i<0 || j<0 || i>=m.size() || j>=m.size()){
            return;
        }
        if(i==m.size()-1 && j==m.size()-1){
            ans.push_back(s);
            return;
        }
        if(i+1<m.size() && m[i+1][j]==1){
            m[i+1][j]=0;
            s=s+"D";
            helper(m, s, i+1, j);
            m[i+1][j]=1;
            s=s.substr(0,s.size()-1);
        }
        if(j+1<m.size() && m[i][j+1]==1){
            m[i][j+1]=0;
            s=s+"R";
            helper(m, s, i, j+1);
            m[i][j+1]=1;
            s=s.substr(0,s.size()-1);
        }
        if(i-1>=0 && m[i-1][j]==1){
            m[i-1][j]=0;
            s=s+"U";
            helper(m, s, i-1, j);
            m[i-1][j]=1;
            s=s.substr(0,s.size()-1);
        }
        if(j-1>=0 && m[i][j-1]==1){
            m[i][j-1]=0;
            s=s+"L";
            helper(m, s, i, j-1);
            m[i][j-1]=1;
            s=s.substr(0,s.size()-1);
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0){
            return ans;
        }
        m[0][0]=0;
        string s="";
        helper(m,s,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};