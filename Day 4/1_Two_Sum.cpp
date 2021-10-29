// bit optimized

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        for(int i=0;i<nums.size();i++){
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(i);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        int i=0,j=nums.size()-1;
        vector<int> res;
        while(i<j){
            if(v[i][0]+v[j][0]==target){
                res.push_back(v[i][1]);
                res.push_back(v[j][1]);
                return res;
            }
            if(v[i][0]+v[j][0]>target){
                j--;
            }
            if(v[i][0]+v[j][0]<target){
                i++;
            }
        }
        return res;
    }
};

//using map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                res.push_back(mpp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            mpp[nums[i]]=i;
        }
        return res;
    }
};