//brute force

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i=i+2){
            if(i+1>=nums.size()){
                return nums[i];
            }
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};

//binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(mid%2==0){
                if(nums[mid+1]==nums[mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                if(nums[mid-1]==nums[mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return nums[low];
    }
};