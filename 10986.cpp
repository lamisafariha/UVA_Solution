		/****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |	     -----  /-------------\   #
#   |   \   /   |  |           |   |    /      |           |          #
#   |    \ /    |  |           |   |  /        |           |          #
#   |           |  |           |   |/          |           |          #
#   |           |  |           |   |\          |           |          #
#   |           |  |           |   |  \        |           |          #
#   |           |   \         /    |    \      |           |          #
#  ---         ---   \______ /     |         -----       -----        #
#                                                                     #
#                                                                     #
#                                                                     #
#    			codeforces = Mukit09                                  #
#    			topcoder = mukitmkbs25                                #
#    			codechef = mukit_mkbs                                 #
#    			uva = mkbs_cse09                                      #
#    			spoj = mkbs_cse09                                     #
#    			CSE, CUET                                             #
#    facebook : https://www.facebook.com/hesitated.mkbs?ref=tn_tnmn   #
#                                                                     #
#                                                                     #
\*********************************************************************/

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 20010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define pb push_back
#define mpair make_pair
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < eps ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,n,cs=1,cnt,sm,fg,s,t,u,v,w;
i64 d[si];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

/*
int ara[si],cnt_p=1,pr[si];

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	pr[cnt_p++]=2;
	ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
		    pr[cnt_p++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
		ara[i+1]=1;
    }
}
*/

/*
struct P
{
    double x,y;
    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y);} // Dot Product
double CP(P aa,P bb){return aa.x*bb.y-aa.y*bb.x;} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));} // Value of Vector aa
double TRIANGLE(P aa,P bb){return CP(aa,bb)/2.0;} // Area of Triangle using CP
P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}//Rotaion with rad
P VL(P aa,double len){double v=VA(aa);return P(aa.x*len/v,aa.y*len/v);}// Make Vector of 'len' length
*/

vector<int>ve[si],cst[si];

struct dij
{
    int u,w;
    dij(int a,int b)
    {
        u=a;
        w=b;
    }

    bool operator < (const dij& p) const { return w>p.w;}
};

void dijkstra()
{
    d[s]=0;
    priority_queue<dij>q;
    q.push(dij(s,0));
    int i,nw,v,l;
    while(!q.empty())
    {
        dij u=q.top();
        q.pop();
        nw=u.u;
        if(nw==t)
        return;
        l=ve[nw].size();
        rep(i,0,l)
        {
            v=ve[nw][i];
            if(d[nw]+cst[nw][i]<d[v])
            {
                d[v]=d[nw]+cst[nw][i];
                q.push(dij(v,d[v]));
            }
        }
    }
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int m,T;
    scanf("%d",&T);
   	while(T--)
   	{
   	    scanf("%d%d%d%d",&n,&m,&s,&t);
   	    sm=cnt=0;
		fg=1;

		rep(i,0,n)
		{
		    d[i]=inf;
		    ve[i].clear();
		    cst[i].clear();
		}

		while(m--)
		{
		    scanf("%d%d%d",&u,&v,&w);
		    ve[u].pb(v);
		    ve[v].pb(u);
		    cst[u].pb(w);
		    cst[v].pb(w);
		}
		dijkstra();
		if(d[t]<inf)
		printf("Case #%d: %d\n",cs++,d[t]);
		else
		printf("Case #%d: unreachable\n",cs++);
    }
   	return 0;
}
