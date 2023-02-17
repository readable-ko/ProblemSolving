#include <stdio.h>
#include <string.h>

int main() {
  int m;// 이진수의 자리수
  char n[1000001];// 이진수
  int k;
  
  int c=0;
  scanf("%d",&m);
  scanf("%s",n);
  scanf("%d",&k);
  if(k > m) k = m ;
  for(int i=0;i<k;i++){
    if(n[m-1-i]!='0'){//n의 가장 뒷자리부터
                      //k자리까지 '0'인지 확인
      c=1;            // 아니면 c=1
      break;
    }
  }
  if(c==0){       
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}