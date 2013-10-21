#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
/*#include <sys/types.h>
#include <WinSock2.h>
#include<WinSock.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
#include <stdio.h>
/*#include <netdb.h>
#include <unistd.h>        // only needed for definition of gethostname for part 1
#include <netinet/in.h>    // only needed for section 8
#include <arpa/inet.h>     // only needed for section 8
#include <sys/socket.h>    // only needed for definition of AF_INET for part 5
#include <sys/param.h>    // only needed for definition of MAXHOSTNAMELEN for part 1

class internet{
void main(int argc, char *argv[])
{ 
  // get server IP address and port number of server from command line
  if (argc!=3)
  { fprintf(stderr, "no address and port\n"); exit(1); }
  char * server = argv[1];
  int port_number = atol(argv[2]);

  // Step 1 Look up server to get numeric IP address
  hostent * record = gethostbyname(server);
  if (record==NULL) { herror("gethostbyname failed"); exit(1); }
  in_addr * addressptr = (in_addr *) record->h_addr;

  // Step 2 create a socket
  int main_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (main_socket<0) { perror("socket creation"); exit(1); }

  // Step 3 create a sockaddr_in to describe the server
  sockaddr_in server_info;
  server_info.sin_len = sizeof(server_info);
  server_info.sin_family = AF_INET;
  server_info.sin_addr = * addressptr;
  server_info.sin_port = htons(port_number);

  // Step 4 connect
  int r = connect(main_socket, (sockaddr *) &server_info, sizeof(server_info));
  if (r<0) { perror("connect"); exit(1); }
  printf("Connected to %s\n", inet_ntoa(* addressptr));

  // Step 5 (Optional) Create normal files for communication with the client
  //        Or just use read and write directly on the session_socket itself
  FILE * r_connection=fdopen(main_socket, "r");
  FILE * w_connection=fdopen(main_socket, "w");

  // Step 6 (Optional, for web servers only)
  //        Only include the following two lines when connecting to a web server
  fprintf(w_connection, "GET /index.html HTTP/1.0\r\n\r\n");
  fflush(w_connection);

  // Step 7 Deal with the client
  char line[1000];
  for (int i=1; 1; i+=1)
  { char *s=fgets(line, 999, r_connection);
    if (s==NULL)
    { printf("Disconnected\n");
      break; }
    printf("Line %d: %s", i, line); }

  // Step 8 When finished send all lingering transmissions and close the connection
  fflush(w_connection);
  fclose(w_connection);
  fclose(r_connection);   
  close(main_socket); }
};*/