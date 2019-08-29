/*******
Christian Miller
Program: N-Queen Solution
Using Backtracking, gives solution for N-Queen
******/

#include<stdio.h>
#include<stdlib.h>

void printSolution(int n,int x[]){
        int i,j;
        char c[100][100];
        for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                        c[i][j]='_';
                }//insideFor
        }//outsideFor

        for(i=1; i<=n; i++){
                c[i][x[i]]='Q';
        }//for

        for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                        printf("%c\t",c[i][j]);
                }//for
                printf("\n");
        }//for

}//printSolution

int place(int x[],int n){
        int i;
        for(i=1; i<n; i++){
                if((x[i] == x[n]) || (i-x[i] == n-x[n]) || (i+x[i]==n +x[n]))
                return 0;
        }//for
                return 1;
}//place

void nQueens(int n){
        int x[100], count=0, k=1;
        x[k] = 0;

        while(k != 0){
                x[k]++;
                while((x[k] <= n) && ( !place(x,k))){
                        x[k]++;
                }//while
                if(x[k] <= n){
                        if(k == n){
                                count ++;
                                if(count == 1){
                                        printf("Solution:\n");
                                        printSolution(n,x);
                                }//if
                        }//inside if
                        else{
                                k++;
                                x[k]=0;
                        }//else
                }//if
                else k--;
    }//while
}//nQueens

int main(){
    int input;
    printf("enter number of queens\n");
    scanf("%d",&input);
    if(input == 2 || input == 3)
        printf("There is no possible solution for 2 or 3, please try again.\n");
    nQueens(input);
    return 0;
}//main
