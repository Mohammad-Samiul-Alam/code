#include<stdio.h>
int main() {
    int process_id, i;

    printf("Enter the number of process id: ");
    scanf("%d", &process_id);

    int arrival_t[process_id], burst_t[process_id], completion_t[process_id], turnaround_t[process_id], waiting_t[process_id];

    // Arrival and burst part
    for(i=0; i<process_id; i++) {
        printf("Enter the arrival time of %d: ", i+1);
        scanf("%d", &arrival_t[i]);
        printf("Enter the burst time of %d: ", i+1);
        scanf("%d", &burst_t[i]);
    }
    // completion time
    completion_t[0] = arrival_t[0] + burst_t[0];
    for(i=1; i<process_id; i++) {
        if(arrival_t[i] > completion_t[i-1]) {
            completion_t[i] = arrival_t[i] + burst_t[i]; //cpu idle(faka thaka bujai)
        } else { //(arrival_t[i] <= completion_t[i-1])
            completion_t[i] = completion_t[i-1] + burst_t[i]; //main algorithm
        }
    }

    float average_turnaround_t = 0, average_waiting_t = 0;
    // turnaround time and waiting time
    for(i=0; i<process_id; i++) {
        turnaround_t[i] = completion_t[i] - arrival_t[i];
        waiting_t[i] = turnaround_t[i] - burst_t[i];
        average_turnaround_t += turnaround_t[i]; // average_turnaround_t = 5 + 6 + 5 = 16 (just example)
        average_waiting_t += waiting_t[i]; // average_waiting_t = 5 + 6 + 5 = 16 (just example)
    }

    average_turnaround_t /= process_id; // average_turnaround_t = 5 + 6 + 5 / process_id = answer will get (just example)
    average_waiting_t /= process_id; // average_waiting_t = 5 + 6 + 5 / process_id = answer will get (just example)

    // print table(process id, completion time, turnaround time, waiting time)
    printf("\n process_id \t completion_t \t turnaround_t \t waiting_t");
    for(i = 0; i<process_id; i++) {
        printf("\n process %d \t %d \t %d \t %d",i+1, completion_t[i], turnaround_t[i], waiting_t[i]);
    }

    // print average turn around time and waiting time
    printf("\n Average turn around time: %.2f", average_turnaround_t);
    printf("\n Average waiting time: %.2f", average_waiting_t);
}