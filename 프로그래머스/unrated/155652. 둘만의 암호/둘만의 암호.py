from string import ascii_lowercase

def solution(s, skip, index):
    answer = ''
    word = set(ascii_lowercase)
    word -= set(skip)
    word = sorted(word)

    dic_alpha = {alpha:idx for idx, alpha in enumerate(word)}
    
    for i in s:
        answer += word[(dic_alpha[i] + index) % len(word)]
    return answer