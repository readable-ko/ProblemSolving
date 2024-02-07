def to_days(date):
    year, month, day = map(int,date.split('.'))
    return (year - 1) * 12 * 28 + (month - 1) * 28 + day

def solution(today, terms, privacies):
    answer = []
    d_day = to_days(today)

    terms_map = {i.split(' ')[0]: int(i.split(' ')[-1]) for i in terms }
    
    for idx, it in enumerate(privacies):
        now = to_days(it.split(' ')[0]) + int(terms_map[it.split(' ')[-1]]) * 28
        if d_day >= now:
            answer.append(idx+1)
    return answer