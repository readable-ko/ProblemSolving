#include <bits/stdc++.h>
#define SETTING ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string condition, arr;
vector<int> num_arr;
int sp, ep, * curr, countD = 0 ;


int MakeAnswer()
{
   sp = 0, ep = num_arr.size() - 1;
   curr = &sp;
   if (num_arr.empty()) return 1;

   for (int i = 0; i < condition.length(); i++)
   {
      if (condition[i] == 'R') curr == &sp ? curr = &ep : curr = &sp;
      else curr == &sp ? (*curr)++ : (*curr)--;
      if (sp > ep) return 1;
   }
   return 0;
}

void CasePrinter(int sp, int ep, bool type)
{
   cout << "[";
   for (int i = sp; i != ep; )
   {
      cout << num_arr[i];
      if (i != ep) cout << ",";
      type == true ? i++ : i--;
   }
   cout << num_arr[ep];
   cout << "]\n";
}

void PrintAnswer()
{
    if(MakeAnswer()) cout << "[]\n" ;
    else if (curr == &sp) CasePrinter(sp, ep, 1);
    else CasePrinter(ep, sp, 0);
}


void InputSetting()
{
   condition = "", arr = "";
   cin >> condition >> ep >> arr;
   string temp = "";
   num_arr.clear();
   countD = 0 ;

   for(int i = 0 ; i < condition.length() ; i++)
      if(condition[i] == 'D') countD++ ;
   
   for (int i = 1; i < arr.length(); i++)
   {
      if (isdigit(arr[i])) temp.push_back(arr[i]);
      else {
         if (temp.empty()) break;
         num_arr.push_back(stoi(temp));
         temp = "";
      }
   }
}

int main()
{
   int T;
   cin >> T;
   
   for (int i = 0; i < T; i++)
   {
      InputSetting();
      if(countD > num_arr.size()) cout << "error\n";
      else PrintAnswer();
   }
}