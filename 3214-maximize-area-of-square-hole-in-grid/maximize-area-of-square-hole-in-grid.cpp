class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 1;

        sort(arr.begin(), arr.end());

        int maxLen = 1, curr = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                curr++;
            } else if (arr[i] != arr[i - 1]) {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }

        return maxLen + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hGap = longestConsecutive(hBars);
        int vGap = longestConsecutive(vBars);

        int side = min(hGap, vGap);
        return side * side;
    }
};
