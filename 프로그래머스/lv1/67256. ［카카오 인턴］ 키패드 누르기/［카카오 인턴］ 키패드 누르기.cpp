#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int marking(int mark, int given) {
    int gmm = abs(given - mark);
    if(gmm == 0) return 0;
    else if(gmm == 1 || gmm == 3) return 1;
    else if(gmm == 2 || gmm == 4 || gmm == 6) return 2;
    else if(gmm == 5 || gmm == 7 || gmm == 9) return 3;
    else return 4;
}

bool markingcompare(int left, int right, int mark, string hand) {
    if(marking(mark, left) < marking(mark, right)) return true;
    else if(marking(mark, left) > marking(mark, right)) return false;
    else {
        if(hand == "right") return false;
        else return true;}
}

string solution(vector<int> numbers, string hand) {
    int Mark_Left = 10;
    int Mark_Right = 12;
    bool temp = true;
    string answer = "";
    for(int i = 0; i < numbers.size(); ++i) {
        if(numbers[i] == 0) numbers[i] = 11;
        switch (numbers[i]) {
            case 1:
            case 4:
            case 7: Mark_Left = numbers[i]; answer += 'L'; break;
            case 3:
            case 6:
            case 9: Mark_Right = numbers[i]; answer += 'R'; break;
            default: temp = markingcompare(Mark_Left, Mark_Right, numbers[i], hand);
                if(temp == true) {
                    Mark_Left = numbers[i];
                    answer += 'L';
                }else {
                    Mark_Right = numbers[i];
                    answer += 'R';
                } break;
        }
    }

    return answer;
}