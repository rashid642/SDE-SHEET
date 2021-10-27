#include <bits/stdc++.h>
using namespace std;

void traverse(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void onescompliment(int m[],int arr[]){
    int n=6;
    for(int i=0;i<n;i++){
	    if(m[i]==0){
	        arr[i]=1;
	    }else{
	        arr[i]=0;
	    }
	}
}

void twocompliment(int m[],int arr[]){
    int n=6;
    int carry=1;
    for(int i=n-1;i>=0;i--){
        int temp=m[i]+carry;
        if(temp==0){
            arr[i]=0;
            carry=0;
        }else if(temp==1){
            arr[i]=1;
            carry=0;
        }else if(temp==2){
            arr[i]=0;
            carry=1;
        }
    }
}

void rightshift(int * m, int * ls, int k, int size){
    ls[0]=k;
    for(int i=1;i<size;i++){
        ls[i]=m[i-1];
    }
    for(int i=0;i<size;i++){
        m[i]=ls[i];
        //  cout<<m[i]<<" ";
    }
}

void add(int * m, int * n, int * added){
    int size=6;
    int carry=0;
    for(int i=size-1;i>=0;i--){
        int temp=m[i]+n[i]+carry;
        if(temp==0){
            added[i]=0;
            carry=0;
        }else if(temp==1){
            added[i]=1;
            carry=0;
        }else if(temp==2){
            added[i]=0;
            carry=1;
        }else if(temp==3){
            added[i]=1;
            carry=1;
        }
    }
    for(int i=0;i<size;i++){
        m[i]=added[i];
    }
}

void binaryToDecimal(int arr[], int size){
    int sum=0;
    int counter=0;
    for(int i=size-1;i>=0;i--){
        sum=sum+arr[i]*pow(2,counter);
        counter++;
    }
    cout<<sum;
}

void boothAlgo(int m[],int q[], int n){
    int size=n;
    int mOneC[n],mTwoC[n];
    onescompliment(m,mOneC);
    twocompliment(mOneC,mTwoC);//two's compliment of m is mTwoC
    
    int qo=0;
    int a[6]={0};
    int temp[6];
    
    cout<<"a=";
    traverse(a,size);
    cout<<"   q=";
    traverse(q,size);
    cout<<"   Twos compliment m=";
    traverse(mTwoC,size);
    cout<<"   m=";
    traverse(m,size);
    cout<<"   qo=";
    cout<<qo<<endl;
    
    while(n>0){
        if(q[size-1]==1 && qo==0){
            add(a,mTwoC,temp);
        }
        if(q[size-1]==0 && qo==1){
            add(a,m,temp);
        }
        cout<<"n="<<n<<"   ";
        qo=q[size-1];
        int lasteleQ=q[size-1];
        rightshift(q, temp,a[size-1],size);
        rightshift(a, temp,lasteleQ,size);
        cout<<"a=";
        traverse(a,size);
        cout<<"   q=";
        traverse(q,size);
        cout<<"   qo=";
        cout<<qo<<endl;
        n--;
    }
    // traverse(a,size);
    // traverse(q,size);
    cout<<endl;
    int res[2*size]={0};
    int i;
    for(i=0;i<size;i++){
        res[i]=a[i];
    }
    for(int j=0;j<size;j++){
        res[i]=q[j];
        i++;
    }
    traverse(res,2*size);
    cout<<endl;
    binaryToDecimal(res,2*size);
    
}
void decimalToBinary(int m[],int num, int size){
    int i=size-1;
    while(num>0){
        m[i]=num%2;
        num/=2;
        i--;
    }
}
int main() {
// 	int m[4]={0,1,1,1},q[4]={0,0,1,1};
	int m[6]={0},q[6]={0};
    cout<<"enter two number ";
    int a,b;
    cin>>a>>b;
    decimalToBinary(m,a,6);
    decimalToBinary(q,b,6);
    boothAlgo(m,q,6);
}
