#include <iostream>
#include <vector>
#include "magasin.h"

Magasin::Magasin(std::vector<Client> clients, std::vector<Product> products, std::vector<Order> orders) : _clients(clients), _products(products), _orders(orders) {

}