/* CMPE-338 _ LAB TAKE HOME EXAM _ Mustafa Çakıcı 19244710068 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define total_processes 20
#define processor_count 4

struct processor
{
    int proc_ETs[5];
    int proc_id;
};

void *process(void *args)
{
    struct processor *procitem = (struct processor *)args;
    for (int y = (total_processes / processor_count); y >= 0; y--)
    {
        for (int i = sizeof(procitem->proc_ETs) / sizeof(procitem->proc_ETs[0]); i > 0; i--)
        {
            printf("Process %d from Processor %d has Remaining %d ET.\n", (i), procitem->proc_id, (y));
            sleep(0.5);
        }
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t pids[processor_count];
    struct processor proc[processor_count];
    int process_ETs[total_processes];

    //all processes
    for (int i = 0; i < total_processes; i++)
    {
        process_ETs[i] = (i % 4) + 1;
    }

    for (int i = 0; i < processor_count; i++)
    {
        //set processor id
        proc[i].proc_id = (i + 1);

        //set processes (distribute)
        int numOfDistribution = (total_processes / processor_count);
        for (int j = i * numOfDistribution; j < (i * numOfDistribution)+numOfDistribution; j++)
        {
            proc[i].proc_ETs[(j % numOfDistribution)] = process_ETs[j];
        }

        //run processors
        if (pthread_create(&pids[i], NULL, process, &proc[i]))
        {
            fprintf(stderr, "An error occured while creating thread/process %d.\n", i);
        }
    }

    for (int i = 0; i < processor_count; i++)
    {
        pthread_join(pids[i], NULL);
        printf("Processor %d has completed all assigned processes.\n", proc[i].proc_id);
    }

    return 0;
}
/* 
Sample Terminal Output:

Process 5 from Processor 1 has Remaining 5 ET.
Process 5 from Processor 4 has Remaining 5 ET.
Process 5 from Processor 3 has Remaining 5 ET.
Process 5 from Processor 2 has Remaining 5 ET.
Process 4 from Processor 4 has Remaining 5 ET.
Process 4 from Processor 1 has Remaining 5 ET.
Process 4 from Processor 3 has Remaining 5 ET.
Process 4 from Processor 2 has Remaining 5 ET.
Process 3 from Processor 3 has Remaining 5 ET.
Process 3 from Processor 4 has Remaining 5 ET.
Process 3 from Processor 2 has Remaining 5 ET.
Process 3 from Processor 1 has Remaining 5 ET.
Process 2 from Processor 3 has Remaining 5 ET.
Process 2 from Processor 2 has Remaining 5 ET.
Process 2 from Processor 4 has Remaining 5 ET.
Process 2 from Processor 1 has Remaining 5 ET.
Process 1 from Processor 3 has Remaining 5 ET.
Process 1 from Processor 2 has Remaining 5 ET.
Process 1 from Processor 4 has Remaining 5 ET.
Process 1 from Processor 1 has Remaining 5 ET.
Process 5 from Processor 3 has Remaining 4 ET.
Process 5 from Processor 2 has Remaining 4 ET.
Process 5 from Processor 4 has Remaining 4 ET.
Process 4 from Processor 2 has Remaining 4 ET.
Process 5 from Processor 1 has Remaining 4 ET.
Process 4 from Processor 3 has Remaining 4 ET.
Process 4 from Processor 4 has Remaining 4 ET.
Process 3 from Processor 2 has Remaining 4 ET.
Process 4 from Processor 1 has Remaining 4 ET.
Process 3 from Processor 4 has Remaining 4 ET.
Process 3 from Processor 3 has Remaining 4 ET.
Process 2 from Processor 2 has Remaining 4 ET.
Process 3 from Processor 1 has Remaining 4 ET.
Process 2 from Processor 4 has Remaining 4 ET.
Process 2 from Processor 1 has Remaining 4 ET.
Process 2 from Processor 3 has Remaining 4 ET.
Process 1 from Processor 2 has Remaining 4 ET.
Process 1 from Processor 1 has Remaining 4 ET.
Process 1 from Processor 4 has Remaining 4 ET.
Process 5 from Processor 1 has Remaining 3 ET.
Process 4 from Processor 1 has Remaining 3 ET.
Process 5 from Processor 2 has Remaining 3 ET.
Process 1 from Processor 3 has Remaining 4 ET.
Process 4 from Processor 2 has Remaining 3 ET.
Process 3 from Processor 1 has Remaining 3 ET.
Process 5 from Processor 4 has Remaining 3 ET.
Process 2 from Processor 1 has Remaining 3 ET.
Process 4 from Processor 4 has Remaining 3 ET.
Process 3 from Processor 2 has Remaining 3 ET.
Process 1 from Processor 1 has Remaining 3 ET.
Process 3 from Processor 4 has Remaining 3 ET.
Process 5 from Processor 3 has Remaining 3 ET.
Process 5 from Processor 1 has Remaining 2 ET.
Process 2 from Processor 2 has Remaining 3 ET.
Process 4 from Processor 1 has Remaining 2 ET.
Process 2 from Processor 4 has Remaining 3 ET.
Process 3 from Processor 1 has Remaining 2 ET.
Process 1 from Processor 4 has Remaining 3 ET.
Process 1 from Processor 2 has Remaining 3 ET.
Process 5 from Processor 4 has Remaining 2 ET.
Process 5 from Processor 2 has Remaining 2 ET.
Process 2 from Processor 1 has Remaining 2 ET.
Process 4 from Processor 2 has Remaining 2 ET.
Process 1 from Processor 1 has Remaining 2 ET.
Process 4 from Processor 4 has Remaining 2 ET.
Process 5 from Processor 1 has Remaining 1 ET.
Process 3 from Processor 2 has Remaining 2 ET.
Process 3 from Processor 4 has Remaining 2 ET.
Process 4 from Processor 1 has Remaining 1 ET.
Process 2 from Processor 2 has Remaining 2 ET.
Process 3 from Processor 1 has Remaining 1 ET.
Process 2 from Processor 4 has Remaining 2 ET.
Process 1 from Processor 2 has Remaining 2 ET.
Process 2 from Processor 1 has Remaining 1 ET.
Process 1 from Processor 1 has Remaining 1 ET.
Process 5 from Processor 2 has Remaining 1 ET.
Process 1 from Processor 4 has Remaining 2 ET.
Process 5 from Processor 4 has Remaining 1 ET.
Process 4 from Processor 2 has Remaining 1 ET.
Process 5 from Processor 1 has Remaining 0 ET.
Process 3 from Processor 2 has Remaining 1 ET.
Process 4 from Processor 4 has Remaining 1 ET.
Process 4 from Processor 1 has Remaining 0 ET.
Process 2 from Processor 2 has Remaining 1 ET.
Process 3 from Processor 1 has Remaining 0 ET.
Process 4 from Processor 3 has Remaining 3 ET.
Process 3 from Processor 4 has Remaining 1 ET.
Process 2 from Processor 1 has Remaining 0 ET.
Process 1 from Processor 2 has Remaining 1 ET.
Process 1 from Processor 1 has Remaining 0 ET.
Process 2 from Processor 4 has Remaining 1 ET.
Process 3 from Processor 3 has Remaining 3 ET.
Process 5 from Processor 2 has Remaining 0 ET.
Process 1 from Processor 4 has Remaining 1 ET.
Process 4 from Processor 2 has Remaining 0 ET.
Process 2 from Processor 3 has Remaining 3 ET.
Process 5 from Processor 4 has Remaining 0 ET.
Process 3 from Processor 2 has Remaining 0 ET.
Process 1 from Processor 3 has Remaining 3 ET.
Process 4 from Processor 4 has Remaining 0 ET.
Process 2 from Processor 2 has Remaining 0 ET.
Process 5 from Processor 3 has Remaining 2 ET.
Process 3 from Processor 4 has Remaining 0 ET.
Processor 1 has completed all assigned processes.
Process 1 from Processor 2 has Remaining 0 ET.
Process 4 from Processor 3 has Remaining 2 ET.
Processor 2 has completed all assigned processes.
Process 2 from Processor 4 has Remaining 0 ET.
Process 1 from Processor 4 has Remaining 0 ET.
Process 3 from Processor 3 has Remaining 2 ET.
Process 2 from Processor 3 has Remaining 2 ET.
Process 1 from Processor 3 has Remaining 2 ET.
Process 5 from Processor 3 has Remaining 1 ET.
Process 4 from Processor 3 has Remaining 1 ET.
Process 3 from Processor 3 has Remaining 1 ET.
Process 2 from Processor 3 has Remaining 1 ET.
Process 1 from Processor 3 has Remaining 1 ET.
Process 5 from Processor 3 has Remaining 0 ET.
Process 4 from Processor 3 has Remaining 0 ET.
Process 3 from Processor 3 has Remaining 0 ET.
Process 2 from Processor 3 has Remaining 0 ET.
Process 1 from Processor 3 has Remaining 0 ET.
Processor 3 has completed all assigned processes.
Processor 4 has completed all assigned processes.  */