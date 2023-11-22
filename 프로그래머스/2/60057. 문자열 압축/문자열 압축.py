def solution(s):
    answer = len(s)
    for jump in range(1, (len(s) // 2) + 1):
        cnt = 1
        sub_str = s[:jump]
        changed_str = ""
        for idx in range(jump, len(s) + jump, jump):
            if sub_str == s[idx : idx + jump]:
                cnt += 1
            else:
                if cnt != 1:
                    changed_str += str(cnt)
                changed_str += sub_str
                sub_str = s[idx : idx + jump]
                cnt = 1

        answer = min(answer, len(changed_str))
    return answer