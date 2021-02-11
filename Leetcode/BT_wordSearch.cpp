class Solution
{
public:
    bool backTracking(vector<vector<char>>& board, int row, int col, string& target, int index) {
        if (index == target.length() - 1) return true;

        char tmp = board[row][col];
        board[row][col] = '*';

        if (row + 1 < board.size() && target[index + 1] == board[row + 1][col]) {
            if (backTracking(board, row + 1, col, target, index + 1)) {
                return true;
            }
        }

        if (col + 1 < board[0].size() && target[index + 1] == board[row][col + 1]) {
            if (backTracking(board, row, col + 1, target, index + 1)) {
                return true;
            }
        }

        if (row - 1 >= 0 && target[index + 1] == board[row - 1][col]) {
            if (backTracking(board, row - 1, col, target, index + 1)) {
                return true;
            }
        }

        if (col - 1 >= 0 && target[index + 1] == board[row][col - 1]) {
            if (backTracking(board, row, col - 1, target, index + 1)) {
                return true;
            }
        }

        board[row][col] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int i, j;

        for (i = 0; i < board.size(); i++) {
            for (j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (backTracking(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};