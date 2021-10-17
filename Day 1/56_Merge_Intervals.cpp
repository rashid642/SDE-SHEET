//brute force

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       // vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            
            if(intervals[i][1]>=intervals[i+1][0] && intervals[i][1]<intervals[i+1][1]){
                intervals[i][1]=intervals[i+1][1];
                //deleting interval[i+1];
                for(int j=i+1;j<intervals.size()-1;j++){
                    intervals[j]=intervals[j+1];
                }
                intervals.pop_back();
                i--;
            }
            else if(intervals[i][0]<=intervals[i+1][0] && intervals[i][1]>=intervals[i+1][1]){
                for(int j=i+1;j<intervals.size()-1;j++){
                    intervals[j]=intervals[j+1];
                }
                intervals.pop_back();
                i--;
            }
        }
        return intervals;
    }
};


//optimised

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        
        vector<int> v=intervals[0];
        for(auto itr:intervals){
            if(itr[0]<=v[1]){
                v[1]=max(itr[1],v[1]);
            }else{
                merged.push_back(v);
                v=itr;
            }
        }
        merged.push_back(v);
        return merged;
    }
};