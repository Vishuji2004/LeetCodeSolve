class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<vector<int>> res(101);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            res[nums[i]].push_back(i);
        }
        return res[target];
    }
};