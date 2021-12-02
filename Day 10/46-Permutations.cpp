class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};

//recursuion and backtracking

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> nums, vector<int> &v, int mp[]){
        if(v.size()==nums.size()){
            res.push_back(v);
            return;
        }
        // cout<<nums.size()<<" ";?
        for(int i=0; i<nums.size(); i++){
            if(mp[i]==0){
                mp[i]=1;
                v.push_back(nums[i]);
                helper(nums, v, mp);
                mp[i]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        int mp[n];
        for(int i=0;i<n;i++)mp[i]=0;
        helper(nums,v,mp);
        return res;
    }
};

//more optimized

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, int ind){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i],nums[ind]);
            helper(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return res;
    }
};