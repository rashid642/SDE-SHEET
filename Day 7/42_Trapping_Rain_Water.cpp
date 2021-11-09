class Solution {
public:
    void traverse(int arr[],int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int maxi=-1;
        int premax[n],postmax[n];
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            premax[i]=maxi;
        }
        maxi=-1;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            postmax[i]=maxi;
        }
        // traverse(premax,n);
        // traverse(postmax,n);
        int res=0;
        for(int i=0;i<n;i++){
            res=res+min(premax[i],postmax[i])-height[i];
        }
        return res;
    }
};