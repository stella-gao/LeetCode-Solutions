//#include<cctype>
class Solution {
public:
    int myAtoi(string str) {
        int ret = 0; int len = str.length();
        bool overflow = false;
        int sign = 1;    // default is '+'
        
        int i = 0;

        while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
            ++i;
        if (i == len)
            return 0;
        
        // get sign
        if (str[i] == '-') {
            ++i;
            sign = -1;
        } else if (str[i] == '+')
            ++i;

        while (i < len) {
            if (!isdigit(str[i]))
                break;
            if ((sign == 1 && ret > (INT_MAX - (str[i]-'0')) / 10) ||
                    (sign == -1 && -ret < (INT_MIN + (str[i]-'0')) / 10)) {
                overflow = true;
                break;
            }
            ret = ret * 10 + (str[i] - '0');
            ++i;
        }
        if (overflow)
            ret = (sign == 1) ?  INT_MAX : INT_MIN;
        else
            ret *= sign;
        return ret;
    }
};
