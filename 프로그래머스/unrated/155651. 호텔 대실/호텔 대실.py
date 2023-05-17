def solution(book_time):
    answer = [0 for _ in range(1450)]
    for time in book_time:
        st = int(time[0][0:2]) * 60 + int(time[0][3:5])
        et = int(time[1][0:2]) * 60 + int(time[1][3:5])
        for i in range(st, et+10):
            answer[i] += 1

    return max(answer)