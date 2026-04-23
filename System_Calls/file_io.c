#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char write_buf[] = "Hello, System Calls!\n";
    char read_buf[50];

    fd = open("testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Failed to open file for writing.\n");
        return 1;
    }
    
    write(fd, write_buf, strlen(write_buf));
    printf("Wrote to file successfully.\n");
    close(fd);

    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file for reading.\n");
        return 1;
    }

    int bytes_read = read(fd, read_buf, sizeof(read_buf) - 1);
    read_buf[bytes_read] = '\0'; 
    
    printf("Read from file: %s", read_buf);
    close(fd);

    return 0;
}
