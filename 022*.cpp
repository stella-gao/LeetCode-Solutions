// http://likemyblogger.blogspot.com/search?q=Generate+Parentheses


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(!n) return res;
        bt(res, n*2, "", 0, 0, 0);
    }
    void bt(vector<string> &res, int n, string cur, int pos, int nl, int nr){
        if(pos==n){
            res.push_back(cur);
        }else{
            if(nl>nr) bt(res, n, cur+")", pos+1, nl, nr+1);
            if(nl<n/2) bt(res, n, cur+"(", pos+1, nl+1, nr);
        }
    }
};

//////////////////////////

class Solution {
private:
    string tmp;
    void dfs(vector<string> &v, int pos, int n, int used) {
        if (pos == n * 2) {
            cout << tmp << endl;
            v.push_back(tmp);
            return;
        }
        if (used < n) {
            tmp.push_back('(');
            dfs(v, pos + 1, n, used + 1);
            tmp.pop_back();
        }
        if (used * 2 > pos) {
            tmp.push_back(')');
            dfs(v, pos + 1, n, used);
            tmp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0)
            return res;
        tmp = "";
        dfs(res, 0, n, 0);
        return res;
    }
};

