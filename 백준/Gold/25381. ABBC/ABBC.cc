//This Code is written by gloryko fpqpsxh.
/**
 * 그냥 C앞에 B 갯수 세고 지워지지 않은 B를 체크해서 A 뒤에 몇개 있는지 세면 되는거 아냐?
 * 반례: BABC 2가 나와야하는데 그렇게하면 1이 나오지롱
 * 거꾸로 AB세고 BC 세면?
 * 반례: ABCB 2가 나와야하는데 1이 나오겠징
 * BC세고 AB세면 안되냐? 근데 그럼 bool로 체크 못하니까 B를 queue에 넣었다가 빼자.
 */
#include <iostream>
#include <queue>
using namespace std ;
bool check[300001] ;
int check_box, answer ;
string str ;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> str ;
    queue<int> que ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] == 'B') que.push(i) ;
        else if(str[i] == 'C' && !que.empty())
        {
            check[que.front()] = 1 ;
            que.pop() ;
            answer++ ;
        }
    }

    que = queue<int>() ; check_box = 0 ;
    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] == 'A') check_box++ ;
        else if(str[i] == 'B' && check_box && !check[i])
        {
            check[i] = 1 ;
            check_box-- ;
            answer ++ ;
        }
    }

    cout << answer ;
}