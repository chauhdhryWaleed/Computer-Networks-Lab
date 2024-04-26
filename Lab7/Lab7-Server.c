#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int customSocket2;
    struct sockaddr_in customServer2;
    char customServerMessage2[2000], customClientMessage2[2000];

    // Clearing Buffers
    memset(customServerMessage2, '\0', sizeof(customServerMessage2));
    memset(customClientMessage2, '\0', sizeof(customClientMessage2));

    // Creating Custom Socket
    customSocket2 = socket(AF_INET, SOCK_STREAM, 0);

    if (customSocket2 < 0)
    {
        printf("Custom Socket2 Creation Failed. Error!!!!!\n");
        return -1;
    }

    printf("Custom Socket2 Created\n");

    // Specifying the Custom IP and Port
    customServer2.sin_family = AF_INET;
    customServer2.sin_port = htons(12345); // Use a unique port number
    customServer2.sin_addr.s_addr = inet_addr("192.168.0.2"); // Use your specific server IP

    // Connecting to the Custom Server
    if (connect(customSocket2, (struct sockaddr*)&customServer2, sizeof(customServer2)) < 0)
    {
        printf("Custom Connection2 Failed. Error!!!!!");
        return -1;
    }

    printf("Custom Connected2\n");

    // Get Input from the User
    int i2 = 0;
    while (i2 < 2)
    {
        i2++;
        printf("Enter Custom Message2: ");
        fgets(customClientMessage2, sizeof(customClientMessage2), stdin);

        // Send the custom message to the server
        if (send(customSocket2, customClientMessage2, strlen(customClientMessage2), 0) < 0)
        {
            printf("Custom Send2 Failed. Error!!!!\n");
            return -1;
        }

        // Receive the custom message back from the server
        if (recv(customSocket2, customServerMessage2, sizeof(customServerMessage2), 0) < 0)
        {
            printf("Custom Receive2 Failed. Error!!!!!\n");
            return -1;
        }

        printf("Custom Server Message2: %s\n", customServerMessage2);

        if (!strcmp("Custom Response2", customServerMessage2))
        {
            break;
        }

        memset(customServerMessage2, '\0', sizeof(customServerMessage2));
        memset(customClientMessage2, '\0', sizeof(customClientMessage2));
    }

    // Closing the Custom Socket
    close(customSocket2);

    return 0;
}
