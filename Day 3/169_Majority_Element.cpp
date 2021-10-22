//BRUTE FORCE memory leak but works

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<long long> vp(2147483647);
        vector<long long> vn(2147483647);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                vp[nums[i]]++;
                if(vp[nums[i]]>(nums.size()/2)){
                    return nums[i];
                }
            }else{
                vn[-1*nums[i]]++;
                if(vn[-1*nums[i]]>(nums.size()/2)){
                    return nums[i];
                }
            }
            
        }
        return 0;
    }
};