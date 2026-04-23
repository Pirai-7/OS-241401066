#include <stdio.h>

int main() {
    int n, i, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n], ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++) {
        printf("Enter arrival and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    float total_tat = 0, total_wt = 0;
    int current_time = 0;
    int completed = 0;

    while(completed < n) {
        int idle = 1;
        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && rem_bt[i] > 0) {
                idle = 0;
                if(rem_bt[i] > quantum) {
                    current_time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    current_time += rem_bt[i];
                    rem_bt[i] = 0;
                    completed++;
                    
                    ct[i] = current_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    
                    total_tat += tat[i];
                    total_wt += wt[i];
                }
            }
        }
        if(idle) {
            current_time++;
        }
    }

    printf("\nAverage turnaround time: %.2f", total_tat / n);
    printf("\nAverage waiting time: %.2f\n", total_wt / n);

    return 0;
}
