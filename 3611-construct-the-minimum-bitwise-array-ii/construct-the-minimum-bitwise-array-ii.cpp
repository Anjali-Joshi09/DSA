class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
            } else {
                int leadingOne = 1;
                while (num & leadingOne) {
                    leadingOne <<= 1;
                }
                leadingOne >>= 1;
                ans.push_back(num - leadingOne);
            }
        }
        return ans;
    }
};
