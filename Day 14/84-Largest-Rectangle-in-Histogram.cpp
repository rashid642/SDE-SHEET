class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int mini=INT_MAX;
            for(int j=i; j<heights.size(); j++){
                int len = j-i+1;
                mini = min(mini, heights[j]);
                int area = len * mini;
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};

//optimized

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int left[n], right[n];
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=0;
            }else{
                left[i]=st.top()+1;    
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-1;
            }else{
                right[i]=st.top()-1;    
            }
            st.push(i);
        }
        int area=0;
        for(int i=0; i<n; i++){
            cout<<"("<<left[i]<<","<<right[i]<<") ";
            area = max(area, (right[i]-left[i]+1)*heights[i] );
        }
        return area;
    }
};

//more optimized

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        int n = heights.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()])){
                int h = heights[st.top()];
                st.pop();
                int w;
                if(st.empty()){
                   w = i; 
                } 
                else{
                    w = i-st.top()-1;
                }
                area = max(area, h*w);
            }
            st.push(i);
        }
        return area;
    }
};