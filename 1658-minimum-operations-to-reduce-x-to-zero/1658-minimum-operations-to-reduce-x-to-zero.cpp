class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int tar = tot - x;

        if(tar == 0) return n;

        unordered_map<int, int> look;
        look[0] = -1;

        int s = 0; int ans = -1;
        for(int i = 0; i < n; i++){
            s += nums[i];
            int f = s - tar;

            if(look.contains(f)) ans = max(ans, i - look[f]);

            if(!look.contains(s)) look[s] = i;
        }

        return ans == -1 ? -1 : n - ans;
    }
};