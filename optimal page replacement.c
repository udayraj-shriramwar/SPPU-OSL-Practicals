#include <stdio.h>

int main() {
    int pages[30], frame[10];
    int n, f, i, j, k, pos, pageFaults = 0, flag1, flag2, max, temp[10];

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

        // Check if page already exists
        for (j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // Empty frame available
        if (flag1 == 0) {
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    pageFaults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replace optimal page
        if (flag2 == 0) {
            for (j = 0; j < f; j++) {
                temp[j] = -1;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            pos = 0;
            for (j = 0; j < f; j++) {
                if (temp[j] == -1) {
                    pos = j;
                    break;
                } else if (temp[j] > temp[pos]) {
                    pos = j;
                }
            }
            frame[pos] = pages[i];
            pageFaults++;
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
