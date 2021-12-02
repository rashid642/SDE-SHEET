class Solution{
    public:
    vector<string> ans;
    bool helper(vector<vector<int>> &m, string &s, int i, int j){
        if(i<0 || j<0 || i>=m.size() || j>=m.size()){
            return false;
        }
        if(i==m.size()-1 && j==m.size()-1){
            ans.push_back(s);
            return true;
        }
        if(m[i][j+1]==1){
            m[i][j+1]=0;
            s=s+"D";
            if(!helper(m, s, i, j+1)){
                m[i][j+1]=1;
                s=s.substr(0,s.size()-1);
            }
        }
        if(m[i+1][j]==1){
            m[i+1][j]=0;
            s=s+"R";
            if(!helper(m, s, i+1, j)){
                m[i+1][j]=1;
                s=s.substr(0,s.size()-1);
            }
        }
        if(m[i-1][j]==1){
            m[i-1][j]=0;
            s=s+"U";
            if(!helper(m, s, i-1, j)){
                m[i-1][j]=1;
                s=s.substr(0,s.size()-1);
            }
        }
        if(m[i][j-1]==1){
            m[i][j-1]=0;
            s=s+"L";
            if(!helper(m, s, i, j-1)){
                m[i][j-1]=1;
                s=s.substr(0,s.size()-1);
            }
        }
        return false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        helper(m,"",0,0);
        return ans;
    }
};