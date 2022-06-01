#include <bits/stdc++.h>
int A,B,V,C;int main(){std::cin>>A>>B>>V;V-=A;C+=ceil((double)V/(A-B));std::cout<<++C;}