class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem(n);
        for(int i = 0; i < n; i++){
            rem[i] = nums[i] % k;
        }

        int res = 0;
        int l = 0; int r = 1;
        while(r < n){
            if(rem[l] != rem[r]){
                int s = r - l;
                while((s-1)*rem[l] % k != 0) s--;
                res = max(res, s);
                l = r;
            }
            r++;
        }

        int s = r - l;
        while((s-1)*rem[l] % k != 0) s--;
        res = max(res, s);

        return res;
    }
};