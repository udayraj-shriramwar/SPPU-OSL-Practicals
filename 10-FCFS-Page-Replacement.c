#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, k = 0, pageFaults = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames (minimum 3): ");
    scanf("%d", &f);
    if (f < 3) f = 3;

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tPage Fault\n");
    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page exists in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If not present, replace using FCFS
        if (flag == 0) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        if (flag == 0) printf("\tPage Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
