#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>

void LoadFile(char *); //Load File In Path Variable
void GetData(int n,int c[][3]); //Get Data From File   n:number of rows to get
void subtract_matrices(int rows,int col,int out[][col],int mat1[][col],int mat2[][col]);
FILE *f; //carry the file pointer
 


int main(){
char path[256];
LoadFile(path);
f = fopen(path,"r");
int C[5][3],M[5][3],A[1][3];
GetData(5,C);
GetData(5,M);
GetData(1,A);
int need[5][3];
subtract_matrices(5,3,need,M,C);

printf("\n\n %d %d %d",A[0][0],A[0][1],A[0][2]);


}

void LoadFile(char *path)
{
getcwd(path,sizeof(path)); //go to the current path
printf("Enter The File Name ==> ");
char filename[50];
scanf("%s",filename);
strcat(path,filename);
}

void GetData(int n,int c[][3])
{
    int temp = 0,i=0;

    while (i<n)
    {
        while(temp < 3)
            fscanf(f, "%d", &c[i][temp++]);
        temp = 0;
        i++;
    }

}

void subtract_matrices(int rows,int col,int out[][col],int mat1[][col],int mat2[][col])
{
    // subtract two matrices
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < col; ++j) {
      out[i][j] = mat1[i][j] - mat2[i][j];
    }
}