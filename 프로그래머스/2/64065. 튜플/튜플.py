def solution(s):
    numbers = []
    string = s.replace("{","").strip().split("}")
    string = list(filter(None, string))
    
    for sentence in string:
        tmp = list(filter(None, sentence.split(",")))
        tmp = list(map(int, tmp))
        numbers.append(tmp)
    
    numbers.sort(key = lambda x : len(x))
    answer = []
    for number in numbers:
        for contain in number:
            if contain not in answer:
                answer.append(contain)
    
    return answer