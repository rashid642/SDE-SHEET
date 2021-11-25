class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> res;
    void helper(string s, vector<string> hs, int ind){
        if(s.length()==0){
            res.push_back(hs);
            return;
        }
        for(int i=ind; i<s.length();i++){
            if( isPalindrome(s.substr(ind,i+1)) ){
                hs.push_back(s.substr(ind,i+1));
                helper(s.substr(i+1,s.length()),hs,0);
                hs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> hs;
        helper(s,hs,0);
        return res;
    }
};