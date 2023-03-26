#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char** argv)
{
	int test_case ;
	int T = 10 ;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		int dump = 0, tmp ;
        int min_point = 100, max_point = 0 ;
        int box[101] = {0, } ;

        cin >> dump ;
        for(int i = 0 ; i < 100 ; i++)
        {
            cin >> tmp ;
            box[tmp]++ ;
            min_point = min(tmp, min_point) ;
            max_point = max(tmp, max_point) ;
        }

        while(dump--)
        {
            box[min_point]-- ;
            box[min_point + 1]++ ;
            box[max_point]-- ;
            box[max_point - 1]++ ;

            if(box[min_point] == 0) min_point++ ;
            if(box[max_point] == 0) max_point-- ;
            if(min_point == max_point) break ;
        }

        cout << "#" << test_case << " " << max_point - min_point << "\n" ;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}