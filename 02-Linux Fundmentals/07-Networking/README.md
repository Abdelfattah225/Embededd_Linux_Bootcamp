# Networking

## Overview
learning how to use TCP/IP and UDP/IP for communication between processes on different machines. It covers developing both connection-oriented and connectionless programs using C++ and Linux system calls. The chapter provides hands-on recipes for creating a client-server application, demonstrating the fundamental concepts of network programming.

## Covered

### 1. Learning to Use TCP/IP for Communication
This recipe introduces TCP/IP, a reliable communication protocol used extensively on the internet. The chapter guides you through creating a simple client-server program using TCP/IP, where the server listens for incoming connections and the client connects to the server.

#### **Server Program**:
- **Socket Creation**: A socket is created to manage the TCP/IP connection.
- **Binding**: The socket is bound to a local machine's network interface and port.
- **Listening**: The server listens for incoming connections and accepts them.
- **Handling Connections**: After accepting a connection, the server logs client details, sends an acknowledgment, and reads the client's message.
- **Cleanup**: The server closes the sockets and frees resources after communication ends.

#### **Client Program**:
- **Socket Creation**: A socket is created to connect to the server.
- **Connecting to Server**: The client connects to the server using the server's IP and port.
- **Communication**: The client sends a message to the server and receives a response.
- **Cleanup**: The client closes the socket after communication ends.

### 2. Learning to Use UDP/IP for Communication
While not explicitly detailed in the content provided, this section would generally cover developing a connectionless-oriented program using UDP/IP, which is faster but less reliable than TCP/IP.

## How It Works

### Client Algorithm:
1. `socket()`
2. `connect()`
3. `send()`
4. `receive()`

### Server Algorithm:
1. `socket()`
2. `bind()`
3. `listen()`
4. `accept()`
5. `receive()`
6. `send()`

### Key Concepts:
- **Connection-Oriented Communication**: TCP/IP ensures reliable communication using a three-way handshake mechanism.
- **Blocking Calls**: Functions like `connect()` and `accept()` are blocking, meaning the program waits until the operation is completed.

## Improvements
- **Handling Multiple Connections**: 
  - Implement an infinite loop over `accept()` to keep the server always available.
  - Use threading (`std::thread` or `std::async`) to manage multiple concurrent connections.

- **Protocol Awareness**: Ensure the client and server agree on a protocol for data exchange to enable consistent communication.

## Conclusion
By following the provided code examples and explanations, readers can build and run a simple TCP/IP client-server application. This chapter lays a strong foundation for understanding and implementing basic network programming concepts.

