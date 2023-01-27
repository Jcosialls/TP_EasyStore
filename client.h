#pragma once
#include <iostream>
#include <vector>
#include "product.h"

class Client {
	public:
		Client(std::string id = "defaultid", std::string firstname= "defaultfirstname",
				 std::string lastname = "defaultlastname");
		std::string id()const;
		std::string firstname()const;
		std::string lastname()const;
		std::vector<Product> shopping_cart()const;
		void add_to_shopping_cart(Product& product);
		void del_to_shopping_cart(Product& product);
		void erase_shopping_cart();
		void modify_quantity(Product& product, int new_quantity);

	private:
		std::string _id;
		std::string _firstname;
		std::string _lastname;
		std::vector<Product> _shopping_cart;

};
//-------Helper Functions--------//
std::string display_ShoppingCart(Client client);
std::string display_Client(Client client);

//-------Overloading Ops--------//
bool operator == (const Client& c1, const Client& c2);
std::ostream& operator<<(std::ostream& os, Client client);


