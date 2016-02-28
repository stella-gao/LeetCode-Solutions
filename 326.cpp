class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int k = log(INT_MAX)/log(3);
        int x = pow(3,k);
        return x%n==0;
    }
};
