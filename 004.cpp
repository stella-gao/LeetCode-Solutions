class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        vector<int> C;
        int pa = 0, pb = 0;    // point of A & B
        int m=A.size();
        int n=B.size();

        while (pa < m || pb < n) {
            if (pa == m) {
                C.push_back(B[pb++]);
                continue;
            }
            if (pb == n) {
                C.push_back(A[pa++]);
                continue;
            }
            if (A[pa] > B[pb])
                C.push_back(B[pb++]);
            else
                C.push_back(A[pa++]);
        }
        if ((n + m)%2==1)
            return C[(n+m)/2];
        else
            return (C[(n+m)/2 - 1] + C[(n+m)/2]) / 2.0;
    }
};

