def func(arg,end_n,pick_n,pos_n,pick_str):
    if pick_n == end_n:
        cand[end_n].setdefault(pick_str,0)
        cand[end_n][pick_str]+=1
        
        return
    
    if pos_n == len(arg):
        return
    
    func(arg,end_n,pick_n,pos_n+1,pick_str)
    func(arg,end_n,pick_n+1,pos_n+1,pick_str+arg[pos_n])
    return
        
        
def solution(orders, course):
    global cand
    answer = []
    cand = {}
    sort_order = []
    
    for order in orders:
        sort_order.append("".join(sorted(list(order))))
    
    for c in course:
        cand[c] = {}
        
        for order in sort_order:
            func(order,c,0,0,"")
    
    for c in course:
        max_value = 2
        for name,value in cand[c].items():
            max_value = max(max_value,value)
        for name,value in cand[c].items():
            if value == max_value:
                answer.append(name)
    
    return sorted(answer)