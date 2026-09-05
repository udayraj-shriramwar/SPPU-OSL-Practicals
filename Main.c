#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    printf("Sorted array by child: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    char *newargv[n + 2];
    char buffers[n][12];

    newargv[0] = argv[1];
    for (int i = 0; i < n; i++) {
        sprintf(buffers[i], "%d", arr[i]);
        newargv[i + 1] = buffers[i];
    }
    newargv[n + 1] = NULL;

    pid_t pid = fork();
	if (pid == 0) {
	    execve(newargv[0], newargv, NULL);
	    exit(1);
	} else {
	    wait(NULL);
	}
      

    return 0;
}

