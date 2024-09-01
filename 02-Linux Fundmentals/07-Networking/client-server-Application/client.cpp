#include <iostream>       
#include <string>         
#include <unistd.h>      
#include <arpa/inet.h>    
#include <netdb.h>       
#include <cstring>        

constexpr unsigned int SERVER_PORT = 50542; // Define the server port number
constexpr unsigned int MAX_BUFFER = 128;    // Define the maximum buffer size

int main(int argc, char *argv[]) {
    // Check if the hostname is provided as a command-line argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <hostname>" << std::endl;
        return 1;
    }

    // Create a socket for the client
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 2;
    }

    // Resolve the server hostname to an IP address
    struct hostent* server = gethostbyname(argv[1]);
    if (!server) {
        std::cerr << "Error: No such host" << std::endl;
        return 3;
    }

    // Set up the server address structure
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;  // Use IPv4
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length); // Copy server IP address
    server_addr.sin_port = htons(SERVER_PORT); // Set the server port number

    // Attempt to connect to the server
    if (connect(client_sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        return 4;
    }

    // Receive the welcome message from the server
    char buffer[MAX_BUFFER] = {0};
    int bytes_read = recv(client_sock, buffer, MAX_BUFFER, 0);
    if (bytes_read > 0) {
        std::cout << "Server: " << buffer << std::endl; // Display the server's welcome message
    }

    // Begin communication loop
    while (true) {
        std::string client_message;
        std::cout << "Client: ";           // Prompt for client's message
        std::getline(std::cin, client_message); // Get the message from the user

        send(client_sock, client_message.c_str(), client_message.size(), 0); // Send the message to the server

        if (client_message == "CLOSE") {  // Check if the client wants to close the connection
            std::cout << "\nConnection closed!\n "; 
            break;
        }

        // Receive the server's response
        char server_response[MAX_BUFFER] = {0};
        int bytes_read = recv(client_sock, server_response, MAX_BUFFER, 0);

        if (bytes_read <= 0) { // Check if the connection is closed by the server
            std::cerr << "Connection closed by server" << std::endl;
            break;
        }

        std::cout << "Server: " << server_response << std::endl; // Display the server's response

        if (std::string(server_response) == "CLOSE") { // Check if the server sent the close message
            break;
        }
    }

    close(client_sock); // Close the socket after communication ends
    return 0;
}
