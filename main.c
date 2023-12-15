#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
  /*
    AF_INET - Internet domain sockets for use with IPV4 addresses.
    SOCK_STREAM - Byte-stream socket.
  */
  int server_socket = socket(AF_INET6, SOCK_STREAM, 0);

  // create server
  const int PORT = 2727;
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET6;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind(int fd, const struct sockaddr *addr, socklen_t len)
  bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));


  return 0;
}
