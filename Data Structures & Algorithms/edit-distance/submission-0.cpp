class Solution {
public:
    int solve(int s1,int s2, string w1, string w2,vector<vector<int>> &dp){
        if(s1<0) return s2+1;
        if(s2<0) return s1+1;
        if(dp[s1][s2]!=-1) return dp[s1][s2];
        if(w1[s1]==w2[s2]) return dp[s1][s2]=solve(s1-1,s2-1,w1,w2,dp);
        int insert = solve(s1,s2-1,w1,w2,dp);
        int del = solve(s1-1,s2,w1,w2,dp);
        int rep = solve(s1-1,s2-1,w1,w2,dp);
        return dp[s1][s2]= 1+min(del,min(insert,rep));
    }
    int minDistance(string w1, string w2) {
        int s1 = w1.size(), s2 = w2.size();
        vector<vector<int>> dp(s1,vector<int>(s2,-1));
        return solve(s1-1,s2-1,w1,w2,dp);
    }
};
