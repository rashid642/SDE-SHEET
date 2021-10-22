#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right){
    int i=left,j=mid;
    int k=left;
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
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
        // cout<<temp[i]<<" ";
        arr[i]=temp[i];
    }
}

void _mergeSort(int arr[], int temp[], int left, int right){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        _mergeSort(arr,temp,left,mid);
        _mergeSort(arr,temp,mid+1,right);
        
        merge(arr,temp,left,mid+1,right);
        return;
    }
}

int main() {
	int arr[5]={5,3,2,4,1};
	int left=0,right=4;
	int temp[5];
	for(int i=0;i<5;i++){
	    cout<<arr[i]<<" ";
	}cout<<endl;
	_mergeSort(arr,temp,left,right);
	for(int i=0;i<5;i++){
	    cout<<arr[i]<<" ";
	}
    
}
