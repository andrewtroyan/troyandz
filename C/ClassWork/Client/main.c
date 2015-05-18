#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//Сокет - "файл", способ общаться с другим процессом или компьютером. Системные и сетевые.
//Сетевые поддерживают различные протоколы.
//TCP - пакетный протокол.

//Сервер - это тот, кто слушает. Клиент - тот, кто начинает разговор первым.

/*
<sys/socket.h>:
int socket(int domain, int type, int protocol);
Возвращает сокет, если его получилось создать и -1, если ничего не получилось.
domain: AF_INET - сетевой
type: SOCK_STREAM - TCP
protocol: 0

int connect(int socket, const struct sockadd *peer, int peer_len);

const struct sockadd *peer - структура, с кем мы собираемся общаться
int peer_len - ее длина

Возвращает 0, если ок и -1, если все плохо.
*/

int main()
{
    //создаем сокет
    int aSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(aSocket < 0)
    {
        write(2, "Error: socket.\n", 15);
        return 1;
    }

    int error;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7500); //7500 - порт, по которому будем общаться
    peer.sin_addr.s_addr = inet_addr("127.0.0.1");

    error = connect(aSocket, (struct sockaddr *)&peer, sizeof(peer));
    if(error)
    {
        write(2, "Error: connect.\n", 16);
        return 1;
    }

    error = write(aSocket, "123", 3);
    if(error <= 0)
    {
        write(2, "Error: write.\n", 14);
        return 1;
    }

    char buf[3];
    error = read(aSocket, buf, 3);
    if(error <= 0)
    {
        write(2, "Error: read.\n", 13);
        return 1;
    }
    else
    {
        write(1, buf, 3);
        write(1, "\n", 1);
    }

    return 0;
}
