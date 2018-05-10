#include<stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct Processes {
   int pid;
   int cpuT;
   int startT;
   int endT;
   int numberTickets;
   int waiting;
   int arrivalT;

};

void busyCPU(unsigned int seconds) {
    unsigned int retTime = time(0) + seconds;
    while (time(0) < retTime);
}



int main(){

//The file takes time until it runs but at the program shows a message at the end that indicates the running is done
     FILE * fp;
     fp = fopen ("/home/rana/Desktop/TheRoundRobinresults","w");

    int q;
    int Numbr;
    int count;
    int totalTickets;
    int finalsize=0;
    int size=0;
    int diff=0;
    int time=0;


//Please make sure to change the input file twice because the first time
//it gets loaded to count the number of processes
//and the next time to load the values into the processes array
//Load the file in line 46 and line 64

    freopen("Input-1.txt","r",stdin);
    scanf("%d",&q);
    scanf("%d",&totalTickets);

 count=0;

    while(scanf("%d ,",&Numbr)==1)
    {
       count++;
    }

    size=count/4;
    finalsize=count/4;

    int inputs[count];

    struct Processes ready [size];

     freopen("Input-1.txt","r",stdin);
    scanf("%d",&q);
    scanf("%d",&totalTickets);



int countz=0;
     while(countz<count)
    {
    scanf("%d ,",&inputs[countz]);
    countz++;
    }

    int b=0;

for(int t=0;t<finalsize;t++)
{
ready[t].pid=inputs[b];
b++;
ready[t].arrivalT=inputs[b];
b++;
ready[t].cpuT=inputs[b];
b++;
ready[t].numberTickets=inputs[b];
b++;
ready[t].waiting=0;

}


int waitingTimes[finalsize];
int turnAroundTimes[finalsize];

int i=0;
while(size>0)
{

    if(ready[i].pid!=-1)
    {
     fprintf (fp,"\n");
     fprintf (fp,"Time ");
    fprintf (fp,"%d",time);
     fprintf (fp,": P");
     fprintf (fp,"%d",ready[i].pid, " ");
 fprintf (fp," Entering quantum" );
    fprintf (fp,"\n");

        printf("\n");
    printf("Time ");
    printf("%d",time);
    printf(": P");
    printf("%d",ready[i].pid, " ");
    printf(" Entering quantum" );
    printf("\n");



  if(ready[i].cpuT<q)
     {
         busyCPU(ready[i].cpuT/1000);
             time+=ready[i].cpuT;
         for(int z=0;z<finalsize;z++)
     {
     if(z!=i)
     {
     if(ready[z].pid!=-1)
   {
         ready[z].waiting=ready[z].waiting+ready[i].cpuT;
     }
     }
      }

     }

else{
   busyCPU(q/1000);
          time+=q;
         for(int z=0;z<finalsize;z++)
     {
     if(z!=i)
     {
     if(ready[z].pid!=-1)
   {
         ready[z].waiting=ready[z].waiting+q;
     }
     }
      }

}

      ready[i].cpuT-=q;

    if(ready[i].cpuT<=0)
    {
       //Printing the waiting time and turn around and saving them into arrays for the average
        int u=time-ready[i].arrivalT;
        //  int u=time-ready[i].arrivalT;
       waitingTimes[i]=ready[i].waiting;
       turnAroundTimes[i]=time;

        fprintf (fp,"\n");
       fprintf (fp,"Time ");
       fprintf (fp,"%d",u);
       fprintf (fp,": P");
        fprintf (fp," Done Turn around: ");
       fprintf (fp,"%d",u);
        fprintf (fp," Waiting time: ");
        fprintf (fp,"%d",ready[i].waiting);
      fprintf (fp,"\n");

             printf("\n");
       printf("Time ");
       printf("%d",u);
       printf(": P");
       printf("%d",ready[i].pid);
       printf(" Done Turn around: ");
       printf("%d",u);
       printf(" Waiting time: ");
       printf("%d",ready[i].waiting);
       printf("\n");


       ready[i].pid=-1;
       size=size-1;

    }

}
if(i==(finalsize-1))
{
    i=0;
}
else
{
i=i+1;
}
}

int sum1=0;

for(int e=0;e<finalsize;e++)
{
    sum1+=waitingTimes[e];
}

int sum2=0;

for(int q=0;q<finalsize;q++)
{
    sum2+= turnAroundTimes[q];
}
 fprintf (fp,"\n");
 fprintf (fp,"\nAverage Waiting Time= %f\n",sum1*1.0/finalsize);
 fprintf (fp,"\n");
 fprintf (fp,"\nAverage Turnaround time= %f\n",sum2*1.0/finalsize);
 fprintf (fp,"\n");
 printf("\n");
printf("\nAverage Waiting Time= %f\n",sum1*1.0/finalsize);
printf("\n");
printf("\nAverage Turnaround time= %f\n",sum2*1.0/finalsize);
printf("\n");
 printf("Done! You can now check the output on the desktop in the file TheRoundRobinresults :) !");
fclose (fp);
return 0;
}
