/*
Grupo: 4CV1
Flores Anzurez Marco Antonio

Comunicación de procesos utilizando sockets
Este es un ejemplo de un servidor y un cliente que se comunican a través de un socket.
*/
// Cliente
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int sock_desc;
    struct sockaddr_in serv_addr;
    char buffer[200];

    // Creación del socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    // Configuración de la dirección del servidor
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    // Conexión al servidor
    connect(sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // Envía y recibe datos del servidor
    while (1) {
        // Solicita al usuario que escriba un mensaje
        printf("Escribe un mensaje: ");
        gets(buffer);

        // Envía el mensaje al servidor
        write(sock_desc, buffer, strlen(buffer)+1);

        // Limpia el buffer
        memset(buffer, 0, sizeof(buffer));

        // Lee la respuesta del servidor
        read(sock_desc, buffer, sizeof(buffer));

        // Imprime el mensaje del servidor
        printf("Mensaje del servidor: %s\n", buffer);
    }

    return 0;
}
