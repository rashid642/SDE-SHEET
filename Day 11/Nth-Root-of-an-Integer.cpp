class Solution{
	public:
	long long int multiply(int n, int m){
	    long long int res=1;
	    for(int i=0;i<m;i++){
	        res*=n;
	    }
	    return res;
	}
	int NthRoot(int n, int m)
	{
	    cout<<multiply(2048,6)<<" ";
	    int low=1,high=m;
	    while(low<=high){
	        int mid=(low+high)/2;
	        long long int temp=multiply(mid,n);
	        if(temp==m){
	            return mid;
	        }
	        else if(temp<m){
	            low=mid+1;
	        }else{
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};