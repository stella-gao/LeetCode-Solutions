class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        for (char i : s)
            col = col * 26 + (i - 'A' + 1);
        return col;
    }
};
