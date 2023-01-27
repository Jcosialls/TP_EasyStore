#pragma once
#include <iostream>
#include <vector>
#include "product.h"
#include "client.h"

enum class Status{Deliver, Undeliver, Ongoing}; 

class Order {
	private :
		Client _client;
		std::vector<Product> _products;
		Status _status;

	public :
		Order(Client client, std::vector<Product> products, Status status);
		Client client()const;
		std::vector<Product> products()const;
		Status status()const;
		void modify_status(Status status);
};

//-------Helper Functions--------//
std::string display_Order(Order order);

//-------Overloading Ops--------//
bool operator == (const Order& o1, const Order& o2);
std::ostream& operator<<(std::ostream& os, Order order);