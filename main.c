#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdio.h>

const int PORT = 2727;

int main()
{
  // create serve socket wtih IPV6 IP
  int server_socket, client_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // create server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;
  bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

  // listen on PORT
  listen(server_socket, 5);

  // create client
  client_socket = accept(server_socket, NULL, NULL);
  char buffer[1024];
  int bytes_read =  read(client_socket, buffer, sizeof(buffer));
  if (bytes_read > 0) {
    buffer[bytes_read] = '\0';
    printf("Received data from server %s\n", buffer);
  } else if (bytes_read == 0) {
    printf("Connection closed to client");
  } else {
    printf("Error reading from client");
    return 0;
  }
  write(client_socket, "Hello", sizeof("Hello"));

  close(client_socket);
  close(server_socket);

  return 0;
}
