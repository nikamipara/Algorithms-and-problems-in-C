#include <stdio.h>
#include <string.h>

int main() {

char str[100] = "aabcdefddddsddddddddddddddjjjjjjjjjjjjl;;;;;;;;;;;nhfnnfnf";
printf("before string operation %s",str);
int length = strlen(str);
int i;
int flag = 0;
for(i= 0 ; i<= length; i++){
    int j;
    for(j=0;j<i;j++){
        if(str[i]==str[j]) 
           {flag = 1;
                printf("\nthere is a match %c",str[i]);
            break;}
        
    }
   if(flag == 1){
        flag =0;
        int k;
        for(k = i ; k< length ; k++){
           str[k] = str[k+1]; 
        } 
       // str[k] = NULL;
        i--;
        length--;

   }
}
printf("after string operation %s\n",str);

return 0;
}