#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>
#include <semaphore.h>
const int p=10;                  //for 10 cycles of execution (can give different values also)
const int i=0;
const int j=1;
int turn;
int flag1;                             //flag to indicate whether process Pi is ready to execute or no
int flag2;                               //flag to indicate whether process Pj is ready to execute or no
void *processi(void *P);  
void *processj(void *P); 
int main()
{
	pthread_t Pi, Pj;                             //Initiating 2 process Pi and Pj
	for(int i=0;i<p;i++)                        
	{
		pthread_create(&Pi, NULL,processi,NULL);     //Creating 2 processes Pi and Pj
        pthread_create(&Pj, NULL,processj,NULL);
	}
	for(int i=0;i<p;i++)
	{
		pthread_join(Pi, NULL);                      //For running the processes parallell to eachother
        pthread_join(Pj, NULL);
	}
}                 
void *processi(void *P)                  // for process Pi
{
	int t=1;                             //as a time constant for wait operation
	flag1=1;                             // Implies that process Pi is ready to get into critical section
	turn=j;                              // It gives a turn for process Pj to enter the critical section
	while(flag2 && turn==j)              //checking whether it's process Pi's turn to enter critical section
	{
		usleep(t);                      //If not wait() operation
		t++;
	}
	printf("Process Pi has entered the critical section\nPi is exiting the critical section\n\n");   //Pi has entered the critical section 
}
void *processj(void *P)           //For process Pj
{
	int t=1;                     //as a time constant for wait operation
	flag2=1;                     // Implies that process Pj is ready to get into critical section
	turn=i;                      // It gives a turn for process Pi to enter the critical section
	while(flag1 && turn==i)      //checking whether it's process Pj's turn to enter critical section
	{
		usleep(t);               //If not wait() operation
		t++;
	}
	printf("Process Pj has entered the critical section\nPj is exiting the critical section\n\n");
}
