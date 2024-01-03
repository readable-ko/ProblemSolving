import re
def solution(s):
    mapping_table = {"one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9, "zero":0}
    for key, value in mapping_table.items():
        s = re.sub(key,str(value),s)
    return int(s)