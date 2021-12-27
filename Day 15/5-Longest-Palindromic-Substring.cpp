class Solution {
public:
    string longestPalindrome(string s) {
       bool dp[s.length()][s.length()];
        int maxlen = 0;
        string ans="";
        for(int g=0; g<s.length(); g++){
            for(int i=0, j=g; j<s.length(); i++, j++){
                // cout<<i<<","<<j<<" bool=";
                if(g==0){
                    dp[i][j]=true;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(dp[i+1][j-1]==true && s[i]==s[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                // cout<<dp[i][j]<<" stirng="<<s.substr(i,i-j+1)<<"   ";
                if(dp[i][j]){
                    if(j-i+1>maxlen){
                        maxlen = j-i+1;
                        ans = s.substr(i,j-i+1);
                        // cout<<ans<<" ";
                    }
                }
            }
        }
        return ans;
    }
};