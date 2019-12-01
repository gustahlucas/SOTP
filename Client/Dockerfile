FROM gcc:4.9 
MAINTAINER Gustavo Lucas 
COPY . /usr/src/cliente
WORKDIR /usr/src/cliente
RUN g++ -o cliente *.cpp -lpthread -std=c++11
CMD ["./cliente"] 
 

