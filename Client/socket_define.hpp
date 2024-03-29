#ifndef SOCKETDEFINE_H
#define SOCKETDEFINE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <thread>
#include <vector>
#include <string>

#define PORT              54000
#define MAXCONECTION      SOMAXCONN // SOMAXCONN: Numero maximo de conexões
#define SIZEBUFFER        4096
#define RECEIVING          1
#define CONNECTION_FAILED -1
#define INVALID_SOCKET    -1
#define SOCKET_ERROR      -1
#define SEND_ERROR        -1
#define READ_ERROR        -1
#define SRC_INV_ADDR       0
#define AF_INV_ADDR       -1
#define SUCESS            42
#define ATTEMPTS          100
#define ADDR_FAMILY       AF_INET     //Address Family
#define BIND_LC_INTF      INADDR_ANY //Bind local interface
#define NUM_MAX_HOST      NI_MAXHOST //Number max of hosts
#define NUM_MAX_SERV      NI_MAXSERV //Number max of service
#define NUM_MAX_CLIENT    50

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::thread;
using std::vector;

#endif
