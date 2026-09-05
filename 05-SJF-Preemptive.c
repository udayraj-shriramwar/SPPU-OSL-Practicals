#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, min = INT_MAX, shortest = 0, finish_time;
    float totalWT = 0, totalTAT = 0;

    while (complete != n) {
        shortest = -1;
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            complete++;
            finish_time = time;
            tat[shortest] = finish_time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            totalWT += wt[shortest];
            totalTAT += tat[shortest];
        }
    }

    printf("\nPID\tAT\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    return 0;
}
