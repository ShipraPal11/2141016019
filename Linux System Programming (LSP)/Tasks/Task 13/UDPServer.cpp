/*NAME - Shipra Pal
REGISTRATION NO.-2141016019

UDP Socket Programming in C
Create a basic UDP program in C:
Implement both client and server functionalities within the program.
The client sends a message "Hello from Client" to the server.
he server receives the message, prints it, and responds with "Hello from Server."
The client receives the server's response and displays it.*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

using namespace std;

int main()
{
	int sockfd, len, p;
	struct sockaddr_in servaddr, clientaddr;
	char buff[1024];

	len = sizeof(struct sockaddr_in);
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
     
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(0);  

	bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	getsockname(sockfd, (struct sockaddr*)&servaddr, (socklen_t*)&len);
	cout << "After bind, ephemeral port: " << ntohs(servaddr.sin_port) << endl;

	recvfrom(sockfd, &p, sizeof(p), 0, (struct sockaddr*)&clientaddr, (socklen_t*)&len);
	cout << "\nClient sent: " << p << endl;

	cout << "\nGive a string to send to client: ";
	cin >> buff;

	sendto(sockfd, buff, 50, 0, (struct sockaddr*)&clientaddr, len);

	close(sockfd);
	return 0;
}

