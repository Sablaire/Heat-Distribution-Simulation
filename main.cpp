#include <iostream>
#include <fstream>
#include <math.h>
#define n 15   // длина комнаты 
using namespace std;
int main()
{
	int i, k=0;
	double dx, dt, newp[n], oldp[n], eps, max,a=1.0;
	dx=1.0/(n-1);
	dt=0.5*dx*dx;
	eps=0.00001;

	for(i=0;i<5;i++)
		oldp[i]=20.0;
		for(i=5;i<n;i++)
		oldp[i]=0.0;
	do{
		cout<<k<<endl;
		k++;
		oldp[0]=20.0;
		newp[0]=20.0;
		oldp[n-1]=0.0;
		newp[n-1]=0.0;

		for(i=1;i<n-1;i++){
			if (i<10 && i>4) a=0.00000052;
			newp[i]=oldp[i]+dt*a*((oldp[i+1]-2.0*oldp[i]+oldp[i-1])/(dx*dx));
		}
	oldp[0]=20.0;
		newp[0]=20.0;
		oldp[n-1]=0.0;
		newp[n-1]=0.0;
		max=0.0;

	for(i=0;i<n;i++)
		if(max<fabs(newp[i]-oldp[i]))
		max=fabs(newp[i]-oldp[i]);

	for(i=0;i<n;i++)
		oldp[i]=newp[i];

	}while(k<100);

	ofstream fout("file.txt");
				for(i=0;i<n;i++)
					fout<<newp[i]<<'\t';
	system("pause");
	return 0;
}
