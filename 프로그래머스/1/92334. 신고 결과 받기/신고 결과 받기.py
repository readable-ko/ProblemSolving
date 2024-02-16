from collections import defaultdict
def solution(id_list, report, k):
    reports = defaultdict(list)
    answer = [0 for _ in id_list]
    for r in set(report):
        give, gave = r.split()
        reports[gave].append(give)
    
    for r in reports:
        if len(reports[r]) >= k:
            for who in reports[r]:
                answer[id_list.index(who)] += 1
    return answer