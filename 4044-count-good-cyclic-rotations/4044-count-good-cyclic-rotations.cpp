class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        vector<int> a(2 * n);

        for (int i = 0; i < 2 * n; i++)
            a[i] = nums[i % n];

        vector<long long> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++)
            prefix[i + 1] = prefix[i] + a[i];

        long long total = prefix[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = prefix[i + half] - prefix[i];
            long long right = total - left;

            if (left > right)
                ans++;
        }

        return ans;
    }
};