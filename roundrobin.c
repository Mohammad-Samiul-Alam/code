#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // arrival and burst time
    int i, at[n], bt[n], rt[n];
    for(i=0; i<n; i++) {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time initially = burst time
    }

    // time quantum
    int tq;
    printf("Enter the time quantum value: ");
    scanf("%d", &tq);

    // completion time
    int flag, completed=0, time=0, ct[n], tat[n], wt[n];
    float atat = 0, awt=0;

    while (completed<n) {
        flag=0;
        for(i=0; i<n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                flag = 1;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    atat += tat[i];
                    awt += wt[i];
                }
            }
        }
        if(flag == 0) time++;
    }

    atat /= n;
    awt /= n;

    // result
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage Turnaround Time = %.2f", atat);
    printf("\nAverage Waiting Time = %.2f\n", awt);

    return 0;
}
