#미쳤다 스택쓸 생각 어케 하냐 .
def solution(numbers):
    answer = [-1 for _ in range(len(numbers))]
    st = []
    for idx, num in enumerate(numbers):
        while len(st) != 0 and st[-1][1] < num:
            top = st.pop()
            answer[top[0]] = num
        st.append([idx, num])
    return answer