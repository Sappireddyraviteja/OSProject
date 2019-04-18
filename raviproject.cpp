#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>
pthread_t t1;
pthread_mutex_t counter;
typedef struct
{
char name[10];
int pos;
int ngift;
}billing;
void *bill()
{
pthread_mutex_lock(&counter);
printf("is getting billed\n");
printf("Wait billing is going on\n");
sleep(2);
pthread_mutex_unlock(&counter);
printf("\n\nNext person\n");
}
int main()
{
int n,i,j;
billing d[100],t;
printf("enter no of students for billing\n");
scanf("%d",&n);
printf("enter the students for billing with their positions in a queue\n");
printf("Also enter the no of gifts an individual has for billing\n");
for(i=0;i<n;i++)
{
scanf("%s",d[i].name);
scanf("%d",&d[i].pos);
scanf("%d",&d[i].ngift);
}
printf("\nsort them on the basis of no of gifts they have for billing\n");
printf("if any of them has equal no of gifts then sort w.r.t position\n");
for(i=0;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(d[j].ngift<d[j+1].ngift)
{
t=d[j];
d[j]=d[j+1];
d[j+1]=t;
}
else if(d[j].ngift==d[j+1].ngift)
{
if(d[j].pos>d[j+1].pos)
{
t=d[j];
d[j]=d[j+1];
d[j+1]=t;
}
}
}
}
for(i=0;i<n;i++)
{
printf("%s with %d gifts ",d[i].name,d[i].ngift);
}
pthread_exit(NULL);
}

