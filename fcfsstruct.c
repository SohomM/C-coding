#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;    // Process ID
    int bt;     // Burst Time
    int wt;     // Waiting Time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Array of structures to store information of each process
    struct Process processes[n];

    // Input process details
    printf("Enter process id and burst time of all the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].pid, &processes[i].bt);
    }

    // Calculate waiting time for each process
    processes[0].wt = 0;
    for (int i = 1; i < n; i++) {
        processes[i].wt = processes[i - 1].bt + processes[i - 1].wt;
    }

    // Print process details
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float twt = 0.0, tat = 0.0;
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].bt, processes[i].wt, processes[i].bt + processes[i].wt);
        twt += processes[i].wt;
        tat += processes[i].bt + processes[i].wt;
    }

    // Calculate and print average waiting time and average turnaround time
    float awt = twt / n;
    float att = tat / n;
    printf("\nAvg. waiting time= %f\n", awt);
    printf("Avg. turnaround time= %f\n", att);

    return 0;
}

