class Solution {
public:
    bool isValid(int r,int c,char d,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=c && board[r][i]==d){
                return false;
            }
            if(i!=r && board[i][c]==d){
                return false;
            }
        }

        int start_i=(r/3)*3;
        int start_j=(c/3)*3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
               if ((start_i + k != r || start_j + l != c) &&
    board[start_i + k][start_j + l] == d) {
    return false;
}
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(i,j,board[i][j],board)) return false;
                }
            }
        }
        return true;
    }
};