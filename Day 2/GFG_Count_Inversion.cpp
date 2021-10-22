// brute force

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long count=0;
        for(long long i=0;i<N;i++){
            for(long long j=i+1;j<N;j++){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}


//Using Merge Sort

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right){
    long long i=left,j=mid;
    long long k=left;
    long long inv_count=0;
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            inv_count=inv_count+mid-i;
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return inv_count;
}

long long int _mergeSort(long long arr[], long long temp[], long long left, long long right){
    long long mid;
    long long inv_count=0;
    if(left<right){
        mid=(left+right)/2;
        inv_count+=_mergeSort(arr,temp,left,mid);
        inv_count+=_mergeSort(arr,temp,mid+1,right);
        
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return _mergeSort(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
