#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include <stdlib.h>

//Build Queue
typedef struct {
    int front;
    int rear;
    int size;
    int max;
    int *data;
}Queue;

void CreateQueue(Queue* q ,int n);
int IsEmpty(Queue* q);      //check if queue is empty
void QueueAdd(Queue* q , int ndata);
int QueueOut(Queue* q);
void QueuePrint (Queue q);

// Function Prototype
void LoadFile(char *); //Load File In Path Variable
void GetData(int n,int c[][3]); //Get Data From File   n:number of rows to get
void subtract_matrices(int rows,int col,int out[][col],int mat1[][col],int mat2[][col]);     //separite the matrices
void Banker(int C[5][3],int M[5][3],int A[1][3],int need[5][3]);           //banker's algorithm function
FILE *f; //carry the file pointer



int main(){
char path[512] = "";
LoadFile(path);    //loads the file
if (f = fopen(path,"r")){

int C[5][3],M[5][3],A[1][3];
GetData(5,C);
GetData(5,M);
GetData(1,A);           //fetch data to each matrix
fclose(f);          // closes the file
int need[5][3];
subtract_matrices(5,3,need,M,C);
Banker(C,M,A,need);      // run the algorithm
}
else
    printf("File Not Exist");       //error if the file name is wrong
getchar();
return 0;
}

void LoadFile(char *path)
{
getcwd(path,sizeof(path)); //go to the current path
printf("Enter The File Name ==> ");
char filename[50];
scanf("%s",filename);            // get the file name from the user
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

// the main algorithm
void Banker(int C[5][3],int M[5][3],int A[1][3],int need[5][3])
{
    Queue p,seq;
    CreateQueue(&p,5);
    CreateQueue(&seq,5);
    for(int i = 0;i<5;i++)
        QueueAdd(&p , i);

    while(!IsEmpty(&p))
    {
        int found = 0,p_size = p.size;
        for(int i = 0 ; i < p_size;i++)
        {
            int process = QueueOut(&p);
            // Can Give Resources To That process
            if(need[process][0] <= A[0][0] && need[process][1] <= A[0][1] && need[process][2] <= A[0][2])
            {
                // Add Take The Resources Back From The Process
                for (int j = 0; j < 3; ++j) {
                    A[0][j] = A[0][j] + C[process][j];
                }
                found = 1;
                QueueAdd(&seq,process); //Add the process to Sequance Queue
            }else //Not Enough Resourses
                QueueAdd(&p,process); //Append it Back to the Queue

        }
        if (!found)
        {
            printf("\n UnSafe State\n");
            return;
        }
    }

    //Print the Sequance
    printf("\n Safe State\n");
    printf("\n possible execution sequence : ");
    QueuePrint(seq);


}




// Queue Functions
//intialize the queue
void CreateQueue(Queue* q ,int n)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->max = n;
    q->data = (int*)malloc(n * sizeof(int));
}

//check if empty
int IsEmpty(Queue* q)
{
    return !q->size;
}

//add to the queue
void QueueAdd(Queue* q , int ndata)
{
    q->size ++;
    if (q->rear - q->max == -1)
        q->rear = 0;
        else
            q->rear ++;
    q->data[q->rear]= ndata;
}

// remove from the queue
int QueueOut(Queue* q)
{
    int temp = q->data[q->front];
    q->size --;
    if (q->front - q->max == -1)
        q->front = 0;
        else
            q->front ++;
    return temp;
}

// print the elements in the queue
void QueuePrint (Queue q)
{
    if (IsEmpty(&q))
    {
        printf("Empty\n");
        return;
    }
    printf("P%d",q.data[q.front]);
    q.front ++;
    for (int i=0; i<q.size-1;i++)
    {
        printf(",P%d",q.data[q.front]);
        q.front ++;
    }
    printf("\n");
}
