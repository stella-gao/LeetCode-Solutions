/*
Problem Description:

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

*/

//0ms
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        int odd = 0;
        for(auto c:s){
            hash[c]++;
            if(hash[c]%2==1) odd++;
            else odd--;
        }
        return odd<2;
    }
};
