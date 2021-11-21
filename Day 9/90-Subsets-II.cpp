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