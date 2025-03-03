#pragma once
#include<iostream>
//#include<string>
using namespace std;
#include"user.h"



/// <admin>
/// admin has all the power
/// manager login and file updating of inventory.. 
/// </admin>
class Admin :public User {
protected:
public:
	bool Login();//
	void Registration();//
	void Saveadmdata(Admin object, string FileName);
	void UsernameVerification(Admin*);//
	void PasswordValidation(Admin*);//
};

class Customer :public User {
protected:

public:
	bool Login();//
	void Registration();//

	void UsernameVerification(Customer*);//
	void PasswordValidation(Customer*);//
	void CnicVerification(Customer*);//
	void Savecustdata(Customer object, string FileName);
};




/// <manager>
/// manager a lower officer to admin that oversees operation in its department...
/// </manager>
class Manager :public User
{
protected:
public:
	bool Login();//
	//	void Registration();//
};


/*
* for manager/admin/customer...
	login
	registration



*/