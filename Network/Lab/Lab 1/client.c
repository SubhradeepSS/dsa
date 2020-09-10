#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *client_start_msg = "Hello from Client!!"; 
	char buffer[1024] = {0}; 

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	}
	else{
		printf("Client socket created.\n");
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	}
	else{
		printf("Socket connected.\n");
	}

	send(sock, client_start_msg, strlen(client_start_msg), 0 ); 
	printf("Client message sent!!!\n"); 
	valread = read(sock , buffer, 1024); 
	printf("Message from server: %s\n",buffer ); 
	return 0; 
} 
