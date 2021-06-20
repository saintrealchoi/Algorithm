import re

def solution(info, query):
    answer = []
    score = []
    info_dic = {}
    
    for i in range(len(info)):
        tmp = re.split(" ",info[i])
        for j in range(4):
            try:
                info_dic[tmp[j]].append(i)
            except:
                info_dic[tmp[j]] = [i]
        score.append(tmp[-1])

    for i in range(len(query)):
        count = 0
        tmp = re.split(" and ",query[i])
        tmp2 = re.split(" ",tmp[-1])
        tmp.pop()
        tmp.append(tmp2[0])
        tmp.append(tmp2[1])
        
        ans_list = [0 for i in range(len(info))]
        for j in range(len(tmp)-1):
            if tmp[j] != '-':
                for k in info_dic[tmp[j]]:
                    ans_list[k] +=1
            else:
                for q in range(len(info)):
                    ans_list[q] +=1
        
        for j in range(len(ans_list)):
            if ans_list[j] == 4:
                if int(score[j]) >= int(tmp[-1]):
                    count+=1
            
        answer.append(count)
    
    return answer