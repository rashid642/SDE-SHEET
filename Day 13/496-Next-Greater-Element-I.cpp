class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        for(int i=0; i<nums1.size();i++){
            bool flag=false;
            for(int j=0; j<nums2.size();j++){
                if(!flag){
                    if(nums2[j]==nums1[i]){
                        flag=true;
                    }
                }else{
                    if(nums2[j]>nums1[i]){
                        res[i]=nums2[j];
                        break;
                    }
                }
            }
        }
        return res;
    }
};

//using stacks

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> v; 
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
                st.push(nums2[i]);
                continue;
            }
            v.push_back(st.top());
            st.push(nums2[i]);
        }
        reverse(v.begin(), v.end());
        // for(int i=v.size()-1; i>=0; i--){
        //     cout<<v[i]<<" ";
        // }cout<<endl;
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            int j;
            for(j=0; j<nums2.size(); j++){
                if(nums2[j]==nums1[i])break;
            }
            if(j!=nums2.size()){
                res.push_back(v[j]);
            }
        }
        return res;
    }
};