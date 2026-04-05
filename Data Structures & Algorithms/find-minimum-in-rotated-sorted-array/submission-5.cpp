class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1,ans=0;
        if(nums.size()==2) return min(nums[0],nums[1]);
        while(l<=r){
            if(nums[l]<=nums[r]) return nums[l];
            else {
                int mid = l+(r-l)/2;
                if(nums[mid]<nums[mid-1] and nums[mid]<nums[mid+1]) return nums[mid];
                else if(nums[mid]>nums[r]) l=mid+1;
                else r=mid-1;
            }
        }
        return nums[0];
    }
};
