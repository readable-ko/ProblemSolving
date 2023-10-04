import math
from collections import defaultdict

def hour_to_min(time):
    hour, minute = time.split(":")
    return int(hour) * 60 + int(minute)

def solution(fees, records):
    # 각 차량번호로 in out 기록
    # 각 차량번호로 요금 저장
    mp = dict()
    answer = defaultdict(int)
    
    # hour to min function
    def check_fee(time):
        stayed = time -fees[0]
        fee = fees[1]
        
        if stayed <= 0:
            return fee
        
        fee += (math.ceil(float(stayed) / fees[2]) * fees[3])
        return fee    
    
    # map으로 차량번호기준 나열
    for record in records:
        time, num, check = record.split(" ")
        
        if check == "IN":
            mp[num] = hour_to_min(time)
        else:
            answer[num] += hour_to_min(time) - mp[num]
            mp[num] = -1

    #안나간 놈 잡아라
    for key, val in mp.items():
        if val != -1:
            answer[key] += hour_to_min("23:59") - mp[key]
    
    sort_key = sorted([key for key in mp.keys()])
    answer = [check_fee(answer[key]) for key in sort_key]
    return answer