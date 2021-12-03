class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string> arr, int r, int c, int n){
        for(int i=0;i<n;i++){
            if(arr[r][i]=='Q')return false;
        }
        for(int i=0;i<n;i++){
            if(arr[i][c]=='Q')return false;
        }
        for(int i=r,j=c;i<n && j<n; i++,j++){
            if(arr[i][j]=='Q')return false;
        }
        for(int i=r,j=c;i>=0 && j>=0; i--,j--){
            if(arr[i][j]=='Q')return false;
        }
        for(int i=r,j=c;i<n && j>=0; i++,j--){
            if(arr[i][j]=='Q')return false;
        }
        for(int i=r,j=c;i>=0 && j<n; i--,j++){
            if(arr[i][j]=='Q')return false;
        }
        return true;
    }
    void helper(vector<string> &s, int col,int n){
        if(col==n){
            res.push_back(s);
        }
        for(int i=0;i<n;i++){
            if( isValid(s,i,col,n) ){
                s[i][col]='Q';
                helper(s,col+1,n);
                s[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n);
        string a(n,'.');
        for(int i=0;i<n;i++){
            s[i]=a;
        }
        // res.push_back(s);
        helper(s,0,n);
        return res;
    }
};