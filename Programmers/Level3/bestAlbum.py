def solution(genres, plays):
    answer = []
    dict_p = {} 
    dic = {} 
    
    for i in range(len(genres)):
        dict_p[genres[i]] = dict_p.get(genres[i], 0) + plays[i]
        dic[genres[i]] = dic.get(genres[i], []) + [(plays[i], i)]
    
    genreSort = sorted(dict_p.items(), key = lambda x: x[1], reverse = True)
    
    for (genre, totalPlay) in genreSort:
        dic[genre] = sorted(dic[genre], key = lambda x: (-x[0], x[1]))
        answer += [idx for (play, idx) in dic[genre][:2]]
    
    return answer