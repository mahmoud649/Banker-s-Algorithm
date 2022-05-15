#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>

//Build Queue
typedef struct {
    int front;
    int rear;
    int size;
    int *data;
}Queue;

void CreateQueue(Queue* q ,int n);
int IsEmpty(Queue* q);
void QueueAdd(Queue* q , int ndata);
int QueueOut(Queue* q);
void QueuePrint (Queue q);

// Function Prototype
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


void Banker(C[5][3],M[5][3],A[1][3],need[5][3])
{
    Queue q;
    CreateQueue(&q,5);
    for(int i = 0;i<5;i++)
        QueueAdd(&q , i);
    
    while(!IsEmpty(&q))
    {
        
    }


}




// Queue Funs
void CreateQueue(Queue* q ,int n)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->data = (int*)malloc(n * sizeof(int));
}

int IsEmpty(Queue* q)
{
    return !q->size;
}

void QueueAdd(Queue* q , int ndata)
{
    q->size ++;
    q->rear ++;
    q->data[q->rear]= ndata;
}

int QueueOut(Queue* q)
{
    int temp = q->data[q->front];
    q->size --;
    q->front ++;
    return temp;
}

void QueuePrint (Queue q)
{
    if (IsEmpty(&q))
    {
        printf("Empty\n");
        return;
    }
    printf("%d",q.data[q.front]);
    q.front ++;
    for (int i=0; i<q.size-1;i++)
    {
        printf(",%d",q.data[q.front]);
        q.front ++;
    }
    printf("\n");
}