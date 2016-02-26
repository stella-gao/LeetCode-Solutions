class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> rec(26, 0);
        for (char i : s) {
            ++rec[i - 'a'];
        }
        for (char i : t) {
            if (--rec[i - 'a'] < 0)
                return false;
        }
        return s.length() == t.length();
    }
};
