#include <cstdio>
using namespace std ;
char a[50000000] ;

int main()
{
    int N = 0, i, temp ;
    long long sum = 0 ;
    printf(0b1111)
    fread(a, 1, sizeof(a), stdin) ;
    for(i = 0 ; a[i] != '\n' ; i++) N = N * 10 + (a[i] - 0x30) ;
    printf("%d\n", N) ;
    
    while(N--)
    {
        temp = 0 ;
        for(i++ ; a[i] != '\n' ; i++) temp = temp * 10 + (a[i] - 0x30) ;
        sum += temp ;
    }
    printf("%d\n", sum) ;
}
// inline int Converter()
// {
//     register int b = 0 ;
//     register char c ;
//     while((c = getchar()) != '\n')
//     {
//         b = (b*10) + c - 0x30 ;
//     }
//     return b ;
// }

// int main()
// {
//     register long long int a  = 0 ;
//     register int T = Converter() ;
//     printf("%d\n", T) ;
//     while(T--)
//     {
//         a += Converter() ;
//     }
//     printf("%d", a) ;
// }