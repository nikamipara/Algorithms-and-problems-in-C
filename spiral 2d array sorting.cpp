#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int array[5][5];
int arrcp[5][5];

void swap(int i,int j);
void printt();
void printtt();
int* arrayof(int i);
void selectionsort();
void spiral();
bool check(int i,int j,int di);
int main()
{

    srand(time(NULL));
    int count =25;
    for(int i=0;i<5;i++){
        for(int j=4;j!=-1;j--){
            array[i][j]=count--;
        }
    }
    printt();
    selectionsort();
    printf("after selection sort\n");
    printt();
    spiral();
    printf("after spiral\n");
    printtt();
    return 0;
}
void printt(){
     for(int i=5;i>0;i--){
        for(int j=5;j>0;j--){
            printf("%d\t",array[5-i][5-j]);
        }
        printf("\n");
    }
}
void printtt(){
     for(int i=5;i>0;i--){
        for(int j=5;j>0;j--){
            printf("%d\t",arrcp[5-i][5-j]);
        }
        printf("\n");
    }
}
int* arrayof(int i){
    if(i==0) return &array[0][0];
    int a = i%5;
    int b = i/5;
    if(a==0){
        return &array[b-1][4];
    }
    else{
        return &array[b][a-1];
    }
}
void selectionsort(){
    for(int i=25;i>0;i--){
        int maxposition = i;
        for(int j=i-1;j>0;j--){
            if(*arrayof(j)>*arrayof(maxposition)){
               maxposition=j;
            }
        }
        swap(i,maxposition);
    }
}
void swap(int i,int j){
    int a = *arrayof(i);
    *arrayof(i)= *arrayof(j);
    *arrayof(j)=a;
}
void spiral(){
    arrcp[5][5]={0};
    int i=0,j=0,dir=0;
    arrcp[0][0]=*arrayof(0);
    for(int x=24;x>=0;x--){
        if(!check(i,j,dir)){
            dir = (dir+1)%4;
        }
         int no = *arrayof(25-x);
        if(dir==0){
            arrcp[i][j++]=no;
        }
        else if(dir==1){
             arrcp[i++][j]=no;
        }
        else if(dir==2){
            arrcp[i][j--]=no;
        }
        else{
            arrcp[i--][j]=no;
        }
    }
}
bool check(int i,int j,int dir){
    if(dir==0){return (j<4&&arrcp[i][j+1]==0)?(true):(false);}
    else if(dir==1){return (i<4&&arrcp[i+1][j]==0)?(true):(false);}
    else if(dir==2){return (j>0&&arrcp[i][j-1]==0)?(true):(false);}
    else{return (i>0&&arrcp[i-1][j]==0)?(true):(false);}
}
