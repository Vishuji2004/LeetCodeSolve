class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int id = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        while(id > 0 && nums[id-1] == target){
            res.push_back(id-1);
            id--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};