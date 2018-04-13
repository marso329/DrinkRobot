/*
 * database.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */

#include "database.h"

DataBase::DataBase(QObject* _parent) :
		QObject(_parent) {
	if (boost::filesystem::exists("database.db")) {
		std::fstream afile;
		afile.open("database.db", std::ios::in);
		boost::archive::text_iarchive iarch(afile);
		iarch >> *this;
		afile.close();
	}
}

DataBase::~DataBase() {
	{
		std::ofstream outfile;
		outfile.open("database.db", std::ios::out | std::ios::trunc);
		boost::archive::text_oarchive ar(outfile);
		ar << *this;
		outfile.close();
	}

}

void DataBase::addUser(std::string& name, std::string& pass, bool admin) {
	users[name] = User(name, hash(pass), admin);
}
std::vector<std::string> DataBase::getUsers() {
	std::vector<std::string> users_return;
	for (auto it = users.begin(); it != users.end(); it++) {
		users_return.push_back(it->first);
	}
	return users_return;
}

std::vector<std::tuple<std::string, int, int>> DataBase::getIngrediants() {
	std::vector<std::tuple<std::string, int, int>> ingrediants_return;
	for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
		ingrediants_return.push_back(
				std::tuple<std::string, int, int>(it->second.name,
						it->second.alcohol, it->second.price));
	}
	return ingrediants_return;
}
void DataBase::addIngrediant(std::string& name, int strength, int price) {
	ingredients[name] = Ingredient(name, strength, price);
}
void DataBase::changeIngrediant(std::string& name, int strength, int price) {
	if (price != -1) {
		ingredients[name].price = price;
	}
	if (strength != -1) {

		ingredients[name].alcohol = strength;
	}
}

void DataBase::removeIngrediant(std::string& name){
	if(ingredients.find(name)!=ingredients.end()){
		ingredients.erase(name);
	}
}

