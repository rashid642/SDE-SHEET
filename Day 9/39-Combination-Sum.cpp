class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> candidates, vector<int> h, int ind, int target){
        if(ind>=candidates.size()){
            if(target==0){
                res.push_back(h);
                return;
            }
            return;
        }
        if(candidates[ind]<=target){
            h.push_back(candidates[ind]);
            helper(candidates, h, ind, target-candidates[ind]);
            h.pop_back();
        }
        helper(candidates, h, ind+1, target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> h;
        helper(candidates,h,0,target);
        return res;
    }
};