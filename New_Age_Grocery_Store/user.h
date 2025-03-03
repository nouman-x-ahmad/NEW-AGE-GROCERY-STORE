#pragma once
#include<iostream>
#include<string>
using namespace std;

/// <user>
/// here is a class that contain alls the customer related stuff
/// </user>

class User {
protected:
	char user_cnic[14],	//user defined cnic;
		user_passw[20],	//user made password;
		user_gend[1],	//user declared gender obviously female or male :);
		user_phone[15],	//users phone number to contact them if anything smell fonny :);
		user_addres[100],	//user address to so we can rob.... meaning to TCS them their parcel obv.. :);
		user_info[100],		// yeah nothing sus abt that, only wana know who are our customers...
		user_email[20],
		user_name[15];
	int age;	//their age to identify them that thay are mentally capable to order or not...

public:
	User();						//const-tructor......vroom vroom vroom
	//setter...
	void setuser_cnic(string);	//for our beloved customer cnic;
	void setuser_passw(string);	//for our user,setting up their password
	void setuser_gend(char);	//larka hai kai larkee wo janai kailiyai mereee jaan.
	void setuser_phone(string);	//unka phone number.....
	void setuser_address(string);//unkai ghar ka pata meree janeman...
	//	void setuser_info(string);
	void setuser_age(int);		//18+ ya kai nheee ....
	void setuser_email(string);
	void setuser_name(string);

	//updating
	void updateuser_address(string);	//for updating user's address
	void updateuser_passw(string);		//for updating user's password in case of forgottien or any other case...

	//getter func...
	char* getuser_cnic();	//for our beloved customer cnic;
	char* getuser_passw();	//for our user,setting up their password
	char* getuser_gend();	//larka hai kai larkee wo janai kailiyai mereee jaan.
	char* getuser_phone();	//unka phone number.....
	char* getuser_address();//unkai ghar ka pata meree janeman...
	//	void getuser_info();
	char* getuser_name();//
	int getuser_age();		//18+ ya kai nheee ....
	char* getuser_email();
	virtual bool Login();//logang
	virtual void Registration();//renagae

};