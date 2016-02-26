class Solution {
public:
    bool match1char(const char * a, const char * b){
        return (*a==*b || (*b=='.' && *a!='\0'));
    }
 
    bool isMatch(const char * a, const char * b){
        if(*b=='\0') return *a=='\0';
        if(*(b+1)!='*'){
            if(match1char(a, b))
                return isMatch(a+1, b+1);
        }else{
            if(isMatch(a, b+2)) return true;
            while(match1char(a, b)){
                if(isMatch(++a, b+2)) return true;
            }
        }
        return false;
    }
 
    bool isMatch(string s, string p) {
        const char *a = s.c_str();
        const char *b = p.c_str();
        return isMatch(a, b);
    }
};
