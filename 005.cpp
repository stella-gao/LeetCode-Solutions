/*
P[i,j]= 1, if i==j
      = (s[i]==s[j]),  if j=i+1
      = (s[i]==s[j]) && P[i+1][j-1],  if j>i+1

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        int P[len][len];
        memset(P,0,len*len*sizeof(int));
        int maxL=0, start=0, end=0;
        
        for(int j=0; j<len; j++){
            P[j][j]=1;
            for(int i=0; i<j; i++){
                P[i][j]=(s[i]==s[j] && (j-i<2 || P[i+1][j-1]));
                if(P[i][j] && maxL<(j-i+1)){
                    maxL=j-i+1;
                    start=i;
                    end=j;
                }
            }
        }
        
        return s.substr(start,end-start+1);
    }
};
