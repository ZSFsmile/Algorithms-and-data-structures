#include<bits/stdc++.h>
using namespace std;
int p[100005];//存质因子
int c[100005];//存质因子对应个数
void divide(int n)
{
    int m=0;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            p[++m]=i;
            c[m]=0;
            while(n%i==0)
            {
                n/=i;
                c[m]++;
            }
        }
    }
    if(n>1)
    {
        p[++m]=n;
        c[m]=1;
    }
    for(int i=1;i<=m;++i)
    {
        cout<<p[i]<<'^'<<c[i]<<endl;
    }
}
int main()
{
    divide(100);
    return 0;
}
