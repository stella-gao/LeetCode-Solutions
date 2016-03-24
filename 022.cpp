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
