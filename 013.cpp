class Solution {
private:
    int val[255];
    void init() {
        val['I'] = 1; val['V'] = 5; val['X'] = 10; val['L'] = 50;
        val['C'] = 100; val['D'] = 500; val['M'] = 1000;
    }
public:
    int romanToInt(string s) {
        init();
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && val[s[i]] > val[s[i - 1]]) {
                ret += val[s[i]] - 2 * val[s[i - 1]];
            } else {
                ret += val[s[i]];
            }
        }
        return ret;
    }
};

