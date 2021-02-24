#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)//试除法，判定n是否为素数
{
    if(n<2)
        return false;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int vis[100005];//合数标记
void primes1(int n)//eratosthenes筛法
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;++i)
    {
        if(vis[i])
            continue;
        for(int j=i;j<=n/i;++j)
            vis[i*j]=1;
    }
}
int v[100005];//最小质因子
int prime[100005];//存质数
void primes2(int n)//线性筛法
{
    memset(v,0,sizeof(v));
    int m=0;//最后结果为质数个数
    for(int i=2;i<=n;++i)
    {
        if(v[i]==0)//i是质数
        {
            v[i]=i;
            prime[++m]=i;
        }
        for(int j=1;j<=m;++j)
        {
            if(prime[j]>v[i]||prime[j]>n/i)
                break;
            v[i*prime[j]]=prime[j];
        }
    }
    
}
int main()
{
    return 0;
}
