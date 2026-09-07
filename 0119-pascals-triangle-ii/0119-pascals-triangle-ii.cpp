class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for(int i = 0; i < rowIndex; i++){
            int n = i + 2;
            vector<int> nrow(n);
            for(int j = 0; j <= n/2; j++){
                int p = j-1;
                nrow[j] = (p < 0 ? 0 : row[p]) + (j < row.size() ? row[j] : 0);
                nrow[n-j-1] = nrow[j];
            }
            row = nrow;
        }
        return row;
    }
};