class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        if(st.size()<nums.size()) return true;
        return false;
    }
};