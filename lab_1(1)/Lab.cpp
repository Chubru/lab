// Lab.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>


int step(int n,int st){
	int data=n;
	if(st==0){
		return 1;
	}
	for(int i=0;i<st-1;i++){
		n=n*data;

	}
	return n;
}


int main()
{
	printf("%s"," z=a^(b/c)\n");



	int a,b,c,z;
	printf("%s","Enter z\n");

	scanf("%d",&z);

	printf("%s","Enter b\n");

	scanf("%d",&b);

	printf("%s","Enter c\n");

	scanf("%d",&c);
	if((z<=0)||(b <= 0)||(c <= 0)){
		printf("%s","false\n");
		return 0;
	}
	for(int i=0;i<1000;i++){
		if((step(z,c))==(step(i,b))){
			printf("%s","true");

			return 0;
		}
	}
	printf("%s","false");
	return 0;
}

