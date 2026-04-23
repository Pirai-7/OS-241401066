#include <stdio.h>

int main() {
    int m, n;
    
    printf("Enter number of memory block:\n");
    scanf("%d", &m);
    
    int blockSize[m], remSize[m];
    
    printf("Enter size of each block:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        remSize[i] = blockSize[i];
    }
    
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    
    int processSize[n];
    
    printf("Enter size of each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int all = 0;
        for(int j = 0; j < m; j++) {
            if(remSize[j] >= processSize[i]) {
                int frag = remSize[j] - processSize[i];
                printf("Process %d of size %d is allocated to block %d of size %d with fragment %d\n", i+1, processSize[i], j+1, blockSize[j], frag);
                remSize[j] -= processSize[i];
                all = 1;
                break;
            }
        }
        if(!all) {
            printf("Process %d of size %d is not allocated\n", i+1, processSize[i]);
        }
    }
    
    return 0;
}
