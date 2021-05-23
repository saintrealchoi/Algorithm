def solution(lottos, win_nums):
    answer = []
    tmp_num = [0 for _ in range(46)]
    count = 0
    z_count = 0
    
    for win in win_nums:
        tmp_num[win] = 1
    
    for num in lottos:
        if num == 0:
            z_count +=1
            continue
        if tmp_num[num] == 1:
            count += 1
            
    if count+z_count > 1:
        answer.append(7-(count+z_count))
    else:
        answer.append(6)
    
    
    if count > 1:
        answer.append(7-count)
    else:
        answer.append(6)
    
    return answer