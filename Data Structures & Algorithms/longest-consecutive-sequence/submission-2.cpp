class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int n:nums) st.insert(n);
        int ans=0;
        for(int n:st){
            int count=0;
            int i=n;
            if(st.find(n-1)==st.end()){
                while(st.find(i)!=st.end()){
                    i++;
                    count++;
                }
            }
            ans = max(ans,count);
        }
    return ans;
    }
};
