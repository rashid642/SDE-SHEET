// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> res;
    void helper(vector<int> arr, int ind, int N,int sum){
        if(ind==N){
            res.push_back(sum);
            return;
        }
        sum+=arr[ind];
        helper(arr,ind+1,N,sum);
        sum-=arr[ind];
        helper(arr,ind+1,N,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        helper(arr,0,N,0);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends