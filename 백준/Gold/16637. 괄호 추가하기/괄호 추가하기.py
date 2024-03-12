import sys
import operator
import re

s_length = int(sys.stdin.readline())
expression = sys.stdin.readline()

func = {'*': operator.mul, '+': operator.add, '/': operator.mul, '-': operator.sub}
opd = list(map(int, re.findall("\\d", expression)))
opt = re.findall("\\D", expression)[:-1]
sp = opd.pop(0)
answer = []


def find(idx, val):
    if idx >= len(opt):
        answer.append(val)
        return

    find(idx + 1, func[opt[idx]](val, opd[idx]))
    if idx + 2 <= len(opt):
        find(idx + 2, func[opt[idx]](val, func[opt[idx + 1]](opd[idx], opd[idx + 1])))
    return


find(0, sp)
print(max(answer))