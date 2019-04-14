#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>
using namespace std;
void *Student(void *at);
void *Faculty(void *at1);
void *Staff(void *at2);
void *Enter(void *at3);
pthread_t t,t1,t2,t3,t4;
pthread_mutex_t  l;

int main()
{
int n;
printf("Choose your Mode \n");
printf("single press 1\n");
printf("multiplayer press 2\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
pthread_create(&t,NULL,Enter,NULL);
pthread_join(t,NULL);
}
}
void *Student(void *at)
{
	float time;
pthread_mutex_lock(&l);
printf("Student can play till 6.00hr \n");
printf("Student playing\n");
sleep(1);
pthread_mutex_unlock(&l);
printf("GAME OVER\n");
}
void *Faculty(void *at1)
{
	float time;
pthread_mutex_lock(&l);
printf("Faculty can play till 8.00hr \n",time);
printf("Faculty playing\n");
sleep(2);
pthread_mutex_unlock(&l);
printf("GAME OVER\n");
}
void *Staff(void *at2)
{
	float time;
pthread_mutex_lock(&l);
printf("Staff you can play till you want \n",time);
printf("Staff playing\n");
sleep(2);
pthread_mutex_unlock(&l);
printf("GAME OVER\n");
}
void *Enter(void *at3)
{
float time;
char name[10];
printf("Are you a\n\n student\n faculty \n staff");
printf("\n\nEnter the person name  who want to play the game\n");
scanf("%s",name);
printf("Arival time\n");
scanf("%f",&time);
if(strcmp(name,"student")==0)
{
if(time>=22.00 || time<=6.00)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t3,NULL,&Student,NULL);
pthread_join(t3,NULL);
}
else
{
printf("\n\n%s,you are not allowed to play as your arrival %.2fhr time is differ different  from the scheduled one \n",name,time);
}
}
else if(strcmp(name,"faculty")==0)
{
if(time>=17.00 || time<=8.00)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t2,NULL,&Faculty,NULL);
pthread_join(t2,NULL);
}
else
printf("\n\n%s,you are not allowed to play as your arrival %.2fhr time is different  from the scheduled one \n",name,time);
}
else if(strcmp(name,"staff")==0)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t1,NULL,&Staff,NULL);
pthread_join(t1,NULL);
}
else
printf("\n\n%s you don't have access to the game right now\n",name);
pthread_exit(NULL);
}

