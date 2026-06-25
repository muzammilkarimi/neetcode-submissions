class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0],curmin=1,curmax=1;
        for(int num:nums){
            int temp = num*curmax;
            curmax = max(max(num*curmax,num*curmin),num);
            curmin = min(min(temp,curmin*num),num);
            res  = max(res,curmax);
        }
        return res;
    }
};
