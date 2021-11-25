//brute force
class Solution {
public:
    string getPermutation(int n, int k) {
        int num[n];
        int i=0;
        string res="";
        while(i<n){
            num[i]=i+1;
            i++;
        }
        do{
            k--;
        }while(k>0 && next_permutation(num, num + n));
        for(int i=0;i<n;i++){
            string temp=to_string(num[i]);
            res=res+temp;
        }
        return res;
    }
};