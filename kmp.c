#include <stdio.h>
void kmp(char *array,char *match);
int main(){
/*
 char array[50];
 int i;
 for(i=50;i>0;i--){
    array[i-1] = (char)(rand()%4 + 97);
 }*/


 char * array = "abdbabbcddcdddabcdcddcabcabcadadcddbdbbbabcacabacdb";
 char* match= "abca";
 //printf("%s\n%s\n %d",array,match,(int)'a');
 kmp(array,match);







return 0;
}
void kmp(char *array,char* match){
    int pi[5];
     pi[0]=0;
    int k=0;
    int i;
    for(i=1;i<5;i++){
        while(k>0 && match[k]!=match[i]){
            k=pi[k-1];
        }
        if(match[k]==match[i]){
            k++;
        }
        pi[i]=k;
    }
    printf("%s\n",array);
    int state =0;
    for(i=0;i<50;i++){
        while(state>0 && match[state]!=array[i]){
            state = pi[state-1];
        }
        if(match[state]==array[i]){
            state++;
        }
        if(state==4){
                printf("match found at I=%d\n",i-4);
                state = pi[state-1];
        }
    }

    printf("%s\n",match);
    printf("%d  %d  %d  %d %d",pi[0],pi[1],pi[2],pi[3]);
}
