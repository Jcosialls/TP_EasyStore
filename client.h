#pragma once
#include <iostream>
#include <vector>

class Client {
	public:
		Client(std::string id, std::string firstname, std::string lastname);
		std::string id()const;
		std::string firstname()const;
		std::string lastname()const;
	private:
		std::string _id;
		std::string _firstname;
		std::string _lastname;

};
std::string display_Client(Client client);

std::ostream& operator<<(std::ostream& os, Client client);

std::string entrerClient(std::vector<Client>& clients);
