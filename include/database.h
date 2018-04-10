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
#include <iostream>
#include <sstream>
#include <fstream>
struct User {
public:
	User(std::string name,unsigned long pass,bool admin):name(name),pass(pass),admin(admin),vol(0.0){
	}
	User(){
		name="";
		pass=0;
		admin=false;
		vol=0.0;
	}
private:
	friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version) {
			(void)version;
			ar & name;
			ar & pass;
			ar & admin;
			ar & vol;
	}
	std::string name;
	unsigned long pass;
	bool admin;
	float vol;
};

struct Ingredient {
public:
	Ingredient(std::string name,float alcohol):name(name),alcohol(alcohol){
	}
	Ingredient(){
		name="";
		alcohol=0.0;
	}
private:
	friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version) {
			(void)version;
			ar & name;
			ar & alcohol;
	}
	std::string name;
	float alcohol;
};



class DataBase: public QObject {
Q_OBJECT
public:
	DataBase(QObject* _parent = NULL);
	~DataBase();
	void addUser(std::string& name, std::string& pass,bool admin);
	std::vector<std::string> getUsers();
protected:
private:
private:
	friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version) {
			(void)version;
			ar & users;
	}

	std::map<std::string,User> users;
	std::hash <std::string> hash;

};

#endif /* INCLUDE_DATABASE_H_ */
