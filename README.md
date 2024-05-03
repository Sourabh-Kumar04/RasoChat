# RasoChat

This is a simple client-server chat application built using C++ and the Windows Sockets (Winsock) API. It allows multiple clients to connect to a server and exchange messages with each other in real-time.

## Features

- Server can handle multiple client connections simultaneously
- Clients can send and receive messages to/from other connected clients
- Clients can choose a chat name to identify themselves
- Clients can gracefully disconnect from the server by sending the "Close" command

## Getting Started

### Prerequisites

- Windows operating system
- C++ compiler (e.g., Visual Studio)

### Building and Running

1. Clone the repository or download the source code.
2. Open the project in your preferred C++ IDE or compiler.
3. Build the project to generate the executable files.

#### Running the Server

1. Open a terminal or command prompt.
2. Navigate to the directory containing the server executable.
3. Run the server executable.
4. The server will start listening for incoming client connections on port 12345.

#### Running the Client

1. Open a new terminal or command prompt for each client you want to run.
2. Navigate to the directory containing the client executable.
3. Run the client executable.
4. When prompted, enter a chat name for the client.
5. The client will connect to the server, and you can start sending messages.
6. To disconnect from the server, type "Close" and press Enter.

## Code Structure

### Server

The server code (`main.cpp`) includes the following main steps:

1. Initialize the Winsock library.
2. Create a socket for listening for incoming connections.
3. Bind the socket to a specific IP address and port (0.0.0.0:12345).
4. Listen for incoming connections.
5. Accept new client connections and create a new thread to handle communication with each client.
6. Receive messages from clients and broadcast them to all other connected clients.
7. Clean up resources and close the Winsock library.

### Client

The client code (`main.cpp`) includes the following main steps:

1. Initialize the Winsock library.
2. Create a socket for connecting to the server.
3. Connect to the server using the specified IP address and port.
4. Start two threads: one for sending messages and one for receiving messages.
5. Send messages entered by the user to the server.
6. Receive messages from the server and display them.
7. Clean up resources and close the Winsock library.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
```

This README.md file provides an overview of the chat application, including its features, prerequisites, instructions for building and running the server and client, a high-level description of the code structure, and information about contributing and licensing.
