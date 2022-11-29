/**
 * number 23306
 * @author fpqpsxh
 * @date 2022-11-22
 * @brief 비오길래 구글에 binary호남선 쳤다가 여기까지 왔따..
 * 인터렉티브를 처음 풀어봐서 난해하다. 다시보니 질문을 log2 (N)회 밖에 못하는데
 * 시작과 끝만 비교해서 올라간 횟수가 많은지 내려간 횟수가 많은지 확인할 수 있다.(00이나 11은 don't care이므로)
 */

#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std ;
int N, answer, sp, ep ;

int main()
{
    cin >> N ;
    cout << "? 1" << endl ;
    cin >> sp ;
    cout << "? " << N << endl ;
    cin >> ep ;
    
    if(sp == ep)
        cout << "! 0" << endl;
    else
        sp > ep ? cout << "! -1" << endl : cout << "! 1" << endl ;
}