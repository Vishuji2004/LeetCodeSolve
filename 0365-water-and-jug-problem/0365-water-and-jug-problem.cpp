class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;

        vector<vector<int>> vis(x+1, vector<int>(y+1, false));

        auto bfs = [&](int i, int j)->bool{
            queue<pair<int, int>> q;
            vis[i][j] = true;
            q.push({i, j});

            while(!q.empty()){
                auto [px, py] = q.front(); q.pop();

                if(px + py == target) return true;

                vector<pair<int, int>> ss = {
                    {x, py}, {px, y}, {0, py}, {px, 0},
                    {min(x, px + py), max(0, (px + py - x))}, 
                    {max(0, px + py - y), min(y, px + py)}
                };

                for(auto [dx, dy] :ss){
                    if(vis[dx][dy] == false){
                        vis[dx][dy] = true;
                        q.push({dx, dy});
                    }
                }
            }

            return false;
        };

        return bfs(0, 0);
    }
};