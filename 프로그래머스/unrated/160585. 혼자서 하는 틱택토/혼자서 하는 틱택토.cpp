#include <string>
#include <vector>
#include <map>
using namespace std;

bool lineEqual(char a, char b, char c) {
    return (a == b && a == c) ? true : false ;
}

int solution(vector<string> board) {
    int answer = 0 ;
    int circle = 0, cross = 0 ;
    for(string s : board)
        for(char c : s)
            if(c == 'O') circle++ ;
            else if(c == 'X') cross++ ;

    if(circle - cross < 0 || circle - cross > 1) return 0 ;
    
    map<char, int> mp;
    mp['O'] = 0 ;
    mp['X'] = 0 ;
    mp['.'] = - 30 ;
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
        {
            if(j == 1 && lineEqual(board[i][j], board[i][j-1], board[i][j+1]))
                mp[board[i][j]]++ ;
            if(i == 1 && lineEqual(board[i][j], board[i-1][j], board[i+1][j]))
                mp[board[i][j]]++ ;
            if(i == 1 && j == 1)
                if(lineEqual(board[i-1][j-1], board[i][j], board[i+1][j+1]) ||
                  lineEqual(board[i-1][j+1], board[i][j], board[i+1][j-1]))
                    mp[board[i][j]]++ ;
            
            if(mp[board[i][j]] > 2) return 0 ;
        }
    
    if(mp['O'] > 0 && mp['X'] > 0) return 0 ;
    if(mp['O'] > 0 && circle == cross) return 0;
    if(mp['X'] > 0 && circle > cross) return 0 ;
    return 1;
}