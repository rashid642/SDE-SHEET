//Brute Force

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                int temp=prices[j]-prices[i];
                maxi=max(maxi,temp);
            }
        }
        return maxi;
    }
};

//Optimized, similar to kadane's algo

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX,profit=0;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            int temp=prices[i]-mini;
            profit=max(temp,profit);
        }
        return profit;
    }
};