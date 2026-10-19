class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int sm = 0;
        int eq = 0;
        for(int x : nums){
            if(x < target) sm++;
            else if(x == target) eq++;
        }
        for(int i = sm; i < sm + eq; i++) res.push_back(i);
        return res;
    }
};