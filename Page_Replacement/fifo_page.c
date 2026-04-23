#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, found, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    int pos = 0;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        
        if(found == 0)
            printf("\t\t(Miss)\n");
        else
            printf("\t\t(Hit)\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
