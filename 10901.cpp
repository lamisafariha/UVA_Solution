#include<stdio.h>
#include<queue>
#define min(a,b) (a<b ?a:b)
#define inf 2147483647
#define si 10010
using namespace std;
queue<long>qr,ql,qli,qri;
char ch[10];
long n,t,m,v,cst,fg,cnt,tst,a,b,chk[si],i,ind,u;
int main()
{
	scanf("%ld",&tst);
	while(tst--)
	{
		scanf("%ld%ld%ld",&n,&t,&m);
		a=b=inf;
		for(i=1;i<=m;i++)
		{
			scanf("%ld%s",&chk[i],ch);
			if(ch[0]=='l')
			{
				b=min(b,chk[i]);
				ql.push(chk[i]);
				qli.push(i);
			}
			else
			{
				a=min(a,chk[i]);
				qr.push(chk[i]);
				qri.push(i);
			}
		}
		if(a<b)
		{
			fg=0;
			cst=a+t;
		}
		else
		{
			fg=1;
			cst=b;
		}
		cnt=0;
		while(1)
		{
			if(fg)
			{
				if(ql.empty())
				{
					fg=cnt=0;
					if(!qr.empty())
					{
						u=qr.front();
						if(cst<u)
						{
							cst=u+t;
							continue;
						}
					}
					cst+=t;
				}
				else
				{
					v=ql.front();
					ind=qli.front();
					if(cst>=v)
					{
						cnt++;	
						chk[ind]=cst+t;
						ql.pop();
						qli.pop();
						while(cnt<n&&!ql.empty())
						{
							v=ql.front();
							ind=qli.front();
							if(cst<v)
							{
								fg=cnt=0;
								break;
							}
							if(cst>=v)
							{
								cnt++;
								chk[ind]=cst+t;
							}
							ql.pop();
							qli.pop();
						}
						cst+=t;
					}
					else
					{
						if(!qr.empty())
						{
							u=qr.front();
							if(u<v&&cst<u)
								cst=u+t;
							else if(u<v)
								cst+=t;
							else
							{
								cst=v;
								chk[ind]=cst+t;
								cnt++;
								qli.pop();
								ql.pop();
								while(cnt<n&&!ql.empty())
								{
									v=ql.front();
									ind=qli.front();
									if(cst<v)
										break;
									if(cst>=v)
									{
										cnt++;
										chk[ind]=cst+t;
									}
									ql.pop();
									qli.pop();
								}
								cst+=t;
							}
						}
						else
						{
							cst=v;
							chk[ind]=cst+t;
							cnt++;
							ql.pop();
							qli.pop();
							while(cnt<n&&!ql.empty())
							{
								v=ql.front();
								ind=qli.front();
								if(cst<v)
									break;
								if(cst>=v)
								{
									cnt++;
									chk[ind]=cst+t;
								}
								ql.pop();
								qli.pop();
							}
							cst+=t;
						}
						cnt=fg=0;
					}
					if(cnt==n||ql.empty())
						fg=cnt=0;
				}
			}
			else
			{
				if(qr.empty())
				{
					fg=1,cnt=0;
					if(!ql.empty())
					{
						u=ql.front();
						if(cst<u)
						{
							cst=u+t;
							continue;
						}
					}
					cst+=t;
				}
				else
				{
					v=qr.front();
					ind=qri.front();
					if(cst>=v)
					{
						cnt++;
						chk[ind]=cst+t;
						qr.pop();
						qri.pop();
						while(cnt<n&&!qr.empty())
						{
							v=qr.front();
							ind=qri.front();
							if(cst<v)
							{
								fg=1,cnt=0;
								break;
							}

							if(cst>=v)
							{
								cnt++;
								chk[ind]=cst+t;
							}
							qr.pop();
							qri.pop();
						}
						cst+=t;
					}	
					else
					{
						if(!ql.empty())
						{
							u=ql.front();
							if(u<v&&cst<u)
								cst=u+t;
							else if(u<v)
								cst+=t;
							else
							{
								cst=v;
								chk[ind]=cst+t;
								cnt++;
								qri.pop();
								qr.pop();
								while(cnt<n&&!qr.empty())
								{
									v=qr.front();
									ind=qri.front();
									if(cst<v)
										break;
									if(cst>=v)
									{
										cnt++;
										chk[ind]=cst+t;
									}
									qr.pop();
									qri.pop();
								}
								cst+=t;
							}
						}
						else
						{
							cst=v;
							chk[ind]=cst+t;
							cnt++;
							qr.pop();
							qri.pop();
							while(cnt<n&&!qr.empty())
							{
								v=qr.front();
								ind=qri.front();
								if(cst<v)
									break;
								if(cst>=v)
								{
									cnt++;
									chk[ind]=cst+t;
								}
								qr.pop();
								qri.pop();
							}
							cst+=t;
						}
						fg=1,cnt=0;
					}
					if(cnt==n||qr.empty())
						fg=1,cnt=0;
				}
			}
			if(ql.empty()&&qr.empty())
				break;
		}
		for(i=1;i<=m;i++)
			printf("%ld\n",chk[i]);
		if(tst)
			printf("\n");
	}
	return 0;
}