#include <iostream>       
#include <string>         
#include <unistd.h>      
#include <arpa/inet.h>    
#include <thread>         
#include <cstring>       

constexpr unsigned int SERVER_PORT = 50542; // Define the server port number
constexpr unsigned int MAX_BUFFER = 128;    // Define the maximum buffer size

// Function to handle communication with a single client
int handle_client(int client_sock , int server_sock) {
    std::string welcomeMessage = "Welcome to the chat";
    send(client_sock, welcomeMessage.c_str(), welcomeMessage.size(), 0); // Send welcome message to client

    // Begin communication loop with the client
    while (true) {
        char buffer[MAX_BUFFER] = {0};
        int bytes_read = recv(client_sock, buffer, MAX_BUFFER, 0); // Receive message from client

        if (bytes_read <= 0) { // Check if the connection is closed by the client
            std::cerr << "Connection closed by client" << std::endl;
            break;
        }

        std::string client_message(buffer); // Convert the received message to a string
       
        if (client_message == "CLOSE") { // Check if the client sent the close message
            std::cout << "Clinet : Good bye! \n Connection closed!by client: ";
            break;
        }
        else {
          std::cout << "Client: " << client_message << std::endl; // Display the client's message

        }

        std::string server_response;
        std::cout << "Server: ";           // Prompt for server's response
        std::getline(std::cin, server_response); // Get the response from the server operator

        send(client_sock, server_response.c_str(), server_response.size(), 0); // Send the response to the client

        if (server_response == "CLOSE") { // Check if the server operator wants to close the connection
            std::string endMessage = "Server : Good bye!\nConnection closed!by client: ";
            send(client_sock, endMessage.c_str(), endMessage.size(), 0); // Send close message to client
             std::cout << "\nConnection closed!: ";
            break;
        }
    }

    close(client_sock); // Close the client socket after communication ends
    close(server_sock); // Close the server socket after communication ends
    return 0;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0); // Create a socket for the server
    if (server_sock < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Set up the server address structure
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;  // Use IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    server_addr.sin_port = htons(SERVER_PORT); // Set the server port number

    // Bind the server socket to the specified address and port
    if (bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        return 2;
    }

    listen(server_sock, 5); // Listen for incoming connections, with a maximum queue of 5
    std::cout << "Server is listening on port " << SERVER_PORT << std::endl;

    // Main loop to accept and handle incoming client connections
    while (true) {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (sockaddr*)&client_addr, &client_len); // Accept a new client connection

        if (client_sock < 0) {
            std::cerr << "Error accepting connection" << std::endl;
            continue; // Skip this iteration and continue to the next one
        }

        std::cout << "Server: Got connection from " << inet_ntoa(client_addr.sin_addr) << std::endl; // Display client's IP
        std::thread client_thread(handle_client, client_sock , server_sock); // Create a new thread to handle the client
        client_thread.detach(); // Detach the thread to allow it to run independently
    }

    close(server_sock); // Close the server socket (this will never be reached in this infinite loop)
    return 0;
}
