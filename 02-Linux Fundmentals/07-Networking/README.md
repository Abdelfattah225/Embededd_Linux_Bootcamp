# Network Programming Overview

## Introduction
This document provides an overview of network programming concepts, focusing on TCP/IP and UDP/IP communication. It covers how to develop connection-oriented and connectionless programs using C++ and Linux system calls.

## Network Stack Concepts

### TCP/IP Communication
TCP/IP (Transmission Control Protocol/Internet Protocol) is a fundamental protocol suite used for reliable communication over the internet. TCP is connection-oriented, meaning it ensures data is accurately transmitted between processes on different machines.

#### **Creating a TCP/IP Client-Server Application**

**Server Program:**
1. **Socket Creation**: Use `socket()` to create a socket for managing TCP/IP connections.
2. **Binding**: Bind the socket to a network interface and port on the local machine using `bind()`.
3. **Listening**: Set the socket to listen for incoming connections with `listen()`.
4. **Accepting Connections**: Accept incoming connections using `accept()`.
5. **Handling Communication**: After accepting a connection, log client details, send an acknowledgment, and read messages from the client.
6. **Cleanup**: Close the sockets and free resources after communication ends using `close()`.

**Client Program:**
1. **Socket Creation**: Create a socket with `socket()` for connecting to the server.
2. **Connecting to Server**: Connect to the server using `connect()` with the server's IP and port.
3. **Sending and Receiving Data**: Send a message to the server with `write()` and receive a response using `read()`.
4. **Cleanup**: Close the socket after communication ends.

### UDP/IP Communication
UDP (User Datagram Protocol) is a connectionless protocol that provides faster communication but does not guarantee reliability. While not detailed in this overview, UDP is used for applications where speed is critical and occasional data loss is acceptable.

## Key Concepts

### Connection-Oriented Communication
- **TCP/IP**: Ensures reliable, ordered, and error-checked delivery of data.
- **Three-Way Handshake**: TCP uses a three-phase process to establish a connection before data transmission.

### Blocking Calls
- **Client**: Functions like `connect()` and `read()` are blocking, meaning the client waits for these operations to complete.
- **Server**: Functions like `accept()` and `receive()` are blocking, meaning the server waits until an incoming connection or data is available.

## Enhancements for Concurrent Connections
- **Server Improvement**: Implement an infinite loop around `accept()` to continuously accept connections. Use threading (`std::thread` or `std::async`) to handle multiple concurrent connections.

- **Protocol Agreement**: Ensure that both client and server agree on a communication protocol for consistent data exchange.

## Conclusion
This overview introduces the basics of network programming with TCP/IP and UDP/IP. By understanding and implementing these concepts, you can build robust client-server applications and manage network communication effectively.

