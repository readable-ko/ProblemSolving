/**
 * @file 1064.cpp
 * @author fpqpsxh
 * @brief 진짜 계속 틀렸다. 생각해보니 기울기는 양수 음수가 중요하다.
 * @date 2023-02-08
 */
#include <bits/stdc++.h>
using namespace std ;
double maxima, minima = 0x3f3f3f3f, dist_line ;

//X,Y좌표를 저장하기 위한 클래스
class point
{
    public:
    double x ;
    double y ;
};

//3개의 점이 모두 다른 위치에 있는지 확인
bool CheckDiff(point p1, point p2, point p3)
{
    if(p1.x == p2.x && p1.y == p2.y) return true ;
    if(p1.x == p3.x && p1.y == p3.y) return true ;
    if(p2.x == p3.x && p2.y == p3.y) return true ;
    return false ;
}

// 3점이 나란히 있는지 확인
bool CheckAngle(point p1, point p2, point p3)
{
    double angle1 = (p1.y - p2.y) * (p2.x - p3.x) ;
    double angle2 = (p2.y - p3.y) * (p1.x - p2.x) ;
    return angle1 == angle2 ;
}

// 점 p1과 p2 사이의 거리를 계산
double UclidDistance(point p1, point p2)
{
    double width = (p1.x - p2.x) ;
    double height = (p1.y - p2.y) ;
    return sqrt(width * width + height * height) ;
}

int main()
{
    point p[3] ;
    ios::sync_with_stdio(0), cin.tie(0) ;
    for(int i = 0 ; i < 3 ; i++)
        cin >> p[i].x >> p[i].y ;
    
    if(CheckDiff(p[0], p[1], p[2])) cout << "-1.0\n" ;
    else if(CheckAngle(p[0], p[1], p[2])) cout << "-1.0\n" ;
    else
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            dist_line = UclidDistance(p[i % 3], p[(i+1) % 3]) ;
            maxima = max(maxima, dist_line) ;
            minima = min(minima, dist_line) ;
        }
        cout << fixed ;
        cout.precision(10) ;
        cout << ((maxima - minima) * 2) << '\n' ;
    }

}