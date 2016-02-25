class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        int step = nRows * 2 - 2, len = s.length();
        string ret = "";
        // first row
        for (int i = 0; i < len; i += step)
            ret += s[i];
        
        // middle rows    
        for (int i = 1; i < nRows - 1; i++) {
            for (int j = i; j < len; j += step) {
                ret += s[j];
                if (j + (step - i * 2) < len)
                    ret += s[j + (step - i * 2)];
            }
        }
        
        // last row
        for (int i = nRows - 1; i < len; i += step)
            ret += s[i];
        return ret;
    }
};
