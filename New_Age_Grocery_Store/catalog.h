#pragma once
#include<iostream>
//#include<string>
using namespace std;

/// <Newgrocery>
///this class is used as a main path for users to move around in menu
/// </Newgrocery>
class Newgrocery
{
protected:


public:
	Newgrocery() {

	}
	void MainMenu();
	void Showinventory(Manager, int);
	void Viewcatalogue(char*);

	void SubMenu(int);
};


/// <product catalog>
/// here all the shopping items will be listed ...
/// </product catalog>
class productcat {
protected:
	char productname[20];
	int prodprice;
	int idno;

	int price;
public:
	//s etter
	void setprice(int);
	int getprice();
	void setproductname(string);
	void setprodprice(int);
	void setidno(int);

	//getter
	char* getproductname();
	int getprodprice();
	int getidno();
	virtual	void addproduct();
	virtual	void editproduct();


};


class islamabad :public productcat {
public:
	//bool perishable;
	productcat pdr;
public:

	islamabad()
	{

	}
	void addproduct();
	//	void editproduct();
	void Saveproddata(islamabad object, string FileName);
	void DisplayProduct();
	void prod();
};


class rawalpindi :public productcat {
protected:
	//bool perishable;
public:
	rawalpindi()
	{

	}
	void addproduct();
	//	void editproduct();
	void Saveproddata(rawalpindi object, string FileName);
	void DisplayProduct();
	void prod();
};
