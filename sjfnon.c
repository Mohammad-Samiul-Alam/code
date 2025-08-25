#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int i, arrival_t[n], burst_t[n];
    for(i=0; i<n; i++) {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &arrival_t[i]);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &burst_t[i]);
    }

    int completion_t[n], done[n], turnaround_t[n], waiting_t[n];
    float avg_tat=0, avg_wt=0;
    int completed=0, time=0;

    // Initialize done array to 0
    for(i=0; i<n; i++) done[i] = 0;

    while(completed < n) {
        int index = -1;
        int min_bt = 9999;

        for(i=0; i<n; i++) {
            if(!done[i] && arrival_t[i] <= time && burst_t[i] < min_bt) {
                min_bt = burst_t[i];
                index = i;
            }
        }

        if(index == -1) {
            // No process has arrived yet, CPU idle
            time++;
        } else {
            time += burst_t[index];
            completion_t[index] = time;
            turnaround_t[index] = completion_t[index] - arrival_t[index];
            waiting_t[index] = turnaround_t[index] - burst_t[index];
            avg_tat += turnaround_t[index];
            avg_wt += waiting_t[index];
            done[index] = 1;
            completed++;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nProcess\tCompletion\tTurnaround\tWaiting\n");
    for(i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, completion_t[i], turnaround_t[i], waiting_t[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
