#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int check = -1;
    vector<int> bar;

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (!bar.empty())
                check = bar.back();
            if (board[j][moves[i]-1]) {
                bar.emplace_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                if (bar.back() == check) {
                    bar.pop_back();
                    bar.pop_back();
                    answer += 2;
                }
                break;
            }
            
        }
    }


    return answer;
}