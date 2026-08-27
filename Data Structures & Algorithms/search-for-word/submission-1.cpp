class Solution {
public:
    bool result = false;
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void findword(vector<vector<char>>& board, int r, int c, string word, int i){
        if(result)return;
        if(i == word.size()){result = true; return;}
        if(board[r][c] != word[i]) return;
        if(i==word.size()-1){result = true; return;}
        char ch = board[r][c];
        board[r][c]='*';
        for(auto d : dirs){
            int r1 = r + d.first;
            int c1 = c + d.second;
            if(r1>=0 &&r1<board.size()&&c1>=0&&c1<board[0].size()){
                findword(board, r1, c1, word, i+1);
            }
        }
        board[r][c] = ch;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j) {
                findword(board, i, j, word, 0);
            }
        }
        return result;
    }
};
