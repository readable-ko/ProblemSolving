#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   int answer = 0;
   answer = n - lost.size();
   int i = 0;
   int j = 0;
   sort(lost.begin(), lost.end());
   sort(reserve.begin(), reserve.end());
   for (int k = 0; k < reserve.size(); ++k) {
      if (find(lost.begin(), lost.end(), reserve[k]) != lost.end()) {
         lost.erase(find(lost.begin(), lost.end(), reserve[k]));
         reserve.erase(reserve.begin() + k);
          ++answer;
          k=-1;
      }
   }

   while (i < lost.size() && !reserve.empty()) {
      if (j >= reserve.size()) {
         ++i; j = 0;
      }
      else if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1) {
         ++answer;
         lost.erase(lost.begin() + i);
         reserve.erase(reserve.begin() + j);
          i = 0; j = 0;
      }
      else {
         ++j;
      }

   }
   return answer;
}