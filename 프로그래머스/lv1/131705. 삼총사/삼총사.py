def solution(num):
    answer = 0
    size = len(num)
    for i in range(size):
        for j in range(i + 1, size):
            for k in range(j + 1, size):
                if num[i] + num[j] + num[k] == 0:
                    print(i, j, k)
                    answer += 1
    return answer