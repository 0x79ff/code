#include<bits/stdc++.h>
using namespace std;

const int N=4e5+5;
struct node{
	double a[4];
}p[N];


//.........


int n;
double x,y,xx,yy;
double z=sin(1),w=cos(1),ans=1e16;

bool cmp (const node t1,const node t2)
{
	return t1.a[0]*t1.a[1]<t2.a[0]*t2.a[1];
}


int main()
{
	scanf("%d",&n);
	int k=80;

	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x,&y);
        p[i].a[0]=x*w-y*z;
        p[i].a[1]=x*z+y*w;
        p[i].a[2]=x;
        p[i].a[3]=y;
	}
	stable_sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k && j<=n-i;j++)
        {
			x=p[i].a[2],y=p[i].a[3];
			xx=p[i+j].a[2],yy=p[i+j].a[3];
			z=(x-xx)*(x-xx)+(y-yy)*(y-yy);
			ans=min(ans,z);
		}
	printf("%.0lf\n",ans);
	return 0;
}