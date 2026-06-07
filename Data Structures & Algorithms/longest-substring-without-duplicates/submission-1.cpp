class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,-1);
        int last = 0,ans = 0;
        for(int i=0;i<s.size(); i++){
            if(map[s[i]] != -1) last = max(last,map[s[i]]+1);
            map[s[i]]=i;
            ans = max(ans,i-last+1);
        }
        return ans;
    }
};
