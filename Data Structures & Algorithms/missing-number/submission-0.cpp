class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorofnums = 0, xorofn = 0;
        for(int i = 0; i<=nums.size(); i++) xorofn^=i;
        for(int i = 0; i<nums.size(); i++) xorofnums^=nums[i];
        return xorofn^xorofnums;
    }
};
