class Solution {
public:
    int maxArea(vector<int> &height) {
        int lpoint = 0, rpoint = height.size() - 1;
        int area = 0;
        while (lpoint < rpoint) {
            area = max(area, min(height[lpoint], height[rpoint]) *
                    (rpoint - lpoint));
            if (height[lpoint] > height[rpoint])
                rpoint--;
            else
                lpoint++;
        }
        return area;
    }
};
