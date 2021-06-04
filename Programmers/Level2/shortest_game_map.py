from collections import deque

def solution(maps):
    answer = 0 
    x_len,y_len = len(maps),len(maps[0])
    dx,dy = [0,0,1,-1],[1,-1,0,0]
    deq = deque([(0,0)])
    visit = [[0 for _ in range(y_len)] for _ in range(x_len)]
    visit[0][0] = 1
    
    while(deq):
        x, y = deq.popleft()
        if x == x_len-1 and y == y_len-1:
            return visit[x][y]
        for i in range(4):
            next_x,next_y = x+dx[i], y+dy[i]
            if 0<=next_x<x_len and 0<=next_y<y_len and visit[next_x][next_y]==0 and maps[x][y]==1:
                visit[next_x][next_y] = visit[x][y]+1
                deq.append((next_x,next_y))
    return -1