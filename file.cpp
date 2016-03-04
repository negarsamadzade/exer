#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void sort(float *a,int n){
	int i,j,t;
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(a[j+1]<a[j]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

//dar in tabe miyane adade vurudi mohasebe mishavad
//agar tedade adad zoj bashad miyangine 2 adade vasati barabare miyane ast dar gheire in surat adade vasati miyane mibashad.
float median(float *a,int n){
	if(n%2==0)
		return (a[n/2]+a[(n/2)-1])/(float)2;
	else
		return a[n/2];
}
 //in tabe charake aval(miyane nime avale araye)ra hesab mikonad.
float Q1(float *a,int n){
	return median(a,int(n/2));
}
 //tabe Q3 baraye mohasebe charake sevom(miyane nime dovome araye vurudi)neveshte shode ast.
float Q3(float *a,int n){
	float *b=new float[n/2];;
	int j=0;
	if(n%2==0){
		for(int i=n/2;i<n;i++){
			b[j]=a[i];
			j++;
		}
	}
	else{
		for(int i=n/2+1;i<n;i++){
			b[j]=a[i];
			j++;
		}
	}
	return median(b,(int)n/2);
}
float min(float *a,int n){
	return a[0];
}
float max(float *a,int n){
	return a[n-1];
}
 //IQR=Q3-Q1 dar in gesmat hesab mishavad.
float IQR(float *a,int n){
	return Q3(a,n)-Q1(a,n);
}
//outlierha (x>Q3+IQR*1.5 ya x<Q1-IQR*1.5) mihasebe mishavad ke dar surate nabude an ebarate"there is no outlier"ra barmigardanad.
void outlier(float *a,int n){
	
	int j=0;
	float b,c,d;
	float *a1;
	a1=new float[n];
	string s=" ";
	b=1.5*IQR(a,n);
	c=Q3(a,n)+b;
	d=Q1(a,n)-b;
	for(int i=0;i<n;i++)
	{
		if(a[i]>c || a[i]<d)
		{
			a1[j]=a[i];
			j++;
			
		}
	}
	if(j!=0){
	  for(int i=0;i<j;i++)
		cout<<a1[i]<<" ";
	}
	else
		cout<<"there is no outlier";
}
int main()
{
int n;
cout<<"please enter number of data:";
cin>>n;
cout<<"please enter data:";
float *a=new float[n];
for(int i=0;i<n;i++)
	cin>>a[i];
sort(a,n);
cout<<"min"<<" : "<<min(a,n)<<"\n";
cout<<"max"<<" : "<<max(a,n)<<"\n";
cout<<"Q1"<<" : "<<Q1(a,n)<<"\n";
cout<<"Q2"<<" : "<<median(a,n)<<"\n";
cout<<"Q3"<<" : "<<Q3(a,n)<<"\n";
cout<<"outliers:";
outlier(a,n);
getch();
return 0;
}