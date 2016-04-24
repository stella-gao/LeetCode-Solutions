typedef long long ll;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        ll a = abs((ll)dividend);
        ll b = abs((ll)divisor);
        
        ll res = 0, c = 0;

        while (a >= b) {
            c = b;
            for (int i = 0; a >= c; i++, c <<= 1) {
                a -= c;
                res += (1<<i);
            }
        }
        if (sign)   return max((ll)INT_MIN, -res);
        else        return min((ll)INT_MAX, res);
    }
};

