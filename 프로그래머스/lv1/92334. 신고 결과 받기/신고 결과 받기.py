def solution(id_list, reports, k):
    cnt = {}
    success = {}
    answer = []
    for id in id_list:
        cnt[id] = set()

    for report in reports:
        user = report.split(' ')
        cnt[user[1]].add(user[0])
        
    for user in cnt.keys():
        if len(cnt[user]) >= k:
            for re in cnt[user]:
                if success.get(re) == None:
                    success[re] = 1
                else:
                    success[re] += 1
    
    for id in id_list:
        if success.get(id) != None:
            answer.append(int(success[id]))
        else:
            answer.append(0)
    return answer