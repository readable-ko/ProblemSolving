import re
from itertools import permutations
import operator

ops = {
    '+' : operator.add,
    '-' : operator.sub,
    '*' : operator.mul,
}
def calculate(d, o, choosen):
    new_digit = [d[0]]
    new_operator = []
    
    for idx in range(len(o)):
        if o[idx] == choosen:
            new_digit.append(ops[choosen](int(new_digit.pop()),int(d[idx+1])))
        else:
            new_digit.append(d[idx+1])
            new_operator.append(o[idx])
    return new_digit, new_operator

def solution(expression):
    answer = 0
    digit = re.findall("\d+", expression);
    oper = re.findall("\D+", expression);
    
    for prior in permutations(set(oper)):
        sub_digit = digit.copy()
        sub_operator = oper.copy()
        for expr in prior:
            sub_digit, sub_operator = calculate(sub_digit, sub_operator, expr)
        answer = max(answer, abs(sub_digit[0]))
    return answer