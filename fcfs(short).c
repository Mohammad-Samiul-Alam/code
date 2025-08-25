#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    // arrival time and burst time
    int i, at[n], bt[n];
    for(i=0; i<n; i++) {
        printf("Enter the arrival time of %d:", i+1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of %d:", i+1);
        scanf("%d", &bt[i]);
    }
    // completion time
    int ct[n];
    ct[0] = at[0] + bt[0];
    for(i=1; i<n; i++) {
        if(at[i]>ct[i-1]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }
    // turnaround time and waiting time
    int tat[n], wt[n];
    float atat = 0, awt = 0;
    for(i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
    atat /= n;
    awt /= n;
    // result
    printf("\nProcess_id\tcompletion_time\tturnaround_time\twaiting_time");
    for(i=0; i<n; i++) {
        printf("\n\t%d\t%d\t\t%d\t\t%d", i+1, ct[i], tat[i], wt[i]);
    }
    printf("\nAverage turn around time: %.2f", atat);
    printf("\nAverage waiting time %.2f", awt);

}