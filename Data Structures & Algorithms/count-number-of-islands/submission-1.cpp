class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    count++;
                    findisland(grid, i, j);
                }
            }
        }
        return count;
    }

    void findisland(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        for(auto d : dirs){
            int i = row+d[0];
            int j = col+d[1];
            if(i >=0 && i<grid.size() && j>=0 && j<grid[0].size()&&grid[i][j] == '1'){
                findisland(grid, i, j);
            }
        }
    }
};
