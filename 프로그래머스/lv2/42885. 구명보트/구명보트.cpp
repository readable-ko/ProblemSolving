#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, index = 0;
    sort(people.begin(), people.end());
    int size = people.size();
    
    while(!people.empty() && index <= (size-1)/2) {
        if(&people[index] == &(people.back())) {
            answer++; break;
        }
        else if(people[index] + people.back() <= limit) {
            index++;
            answer++;
            if(&people[index] == &(people.back())) break;
            people.pop_back();
        } else {
            people.pop_back();
            answer++;
        }
    }
    return answer;
}