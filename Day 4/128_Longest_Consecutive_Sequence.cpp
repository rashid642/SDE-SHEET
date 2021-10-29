//using sorting

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=1,count=1;
        if(nums.size()==1){
            return 1;
        }
        if(nums.size()==0){
            return 0;
        }
        int i;
        for(i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                count++;
            }
            else if(nums[i]-nums[i-1]==0){
                continue;
            }
            else{
                count=1;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};

//striver solution but not that optimized

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        int longestStreak=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1)!=st.end()){
                continue;
            }
            int count=0;
            int a=nums[i];
            while(st.find(a)!=st.end()){
                count++;
                a++;
            }
            longestStreak=max(longestStreak,count);
        }
        return longestStreak;
    }
};