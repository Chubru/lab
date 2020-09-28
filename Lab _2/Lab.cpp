#include <stdio.h>







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




int main()
{

  char dat[100000];
  int want=1;
  //scanf("%d",&len);
  printf("%s","Enter string\n");

  //scanf("%100[0-9a-zA-Z ]", &dat);
  gets(dat);
  printf("%s","Enter arg\n");
  scanf("%d", &want);
  int kol=0;
  int len=0;
  for(int i=0;i<sizeof(dat)-1;){
    
    if(checkLetter(dat[i])!=0){
      len++;

    }
    else if (len !=0){
      if(len==want){
        kol++;

      }
      len=0;
    }
    if(dat[i]=='\0'){
      break;
    }
    i++;

  }
  printf("%s %d\n","Kol =",kol);

  return 0;
}