#include <stdio.h>
main(){

    int j=0;
    int i = ++j;
    //printf("hello world!j=%d i=%d",j,i);
    int array[100]={0};
    int h;

   for(;j<2;j++){
      //  array[j]=j;
        int k=0;
        k++;
          h= printf("inside for loop %d",k);
   }
   printf("outside for loop %d",h);

  // for(j=0;j<101;j++){
   //}

}
int sum(int a,int b){
    return a+b;
}
