class Solution {
public:
    int minDistance(string w1, string w2) {
        int s1 = w1.size(), s2 = w2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,-1));
        dp[0][0]=0;
        for(int i=1; i<=s2; i++) dp[0][i]=i;
        for(int i=1; i<=s1; i++) dp[i][0]=i;
        for(int i=1; i<=s1; i++){
            for(int j=1; j<=s2; j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[s1][s2];
        
    }
};
