//not optimized
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> arr, vector<int> h,int ind, int N,int sum){
        if(ind==N){
            sort(h.begin(),h.end());
            vector<vector<int>>::iterator it;
            it = find (res.begin(), res.end(), h);
            if (it == res.end())
            {
                res.push_back(h);
            }
            return;
        }
        h.push_back(arr[ind]);
        helper(arr,h,ind+1,N,sum);
        h.pop_back();
        helper(arr,h,ind+1,N,sum);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> h;
        helper(nums,h,0,nums.size(),0);
        return res;
    }
};

//optimized

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int ind){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            helper(nums,ds,ans,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(nums, ds, ans, 0);
        return ans;
    }
};