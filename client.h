#pragma once
#include <iostream>
#include <vector>
#include "product.h"

class Client {
	public:
		Client(std::string id, std::string firstname, std::string lastname,std::vector<Product> shopping_cart);
		std::string id()const;
		std::string firstname()const;
		std::string lastname()const;
		std::vector<Product> shopping_cart()const;
		void add_to_shopping_cart(Product product);
		void erase_shopping_cart();
		void modify_quantity();

	private:
		std::string _id;
		std::string _firstname;
		std::string _lastname;
		std::vector<Product> _shopping_cart;

};
std::string display_ShoppingCart(Client client);

std::string display_Client(Client client);

std::ostream& operator<<(std::ostream& os, Client client);

std::string entrerClient(std::vector<Client>& clients);
