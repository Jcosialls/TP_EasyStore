#include <iostream>
//#include <algorithm>
#include <vector>
#include "client.h"

Client::Client(std::string id, std::string firstname, std::string lastname, std::vector<Product> shopping_cart)
	: _id(id), _firstname(firstname), _lastname(lastname), _shopping_cart(shopping_cart) {
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

std::vector<Product> Client::shopping_cart()const{
	return _shopping_cart;
}

void Client::add_to_shopping_cart(Product product){
	_shopping_cart.push_back(product);
}

void Client::erase_shopping_cart(){
	_shopping_cart.clear();
}

//----------Fonctions helper-----------//
std::string display_ShoppingCart(Client client){
	std::string s;
	int quantity= 0;
	std::vector<Product> copy_cart = client.shopping_cart();
	auto it = copy_cart.begin();
	do{
		for(auto it2 = copy_cart.begin(); it2 != copy_cart.end(); it2++){
			if(*it == *it2){
				quantity ++;
			}
		}
		s+= it->gettitle() + " x";
		s+= std::to_string(quantity);
		s+= "\n";
		copy_cart.erase(it);
	}while( it!= copy_cart.end());
	std::cout<<s;
	return s;
}

std::string entrerClient(std::vector<Client>& clients) {
	std::string nom_client;
	std::string id_client;
	std::string prenom_client;
	std::vector <Product> shopping_cart;
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
	if (exist == false) {  //on cree un client

		std::cout << "Creation du client " << std::endl;
		std::cout << "Entrer le prenom du client " << std::endl;
		std::cin >> prenom_client;
		std::cout << "Entrer l'identifient du client " << std::endl;
		std::cin >> id_client;
		Client new_client(id_client, prenom_client, nom_client, shopping_cart);
		clients.push_back(new_client);
		std::cout << new_client;
		return id_client;
	}

}

std::string display_Client(Client client) {
	std::string c = client.firstname() + " " + client.lastname() + " id : " + client.id();
	c+= "\nDans le panier : " + display_ShoppingCart(client);
	return c;
}

std::ostream& operator<<(std::ostream& os, Client client) {
	std::string to_display = display_Client(client);
	os << to_display << std::endl;
	return os;
}

