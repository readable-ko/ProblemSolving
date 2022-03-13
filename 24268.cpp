#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int arr_length;

void check_bits(int year, int bits) {
    arr_length = 0;
    while(year) 
    {
        arr[year % bits] = true; year /= bits;
        arr_length++;
    }
}

bool check_exist(int bits)
{
    for(int i = 0 ; i < bits ; i++)
        if(!arr[i]) return false;
    return true;
}

int main() 
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int year, bits;
    cin >> year >> bits;

    while(true)
    {
        arr.assign(bits, 0);
        check_bits(++year, bits);
        if(arr_length > bits) 
        {
            cout << "-1\n"; break;
        }

        if(check_exist(bits)) 
        {
            cout << year << "\n"; break;
        }
    }
}