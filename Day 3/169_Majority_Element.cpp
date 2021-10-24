//Brute force, but time limit exceed

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;
        for(int i=0;i<nums.size();i++){
            int count=0;
            // cout<<nums[i]<<"->";
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    // cout<<nums[j]<<" ";
                    count++;
                    maj=max(count,maj);
                    // cout<<maj<<" ";
                    if(maj>(nums.size()/2)){
                        return nums[i];
                    }
                }
            }
        }
        return 0;
    }
};

//using sorting

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int count=0;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i]){
                count++;
                maxi=max(count,maxi);
                if(maxi>nums.size()/2){
                    return nums[i];
                }
            }else{
                a=nums[i];
                count=1;
            }
        }
        return 0;
    }
};

//Better

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};

//Moores Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
            }
            if(nums[i]==ele){
                count+=1;
            }else{
                count-=1;
            }
        }
        return ele;
    }
};

