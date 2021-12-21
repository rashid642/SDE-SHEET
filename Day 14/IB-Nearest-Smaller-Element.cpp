vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> res(A.size());
    for(int i=0; i<A.size(); i++){
        while(!st.empty() && st.top()>=A[i])
            st.pop();
        if(st.empty()){
            res[i]=-1;
        }else{
            res[i]=st.top();
        }
        st.push(A[i]);
    }
    return res;
}