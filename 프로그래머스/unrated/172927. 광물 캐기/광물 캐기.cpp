#include <bits/stdc++.h>
using namespace std;

class mineral
{
public:
    int d_ ;
    int i_ ;
    int s_ ;
    mineral(){d_ = 0, i_ = 0, s_ = 0;}
    mineral(int d, int i, int s){d_ = d, i_ = i, s_ = s;}
};

struct comp
{
    bool operator()(mineral a, mineral b)
    {
        if(a.d_ == b.d_ && a.i_ == b.i_) return a.s_ < b.s_ ;
        else if(a.d_ == b.d_) return a.i_ < b.i_ ;
        else return a.d_ < b.d_ ;
    }
};


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int total = picks[0] + picks[1] + picks[2];
    priority_queue<mineral, vector<mineral>, comp> pq ;
    
    for(int i = 0 ; i < minerals.size() ; i+=5) {
        mineral sum = mineral() ;
        if(total == 0) break ;
        
        for(int j = i ; j < i + 5 && j < minerals.size() ; j++)
            if(minerals[j] == "diamond") sum.d_++ ;
            else if(minerals[j] == "iron") sum.i_++ ;
            else sum.s_++ ;
        
        total-- ;
        pq.push(sum) ;
    }
    
    for(int i = 0 ; i < 3 ; i++)
    {
        while(picks[i] > 0 && !pq.empty())
        {
            mineral m = pq.top() ; pq.pop() ;
            
            answer += (m.d_ * pow(5, i)) + (m.i_ * pow(5, (i >> 1))) + (m.s_ * pow(5, (i >> 2)));
            picks[i]-- ;
        }
    }
    return answer;
}

//일단 광물의 갯수를 곡갱이 갯수로 한정시켜놓고 (그럴 필요도 없을 듯)
//5개씩 묶어서 다이야가 가장 많은 곳에 다이야 곡갱이 가장 만만한 곳에 돌 곡갱이를 두자
//그냥 pq쓰면 될 거 같은디?