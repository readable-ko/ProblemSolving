
/**
 * This Code is written by gloryko fpqpsxh.
 * @author fpqpsxh
 * @example 5 7 10 2 50 500 1 1 2
 * @example 500 30 10 50
 * @details 
 * 그룹이라면 앞 뒤 중에서 작은 값을 포함시켜 비교한 후 그 방향으로 넘기기
 * 짝수개의 그룹이라면 앞 뒤를 제외하고 
 * 차이가 적은 부서들을 이동시키는게 낫겠쥬? -> 복잡다. 따지지 말고 둘 다 해서 따져보자.
 * 근데 생각해보니까 어차피 이동하려면 인근에 있는 놈이랑 자리 바꿔줘야하는데 굳이 어디에 몇개를 저장해야하나?
 * 하나하나 생각해도 O(N)으로 풀리니까 그냥 바뀌는 순간을 저장하지 말자!
**/
#include <iostream>
#define MIN(A, B) ((A) < (B) ? (A) : (B))
using namespace std ;
int N, odd_even[2], answer[2], temp ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> temp ;
        temp = temp & 1 ;
        odd_even[temp]++ ;
        answer[temp] += odd_even[(temp ^ 1)] ;
    }

    cout << MIN(answer[0], answer[1]) ;
}