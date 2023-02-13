/**
 * @file 2149.cpp
 * @author fpqpsxh
 * @brief 배수라고만 알려줘서 당황스러웠는데 그냥 키로 나눴을 때 몫만큼 가지면 되겠지 싶었다.
 * 벡터에 순서대로 넣고 그 벡터의 키 값을 따로 저장하고 키 값 순서대로 찾으면 될 듯했다.
 * break 안넣어서 틀렸다...
 * @date 2023-02-13
 */
#include <bits/stdc++.h>
using namespace std ;
string key, sorted_key, value ;
bool checker[10] ;
vector<string> pw ;
int value_sz ;

void word_preprocessing()
{
    sorted_key = key ;
    sort(sorted_key.begin(), sorted_key.end()) ;
    value_sz = value.length() / key.length() ;

    for(int i = 0 ; i < value.length() ; i += value_sz)
        pw.push_back(value.substr(i, value_sz)) ;
}

void get_unsorted_matrix()
{
    vector<string> unsorted_pw ;

    for(int i = 0 ; i < key.length() ; i++)
        for(int j = 0 ; j < sorted_key.length() ; j++)
            if((key[i] == sorted_key[j]) && !checker[j])
            {
                checker[j] = 1 ;
                unsorted_pw.push_back(pw[j]) ;
                break ;
            }
    
    for(int c = 0 ; c < value_sz ; c++)
        for(int r = 0 ; r < unsorted_pw.size() ; r++)
            cout << unsorted_pw[r][c] ;
    
    cout << '\n' ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> key >> value ;

    word_preprocessing() ;
    get_unsorted_matrix() ;
}