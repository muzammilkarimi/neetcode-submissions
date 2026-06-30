class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        int maxlen = 0;
        for(auto n:st){
            maxlen = max(maxlen,(int)n.size());
        }
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=max(0,i-maxlen);j--){
                if(dp[j] and st.find(s.substr(j,i-j))!=st.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
