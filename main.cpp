#include <iostream>
#include <vector>

int main() {
	std::vector<Client> mesClients;
	std::vector<Product> mesBonsProduitsBio;
	std::vector<Order> mesCommandes;

	Magasin carrouf(mesClients, mesBonsProduitsBio, mesCommandes);

	return 0;
}