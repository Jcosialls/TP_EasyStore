#pragma once
#include <iostream>
#include <vector>
#include "product.h"
#include "client.h"
#include "order.h"

class Magasin {
	private : 
		std::vector<Client> _clients;
		std::vector<Product> _products;
		std::vector<Order> _orders;

	public: 
		Magasin(std::vector<Client> clients, std::vector<Product> products, std::vector<Order> orders);
		std::vector<Client> clients()const;
		std::vector<Product> products()const;
		std::vector<Order> orders()const;
		void add_product(const Product& new_product);
		void add_client(const Client& new_client);
};
//-------Helper Functions--------//
std::string display_Products(const Magasin& mag);
std::string display_Clients(const Magasin& mag);
std::string found_Product(const Magasin& mag);
std::string found_Client(const Magasin& mag);
void add_Prod_to_Client(const Magasin& mag);
//-------Overloading Ops--------//
std::ostream& operator<<(std::ostream& os, const Magasin& mag);