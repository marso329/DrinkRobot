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
                if (users.find("martin") == users.end()) {
                    std::string name="martin";
                    std::string pass="12345";
                    addUser(name,pass,true);
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

void DataBase::clearDrinkIngredients(std::string& name){
	if(drinks.find(name)!=drinks.end()){
		std::vector<std::tuple<std::string, int>> temp;
		drinks[name].ingredients= temp;
	}
}
void DataBase::addIngredientToDrink(std::string & name,std::string& ingredient,int amount){
	if(drinks.find(name)!=drinks.end()&&ingredient!=""){
		drinks[name].ingredients.push_back(std::tuple<std::string, int>(ingredient,amount));
	}

}

std::vector<std::tuple<int,int>> DataBase::getTanksAndAmountForDrink(std::string name){
	std::vector<std::tuple<int,int>> tanksAmount;
	std::vector<std::tuple<int,std::string, int>> levels=getLevelsWithTank();
	if(drinks.find(name)!=drinks.end()){
		//get ingredients
		std::vector<std::tuple<std::string, int>> ingredients= drinks[name].ingredients;
		for(auto it=ingredients.begin();it!=ingredients.end();it++){
			std::tuple<std::string, int> temp=*it;
			std::string ingredient_name=std::get<std::string>(temp);
			int amount=std::get<int>(temp);
			for(auto it1=levels.begin();it1!=levels.end();it1++){
				std::tuple<int,std::string, int> temp_level=*it1;
				std::string tank_ingredient=std::get<std::string>(temp_level);
				int tank_amount=std::get<2>(temp_level);
				int tank=std::get<0>(temp_level);
				if(tank_ingredient==ingredient_name){
					if(tank_amount>=amount){
						tanksAmount.push_back(std::tuple<int,int>(tank,amount));
						reducelevel(tank,amount);
						break;
					}
					amount-=tank_amount;
				}
			}

		}

}
	return tanksAmount;
}

float DataBase::getStrength(std::string&name){
	float strength=0.0;
	std::vector<std::tuple<std::string, int>> ingred= drinks[name].ingredients;
	for(auto it=ingred.begin();it!=ingred.end();it++){
		std::tuple<std::string, int> temp=*it;
		int amount=std::get<int>(temp);
		std::string ingredient_name=std::get<std::string>(temp);
		int percent=0;
		if(ingredients.find(ingredient_name)!=ingredients.end()){
			percent=ingredients[ingredient_name].alcohol;
		}
		strength+=((float)percent/100.0)*(float)amount;
	}
	return strength;
}

float DataBase::getCost(std::string&name){
	float cost=0.0;
	std::vector<std::tuple<std::string, int>> ingred= drinks[name].ingredients;
	for(auto it=ingred.begin();it!=ingred.end();it++){
		std::tuple<std::string, int> temp=*it;
		int amount=std::get<int>(temp);
		std::string ingredient_name=std::get<std::string>(temp);
		int costPerLiter=0;
		if(ingredients.find(ingredient_name)!=ingredients.end()){
			costPerLiter=ingredients[ingredient_name].price;
		}
		cost+=((float)costPerLiter/100.0)*(float)amount;
	}
	return cost;
}

std::string DataBase::getIngredientFromTank(int tank){
	std::string name="";
	if (levels.find(tank)!=levels.end()){
		name=levels[tank].ingredient;
	}
	return name;
}

//check if it is possible to make a drink
bool DataBase::drinkFeasible(std::string& name){
	bool feasible=true;
	std::vector<std::tuple<std::string, int>> levels=getLevels();
	if(drinks.find(name)!=drinks.end()){
		std::vector<std::tuple<std::string, int>> ingredients= drinks[name].ingredients;
		for(auto it=ingredients.begin();it!=ingredients.end();it++){
			std::tuple<std::string, int> temp=*it;
			std::string ingredient_name=std::get<std::string>(temp);
			int amount=std::get<int>(temp);
			for(auto it1=levels.begin();it1!=levels.end();it1++){
				std::tuple<std::string, int> temp_level=*it1;
				std::string tank_ingredient=std::get<std::string>(temp_level);
				int tank_amount=std::get<int>(temp_level);
				if(tank_ingredient==ingredient_name){
					amount-=tank_amount;
				}
			}
			if(amount>0){
				feasible=false;
			}

		}
		return feasible;
	}
	else{
		return false;
	}
}

void DataBase::addDrink(std::string& name){
	if (drinks.find(name) == drinks.end()) {
		drinks[name] = Drink(name);
	}
}
void DataBase::setIcon(std::string& name,std::string& icon){
	if(drinks.find(name)!=drinks.end()){
		drinks[name].icon=icon;
	}
}
std::string DataBase::getIcon(std::string& name){
	if(drinks.find(name)!=drinks.end()){
		std::string temp =drinks[name].icon;
		if (temp!=""){
			return temp;
		}
		else{
			return "000";
		}
	}
	else{
		return "000";
	}
}

std::vector<std::string> DataBase::getDrinks(){
	std::vector<std::string> temp;
	for (auto it=drinks.begin();it!=drinks.end();it++){
		temp.push_back(it->first);
	}
	return temp;
}
std::vector<std::tuple<std::string, int>> DataBase::getIngredientsInDrink(std::string& name){
	std::vector<std::tuple<std::string, int>> temp;
	if(drinks.find(name)!=drinks.end()){
		return drinks[name].ingredients;
	}
	return temp;

}


bool DataBase::isAdmin(std::string& name){
	if (users.find(name) != users.end()) {
		return users[name].admin;
	}
	return false;
}

bool DataBase::getMale(std::string& name){
	if (users.find(name) != users.end()) {
		return users[name].male;
	}
	return false;

}
float DataBase::getUserSpent(std::string& name){
	if (users.find(name) != users.end()) {
		return users[name].cost;
	}
	return 0;

}
float DataBase::getTotalAmount(std::string& name){
	float amount=0.0;
	if (users.find(name) != users.end()) {
		User user =users[name];
		std::vector<std::tuple<long int,float>> amounts=user.amount;
		for(auto it =amounts.begin();it!=amounts.end();it++){
			amount+=std::get<float>(*it);
		}
	}
	return amount;
}

float DataBase::getPromille(std::string& name){
		float promille=0.0;
	    time_t t = std::time(0);
	    long int now = static_cast<long int> (t);
		if (users.find(name) != users.end()) {
			User user =users[name];
			if(user.weight==0){
				return 0.0;
			}
			std::vector<std::tuple<long int,float>> amounts=user.amount;
			for(auto it =amounts.begin();it!=amounts.end();it++){
				long int time=std::get<long int>(*it);
				//in CL
				float amount=std::get<float>(*it)*7.89;
				float percent=0;
				if(user.male){
					percent=(amount*100.0)/((float)user.weight*680.0);
				}else{
					percent=(amount*100.0)/((float)user.weight*550.0);
				}
				float hours=((float)now-(float)time)/3600.0;
				float burned =hours*0.016;
				percent-=burned;
				if(percent<0.0){
					percent=0.0;
				}
				promille+=percent*10.0;

			}

		}

		return promille;
}
void DataBase::setMale(std::string& name,bool male){
	if (users.find(name) != users.end()) {
		users[name].male=male;
	}
}
int DataBase::getWeight(std::string& name){
	if (users.find(name) != users.end()) {
		return users[name].weight;
	}
	return 0;
}
void DataBase::setWeight(std::string& name,int weight){
	if (users.find(name) != users.end()) {
		users[name].weight=weight;
	}
}
std::vector<std::tuple<long int,float>> DataBase::getAmount(std::string& name){
	if (users.find(name) != users.end()) {
		return users[name].amount;
	}
	std::vector<std::tuple<long int,float>> temp;
	return temp;
}
//AMOUNT IN GRAMS
void DataBase::addAmountToUser(std::string& name,float amount){
    time_t t = std::time(0);
    long int now = static_cast<long int> (t);
	if (users.find(name) != users.end()) {
		users[name].amount.push_back(std::tuple<long int,float>(now,amount));
	}

}

void DataBase::addCostToUser(std::string& name,float cost){
	if (users.find(name) != users.end()) {
		users[name].cost+=cost;
	}
}


void DataBase::addUser(std::string& name, std::string& pass, bool admin) {
	if (users.find(name) == users.end()) {
		users[name] = User(name, hash(pass), admin);
	}
}

bool DataBase::checkUser(std::string& name, std::string& pass){
	if (users.find(name) != users.end()) {
		return users[name].pass==hash(pass);
	}
	return false;
}

void DataBase::changeAdmin(std::string& name,bool admin){
	if (users.find(name) != users.end()) {
		users[name].admin=admin;
	}
}
std::vector<std::tuple<std::string, bool>> DataBase::getUsers() {
	std::vector<std::tuple<std::string, bool>> users_return;
	for (auto it = users.begin(); it != users.end(); it++) {
		users_return.push_back(
				std::tuple<std::string, bool>(it->first, it->second.admin));
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

std::vector<std::string> DataBase::getIngrediantsName() {
	std::vector<std::string> ingrediants_return;
	for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
		ingrediants_return.push_back(it->second.name);
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

void DataBase::removeUser(std::string& name) {
	if (users.find(name) != users.end()) {
		users.erase(name);
	}
}
void DataBase::clearUser(std::string& name) {
	if (users.find(name) != users.end()) {
		users[name].vol=0;
		users[name].cost=0;
		users[name].amount.clear();
	}
}

void DataBase::removeIngrediant(std::string& name) {
	if (ingredients.find(name) != ingredients.end()) {
		ingredients.erase(name);
	}
	for (auto it = levels.begin(); it != levels.end();) {
		if (it->second.ingredient == name) {
			it = levels.erase(it);
		} else {
			it++;
		}
	}

	for (auto it = drinks.begin(); it != drinks.end();) {
		bool remove = false;
		for (auto it1 = it->second.ingredients.begin();
				it1 != it->second.ingredients.end(); it1++) {
			if (std::get<std::string>(*it1) == name) {
				remove = true;
			}
		}
		if (remove) {
			it = drinks.erase(it);
		} else {
			it++;
		}
	}

}

std::tuple<std::string, int> DataBase::getLevel(int tank) {
	if (levels.find(tank) != levels.end()) {
		Level level = levels[tank];
		return std::tuple<std::string, int>(level.ingredient, level.vol);
	} else {
		return std::tuple<std::string, int>("", 0);
	}
}

void DataBase::reducelevel(int tank,int amount){
	if (levels.find(tank) != levels.end()) {
		levels[tank].vol-=amount;
	}
}
int DataBase::getTemp(int tank){
	if (levels.find(tank) != levels.end()) {
		return levels[tank].temp;
	}
	return 50;
}

void DataBase::setTemp(int tank,int temp){
	if (levels.find(tank) != levels.end()) {
		levels[tank].temp=temp;
	}
}

std::vector<std::tuple<int,std::string, int>> DataBase::getLevelsWithTank(){
	std::vector<std::tuple<int,std::string, int>> temp;
	for(int i=0;i<10;i++){
		if(levels.find(i) != levels.end()){
			Level level = levels[i];
			temp.push_back(std::tuple<int,std::string, int>(i,level.ingredient, level.vol));
		}
	}
	return temp;
}

std::vector<std::tuple<std::string, int>> DataBase::getLevels(){
	std::vector<std::tuple<std::string, int>> temp;
	for(int i=0;i<10;i++){
		if(levels.find(i) != levels.end()){
			Level level = levels[i];
			temp.push_back(std::tuple<std::string, int>(level.ingredient, level.vol));
		}
	}
	return temp;
}
void DataBase::setlevel(int tank, std::string ingredient, int vol) {
	if (levels.find(tank) != levels.end()) {
		Level level = levels[tank];
		level.ingredient = ingredient;
		level.vol = vol;
		levels[tank] = level;
	} else {
		levels[tank] = Level(ingredient, vol);
	}
}
void DataBase::print() {
	std::cout << "Ingredients:" << std::endl;
	for (auto it = ingredients.begin(); it != ingredients.end(); it++) {
		std::cout << "Name: " << it->second.name << " strength: "
				<< it->second.alcohol << " price " << it->second.price
				<< std::endl;
	}
	std::cout << "Levels:" << std::endl;
	for (auto it = levels.begin(); it != levels.end(); it++) {
		std::cout << "Tank: " << it->first << " Ingredient: "
				<< it->second.ingredient << " Vol: " << it->second.vol
				<< std::endl;
	}

}

