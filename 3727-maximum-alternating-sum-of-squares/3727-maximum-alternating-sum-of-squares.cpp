class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](int x){return abs(x);});
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());

        int k = (n+1)/2;
        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += (1LL*pq.top()*pq.top());
            pq.pop();
        }

        while(!pq.empty()){
            ans -= (1LL*pq.top()*pq.top());
            pq.pop();
        }

        return ans;
    }
};