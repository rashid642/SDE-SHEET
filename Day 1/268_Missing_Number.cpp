//Brute Force

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int arr[10000]={0};
        for(int i=0;i<n;i++){
            if(nums[i]<=n){
                arr[nums[i]]++;
            }
        }
        for(int i=0;i<n+1;i++){
            if(arr[i]==0){
                return i;
            }
        }
        return -1;
    }
};

//Bit optimised by using AP formula

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int vectorsum=0;
        for(int i=0;i<n;i++){
            vectorsum+=nums[i];
        }
        return sum-vectorsum;
    }
};

//using bit manipulation

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=-1;
        int i=0;
        for(i=0;i<nums.size();i++){
            x=x^nums[i]^i;
        }
        return x^(-1)^i;
    }
};