const int N = 256;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxlen = 0, left = 0;
       vector<int> prev(N,-1);

       for (int i = 0; i < s.length(); i++) {
           if (prev[s[i]] >= left) {
               left = prev[s[i]] + 1;
           }
           prev[s[i]] = i;
           maxlen = max(maxlen, i - left + 1);
       }
       return maxlen;
    }
};
