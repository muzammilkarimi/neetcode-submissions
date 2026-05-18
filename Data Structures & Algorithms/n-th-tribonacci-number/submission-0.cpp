class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int one = 1, two = 1, three = 2;
        if(n==3) return 2;
        for(int i=4; i<=n; i++){
            int temp = one + two + three;
            one = two;
            two = three;
            three = temp;
        }
        return three;
    }
};