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
        int bestIdx = -1;
        
        for(int j = 0; j < m; j++) {
            if(remSize[j] >= processSize[i]) {
                if(bestIdx == -1 || remSize[j] < remSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        
        if(bestIdx != -1) {
            int frag = remSize[bestIdx] - processSize[i];
            printf("Process %d of size %d is allocated to block %d of size %d with fragment %d\n", 
                   i + 1, processSize[i], bestIdx + 1, blockSize[bestIdx], frag);
            
            remSize[bestIdx] -= processSize[i]; 
        } else {
            printf("Process %d of size %d is not allocated\n", i + 1, processSize[i]);
        }
    }
    
    return 0;
}
