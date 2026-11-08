class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size(); int C = grid[0].size();
        vector<int> row(C, 0);
        vector<int> col(R, 0);
        int cnt = 0;

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j]){
                    row[j]++;
                    col[i]++;
                }
            }
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j]){
                    cnt += (row[j] > 1 || col[i] > 1);
                }
            }
        }

        return cnt;
    }
};