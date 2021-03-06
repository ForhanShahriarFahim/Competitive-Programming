#include <bits/stdc++.h>
using namespace std;
int mark[3000];
int ans[1001];
void Sieve()
{
  for(int i=2;i<3000;++i)
    if(!mark[i])
      for(int j=2;j*i<3000;++j)
        mark[i*j]++;
  for(int i=0,j=0;i<3000 && j<=1000;++i)
    if(mark[i]>=3)
      ans[j++]=i;
}
int main() {
  int t,n;
  Sieve();
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    printf("%d\n",ans[n-1]);
  }
  return 0;
}
