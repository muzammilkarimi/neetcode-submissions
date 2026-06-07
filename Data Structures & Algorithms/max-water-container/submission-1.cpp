class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1,ans=0;
        while(l<r){
            ans = max(ans,(r-l)*min(heights[l],heights[r]));
            if(heights[r]>heights[l]) l++;
            else r--;
        }
        return ans;
    }
};
