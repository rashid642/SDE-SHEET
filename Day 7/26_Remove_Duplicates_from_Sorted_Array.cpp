class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int it:nums){
            st.insert(it);
        }
        vector<int> res;
        int i=0;
        for(auto it=st.begin();it!=st.end();it++){
            nums[i]=*it;
            i++;
        }
        return st.size();
    }
};