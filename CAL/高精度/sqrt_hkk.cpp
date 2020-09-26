#include <stdio.h>
#include <string.h>
#define Int(X) (X - '0')
char str[1005];
void sqrt_hkk(){
  int left, len, reslen, res[1005];
  double i, right, ans;
    len = strlen(str);
    if (len==1 && str[0]=='0') {
      printf("0\n");
      return ;
    }
    left = -len%2, right = 0, reslen = 0;
    if (len%2 == 1) ans = Int(str[0]);
    else ans = Int(str[0])*10 + Int(str[1]);
    while (1) {
      i = 0;
      while (i*(i+20*right) <= ans) ++i;
      --i;
      ans -= i*(i+20*right);
      right = right*10+i;
      res[reslen++] = (int)i;
      left += 2;
      if (left >= len) break;
      ans = ans*100+(double)(Int(str[left]))*10+(double)(Int(str[left+1]));
    }
    for (int j = 0; j < reslen; ++j) printf("%d", res[j]);
    printf("\n");
}
int main() {
  while (~scanf("%s", str)) {
    sqrt_hkk();
  }
  return 0;
}
