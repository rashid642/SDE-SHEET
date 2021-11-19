// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comparison(Item a,Item b){
        double ao=a.value*1.0/a.weight;
        double bo=b.value*1.0/b.weight;
        return (ao>bo);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparison);
        double weight=0,value=0;
        int i=0;
        while(weight<=W && i<n){
            weight+=arr[i].weight;
            value+=arr[i].value;
            i++;
        }
        if(weight>W){
            i--;
            double temp=(arr[i].weight-(weight-W))*1.0/arr[i].weight;
            // double temp=
            value-=arr[i].value;
            value=value+arr[i].value*temp*1.0;
        }
        return value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends