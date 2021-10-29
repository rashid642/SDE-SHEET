//brute force, insane time complexity

class Solution {
public:
    int binarySearch(vector<int> num,int ind,int val){
        int i=ind,j=num.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(num[mid]==val){
                return mid;
            }
            if(num[mid]>val){
                j=mid-1;
            }
            if(num[mid]<val){
                i=mid+1;
            }
        }
        return -1;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    // cout<<"("<<i<<","<<j<<","<<k<<") ";
                    int temp=nums[i]+nums[j]+nums[k];
                    int ind=binarySearch(nums,k+1,target-temp);
                    if(ind!=-1){
                        vector<int> v={nums[i],nums[j],nums[k],nums[ind]};
                        // cout<<st.count(v)<<" ";
                        if(st.count(v)==0){
                           res.push_back(v); 
                           st.insert(v);
                        }
                    }
                }
            }
        }
        return res;
    }
};

//optimized

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty()){
            return res;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target2=target-nums[i]-nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right){
                    if(nums[left]+nums[right]<target2){
                        left++;
                    }else if(nums[left]+nums[right]>target2){
                        right--;
                    }else{
                        vector<int> v={nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(v);
                        while(left<right && nums[left]==v[2])++left;
                        while(left<right && nums[right]==v[3])--right;
                    }
                    while(j+1<n && nums[j]==nums[j+1])++j;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])++i;
        }
        return res;
    }
};