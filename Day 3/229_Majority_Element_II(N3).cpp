//using map

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto itr:mp){
            if(itr.second>nums.size()/3){
                v.push_back(itr.first);
            }
        }
        return v;
    }
};

//most optimized

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int num1=-1,num2=-1,c1=0,c2=0;
        for(auto ele:nums){
            if(ele==num1){
                c1++;
            }else if(ele==num2){
                c2++;
            }else if(c1==0){
                num1=ele;
                c1++;
            }else if(c2==0){
                num2=ele;
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto ele:nums){
            if(ele==num1){
                c1++;
            }else if(ele==num2){
                c2++;
            }
        }
        if(c1>nums.size()/3){
            v.push_back(num1);
        }
        if(c2>nums.size()/3){
            v.push_back(num2);
        }
        return v;
    }
};