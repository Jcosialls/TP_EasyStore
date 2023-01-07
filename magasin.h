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
		void add_product(Product new_product);
};

std::string display_Products(const Magasin& mag);
void found_Product(const Magasin& mag);
std::ostream& operator<<(std::ostream& os, Magasin mag);