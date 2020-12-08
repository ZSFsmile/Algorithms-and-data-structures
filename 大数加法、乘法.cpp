#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>a,vector<int>b)//加法
{
	vector<int>res;
	int lena=a.size();
	int lenb=b.size();
	int lenr=max(lena,lenb);
	int carry=0;
	for(int i=0;i<lenr;++i)
	{
		int temp=0;
		if(i<lena)
            temp+=a[i];
        if(i<lenb)
            temp+=b[i];
        temp+=carry;
        res.push_back(temp%10);
        carry=temp/10;
	}
	if(carry)
        res.push_back(carry);
    return res;
}
vector<int> mul(vector<int>a,vector<int>b)//乘法
{
    vector<int>res;
    res.push_back(0);
    int lena=a.size();
    int lenb=b.size();
    for(int i=0;i<lena;++i)
    {
        int carry=0;
        vector<int>temp;
        for(int j=0;j<i;++j)
            temp.push_back(0);
        for(int j=0;j<lenb;++j)
        {
            int bit=b[j]*a[i];
            bit+=carry;
            temp.push_back(bit%10);
            carry=bit/10;
        }
        if(carry)
            temp.push_back(carry);
        res=add(res,temp);
    }
    return res;
}
int main()
{
    char A[1005],B[1005];//A与B运算
    vector<int>a,b;
    cin>>A>>B;
    int len=strlen(A);
    for(int i=len-1; i>=0; --i)
    {
        a.push_back(A[i]-'0');
    }
    len=strlen(B);
    for(int i=len-1; i>=0; --i)
    {
        b.push_back(B[i]-'0');
    }
    vector<int>ans1=add(a,b);
    len=ans1.size();
    for(int i=len-1;i>=0;--i)
        printf("%d",ans1[i]);
    cout<<'\n';
    vector<int>ans2=mul(a,b);
    len=ans2.size();
    for(int i=len-1;i>=0;--i)
        printf("%d",ans2[i]);
	return 0;
}
