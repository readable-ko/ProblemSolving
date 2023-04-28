def solution(numbers):
    answer = 0
    for x in range(10):
        if x not in numbers:
            answer += x
    return answer