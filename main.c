#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SIZE 250
float myAtof(char *string, char *error);
float opResult(char* op, float fnum1, float fnum2);
char* substring(char *sub, char *string, int loc, int lenght);
int c;

int main()
{
    char string[SIZE];            // Array declaration.
    char *string1[SIZE];
    char *string2[SIZE];
    char sub[SIZE], sub1[SIZE];
    char op;
    float fnum1, fnum2;
    char errorState=0;

    printf("Enter arithmetic operation:\n");
    gets(string);

    int lenght = 0;
    while(string[lenght] != '\0'){ //finds string lenght
      lenght++;
    }

    for(int i = 0; i<lenght ;++i){
      if(isspace(string[i-1]) != 0){ // for 3 * 5 etc. input 
        printf("Error has been occurred due to inappropriate input!\n");
        return 0;
      }
      if(string[i] == '+'){
        op = '+';
        substring( sub, string, i+1,  lenght); //for find second number
        *string2 = sub;
        while (sub[c] != '\0')
          c++;
        substring( sub1, string, 0,  lenght-c-1); 
        *string1 = sub1;
        break;
      }

      else if(string[i] == '*'){
        op = '*';
        substring( sub, string, i+1,  lenght);
        *string2 = sub;
        while (sub[c] != '\0')  //to using substring method
          c++;   //it calculate string2 lenght
        substring( sub1, string, 0,  lenght-c-1);
        *string1 = sub1;
        break;
      }

      else if(string[i] == '/'){
        op = '/';
        substring( sub, string, i+1,  lenght);
        *string2 = sub;
        while (sub[c] != '\0')
          c++;
        substring( sub1, string, 0,  lenght-c-1);
        *string1 = sub1;
        break;
      }

      else if(string[i] == '-'){
        op = '-';
        substring( sub, string, i+1,  lenght);
        *string2 = sub;
        while (sub[c] != '\0')
          c++;
        substring( sub1, string, 0,  lenght-c-1);
        *string1 = sub1;
        break;
      }
    }

    if(string[0]=='*') {
      *string1 = "0";
      op = '*';
    }
    else if( string[0]=='+') {
      *string1 = "0";
      op = '+';
    }
    else if(string[0]=='-'){
      *string1 = "0";
      op = '-';
    } 
     else if(string[0]=='/') {
       *string1 = "0";
      op = '/';
    }
    
      if(string[0]=='*'&&string[1]=='\0') {
      *string1 = "0";
      op = '*';
      *string2 = "0";
      
    }
     else if(string[0]=='-'&&string[1]=='\0') {
      *string1 = "0";
      op = '-';
      *string2 = "0";
      
    }
    else if(string[0]=='/'&&string[1]=='\0') {
      *string1 = "0";
      op = '/';
      *string2 = "0";
      
    }
    else if(string[0]=='+'&&string[1]=='\0') {
      *string1 = "0";
      op = '+';
      *string2 = "0";
      
    }
    
    //printf("%s\n",*string1);
    //printf("%s\n",*string2);

    fnum1=myAtof(*string1,&errorState);
    fnum2=myAtof(*string2,&errorState); 

    float result;
    result = opResult( &op, fnum1, fnum2);
    
    if((op == '/') && (fnum2 == 0.0)){
     printf("Cannot divided into 0.\n");
     return 0;
     }
    if (errorState==0){
        printf("%.2f %c %.2f = %.2f\n", fnum1, op, fnum2, result);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}


float myAtof(char* string, char* error){
  float number = 0.0;
  int index = 0;
  int lenght = 0;
  int i;
  for (i = 0; string[i] != '\0' ; i++){ // until \0 because of string feature
    int d = string[i] ;

    while(string[lenght] != '\0'){  // determine lenght
      lenght++;
    }
    
    if (string[i] == '.'){
      index = i;   //for dot place
     // printf("%d",index); 

    }
    if (d >= '0' && d <= '9'){
      number = number * 10.00 + string[i] -'0';
     // printf("%f",a);  
      *error = 0;
    }

    else{
      *error = 1; 
    }
  }

 // printf("%d",last);
  
  int sign;
  if(string[0] == '-'){
    sign = -1; 
         if(index == 0){
          index=1;
          }
  }
  else{
    sign = 1;
  }
  int last ;
  int a=1 ;
  last = (i-index-1); //index until dot
  //a = pow(10.0,last);
  number = number / a;  // it prints 7777.00 instead of 77.77 so ?? converted that way
  float result = number * sign;
    /**
    if(result==0){
      *error = 1;
    return *error;
    }
    **/
  return result;
}


float opResult(char* op, float fnum1, float fnum2){ //for calculate
    
    float result;

    if(*op == '+') result = (fnum1+fnum2); 
    else if(*op == '-') result = (fnum1-fnum2); 
    else if(*op == '*') result = (fnum1*fnum2);
    else if(*op == '/') result = (fnum1/fnum2); 

    return result;
}

char* substring(char *sub,  char *string, int loc, int lenght) //for split strings
{
    while (lenght > 0)
    {
        *sub = *(string + loc); //loc means location
        sub++;
        string++;
        lenght--; //decrease by one by 
    }
    *sub = '\0'; //for string property
    return sub;
}