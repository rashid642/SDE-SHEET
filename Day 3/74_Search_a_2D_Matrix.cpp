//optimized 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        // cout<<matrix[i][j]<<" "<<i<<" "<<j;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                // cout<<matrix[i][j]<<" ";
                i++;
            }else{
                // cout<<matrix[i][j]<<" ";
                j--;
            }
        }
        return false;
    }
};

//binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int low=0;
        int high=matrix.size()*matrix[0].size()-1;
        int cols=matrix[0].size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid/cols][mid%cols]==target){
                return true;
            }
            if(matrix[mid/cols][mid%cols]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};