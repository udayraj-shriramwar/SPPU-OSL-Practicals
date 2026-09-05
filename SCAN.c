#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, diskSize, seekTime = 0;
    int requests[100], temp, index;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (e.g. 200): ");
    scanf("%d", &diskSize);

    // Sort requests
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find where the head is
    for (i = 0; i < n; i++) {
        if (head < requests[i]) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: ");
    // Move towards higher tracks (away from spindle)
    for (i = index; i < n; i++) {
        printf("%d ", requests[i]);
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }

    // Go to the end (max track)
    seekTime += abs((diskSize - 1) - head);
    head = diskSize - 1;

    // Then move back toward lower tracks
    for (i = index - 1; i >= 0; i--) {
        printf("%d ", requests[i]);
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", seekTime);
    printf("Average Seek Time = %.2f\n", (float)seekTime / n);
    return 0;
}
