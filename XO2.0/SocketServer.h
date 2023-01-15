#pragma once
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

class SocketServer
{

private:
    //Variables
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;


    const char* sendBuffer = "Hello World! - Server";

    char recvBuffer[512];

    //Functions
    int initServer();



public:

    SocketServer();
    ~SocketServer();
    void ServerStart();
    bool addClient();
    int readClient(int a);
    void readClient();
    void readClient(int(&buff)[11]);
    void sendToClient(const char* buff);
    void sendToClient(int buffer);
};

