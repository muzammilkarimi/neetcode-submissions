class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1; i<=n; i++){
            if(s1[i-1]==s3[i-1] and dp[i-1][0])
                dp[i][0]= true;
            else dp[i][0]=false;
        }
        for(int i = 1; i<=m; i++)
            if(s2[i-1]==s3[i-1] and dp[0][i-1])
                dp[0][i]=true;
            else dp[0][i]=false;
        

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j]=(s1[i-1]==s3[i+j-1] and dp[i-1][j]) or
                        (s2[j-1]==s3[i+j-1] and dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};