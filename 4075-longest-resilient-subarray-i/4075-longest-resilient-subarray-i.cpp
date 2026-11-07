class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int l = 0; int r = 1;
        int remL = nums[l] % k;

        while(r < n){
            int remR = nums[r] % k;
            if(remL != remR){
                int s = r - l;
                while((s-1)*remL % k != 0) s--;
                res = max(res, s);
                l = r;
                remL = remR;
            }
            r++;
        }

        int s = r - l;
        while((s-1)*remL % k != 0) s--;
        res = max(res, s);

        return res;
    }
};