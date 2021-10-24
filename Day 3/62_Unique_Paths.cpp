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