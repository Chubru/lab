#include <stdio.h>




//#pragma warning(disable : 4996)  



//проверяет является ли переданный символ буквой.
//проверяет является ли переданный символ буквой.

int checkLetter(char d){
	if((d>='a')&&(d<='z')){//		коды строчных букв идут последовательно  
		return 1;
	}
	if((d>='A')&&(d<='Z')){//		коды заглавных букв идут последовательно 
		return 1;
	}
	return 0;
}




int main(){
	int want=1;
	//scanf("%d",&len);

	//scanf("%100[0-9a-zA-Z ]", &dat);

	printf("%s","Enter arg\n");
	scanf("%d", &want);
	printf("%s","Enter string\n");
	int kol=0;
	int len=0;
	for(int i=0;;i++){
		int dat=getchar();
		if(checkLetter(dat)!=0){
			len++;

		}
		else if (len !=0){
			if(len==want){
				kol++;

			}
			len=0;
		}
		if(dat=='\n'){
			if(i!=0){
				break;
			}
		}
	}
	printf("%s %d\n","Kol =",kol);

	return 0;
}