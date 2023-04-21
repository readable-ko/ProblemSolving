def solution(ingredient):
    answer = 0
    st = []
    for i in ingredient:
        st.append(i)
        
        if len(st) > 3 and st[-4:] == [1,2,3,1]:
            for i in range(4):
                st.pop()
            answer += 1
    return answer