#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10005];
void solve(int n)
{
    a[0]=a[n-1]=1;
    for(int i=1;i*2<n;++i)
    {
        a[i]=a[i-1]*(n-i)/i;
        a[n-i-1]=a[i];
    }
    for(int i=0;i<n;++i)
        cout<<a[i]<<' ';
}
int main()
{
    int n;
    cin>>n;//n为杨辉三角要求的那一行
    solve(n);
    return 0;
}
