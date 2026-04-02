class Solution {
public:
    void solve(int i, int j, int n, int &count, string s){
        while(i>=0 and j<n and s[i]==s[j]){
            count++;
            i--,j++;
        }
        
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count=0;
        for(int i=0; i<n; i++){
            solve(i,i,n,count,s);
            solve(i,i+1,n,count,s);
        }
        return count;
    }
};
