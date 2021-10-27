//this is my best code till now, even if it exceed time limits

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        int l=uniquePaths(m-1,n);
        int r=uniquePaths(m,n-1);
        return l+r;
    }
};

//giving error using dp

class Solution {
public:
    int helper(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m-1 || j==n-1)return 1;
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[m][n]=helper(i+1,j,m,n,dp)+helper(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0,0,m,n,dp);
    }
};

//Most optimized code

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
};