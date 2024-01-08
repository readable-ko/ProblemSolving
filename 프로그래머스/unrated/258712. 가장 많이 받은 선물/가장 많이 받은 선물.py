from collections import defaultdict 

def solution(friends, gifts):
    answer = 0
    history = defaultdict(int)
    index = defaultdict(int)
    
    for gift in gifts:
        dear, to = gift.split()
        history[dear] += 1
        history[to] -= 1
        history[gift] += 1
    
    for me in friends:
        willGot = 0
        for friend in friends:
            if me == friend:
                continue
            me2friend = me + " " + friend
            friend2me = friend + " " + me
            if history[me2friend] > history[friend2me]:
                willGot += 1
            elif history[me2friend] == history[friend2me]:
                if history[me] > history[friend]:
                    willGot += 1
        answer = max(answer, willGot)
    
    return answer