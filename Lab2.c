#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fileptr;
    char array[1024];
    unsigned long long int user1, nice1, system1, idle1, iowait1, irq1, softirq1;
    unsigned long long int user2, nice2, system2, idle2, iowait2, irq2, softirq2;
    double usage;

    while (1) {
        fileptr = fopen("/proc/stat", "r");
        if (fileptr == NULL) {
            perror("Error opening /proc/stat");
            return 1;
        }
        fgets(array, sizeof(array), fileptr);
        sscanf(array, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user1, &nice1, &system1, &idle1, &iowait1, &irq1, &softirq1);
        fclose(fileptr);
        sleep(1);

        fileptr = fopen("/proc/stat", "r");
        if (fileptr == NULL) {
            perror("Error opening /proc/stat");
            return 1;
        }
        fgets(array, sizeof(array), fileptr);
        sscanf(array, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2);
        fclose(fileptr);

        unsigned long long int total1 = user1 + nice1 + system1 + idle1 + iowait1 + irq1 + softirq1;
        unsigned long long int total2 = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2;

        usage = (double)(total2 - total1 - (idle2 - idle1)) / (double)(total2 - total1) * 100.0;
        printf("Average CPU Utilization: %.2lf%%\n", usage);
    }
    return 0;
}