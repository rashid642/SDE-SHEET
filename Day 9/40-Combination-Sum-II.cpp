class Solution {
public:
     vector<vector<int>> res;
    void helper(vector<int> candidates, vector<int> h, int ind, int target){
            if(target==0){
               res.push_back(h);
                return;
            }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue; 
            if(candidates[i]>target) break;
            h.push_back(candidates[i]);
            helper(candidates, h, i+1, target-candidates[i]);
            h.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> h;
        sort(candidates.begin(),candidates.end());
        helper(candidates,h,0,target);
        return res;
    }
};