import copy
def rot(x1,y1,x2,y2,li):
    tmp_list=[li[x1-1][y1-1],li[x1-1][y2-1],li[x2-1][y2-1],li[x2-1][y1-1]]
    tmp_li = [li[x1-1][y1-1],li[x1-1][y2-1],li[x2-1][y2-1],li[x2-1][y1-1]]
    ret_li = copy.deepcopy(li)
    
    for i in range(y2-y1):
        if i == 0:
            li[x2-1][y2-2] = tmp_list[2]
            li[x1-1][y1] = tmp_list[0]
        else:
            li[x2-1][y2-i-2] = ret_li[x2-1][y2-i-1]
            tmp_li.append(li[x2-1][y2-i-2])
            li[x1-1][y1+i] = ret_li[x1-1][y1+i-1]
            tmp_li.append(li[x1-1][y1+i])
    
    for i in range(x2-x1):
        if i == 0:
            li[x1][y2-1] = tmp_list[1]
            li[x2-2][y1-1] = tmp_list[3]
        else:
            li[x1+i][y2-1] = ret_li[x1+i-1][y2-1]
            tmp_li.append(li[x1+i][y2-1])
            li[x2-i-2][y1-1] = ret_li[x2-i-1][y1-1]
            tmp_li.append(li[x2-i-2][y1-1])
            
    return tmp_li,li
    
def solution(rows, columns, queries):
    answer = []
    li = [[(i+1)+(j*rows) for i in range(columns)] for j in range(rows)]
    
    for i in range(len(queries)):
        tmp_li, li = rot(queries[i][0],queries[i][1],queries[i][2],queries[i][3],li)
        tmp_li.sort()
        answer.append(tmp_li[0])
        
    return answer