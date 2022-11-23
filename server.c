#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        return -1;
    }

    struct sockaddr_in address;

    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_family = AF_INET;
    address.sin_port = htons(1234);

    int status = bind(sock_fd, (struct sockaddr *)&address, sizeof(address));
    printf("bind: %s\n", strerror(status));

    status = listen(sock_fd, 5);
    printf("listen: %s\n", strerror(status));

    int size = sizeof(address);


    //accept here
    int conn_fd = accept(sock_fd, (struct sockaddr *)&address, (socklen_t *)&size);
    printf("file descriptor %d\n", conn_fd);

    char buf[1024] = "This is a test message!\n";

    send(conn_fd, buf, 1024, 0);


    close(conn_fd);
    close(sock_fd);

    return 0;
}
