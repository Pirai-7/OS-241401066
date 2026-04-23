#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], is_completed[n];

    for(i = 0; i < n; i++) {
        printf("Enter arrival and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
        is_completed[i] = 0;
    }

    float total_tat = 0, total_wt = 0;
    int current_time = 0;
    int completed = 0;

    while(completed != n) {
        int min_bt = 9999999;
        int shortest_idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && is_completed[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    shortest_idx = i;
                }
                else if(bt[i] == min_bt) {
                    if(at[i] < at[shortest_idx]) {
                        min_bt = bt[i];
                        shortest_idx = i;
                    }
                }
            }
        }

        if(shortest_idx != -1) {
            ct[shortest_idx] = current_time + bt[shortest_idx];
            tat[shortest_idx] = ct[shortest_idx] - at[shortest_idx];
            wt[shortest_idx] = tat[shortest_idx] - bt[shortest_idx];
            
            total_tat += tat[shortest_idx];
            total_wt += wt[shortest_idx];
            
            is_completed[shortest_idx] = 1;
            current_time = ct[shortest_idx];
            completed++;
        } else {
            current_time++;
        }
    }

    printf("\nAverage turnaround time: %.2f", total_tat / n);
    printf("\nAverage waiting time: %.2f\n", total_wt / n);

    return 0;
}
