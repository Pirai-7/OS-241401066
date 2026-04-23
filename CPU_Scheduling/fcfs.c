#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++) {
        printf("Enter arrival and burst time: ");
        scanf("%d %d", &at[i], &bt[i]);
    }

    float total_tat = 0, total_wt = 0;

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage turnaround time: %.2f", total_tat / n);
    printf("\nAverage waiting time: %.2f\n", total_wt / n);

    return 0;
}
