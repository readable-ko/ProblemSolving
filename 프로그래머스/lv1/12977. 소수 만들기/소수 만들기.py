def solution(nums):
    answer = 0
    is_sosu = [False for i in range(3001)]
    
    for i in range(2, len(is_sosu)):
        if is_sosu[i] == True:
            continue
            
        for j in range(i+i, len(is_sosu), i):
            is_sosu[j] = True

    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            for k in range(j+1, len(nums)):
                sosu = nums[i] + nums[j] + nums[k]
                if is_sosu[sosu] == False:
                    answer+=1
    return answer