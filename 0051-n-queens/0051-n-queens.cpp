class Solution {
public:

    bool issafe(vector<string>& board, int row, int c, int n){
        for(int a=0; a<n; a++){
            if(board[row][a] == 'Q'){
                return false;
            }
            if(board[a][c] == 'Q'){
                return false;
            }
        }
        for(int a=row, b=c; a>=0 && b>=0; a--, b--){
            if(board[a][b] == 'Q') return false;
        }
        for(int a=row, b=c; a>=0 && b<n; a--, b++ ){
            if(board[a][b] == 'Q') return false;
        }
        return true;
    }

    void placeQueens(vector<string>& board, vector<vector<string>>& ans, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(issafe(board, row, i, n)){
                board[row][i] = 'Q';
                placeQueens(board, ans, row+1, n);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans; 
        placeQueens(board, ans, 0, n);
        return ans;
    }
};