class Solution {
public:
    // void solve(int sum, int n, int &ans){
    //     if(sum==n) {ans++; return ;}
    //     if(sum>n) return;
    //     solve(sum+1,n,ans);
    //     solve(sum+2,n,ans);
    // }
    int climbStairs(int n) {
        int one=1, two =1;
        for(int i=0; i<n-1; i++){
            int temp = one;
            one = one + two;
            two = temp;
        }  
        return one;
    }
};
