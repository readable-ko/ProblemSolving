def solution(n, arr1, arr2):
    answer = []
    
    for idx in range(len(arr1)):
        bit_checker = (1 << n - 1)
        num1 = arr1[idx]
        num2 = arr2[idx]
        l = ""
        while bit_checker != 0:
            if num1 & bit_checker == bit_checker:
                l += "#"
            elif num2 & bit_checker == bit_checker:
                l += "#"
            else:
                l += ' '
            bit_checker = bit_checker >> 1
        answer.append(l)
    return answer