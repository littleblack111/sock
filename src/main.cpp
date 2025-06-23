#include <libsock/misc/then.hpp>
#include <libsock/server/client.hpp>
#include <libsock/server/clients.hpp>
#include <libsock/server/server.hpp>

using namespace LibSock;

int main(int argc, char *argv[]) {
	auto server = Server::Server::create(8080);
	auto clients = Server::Clients::create(server);
	auto [pClient, waiter] = clients->newClient(false);
	waiter.wait();
	pClient->write("Hello, World!\n");

	return 0;
}
