#include <iostream>
#include <string>
using namespace std;
class package {
protected:
	string name_of_sender, name_of_reciever, address_of_sender,
		address_of_reciever, city_of_sender, city_of_reciever;
	float weight, cost_per_ounce;
public:
	void  SetNameofSender(string names) {
		this->name_of_sender = names;
	}
	void SetNameofReciever(string namer){
		this->name_of_reciever = namer;
	}
	void setsenderaddress(string addres) {
		this->address_of_sender = addres;
	}
	void setrecieveradres(string addres) {
		this->address_of_reciever = addres;
	}
	void setsendercity(string city) {
		this->city_of_sender = city;
	}
	void setrecievercity(string city) {
		this->city_of_reciever = city;
	}
	void setweight(float weight) {
		if (weight > 0)
			this->weight = weight;
		else
			cout << "please enter positive weight value\n";
	}
	void setcost(float cost) {
		if (cost > 0)
			this->cost_per_ounce = cost;
		else
			cout << "cost can't be a negative value\n";
	}
	string getNameofSender() {
		return name_of_sender;
	}
	string getnameofreciever() {
		return name_of_reciever;
	}
	string getsenderaddres() {
		return address_of_sender;
	}
	string getrecieveraddress() {
		return address_of_reciever;
	}
	string getcityofsender() {
		return city_of_sender;
	}
	string getcityreciever() {
		return city_of_reciever;
	}
	float getweight() {
		return weight;
	}
	float getcost() {
		return cost_per_ounce;
	}
	package(string names, string namer, string ads, string adr, string citys, string cityr, float weight, float cost) {
		SetNameofSender(names);
		SetNameofReciever(namer);
		setsenderaddress(ads);
		setrecieveradres(adr);
		setsendercity(citys);
		setrecievercity(cityr);
		setweight(weight);
		setcost(cost);
	}
	float CalculateCost() {
		return weight*cost_per_ounce;
	}
};
class Two_Days_Package:public package {
	float Flatfee;
public:
	void setFlatFee(float flatfee) {
		if (flatfee > 0)
			this->Flatfee = flatfee;
		else
			cout << "enter positive fee value\n";
	}
	float getflatfee() {
		return Flatfee;
	}
	Two_Days_Package(string names, string namer, string ads, string adr, string citys, string cityr, float weight, float cost, float flatfee):package(names, namer, ads, adr, citys, cityr, weight, cost) {
		SetNameofSender(names);
		SetNameofReciever(namer);
		setsenderaddress(ads);
		setrecieveradres(adr);
		setsendercity(citys);
		setrecievercity(cityr);
		setweight(weight);
		setcost(cost);
		setFlatFee(flatfee);
	}
	float CalculateCost() {
		return package::CalculateCost()+Flatfee;
	}
};
class OvernightPackage:public package {
	float Fee_Per_Ounce;
public:
	void Setfeeperounce(float fee) {
		if (fee > 0)
			this->Fee_Per_Ounce = fee;
		else
			cout << "enter positive fee value\n";
	}
	OvernightPackage(string names, string namer, string ads, 
		string adr, string citys, string cityr,
		float weight, float cost,float fee)
		:package(names, namer, ads, adr, citys, cityr, weight,
			cost) {
		SetNameofSender(names);
		SetNameofReciever(namer);
		setsenderaddress(ads);
		setrecieveradres(adr);
		setsendercity(citys);
		setrecievercity(cityr);
		setweight(weight);
		setcost(cost);
		Setfeeperounce(fee);
	}
	float CalculateCost() {
		Fee_Per_Ounce += cost_per_ounce;
		return package::CalculateCost()+Fee_Per_Ounce;
	}
};