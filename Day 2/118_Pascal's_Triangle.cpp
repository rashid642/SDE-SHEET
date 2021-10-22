//Brute force

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> v1={1};
        vector<int> v2={1,1};
        v.push_back(v1);
        if(numRows==1){
            return v;
        }
        v.push_back(v2);
        if(numRows==2){ 
            return v;
        }
        
        cout<<v2[0]+v2[0]<<" "<<v2[1]+v2[1];
        for(int i=3;i<=numRows;i++){
            vector<int> v3;
            vector<int> tempvector=v[i-2];
            v3.push_back(1);
            for(int j=0;j<i-2;j++){
                int temp=tempvector[j]+tempvector[j+1];
                v3.push_back(temp);
            }
            v3.push_back(1);
            v.push_back(v3);
        }
        return v;
    }
};