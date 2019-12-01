#include "client_socket.hpp"
#include <chrono>

using namespace std::chrono; // nanoseconds, system_clock, seconds

Client_Socket::Client_Socket( void ){
  create_socket();
}

int Client_Socket::create_socket( void ){
  sockfd = socket(ADDR_FAMILY, SOCK_DGRAM, IPPROTO_UDP); // IPV4, TCP, Protocolo
  return sockfd;
}

int Client_Socket::initialize_socket( int port_client ){
  memset((char*) &server_address, '0', sizeof(server_address));
  server_address.sin_family      = ADDR_FAMILY;
  server_address.sin_port        = htons(port_client); 
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  client_size = sizeof(server_client);
  server_size = sizeof(server_address);

  return inet_pton(ADDR_FAMILY, "127.0.0.1", &server_address.sin_addr);
}

int Client_Socket::send_data( void ){
  message ="1000"; 
  
  return sendto(sockfd, message, strlen(message), 0, (struct sockaddr*) & server_address, server_size);
  
}

int Client_Socket::receive_data( void ){
	int check = recvfrom(sockfd, buffer, SIZEBUFFER, 0, (struct sockaddr*) & server_client, &client_size);
	cout <<" Quantidade de numeros primos : " << buffer << endl;
  return check;
}

int Client_Socket::check_data() {
	return SUCESS;
}

void Client_Socket::close_socket( void ) {
	shutdown(sockfd, SHUT_RD);
	shutdown(sockfd, SHUT_WR);
	close(sockfd);
}

void Client_Socket::client_shutdown(void) {
	shutdown(sockfd, SHUT_WR);
}
