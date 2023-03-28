class Day:
    year = 0
    month = 0
    day = 0
    
    def __init__(self):
        self.year = 0
        self.month = 0
        self.day = 0
    
    def __init__(self, data):
        self.year = int(data[0])
        self.month = int(data[1])
        self.day = int(data[2])
    
    def add_day(self, possible_day):
        self.month += int(possible_day)
        return (self.year - 1) * 12 * 28 + (self.month - 1) * 28 + self.day

def solution(today, terms, privacies):
    answer = []
    d = Day(today.split('.'))

    terms_map = {}
    for i in terms:
        terms_map[i.split(' ')[0]] = i.split(' ')[-1]
    
    privacies_day = [Day(i.split(' ')[0].split('.')) for i in privacies]

    privacies_term = [i.split(' ')[-1] for i in privacies]
    
    for i in range(len(privacies_day)):
        now = d.add_day(0)
        data = privacies_day[i].add_day(terms_map[privacies_term[i]])

        if now >= data:
            answer.append(i+1)
        
    return answer