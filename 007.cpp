typedef long long ll;

class Solution {
public:
    int reverse(int x) {
        ll tmp = abs((ll)x);
        ll ret = 0;
        while (tmp) {
            ret = ret * 10 + tmp % 10;
            if (ret > INT_MAX)
                return 0;
            tmp /= 10;
        }
            
        return (x>0)?(int)ret:(int)(-ret);
    }
};
