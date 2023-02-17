#include <stdio.h>
#include <string.h>

int main() {
  int m;
  char n[1000001];
  int k;
  
  int c=0;
  scanf("%d",&m);
  scanf("%s",n);
  scanf("%d",&k);
  if(k > m) k = m ;
  for(int i=0;i<k;i++){
    if(n[m-1-i]!='0'){
      c=1; 
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