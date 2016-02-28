class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (s.find(n) == s.end()) {
            s.insert(n);
            int sum = 0;
            while (n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
            if (n == 1) return true;
        }

        return false;
    }
};
