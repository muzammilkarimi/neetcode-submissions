class Solution {
public:
    string solve(int i,int j, string s){
        while(i>=0 and j<s.size() and s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            string s1 = solve(i,i,s);
            string s2 = "";
            if(i<n-1 and s[i]==s[i+1]) s2 = solve(i,i+1,s);
            if(s1.size()<s2.size()) swap(s1,s2);
            if(ans.size()<s1.size()) swap(ans,s1); 
        }
        return ans;
    }
};
