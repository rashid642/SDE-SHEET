//brute force

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(auto i=nums.begin();i<nums.end();i++){
            if(*i==0){
                red++;
            }
            if(*i==1){
                white++;
            }
            if(*i==2){
                blue++;
            }
        }
        // cout<<red<<" "<<white<<" "<<blue<<endl;
        for(int i=0;i<nums.size();i++){
            if(red>0){
                nums[i]=0;
                red--;
            }
            else if(white>0){
                nums[i]=1;
                white--;
            }
            else if(blue>0){
                nums[i]=2;
                blue--;
            }
        }
    }
};

//Optimize solution using DNF algo

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};