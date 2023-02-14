/**
 * @file 2149.cpp
 * @author fpqpsxh
 * @brief N이 최대 1000개이므로 sort한 후 3개씩 슬라이딩 윈도우로 풀면 되지 않을까? (브루트포스)
 * 근데 그 슬라이딩해서 구한 것들 확인 우케할래? map으로 하자! --> 메모리 초과
 * 그럼 map 대신에 set을 쓰자 --> 시간 초과(생각해보니 N^3 logN 이네)
 * 답지 보고 다들 천재인가 싶었다 i + j + k = x라고 할 때 i + j를 저장한 배열에 x - k가 있는지 확인
 * @date 2023-02-14
 */
#include <bits/stdc++.h>
using namespace std ;
int N, maxima ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> arr(N) ;
    set<int> sum ;

    for(int &it : arr)
        cin >> it ;
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            sum.insert(arr[i] + arr[j]) ;
    
    for(int k = 0 ; k < N ; k++)
        for(int x = k ; x < N ; x++)
            if(sum.count(arr[x] - arr[k])) maxima = max(maxima, arr[x]) ;
    
    cout << maxima << '\n' ;

}