#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>


class SocketClient
{
private:

    //variables
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ConnectSocket = INVALID_SOCKET;

    //Function
    int initSocket();
    void Exit();


public:
    SocketClient();
    ~SocketClient();
    void clientStart();

    //void read();
    int read(int);
    void readServer(int(&buff)[11]);

    void sendToServer(char sendBuffer[512]);
    void sendToServer(int buffer);


};
