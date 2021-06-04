import re

def solution(str1, str2):
    answer = 0
    up = 0
    down = 0
    str1_dic = {}
    str2_dic = {}
    
    new_str1 = str1.upper()
    new_str2 = str2.upper()
    for i in range(len(new_str1)-1):
        if len(re.sub(r"[^a-zA-Z]","",new_str1[i:i+2])) != 2:
            continue
        str1_dic.setdefault(new_str1[i:i+2],0)
        str1_dic[new_str1[i:i+2]]+=1
        
    for i in range(len(new_str2)-1):
        if len(re.sub(r"[^a-zA-Z]","",new_str2[i:i+2])) != 2:
            continue
        str2_dic.setdefault(new_str2[i:i+2],0)
        str2_dic[new_str2[i:i+2]]+=1    
        
    for key,value in str1_dic.items():
        if str2_dic.get(key) != None:
            up += min(value,str2_dic[key])
            str2_dic[key] = max(value,str2_dic[key])
        else:
            str2_dic[key] = value
    
    for key,value in str2_dic.items():
        down += value
    
    if down == 0:
        return 65536
    answer = int(up/down * 65536)
        
    return answer