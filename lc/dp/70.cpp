class Solution {
    public:
        int climbStairs(int n){
            // fib sequence
            if(n <= 2) return n;
            return climbStairs(n-1) + climbStairs(n-2);
        }
}
