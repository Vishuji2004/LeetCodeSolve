class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto m = min_element(nums.begin(), nums.end());
        auto M = max_element(nums.begin(), nums.end());

        int lD = max(m - nums.begin(), M - nums.begin()) + 1;
        int rD = max(nums.end() - m, nums.end() - M);

        int fB1 = (M - nums.begin() + 1) + (nums.end() - m);
        int fB2 = (m - nums.begin() + 1) + (nums.end() - M);

        return min(lD, min(rD, min(fB1, fB2)));
    }
};