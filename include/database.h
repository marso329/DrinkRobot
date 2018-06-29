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
#include <ctime>
struct User {
public:
	User(std::string name, unsigned long pass, bool admin) :
			name(name), pass(pass), admin(admin), vol(0.0), cost(0.0) {
	weight=0;
	male=true;
	}
	User() {
		name = "";
		pass = 0;
		admin = false;
		vol = 0.0;
		cost = 0.0;
		weight=0;
		male=true;
	}
	std::string name;
	unsigned long pass;
	bool admin;
	float vol;
	float cost;
	bool male;
	int weight;
	std::vector<std::tuple<long int,float>> amount;
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
		ar & weight;
		ar & male;
		ar & amount;
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
	std::string icon;
	std::vector<std::tuple<std::string, int>> ingredients;
private:

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & name;
		ar & ingredients;
		if (version>0){
			ar&icon;
		}
	}
};

struct Level {
public:
	Level(std::string ingredient, int vol) :
			ingredient(ingredient),vol(vol) {
		temp=0;
	}
	Level() {
		ingredient = "";
		vol=0;
		temp=0;
	}
	std::string ingredient;
	int vol;
	int temp;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void) version;
		ar & ingredient;
		ar & vol;
		ar & temp;
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
	void clearUser(std::string& name);
	bool isAdmin(std::string& name);
	void changeAdmin(std::string& name,bool);
	bool getMale(std::string& name);
	float getUserSpent(std::string& name);
	void setMale(std::string& name,bool);
	int getWeight(std::string& name);
	float getPromille(std::string& name);
	float getStrength(std::string&name);
	float getCost(std::string&name);
	float getTotalAmount(std::string& name);
	void setWeight(std::string& name,int);
	std::vector<std::tuple<long int,float>> getAmount(std::string& name);
	//AMOUNT IN CL
	void addAmountToUser(std::string& name,float);
	void addCostToUser(std::string& name,float);
	void addDrink(std::string& name);
	bool drinkFeasible(std::string& name);
	std::vector<std::tuple<int,int>> getTanksAndAmountForDrink(std::string drink);
	void setIcon(std::string& name,std::string& icon);
	std::string getIcon(std::string& name);
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
	std::vector<std::tuple<std::string, int>> getLevels();
	std::string getIngredientFromTank(int);
	std::vector<std::tuple<int,std::string, int>> getLevelsWithTank();
	void setTemp(int tank,int temp);
	int getTemp(int tank);
	void setlevel(int tank,std::string ingredient,int vol);
	void reducelevel(int tank,int amount);
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
BOOST_CLASS_VERSION(Drink, 1)

#endif /* INCLUDE_DATABASE_H_ */
