//time limit exceeded

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
            for(int j=i+1;j<nums.size();j++){
                int sub=nums[j]-nums[i];
                if(sub>max){
                     max=sub;
                }
            }
        }
        return max;
    }
};

//kadane algrithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0],sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(max<sum){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }
};