FROM gcc:4.9 
MAINTAINER Gustavo Lucas 
COPY . /usr/src/server
WORKDIR /usr/src/server
RUN g++ -o server *.cpp -lpthread -std=c++11
CMD ["./server"] 
 

