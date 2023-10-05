#check_prime(n): 소수인지 판별 -> 에라토스테네스?, 제곱근?
#to_k_number(): k진수로 변경
#select_number(): k진수에서 조건에 맞는 숫자 채택
import math

class FindPrime:
    def __init__(self, n, k):
        self.n = n
        self.k = k
        self.new_n = ""
        self.answer = 0
        
    def to_k_number(self):
        self.new_n = ""
        while self.n > 0:
            self.new_n += str(self.n % self.k)
            self.n //= self.k
        self.new_n = self.new_n[::-1]
    
    def is_prime(self, num):
        if num == 1: return False
    
        for i in range(2,int(num ** 0.5) + 1):
            if num % i == 0: return False
        return True
        
    def split_number(self):
        nums = self.new_n.split("0")
        nums = [int(n) for n in nums if n]
        
        print(nums)
        for num in nums:
            if self.is_prime(num):
                self.answer += 1
                       
    def run(self):
        self.to_k_number()
        self.split_number()
        
        
        
def solution(n, k):
    fp = FindPrime(n, k)
    fp.run()
    
    return fp.answer