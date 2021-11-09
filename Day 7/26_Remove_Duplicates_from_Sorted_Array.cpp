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

//otimized

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};