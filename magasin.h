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
		Magasin(std::vector<Client> clients, std::vector<Product> products,
				std::vector<Order> orders);
		std::vector<Client> clients()const;
		std::vector<Product> products()const;
		std::vector<Order> orders()const;
		void add_product(const Product& new_product);
		void add_client(const Client& new_client);
		void add_order(const Order& new_order);
		void set_stock(const Product& product, int quantity);
		Product found_Product(std::string title);
		Client found_Client(std::string id_client );
};
//-------Helper Functions--------//
std::string display_Products(const Magasin& mag);
std::string display_Clients(const Magasin& mag);
std::string display_Orders(const Magasin& mag);

void add_Prod_to_Client(Magasin& mag, std::string title, std::string id_client);
void del_Prod_to_Client(Magasin& mag, std::string title, std::string id_client);
void modify_QuantityProd_to_Client(Magasin& mag, int quantity,
								   std::string title, std::string id_client );

void check_order(Magasin& mag,  int num_order);
void change_status_order(Magasin& mag,  int num_order, int status);
std::string orders_of_client(Magasin& mag, std::string id_client);

//-------Overloading Ops--------//
std::ostream& operator<<(std::ostream& os, const Magasin& mag);