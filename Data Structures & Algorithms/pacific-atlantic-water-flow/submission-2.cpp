class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1},{0,-1}};
    void dfs(vector<vector<bool>>& oceans, int i, int j, vector<vector<int>>& heights){
        oceans[i][j] = true;
        for(auto d : dirs){
            int r = i+d[0];
            int c = j+d[1];
            if(r>=0 && r<oceans.size() && c>=0 && c<oceans[0].size() && heights[r][c] >= heights[i][j] && !oceans[r][c]) {
                dfs(oceans, r, c, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> alt(m, vector<bool>(n, false));
        for(int i=0; i<heights.size(); ++i){
            dfs(pac, i, 0, heights);
            dfs(alt, i, n-1, heights);
        }
        for(int j=0; j<heights[0].size(); ++j){
            dfs(pac, 0, j, heights);
            dfs(alt, m-1, j, heights);
        }
        vector<vector<int>> ans;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(pac[i][j] && alt[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;

    }
};
