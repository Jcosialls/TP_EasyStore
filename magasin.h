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
};