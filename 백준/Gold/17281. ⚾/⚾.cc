/**
 * @file 17281.cpp
 * @author fpqpsxh
 * @brief 그냥 N이 최대 50이고 9명의 타자가 치는 순서를 최대로 계산하면 8!로 약 4만번
 * 거기에 N번의 이닝을 생각하면 대략 200만번. 근데 최대 한 이닝에 타석이 3번 돈다고 생각하면
 * 600만번 차고 넘친다.
 * @date 2023-03-08
 */
#include <bits/stdc++.h>
using namespace std ;

int inning, answer ;
int order[10] ;
bool already[10] ;
vector< vector<int> > taza ;

int PlayBaseball()
{
    int tasuk = 1, sub_answer = 0 ;
    for(int i = 0 ; i < inning ; i++)
    {
        int out_count = 0 ;
        bool juja[4] = {0,} ;

        while(out_count != 3)
        {
            int now = taza[i][order[tasuk]] ;
            //이거 까먹었었다. 타석 도는거.
            tasuk == 9 ? tasuk = 1 : tasuk++ ;

            if(now == 0) out_count++ ;
            else
            {
                for(int i = 3 ; i > 0 ; i--)
                {
                    if(juja[i])
                    {
                        i + now > 3 ? sub_answer += 1 : juja[i + now] = 1 ;
                        juja[i] = 0 ;
                    }
                }
                //이것도.
                now > 3 ? sub_answer += 1 : juja[now] = 1 ;
            }
        }
    }
    return sub_answer ;
}

void SetTaza(int idx)
{
    if(idx == 4) idx++ ;
    if(idx == 10)
    {
        answer = max(answer, PlayBaseball()) ;
        return ;
    }

    for(int i = 1 ; i <= 9 ; i++)
        if(!already[i] && i != 1)
        {
            already[i] = 1 ;
            order[idx] = i ;
            SetTaza(idx + 1) ;
            already[i] = 0 ;
        }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> inning ;

    taza = vector< vector<int> >(inning, vector<int>(10)) ;
    for(int i = 0 ; i < taza.size() ; i++)
        for(int j = 1 ; j <= 9 ; j++)
            cin >> taza[i][j] ;
    
    already[1] = 1 ;
    order[4] = 1 ;
    SetTaza(1) ;
    cout << answer ;
}