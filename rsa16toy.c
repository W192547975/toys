#include	<stdio.h>
#include	<stdlib.h>

unsigned short rsa16toy(unsigned short m,unsigned int d,unsigned short n);

int main(void)
{
	unsigned short m,n=1;
	unsigned d;
	int o=scanf("%hu%u%hu",&m,&d,&n);
	if(o!=3)printf("%d ",o);
	printf("%hu\n",rsa16toy(m,d,n));
	return o==3?EXIT_SUCCESS:EXIT_FAILURE;
}

unsigned short rsa16toy(unsigned short m,unsigned int d,unsigned short n)
{
	unsigned c;
	unsigned short r=1;
	for(c=0;c<d;c++)
	{
		unsigned long s=r;
		if((s*=m)>=n)s%=n;
		if(s==r)break;
		if((r=s)==m&&c!=0)c=d-d%c;
	}
	return r;
}
