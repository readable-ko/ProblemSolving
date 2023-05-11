#include <bits/stdc++.h>
using namespace std;

bool comp(vector<string> a, vector<string> b)
{
    return stoi(a[1]) < stoi(b[1]) ;
}

//this function change time(string) to minutes(string)
//start time: st
string time2mm(string st)
{
    auto minute =  to_string(stoi(st.substr(0,2)) * 60 + stoi(st.substr(3,5)));
    return minute ;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<vector<string>> st ;
    
    for(auto &plan : plans)
        plan[1] = time2mm(plan[1]) ;
    
    sort(plans.begin() , plans.end(), comp) ;
    
    vector<string> tmp ;
    string str[] = {"LAST", "2000", "2000"} ;
    for(auto s : str)
        tmp.push_back(s);
    plans.push_back(tmp);

    for(int i = 0 ; i < plans.size() - 1 ; i++) {
        int now = stoi(plans[i+1][1]) - (stoi(plans[i][1]) + stoi(plans[i][2])) ;

        if(now >= 0) {
            answer.push_back(plans[i][0]) ;
            
            while(now > 0) {
                if(st.empty()) {
                    now = 0 ;
                    break ;
                }
                int top = stoi(st.top()[2]);
                if(now >= top) {
                    now -= top ;
                    answer.push_back(st.top()[0]) ;
                    st.pop() ;
                }
                else {
                    st.top()[2] = to_string(top - now) ;
                    now = 0 ;
                }
            }
        }
        else {
            plans[i][2] = to_string(-now) ;
            st.push(plans[i]);
        }
        
        // 1-1. 다음 것이 오기 전에 다 끝낸 경우 바로 정답에 넣기 O
        // 1-2. 남은 시간 없을 때까지 남는 시간 스택 맨 앞에꺼 시간 빼주기 O
        // 1-3. 만약 스택 위에꺼 다 했으면 빼고 다음 꺼 진행을 반복 O
        // 2-1. 다음 것이 오기 전에 다 못 끝낸 경우 스택 맨 위에 남은 시간으로 넣기
        // 3. for문 돌고나면 stack 빼주면서 정답 뒤에 넣기.
        /**
        근데 이거 큐에 맨 앞에꺼 처리하는게 너무 복잡해. 차라리 받은 내용을 좀 정리해보는게 어떨까?
        받자마자 name, start -> mm_start, playtime -> mm 으로 분리해서 정리해볼까?
        그러고 현재 curr_mm 으로 현재 몇분으로 지나고 있는지를 확인하는거지 어떄?
        */
    }
    while(!st.empty()) {
        answer.push_back(st.top()[0]);
        st.pop() ;
    }
    return answer;
}