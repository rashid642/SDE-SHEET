class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mpp;
        int res = 0;
        mpp['I'] = 1;   mpp['V'] = 5;   mpp['X'] = 10;   mpp['L'] = 50;   
        mpp['C'] = 100; mpp['D'] = 500; mpp['M'] = 1000;
        for(int i=0; i<s.length(); i++){
            if(mpp[s[i+1]] > mpp[s[i]]){
                // cout<<"inside i+1"<<" ";
                res += mpp[s[i+1]] - mpp[s[i]];
                i++;
            }else{
                res += mpp[s[i]];
            }
        }
        return res;
    }
};