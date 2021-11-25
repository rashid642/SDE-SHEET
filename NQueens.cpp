class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<vector<int>> arr, int r, int c, int n){
        for(int i=0;i<n;i++){
            if(arr[r][i]==1)return false;
        }
        for(int i=0;i<n;i++){
            if(arr[i][c]==1)return false;
        }
        for(int i=r,j=c;i<n && j<n; i++,j++){
            if(arr[i][j]==1)return false;
        }
        for(int i=r,j=c;i>=0 && j>=0; i--,j--){
            if(arr[i][j]==1)return false;
        }
        for(int i=r,j=c;i<n && j>=0; i++,j--){
            if(arr[i][j]==1)return false;
        }
        for(int i=r,j=c;i>=0 && j<n; i--,j++){
            if(arr[i][j]==1)return false;
        }
        return true;
    }
    bool helper(vector<vector<int>> &arr, int col){
        int n=arr.size();
        if(col==n){
            return true;
        }
        for(int i=0;i<n;i++){
            if( isValid(arr,i,col,n) ){
                arr[i][col]=1;
                if(helper(arr,col+1)){
                    return true;
                }else{
                    arr[i][col]=0;
                }
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> arr(n, vector<int>(n,0));
        helper(arr,0);
        string s="";
        vector<string> v;
        for(int i=0;i<n;i++){
            s="";
            for(int j=0;j<n;j++){
                if(arr[i][j]==0)s=s+".";
                if(arr[i][j]==1)s=s+"Q";
                cout<<arr[i][j]<<" ";
            }cout<<endl;
            v.push_back(s);
        }
        
        res.push_back(v);
        return res;
    }
};