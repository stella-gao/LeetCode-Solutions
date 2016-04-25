class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> dict, map;
        for(auto w:words) dict[w]++;
          
        int n1 = words[0].size();
        for(int i=0; i<n1; ++i){
            int start = i, cnt = 0, p = start; 
            map.clear();
            while(p + n1 <= s.size()){
                string ss = s.substr(p, n1);
                if(dict.count(ss)==0){
                    start = p+n1; 
                    cnt = 0; 
                    p = start; 
                    map.clear();
                }else{
                    map[ss]++;
                    cnt++;
                    while(map[ss]>dict[ss]){
                        map[s.substr(start, n1)]--;
                        cnt--;
                        start += n1;
                    }                    
                    if(cnt==words.size()) ret.push_back(start);
                    p += n1;
                }
            }
        }
        return ret;
    }
};
