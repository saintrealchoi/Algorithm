def solution(board):
    answer = 0
    
    row = len(board)
    column = len(board[0])
    
    if row ==1 and column ==1:
        return 1
    
    for i in range(1,row):
        for j in range(1,column):
            if board[i][j] != 0:
                up = board[i-1][j]
                left = board[i][j-1]
                upleft = board[i-1][j-1]
                board[i][j] = min(up,left,upleft) +1
                if answer < board[i][j]:
                    answer = board[i][j]

    return answer**2