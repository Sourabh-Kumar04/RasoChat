#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <thread>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

// intialize winsock
// create socket
// connect to the server
//  send/ recv
// close the socket

bool Intialize() {
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void SendMsg(SOCKET s) {
	cout << "Enter  your Chat Name: " << endl;
	string Name;
	getline(cin, Name);
	string message;

	while (1) {
		getline(cin, message);
		string msg = Name + ":" + message;
		
		int bytesent = send(s, msg.c_str(), msg.length(), 0);
			
		if (bytesent == SOCKET_ERROR) {
			cout << "Error sending message" << endl;
			break;
		}

		if (message == "Close") {
			cout << "Closing the RasoChat " << endl;
			break;
		}
	}

	closesocket(s);
	WSACleanup();

}

void ReceiveMsg(SOCKET s) {
	char buffer[4096];
	int recvLength;
	string msg = "";

	while (1) {
		recvLength = recv(s, buffer, sizeof(buffer), 0);
		if (recvLength <= 0) {
			cout << "Disconnected from the Server " << endl;
			break;
		}
		else {
			msg = string(buffer, recvLength);
			cout << msg << endl;
		}
	}

	closesocket(s);
	WSACleanup();
}

int main() {
	if (!Intialize()) {
		cout << "intialize winsock failed" << endl;
		return 1;
	}

	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) {
		cout << "invalid socket created" << endl;
		return 1;
	}

	int port = 12345;
	string serveraddress = "127.0.0.1";
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));

	if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
		cout << "not able to connect to server" << endl;
		cout << ": " << WSAGetLastError();
		closesocket(s);
		WSACleanup();
		return 1;
	}

	cout << "succesfully connected to server" << endl;

	thread senderthread(SendMsg, s);
	thread receiverthread(ReceiveMsg, s);

	senderthread.join();
	receiverthread.join();


	return 0;
}