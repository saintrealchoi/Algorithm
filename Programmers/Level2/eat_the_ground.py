def solution(land):
    for i in range(1,len(land)):
        a,b,c,d = land[i-1][0],land[i-1][1],land[i-1][2],land[i-1][3]
        for j in range(4):
            if j == 0:
                land[i][j] += max(b,c,d)
            elif j == 1:
                land[i][j] += max(a,c,d)
            elif j == 2:
                land[i][j] += max(a,b,d)
            else:
                land[i][j] += max(a,b,c)
    
    return max(land[len(land)-1])