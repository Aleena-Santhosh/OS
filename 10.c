#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int search(int key, int frame[], int f) {
    for (int i = 0; i < f; i++) {
        if (frame[i] == key)
            return 1;
    }
    return 0;
}
int fifo(int ref[], int n, int f) {
    int frame[f], faults = 0, pos = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        if (!search(ref[i], frame, f)) {
            frame[pos] = ref[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }
    return faults;
}
int lru(int ref[], int n, int f) {
    int frame[f], time[f], faults = 0, t = 0;
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < f; j++) {
            if (frame[j] == ref[i])
                found = j;
        }
        if (found != -1) {
            time[found] = ++t; 
        } else {
            int min = 0;
            for (int j = 1; j < f; j++) {
                if (time[j] < time[min])
                    min = j;
            }
            frame[min] = ref[i];
            time[min] = ++t;
            faults++;
        }
    }
    return faults;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <length> <frames>\n", argv[0]);
        return 0;
    }
    int n = atoi(argv[1]);
    int f = atoi(argv[2]);
    int ref[n];
    srand(time(0));
    printf("Reference String: \n");
    for (int i = 0; i < n; i++) {
        ref[i] = rand() % 10;
        printf("%d ", ref[i]);
    }
    printf("\n\nFIFO Faults: %d", fifo(ref, n, f));
    printf("\nLRU Faults: %d\n", lru(ref, n, f));
    return 0;
}
