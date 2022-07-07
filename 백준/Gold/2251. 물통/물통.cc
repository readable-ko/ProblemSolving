#include <iostream>
#include <queue>
#include <algorithm>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std ;
bool visited[201][201][201] ;
int a, b, c ;

typedef struct water
{
    int A ;
    int B ;
    int C ;

    water(int a, int b, int c)
    {
        A = a, B = b, C = c ;
    }

}Water ;

queue<water> que ;

void CheckWater(int x, int y, int z)
{
    if(!visited[x][y][z])
    {
        visited[x][y][z] = 1 ;
        que.push(water(x,y,z)) ;
    }
}

int main()
{
    SETTING ;
    cin >> a >> b >> c ;
    que.push(water(0,0,c)) ;
    visited[0][0][c] = 1 ;
    vector<int> answer ;

    while(!que.empty())
    {
        water now = que.front() ;
        que.pop() ;

        if(now.A == 0) answer.push_back(now.C) ;

        //C -> B
        (b - now.B >= now.C) ? CheckWater(now.A, now.B + now.C, 0) 
        : CheckWater(now.A, b, now.C - b + now.B) ;

        //C -> A
        (a - now.A >= now.C) ? CheckWater(now.A + now.C, now.B, 0)
        : CheckWater(a, now.B, now.C - a + now.A) ;
        
        //B -> C
        (c - now.C >= now.B) ? CheckWater(now.A, 0, now.B + now.C)
        : CheckWater(now.A, now.B - c + now.C, c) ;
        
        //B -> A
        (a - now.A >= now.B) ? CheckWater(now.A + now.B, 0, now.C)
        : CheckWater(a, now.B - a + now.A, now.C) ;
        
        //A -> C
        (c - now.C >= now.A) ? CheckWater(0, now.B, now.A + now.C)
        : CheckWater(now.A - c + now.C, now.B, c) ;
        
        //A -> B
        (b - now.B >= now.A) ? CheckWater(0, now.A + now.B, now.C)
        : CheckWater(now.A - b + now.B, b, now.C) ;
    }

    sort(answer.begin(), answer.end()) ;
    for(auto it : answer)
        cout << it << " " ;
}