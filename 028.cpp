class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())    return -1;
        if (needle.size() == 0)      return 0;
        int i=0;
        while(i+needle.size()-1<haystack.size()){
            if(haystack.substr(i, needle.size())==needle) return i;
            i++;
        }
        return -1;
    }
};
