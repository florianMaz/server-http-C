/*
/	Etude d'un serveur ECHO
/	Code du serveur
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
        
    char buffer[4096]
    int listen_fd, conn_fd;

    struct sockaddr_in servaddr;
    struct sockaddr cliaddr;

    socklen_t sa_len=sizeof(cliaddr);
    char * buffer = 0;
    long length;
    char *simpleHeader = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\r\n";

    FILE * file = fopen ("index.html", "r");

    if (file) {
    fseek (file, 0, SEEK_END);
    length = ftell (file);
    fseek (file, 0, SEEK_SET);
    bufferFile = malloc (length);
    fread (bufferFile, 1, strlen(simpleHeader), simpleHeader);
    if (bufferFile) {
        fread (bufferFile, 1, length, file);
    }
    fclose (file);

    
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(8081);

    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 10);

    //conn_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    
    while(1) {
        conn_fd = accept(listen_fd, &cliaddr, &sa_len);
        bzero( buffer, 100);
 
        int valueRead = read(conn_fd,buffer,100);
 
        printf("Echoing back - %s",buffer);

    
 
        write(conn_fd, welcomeMsg, strlen(welcomeMsg)+1);
        close(conn_fd);
    }

    return 0;
}