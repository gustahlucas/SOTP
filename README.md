# SOTP
Primos Server Cliente UTP
# ----------------TRABALHO PRATICO II - III ------------------ 
Grupo: Gustavo Lucas Moreira 
       Philipe Lemos Parreira 

Enunciado do trabalho pratico: 

Elaboração e implementação utilizando o Docker, onde uma instância (conteiner) será o cliente que emite uma mensagem, 
um valor limite do qual será calculado pelo servidor o numero de primos dentre zero-valor limite recebido, 
assim o outra instancia será o servidor. Isto no mesmo computador, mas com conteiners diferentes.

Assim é necessario fazer a instalação do ambiente docker host local ou maquina virtual(nesse caso de uso). 
Maquina utilizada: 
VirtualBox Oracle - Linux Ubuntu 64-bits

# --Instalação do Docker: 
 1. Verificar a versao do kernel para conferir a compatibilidade com o Docker (superior ou igual a 3.8)
    #uname -r
 2. Atualização da lista atual de pacotes 
    # sudo apt-get update 
 3. Instalação de alguns pacotes de pre-requisitos que permitem que o apt utilize pacotes via HTTPS:
    #sudo apt install apt-transport-https ca-certificates curl software-properties-common 
 4. Realização da instalação utilizando o script de instalação por atraves da execução do curl:
    #curl -fsSL https://get.docker.com/ | sudo apt-key add -
 5. Adicionando o repositorio Docker as fontes APT: 
    #sudo add-pt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
 6. Atualize o banco de dados de pacotes com os pacotes Docker 
    #sudo apt update 
 7. Utilizando o Docker como sudo:
    #sudo usermod -aG docker ${USER} 

# -- DOCKERFILE --
1. Crie um Dockerfile em cada repositorio 
    SERVER: 
	FROM gcc:4.9 
	MAINTAINER Gustavo Lucas 
	COPY . /usr/src/server
	WORKDIR /usr/src/server
	RUN g++ -o server *.cpp -lpthread -std=c++11
	CMD ["./server"] 
     
     CLIENTE:
	FROM gcc:4.9 
	MAINTAINER Gustavo Lucas 
	COPY . /usr/src/cliente
	WORKDIR /usr/src/cliente
	RUN g++ -o cliente *.cpp -lpthread -std=c++11
	CMD ["./cliente"] 
 
2. Build e run a Docker Image 
	SERVER: 
		1. build:
			$ docker build -t server .
		2. run:
			$ docker run -it --rm --name my-running-server server bash
	CLIENTE: 
		1. build:
			$ docker build -t cliente .
		2. run:
			$ docker run -it --rm --name my-running-cliente cliente bash

# -- EXECUÇÃO -- 
 1. ABRA TRES TERMINAIS, PRIMEIRO E SEGUNDO NOS RESPECTIVOS REPOSITORIOS DE SERVER E CLIENTE, O TERCEIRO E PARA ACOMPANHAMENTO DO DOCKERS ATIVOS 

 2. EXECUTE OS PASSOS DOCKERFILE NOS TERMINAIS DE SERVER E CLIENTE 

 3. NO TERCEIRO TERMINAL EXECUTE: 
	$ docker ps
 	sera mostrado os dockers em uso no momento, em seguida 
 execute o comando docker:
	$ docker inspect my-running-server | grep IPAddress
	será mostrado o endereço ip do servidor, copie e cole sobre o codigo cliente em:

	int Client_Socket::initialize_socket( int port_client ){
	  memset((char*) &server_address, '0', sizeof(server_address));
	  server_address.sin_family      = ADDR_FAMILY;
	  server_address.sin_port        = htons(port_client); 
	  server_address.sin_addr.s_addr = inet_addr("ip address do servidor");
	  client_size = sizeof(server_client);
	  server_size = sizeof(server_address);
	  return inet_pton(ADDR_FAMILY, "ip address do servidor", &server_address.sin_addr);
    }
 4. VÁ AO TERMINAL DO CLIENTE E REALIZE A build e run do mesmo para atualização da image 

 5. Execute o ./server no terminal do servidor 

 6. Execute o ./cliente no terminal do cliente 

 7. Observe os valores de tempo de execução e mensagem enviados pelo servidor ao cliente. 




