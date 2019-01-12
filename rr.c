/*
#Family Name: Khan
#Given Name: Saman
#Student Number: 214217723
#EECS Login: samank
*/


/*
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


// declare global variables
Process processes[MAX_PROCESSES+1];

int numOfProcesses;
int nextProcess;
int totalWaitTime;
int total_context_switches;
int cpu_time_util;
int clock;
int time_quantum; // this variable will vary depending on different time quantums
// integer for the sum of turnarounds?

// Create two queues - ready and waiting
Process_queue readyQ;
Process_queue waitingQ;

// Create pointer for CPUs
Process *CPUS[numOfProcesses];

// Create a temporary ready queue
Process *tempQ[MAX_PROCESSES+1];

// Create a variable for the temp queue's size
int temp_Q_size;

// Declare a uni-process, similar to node, with pointer to it's data and next node

Process_node *newProcessNode (Process *p)
{
	Process_node *node = (Process_node*)malloc(sizeOf(Process_node));

	// check to see if node is empty, output error message
	if node == NULL {error;}

	node->data = p;
	node->next=NULL;

	// return node
	return node;
}

// Reset my global variables, similar to FCFS

void resetVariablesZero(void)
{
	int numOfProcesses = 0;;
	int nextProcess=0;
	int totalWaitTime=0;
	int total_context_switches=0;
	int cpu_time_util=0;
	int clock=0;
	int time_quantum=0;
}

// Method that calculates average weight time
double avgWeightTime(int w)
{
	return double time = w/(double) numberOfProcesses;
}

// Method that calcultes average turnaround time
double avgTurnaroundTime(int t)
{
	return double time = t / (double) numberOfProcesses; \\ make sure to cast!
}

// Method that calculates average time that was utilized by the CPU
double avgCPUTime(int t)
{
	return double time = (t*100.0)/clock;
}

// Method that returns the number of processes that have not arrived yet

int incomingProcesses(void)
{
	return numberOfProcesses = nextProcess;
}

// A method that compares process IDs and returns compare value (conditions prescribed by professor)
// Copied directly from my 'fcfs.c' code

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


// Method that compares two processes' arrival times and outputs it


// Methodd that goes through each CPU and finds out the number of processes running on it

int numRunningProcesses(void)
{
	int numRunningProcesses = 0;
	for (int i =0; i < numberOfProcesses; i++)
	{
		if (CPUS[i] != NULL)
		{
			numRunningProcesses=numRunningProcesses+1;
		}
	}
	return numRunningProcesses;
}

int compareProcessArrival(const void *a, const void *b)
{
	Process *alpha = (Process *) a;
	Process *beta = (Process *) b;
	return alpha->arrivalTime - second->arrivalTime;
}


void initialize_process(void)
{
	while (nextProcess < numOfProcesses && processes[nextProcess].arrivalTime <= clock)
	{
		tempQ[temp_Q_size] = &processes[nextProcess];
		tempQ[temp_Q_size]->quantumRemaining = time_quantum;
		temp_Q_size++;
		nextProcess++
	}
}

// Prepares the subsequent process scheduled for the CPU

process *prepare_next_process()
{
	if (readyQ.size==0)		// if there's no processes waiting, return null
	{
		return NULL;
	}

	process *ready_cpu = readyQ.front->data;
	dequeueProcess(&readyQ);
	return ready_cpu;
}


// Method that initializes the process to a temp array I've created



// Method that obtains the next process in the ready Q and passes it to CPU
// Waiting --> Ready

void obtainNextProcess(void)
{
	int waitingQsize = waitingQ.size;

	for (int i=0; i < waitingQsize; i++)
	{
		Process *obtain = waiting.front->data;
		dequeueProcess(&waitingQ);

		if (obtain->bursts[ready->currentBurst].step == obtain->bursts[ready->currentBurst.length])
		{
			obtain->currentBurst++;
			obtain->quantumRemaining = time_quantum;
			obtain->endTime = clock;
			tempQ[temp_Q_size++]=obtain;
		}

		else
		{
			enqueueProcess(&waitingQ, obtain);
		}
	}
}




