/**
 * @file 1662.cpp
 * @author fpqpsxh
 * @brief 처음에 그냥 문자열 통으로 재귀에 넣고 괄호 맨 앞 '(' 랑 맨 뒤 ')' 이거랑 잘라서 다시 재귀에 넣어주는 형식을
 * 생각했는데 이러면 21(3)32(5) 이런케이스 커버를 못해... 망했네 어케푸냐..
 * 는 스택으로 그냥 담아버리고 ) 나올때까지 카운트해버리자 ( 나올때까지 빼고 뺀 갯수 세면 되겠네.
 * 스택도 같은거 커버 못하네 그냥 재귀를 다르게 만들자.
 * @date 2023-03-09
 */
#include <bits/stdc++.h>
using namespace std ;
string str ;
bool visited[51] ;

int ZipToInt(int idx)
{
    int char_to_number, answer = 0 ;
    for(int i = idx ; i < str.length() ; i++)
    {
        if(visited[i]) continue ;
        if(str[i] == '(')
        {
            visited[i] = 1 ;
            char_to_number = str[i-1] - '0' ;
            answer += char_to_number * ZipToInt(i + 1) - 1 ;
        }
        else if(str[i] == ')')
        {
            visited[i] = 1 ;
            return answer ;
        }
        else
        {
            visited[i] = 1 ;
            answer++ ;
        }
    }
    return answer ;
}

int main()
{
    cin >> str ;
    cout << ZipToInt(0) ;
}