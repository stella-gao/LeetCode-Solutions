/*    Flip Game

Problem Description: You are playing the following Flip Game with your friend: Given a string that contains only these two characters: 
+ and -, you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]

If there is no valid move, return an empty list [].
*/

//0ms
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.size(), i = 0;
        vector<string> ret;
 
        while(i<n-1){
            if(s[i]=='+' && s[i+1]=='+'){
                string ss = s;
                ss[i]='-';
                ss[i+1]='-';
                ret.push_back(ss);
            }
            i++;
        }
        return ret;
    }
};
