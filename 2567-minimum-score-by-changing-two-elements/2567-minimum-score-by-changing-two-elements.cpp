class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n <= 3) return 0;
        
        int r1 = abs(nums[2] - nums[n-1]);
        int r2 = abs(nums[n-2] - nums[1]);
        int r3 = abs(nums[n-3] - nums[0]);
        return min(r1, min(r2, r3));
    }
};