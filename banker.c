#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>

void LoadFile(char *); //Load File In Path Variable
void GetData(int n,int c[][3]); //Get Data From File   n:number of rows to get
FILE *f; //carry the file pointer
 


int main(){
char path[256];
LoadFile(path);
f = fopen(path,"r");
int c[5][3],M[5][3],A[1][3];
GetData(5,c);
GetData(5,M);
GetData(1,A);

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