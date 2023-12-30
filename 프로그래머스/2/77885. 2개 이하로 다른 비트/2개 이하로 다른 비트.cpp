#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long int number : numbers) {
        if (number % 2 == 0) {
            answer.push_back(number + 1);
        }
        else {
            int cnt = 0;
            while ((number >> cnt) % 2) {
                cnt++;
            }
            answer.push_back(number + pow(2, cnt) - pow(2, cnt - 1));
        }
    }
    return answer;
}