/*
#Family Name: Khan
#Given Name: Saman
#Student Number: 214217723
#EECS Login: samank
*/


/*

This is a C program that mimics a FCFS (first come first serve) CPU scheduler.
This program will take a .dat file as its input and print out the answers to the following questions:
What is the average waiting time?
What is the average turnaround time?
When does the CPU finish all these processes?
Which process is the last one to finish?

The program will simulate a maximum of four CPUs running.

*/


#include "sch-helpers.h"  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <errno.h>



Process processes[MAX_PROCESSES+1];   // a large structure array to hold all processes read from data file 
int numberOfProcesses=0;              // total number of processes
int next_process;
int context_switches;
int total_time;
int last_process_endTime = 0;
int cpu_time_utilized;
int clock;

//$$theClock and sumTurnArounds

Process_queue readyQueue;			// a ready queue to utilize
Process_queue waitingQueue;			// a waiting to utilize

// To simulate a CPU
Process *CPU[numberOfProcesses]


// Create a temporary queue that acts as a precursor to my actual ready queue
Proccess *temp_ready_queue[MAX_PROCESSES + 1];
int temp_queue_size;
//$$tmpQueueSize


// reset my global variables to equal zero
void resetVariablesZero(void){
	numberOfProcesses=0;
	next_process=0;
	total_time=0;
	context_switches=0;
	last_process_endTime =0;
	temp_queue_size=0;
	cpu_time_utilized=0;
}



// A method that compares process IDs and returns compare value (condition prescribed by professor)

int comparePIDS(const void *a, const void *b)
{
	process *first = *((process**) a);
	process *second = *((process**) b);

	if (first->pid < second->pid)
	{
		return -1;
	}

	else if (first->pid > second->pid)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}


// A method that calculates the average weight time of a process
double averageWaitTime (int wTime)
{
	double time = wTime/(double) numberOfProcesses;
	return time;
}

// A method that calculates the average time of a process to completion
// Exact same as method above but has different inputs
double averageCompletionTime (int cTime)
{
	double time = cTime / (double) numberOfProcesses;
	return time;
}

// A method that calculates how much the CPU was utilized given a time
double averageUtilTime (int uTime)
{
	double time = uTime*100.0/clock;
	return time;
}






// A method that returns the number of CPUS currently running

int runningCPUS()
{
	int runningCPUS = 0;

	for (int i=0; i < numberOfProcesses; i++)
	{
		if (CPU[i] != NULL)
		{
			runningCPUS++;
		} 
	}

	return runningCPUS;			// returns the # of CPUS running
}


// Retrieves the next process in ready queue to be dispatched to CPU

process *retrieve_next_process()
{
	if (readyQueue.size == 0)
	{
		return NULL;
	}

	else
	{
		process *ready_cpu = readyQueue.front->data;
		dequeueProcess(&readyQueue);
		return ready_cpu
	}
}



void runningToWaiting(){

	for (int i=0; i < numberOfProcesses; i++)
	{
		if (CPU[i] != NULL)
		{

		}
	}

}








int main(void){


    printf("The average waiting time is\t\t     : %.2f \n", );
    printf("The average turnaround time is\t\t     : %.2f \n", );
    printf("The time all processes finished\t     : %d\n", );
    printf("The average CPU utilization is\t\t     : %.1f%c\n", ;
    printf("Number of context switches occured are\t     : %d\n",0);
    printf("The last process to finish is: \t\t");

     return 0; 

}