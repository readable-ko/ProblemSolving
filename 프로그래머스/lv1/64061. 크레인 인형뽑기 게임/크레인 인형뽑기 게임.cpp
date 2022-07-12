#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
   vector<int> ans;
   int answer = 0;
   int mv =0;
   int j=0;
   int k = 0;

   for (int i = 0; i < moves.size(); ++i) {
      mv = moves[i] - 1;
      j = 0;
      while (j < board.size()) {
         if (board[j][mv] == 0) j++;
         else {
            ans.push_back(board[j][mv]);
            board[j][mv] = 0;
            break;
         }
      }
      
      if (ans.size() > 1) {
         while (k+1 < ans.size()) {

            if (ans[k] == ans[k + 1]) {
               ans.erase(ans.begin() + k);
               ans.erase(ans.begin() + k);
               k = 0;
               answer += 2;
            }
            else ++k;
         }
      }
   }

   return answer;
}