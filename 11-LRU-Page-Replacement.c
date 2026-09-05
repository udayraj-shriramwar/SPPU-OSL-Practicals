#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[30], frame[10], time[10];
    int n, f, counter = 0, flag1, flag2, i, j, pos, pageFaults = 0;

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
        flag1 = flag2 = 0;

        // Check if page exists in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // Empty frame available
        if (flag1 == 0) {
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    counter++;
                    pageFaults++;
                    frame[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replace LRU page
        if (flag2 == 0) {
            pos = findLRU(time, f);
            counter++;
            pageFaults++;
            frame[pos] = pages[i];
            time[pos] = counter;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++)
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        if (flag1 == 0) printf("\tPage Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
