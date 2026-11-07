class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        
        int l = 0; int r = 0;
        while(r < n){
            if(minK <= nums[r] && nums[r] <= maxK){
                r++;
            }else{
                long long t = 1LL*r - l;
                ans += (t*(t+1) / 2);
                l = r + 1;
                r = r + 1;
            }
        }
        long long t = 1LL*r - l;
        ans += (t*(t+1)/2);
        return ans;
    }
};