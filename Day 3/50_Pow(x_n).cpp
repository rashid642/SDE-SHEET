//brute force can't handle edge case

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return (1/x)*myPow(x,n+1);
        }else{
            return x*myPow(x,n-1);
        }
        return 0;
    }
};

//BRUTE FORCE, RIGHT ANSWER BUT TIME LIMIT EXCEDDING

class Solution {
public:
    double myPow(double x, int n) {
        long long m=1;
        long long p=n;
        long long a=x;
        if(n<0) p=-1*n; 
        while(p>0){
            m*=a;
            p--;
        }
        if(n<0) return double(1.0)/double(m);
        return double(m);
    }
};

//optimized solution

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0) nn=-1*nn;
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn--;
            }else{
                x=x*x;
                nn/=2;
            }
        }
        if(n<0) ans=(double)(1.0)/double(ans);
        return ans;
    }
};