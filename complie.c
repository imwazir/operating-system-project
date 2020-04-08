#include <stdio.h>
struct student
{
    int Student_Id;
    int FoodTakenTime;
    int WaitingTime;
    int TurnAroundTime;
};

void get_data(struct student list[], int s);
void show(struct student list[], int s);
void scheduling(struct student list[], int s);
void waitingTime(struct student list[], int n);
void turnAroundTime(struct student list[], int n);

int main()
{
    struct student data[20];
    int n,i;
    char c='n';
    do
	{
    printf("Enter the No. of Students wants to eat in mess :- ");
    scanf("%d", &n);
    get_data(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    show(data, n);
    printf("********************if you want to run this program once more press 'y' : ");
    scanf("%s",&c);
    }while(c=='y');
    return 0;
} 

void get_data(struct student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
       // printf("\n\nEnter data for Student %d", i + 1);
        
        printf("\nEnter Student id for Student %d\t", i + 1);
        scanf("%d", &list[i].Student_Id);

        printf("Enter time taken for food (minuts) for Student %d\t", i + 1);
        scanf("%d", &list[i].FoodTakenTime);
    } 
}
void show(struct student list[80], int s)
{
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;
	int TotalWatingTime=0,TotalTurnAroundTime=0;
    printf("\n\nOutput according to LRTF\n");
    printf("\n|***************************************************************|");
    printf("\n|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n|***************************************************************|");    
    for (i = 0; i < s; i++)
    {
        printf("\n|%d\t\t%d\t\t%d\t\t%d\t\t|", list[i].Student_Id, list[i].FoodTakenTime,list[i].WaitingTime,list[i].TurnAroundTime);
        printf("\a\n|===============================================================|");
		TotalWatingTime= TotalWatingTime+list[i].WaitingTime;
		TotalTurnAroundTime= TotalTurnAroundTime+list[i].TurnAroundTime;
	} 
	printf("\n\n\t\t\t\t\t\tTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\n\t\t\t\t\t\tTotal Turn around Time is: = %d\n\n",TotalTurnAroundTime);
	printf("\n\n\t\t\t\t\t\tAverage Waiting Time is: = %d",TotalWatingTime/s);
	printf("\n\t\t\t\t\t\tAverage Turn around Time is: = %d\n\n",TotalTurnAroundTime/s);
}

void scheduling(struct student list[80], int s)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].FoodTakenTime < list[j + 1].FoodTakenTime)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].FoodTakenTime == list[j + 1].FoodTakenTime)
            {
            	if(list[j].Student_Id > list[j + 1].Student_Id)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}


void waitingTime(struct student list[80], int n)
{
int j,total;
list[0].WaitingTime=0;
    for(j=1;j<n;j++)
    {
        list[j].WaitingTime=list[j-1].WaitingTime+list[j-1].FoodTakenTime;
    }
}


void turnAroundTime(struct student list[80], int n)
{
int j,total;
    
           for(j=0;j<n;j++)
         {
          list[j].TurnAroundTime=list[j].WaitingTime+list[j].FoodTakenTime;
         }
}
