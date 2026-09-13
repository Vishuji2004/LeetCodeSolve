class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        unordered_map<int, int> mp;
        int ans = 0;
        for(auto &x : ones1){
            for(auto &y : ones2){
                int dr = x.first - y.first;
                int dc = x.second - y.second;
                int key = dr*100 + dc;
                mp[key]++;
                ans = max(ans, mp[key]);
            }
        }

        return ans;
    }
};