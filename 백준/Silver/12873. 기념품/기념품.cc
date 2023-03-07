#include<bits/stdc++.h>
using namespace std ; 
int N, level = 1 ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    queue<int> people ;
    for(int i = 0 ; i < N ; i++)
        people.push(i+1) ;
    
    while(people.size() != 1)
    {
        long long int die = pow(level, 3) - 1 ;
        die = die % people.size() ;

        for(int i = 0 ; i < die ; i++)
        {
            int front = people.front() ;
            people.pop() ;
            people.push(front) ;
        }
        people.pop() ;
        level++ ;
    }
    cout << people.front() ;
}