class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int n:nums) sum+=n;
        if(sum%2!=0) return false;
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        for(int n:nums){
            for(int i=sum/2; i>=n; i--){
                dp[i]=dp[i] or dp[i-n];
                if(dp[sum/2]) return true;
            }
        }
        return false;
    }
};
