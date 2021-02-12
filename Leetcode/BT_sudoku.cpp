class Solution
{
public:
    bool check(vector<vector<char>>& board, int row, int col, char c)
    {
        // column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        // row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
        }

        // matrix
        int init_row = row / 3 * 3;
        int init_col = col / 3 * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[init_row + i][init_col + j] == c) {
                    return false;
                }
            }
        }
        return true;
    }
    void backTracking(vector<vector<char>>& board, vector<vector<char>>aux, int row, int col)
    {
        // answer!
        if (row == 9) {
            board = aux;
            return;
        }

        int next_row, next_col;

        // change line
        if (col == 8) {
            next_row = row + 1;
            next_col = 0;
        }
        else {
            next_row = row;
            next_col = col + 1;
        }

        // find blank
        if (aux[row][col] != '.') {
            backTracking(board, aux, next_row, next_col);
        }
        else {
            for (char c = '1'; c <= '9'; c++) {
                if (check(aux, row, col, c)) {
                    aux[row][col] = c;
                    backTracking(board, aux, next_row, next_col);
                    aux[row][col] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        vector<vector<char>>aux = board;
        backTracking(board, aux, 0, 0);
    }
};