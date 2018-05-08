/*
 * database.h
 *
 *  Created on: Apr 10, 2018
 *      Author: martin
 */

#ifndef INCLUDE_DATABASE_H_
#define INCLUDE_DATABASE_H_
#include <QObject>
#include <string>
#include <map>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/filesystem.hpp>
#include <tuple.h>
#include <iostream>
#include <sstream>
#include <fstream>
struct User {
public:
	User(std::string name, unsigned long pass, bool admin) :
			name(name), pass(pass), admin(admin), vol(0.0), cost(0.0) {
	}
	User() {
		name = "";
		pass = 0;
		admin = false;
		vol = 0.0;
		cost = 0.0;
	}
	std::string name;
	unsigned long pass;
	bool admin;
	float vol;
	float cost;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & name;
		ar & pass;
		ar & admin;
		ar & vol;
		ar & cost;
	}
};

struct Ingredient {
public:
	Ingredient(std::string name, int alcohol, int price) :
			name(name), alcohol(alcohol), price(price) {
	}
	Ingredient() {
		name = "";
		alcohol = 0;
		price = 0;
	}
	std::string name;
	int alcohol;
	int price;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & name;
		ar & alcohol;
		ar & price;
	}
};

struct Drink {
public:
	Drink(std::string name,
			std::vector<std::tuple<std::string, int>> ingredients) :
			name(name), ingredients(ingredients) {
	}
	Drink() {
		name = "";
	}
	Drink(std::string& name):name(name) {
	}

	std::string name;
	std::vector<std::tuple<std::string, int>> ingredients;
private:

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & name;
		ar & ingredients;
	}
};

struct Level {
public:
	Level(std::string ingredient, int vol) :
			ingredient(ingredient),vol(vol) {
	}
	Level() {
		ingredient = "";
		vol=0;
	}
	std::string ingredient;
	int vol;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & ingredient;
		ar & vol;
	}
};

class DataBase: public QObject {
Q_OBJECT
public:
	DataBase(QObject* _parent = NULL);
	~DataBase();
	void addUser(std::string& name, std::string& pass, bool admin);
	bool checkUser(std::string& name, std::string& pass);
	void removeUser(std::string& name);
	bool isAdmin(std::string& name);
	void changeAdmin(std::string& name,bool);
	void addDrink(std::string& name);
	std::vector<std::string> getDrinks();
	std::vector<std::tuple<std::string, int>> getIngredientsInDrink(std::string& name);
	void clearDrinkIngredients(std::string& name);
	void addIngredientToDrink(std::string & name,std::string& ingredient,int amount);

	std::vector<std::tuple<std::string,bool>> getUsers();
	std::vector<std::tuple<std::string, int, int>> getIngrediants();
	std::vector<std::string> getIngrediantsName();
	void addIngrediant(std::string& name, int strength, int price);
	void changeIngrediant(std::string& name, int strength, int price);
	void removeIngrediant(std::string& name);
	std::tuple<std::string, int> getLevel(int);
	void setlevel(int tank,std::string ingredient,int vol);
	void print();
protected:
private:
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & users;
		ar & ingredients;
		ar & drinks;
		ar & levels;
	}

	std::map<std::string, User> users;
	std::map<std::string, Ingredient> ingredients;
	std::map<std::string, Drink> drinks;
	std::map<int, Level> levels;
	std::hash<std::string> hash;

};

#endif /* INCLUDE_DATABASE_H_ */
