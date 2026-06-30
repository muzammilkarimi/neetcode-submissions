class Solution {
public:
    int solve(int i, bool buy, vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int cool = solve(i+1,buy,prices,dp);
        if(buy){
            int buying = solve(i+1,!buy,prices,dp)-prices[i];
            return dp[i][buy]=max(buying, cool);
        }
        else{
            int sell = solve(i+2,!buy,prices,dp) + prices[i];
            return dp[i][buy] = max(sell, cool);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,true,prices,dp);
    }
};
