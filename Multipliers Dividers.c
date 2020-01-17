#include<stdio.h>
#define M 8 //rows
#define N 10 //columns
void MultipliersDividers(int size,int row,int column);
void MaxZeroArea(int ar[][N],int);
int CountZero(int a,int b,int lenght,int ar[M][N]);

 int main(){
    int size,row,column,mat[M][N],lenght;
    for(int i=0;i<M;i++){
        for(int k=0;k<N;k++){
            printf("Enter 0 or 1 for [%d][%d] position:\n",i,k);
            scanf("%d",&(mat[i][k]));
        }
    }
    printf("Enter a some number:\n");
    scanf("%d",&lenght);
    MaxZeroArea(mat,lenght);
    
    printf("Enter number for rows and columns of your matrix:\n");
    scanf("%d",&size);
    printf("Enter row and column that you want to check:\n");
    scanf("%d%d",&row,&column);
    if((row>size)&&(column>size)){
         printf("Error.\n");
     }
    else{
    MultipliersDividers(size,row,column);
    }
    return 0;
 }

 void MultipliersDividers(int size,int row,int column){
     int count=0,counter=0,i, j;
     int ar[size][size];
   for(i=0; i<size; i++) {
      for(j=0;j<size;j++) {
         printf("Enter value for ar[%d][%d]:", i, j);
         scanf("%d", &ar[i][j]);
      }
   }
     //multiples
     for(int i=0;i<size;i++){
         for(int k=0;k<size;k++){
             if((ar[i][k]%ar[row][column]==0)&&(ar[row][column]!=ar[i][k])){
                 count++;
             }
         }
     }
     printf("Number of multiples:%d\n",count);
     for(int s=0;s<size;s++){
         for(int a=0;a<size;a++){
             if((ar[row][column]%ar[s][a]==0)&&(ar[row][column]!=ar[s][a])){
                 counter++;
             }
             
         }
     }
      printf("Number of divisors:%d\n",counter);
 }

void MaxZeroArea(int ar[M][N],int lenght){
    int tempzero=0,maxzero=0,x=0,y=0;
    for(int s=0;s<(M-lenght);s++){
        for(int d=0;d<(N-lenght);d++){
            tempzero=CountZero(s,d,lenght,ar);
            if(tempzero>maxzero){
                maxzero=tempzero;
                x=s;
                y=d;
            }
        }
    }
    for(int q=x;q<x+lenght;q++){
        for(int w=y;w<y+lenght;w++){
            printf("%d ",ar[q][w]);
        }
        printf("\n");
    }    
    printf("Sub matrix starts at index [%d][%d], lenght=%d : %d Zeroes.\n",x,y,lenght,maxzero);
}

int CountZero(int a,int b,int lenght,int ar[M][N]){
    int count=0;
    for(int i=a;i<a+lenght;i++){
        for(int j=b;j<b+lenght;j++){
            if(ar[i][j]==0)
                count++;    
        }
    }
    return count;
}
