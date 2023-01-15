#include "SocketClient.h"

int SocketClient::initSocket()
{
    /*
    *  return 1    Error WSAStartup;
    *  return 2    Error getaddrinfo;
    *  return 3    Error ConnectScocket;
    *  return 4    Error connect;
    */
    int retErorr = 0;

    retErorr = WSAStartup(MAKEWORD(2, 2), &this->wsaData);
    if (retErorr != 0) return 1;

    ZeroMemory(&this->hints, sizeof(this->hints));
    this->hints.ai_family = AF_INET;
    this->hints.ai_socktype = SOCK_STREAM;
    this->hints.ai_protocol = IPPROTO_TCP;

    retErorr = getaddrinfo("localhost", "80", &this->hints, &this->addrResult);
    if (retErorr != 0) return 2;

    this->ConnectSocket = socket(this->addrResult->ai_family, this->addrResult->ai_socktype, this->addrResult->ai_protocol);
    if (this->ConnectSocket == INVALID_SOCKET) return 3;

    retErorr = connect(this->ConnectSocket, this->addrResult->ai_addr, (int)this->addrResult->ai_addrlen);
    if (retErorr == SOCKET_ERROR)return 4;



    return 0;
}

void SocketClient::Exit()
{

    closesocket(ConnectSocket);
    freeaddrinfo(addrResult);
    WSACleanup();
}

SocketClient::SocketClient()
{

}

SocketClient::~SocketClient()
{
    this->Exit();
}

void SocketClient::clientStart()
{
    int result = this->initSocket();
    if (result == 0)std::cout << "Client ready!" << std::endl;
    else
    {
        std::cout << "Conect error!" << std::endl;
        this->Exit();
    }

}

/*void SocketClient::read()
{

    char recvBuffer[512];
    int temp = 0;
    while (true)
    {
        ZeroMemory(recvBuffer, 512);

        temp = recv(this->ConnectSocket, recvBuffer, 512, 0);
        if (temp > 0)
        {
            if ((recvBuffer[0] == '9') && (recvBuffer[1] == '9'))
            {
                std::cout << "\nSerwer exit  " << std::endl;
                this->Exit();
                return;
            }
            std::cout << recvBuffer << std::endl;
        }
        else if (temp == 0)
        {
            std::cout << "Connection closed" << std::endl;
            break;
        }
        else
        {
            std::cout << "Error recv" << std::endl;
            break;
        }
    }
}*/

int SocketClient::read(int)
{


    int step = 10;
    char recvBuffer[5];

    ZeroMemory(recvBuffer, 5);
    int result = recv(this->ConnectSocket, recvBuffer, 5, 0);
    if (result > 0)
    {
        if ((recvBuffer[0] == '/') && (recvBuffer[1] == '/'))
        {
            step = recvBuffer[2] - '0' - 1;
            std::cout << "Received date:  " << step << std::endl;
            return step;
        }
    }
    else if (result == 0)
    {
        std::cout << "Connection closed" << std::endl;
        return step;
    }
    else
    {
        std::cout << "Error recv" << std::endl;
        return step;
    }

    return 11;
}

void SocketClient::readServer(int(&buff)[11])
{
    int result = 0;
    char Buffer[512];
    int stepNum = 0;
    int step = 0;

    while (true)
    {
        ZeroMemory(Buffer, 512);
        result = recv(this->ConnectSocket, Buffer, 512, 0);
        if (result > 0)
        {
            if ((Buffer[0] == '/') && (Buffer[1] == '/') && (Buffer[3] == '-'))
            {
                stepNum = Buffer[2] - '0';
                step = Buffer[4] - '0';
                buff[stepNum] = step;
                std::cout << "Turn number:  " << stepNum << "  Pizition:  " << step << std::endl;
            }
        }
        else if (result == 0)
        {
            std::cout << "Connection closed" << std::endl;
            return;
        }
        else
        {
            std::cout << "Error recv" << std::endl;
            return;
        }
    }
}

void SocketClient::sendToServer(char sendBuffer[512])
{
    int result = send(this->ConnectSocket, sendBuffer, 512, 0);
    if (result == SOCKET_ERROR)std::cout << "Error send " << result << std::endl;
}

void SocketClient::sendToServer(int buffer)
{
    char bufferint[4];
    bufferint[0] = '*';
    bufferint[1] = '*';
    bufferint[2] = (buffer % 10) + '1';
    bufferint[3] = 0;

    int result = send(this->ConnectSocket, bufferint, 4, 0);
    if (result == SOCKET_ERROR)std::cout << "Error send " << result << std::endl;
}
