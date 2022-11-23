#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>


int main() {
    int conn_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_port = htons(1234);
    address.sin_family = AF_INET;
    //figure out what the fuck this function does and why
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);


    int status = connect(conn_fd, (struct sockaddr *)&address, sizeof(address));
    printf("connect: %s\n", strerror(status));


    char buf[1024] = { 0 };

    recv(conn_fd, buf, 1024, 0);

    printf("%s\n", buf);


    close(conn_fd);


    return 0;
}
