//using map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int maxi=0,count=0;
        for(int i=0;i<s.length();i++){
            if(mpp.count(s[i])==0){
                mpp[s[i]]=i;
                count++;
            }else{
                auto ch=mpp.find(s[i]);
                i=ch->second;
                count=0;
                mpp.clear();
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};