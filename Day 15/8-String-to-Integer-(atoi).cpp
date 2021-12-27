class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long int res=0;
        bool isneg = false;
        while(s[i]==' ')i++;
        if(s[i]=='-'){
            isneg = true;
            i++;
        }
        else if(s[i]=='+'){
            isneg = false;
            i++;
        }
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            res = res*10 + s[i] - 48;
            if(res >= pow(2,31)){
                // return pow(2,31);
                return isneg ? INT_MIN : INT_MAX;
            }
            i++;
        }
        return isneg ? -1*res : res;
    }
};