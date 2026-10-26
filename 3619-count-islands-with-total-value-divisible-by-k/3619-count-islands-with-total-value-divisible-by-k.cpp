class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int MOD) {
        int Row = grid.size();
        int Col = grid[0].size();

        vector<vector<int>> vis(Row, vector<int>(Col, false));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        auto bfs = [&](int r, int c)->bool{
            long long cnt = grid[r][c];

            queue<pair<int, int>> q;
            q.push({r, c});
            vis[r][c] = true;

            while(!q.empty()){
                auto [r, c] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if((0 <= nr && nr < Row) && (0 <= nc && nc < Col)){
                        if((grid[nr][nc] == 0) || vis[nr][nc]) continue;
                        else{    
                            cnt += (1LL*grid[nr][nc]);
                            q.push({nr, nc});
                            vis[nr][nc] = true;
                        }
                    }
                }
            }

            return (cnt % (1LL*MOD) == 0);
        };

        int res = 0;

        for(int i = 0; i < Row; i++){
            for(int j = 0; j < Col; j++){
                int k = (i << 16) | j;
                if(vis[i][j] || grid[i][j] == 0) continue;
                res += (bfs(i, j) ? 1 : 0);
            }
        }

        return res;
    }
};