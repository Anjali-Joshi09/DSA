class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            if (num % 2 == 0) {
                ans.push_back(-1);
                continue;
            }
            int k = 0;
            while ((num >> k) & 1) {
                k++;
            }
            int x = num - (1 << k) + (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};
