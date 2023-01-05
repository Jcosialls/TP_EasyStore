#include <iostream>
#include "client.h"
#include <vector>

Client::Client(std::string id, std::string firstname, std::string lastname)
	: _id(id), _firstname(firstname), _lastname(lastname) {
}

std::string Client::id()const {
	return _id;
}

std::string Client::firstname()const {
	return _firstname;
}

std::string Client::lastname()const {
	return _lastname;
}

std::string display_Client(Client client) {
	std::string c = client.firstname() + " " + client.lastname() + " id : " + client.id();
	return c;
}

std::ostream& operator<<(std::ostream& os, Client client) {
	std::string to_display = display_Client(client);
	os << to_display << std::endl;
	return os;
}

std::string entrerClient(std::vector<Client>& clients) {
	std::string nom_client;
	bool exist = false;

	std::cout << "Entrer le nom du client : " << std::endl;
	std::cin >> nom_client;
	for (auto i = 0; i < clients.size(); i++) {
		if (nom_client == clients.at(i).lastname()) { //le client existe
			exist = true;
			std::cout << clients.at(i);
			return clients.at(i).id();
		}
		else {}                                      //le client n'existe pas                                 
	}
	if (exist == false) {  //on crée un client
		std::string id_client;
		std::string prenom_client;
		std::cout << "Création du client " << std::endl;
		std::cout << "Entrer le prenom du client " << std::endl;
		std::cin >> prenom_client;
		std::cout << "Entrer l'identifient du client " << std::endl;
		std::cin >> id_client;
		Client new_client(id_client, prenom_client, nom_client);
		clients.push_back(new_client);
		std::cout << new_client;
		return id_client;
	}

}