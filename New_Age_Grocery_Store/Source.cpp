/*

Name: Nouman Ahmad
Class: CS-E;
instructor: Ma'am Nimra
Roll no: i21-0727


*/
#include<iostream>		//input output stream libraray or header file

#include<string>		//string data type related function like strcpy and more
#include<ctime>
#include<fstream>		//file handling kailiyai....
#include<Windows.h>		
#include"Header.h"
#include"admin.h";
#include"catalog.h"
#include"customer.h"
#include"manager.h"
#include"paymnt_feedb.h"
#include"user.h"
using namespace std;	//standard library for naming...

void Newgrocery::MainMenu()
{
	int inp,
		insertop2,
		insertop;//insertop=insert your desired option
	bool LoginDone = false;
	
	
	//classes instances.....
	Customer custing;
	Admin admin;
	Manager managing;
	User* uzage;



	std::cout << "    What are you :"
		<<" \n 1) Customer\n"
		<<" 2) Manager \n"
		<<" 3) Admin \n";
	cout << "     Choose an Option : ";
	cin >> insertop;///chhooosing the option from above three

	if (insertop == 1)
	{
		uzage = &custing;
	}
	else if (insertop == 2)
	{
		uzage = &managing;
	}
	else
	{
		uzage = &admin;
	}

	system("pause");
	system("CLS");

	if (insertop == 1 )
	{
		cout << "Main Menu \n"
			<< "1) Registration (sign up). \n"//for registration
			<<"2) Login. \n";//for login op.....

		cout << "Choose an option ( (1) / (2) ) : ";
		cin >> inp;

		switch (inp)
		{
			case 1:
				uzage->Registration();
				cout << "****USER'S REGISTRATION SUCCESSFUL !**** " << endl;
				MainMenu();//back to main menu and proceed by loging in
			
				break;

			case 2:
				LoginDone = uzage->Login();// for user loging in...

				break;

		}  // switch cond... endz ...




	}
	else if (insertop == 2)
	{
		cout << "Manager's Login: ";
		system("pause");
		LoginDone = uzage->Login();
	}
	else if (insertop == 3)
	{
		
		uzage = &admin;
		cout << "Main Menu \n"
			<< "1) Manager's Registration (sign up). \n"//for registration
			<< "2) Login. \n";//for login op.....

		cout << "Choose an option ( (1) / (2) ) : ";
		cin >> inp;

		switch (inp)
		{
		case 1:
			uzage->Registration();
			cout << "****Manager's REGISTRATION SUCCESSFUL !**** " << endl;
			MainMenu();//back to main menu and proceed by loging in

			break;

		case 2:
			LoginDone = uzage->Login();// for user loging in...

			break;

		}
	}

	if (LoginDone == true)
	{
		cout << "wohoo working" << endl;
		
		system("CLS");
		
		SubMenu(insertop);
	}
}
void Newgrocery::SubMenu(int insertype)
{
	int j;
	int p;
	int y;
	switch (insertype)
	{
	case 1:
		//
		cout << "******************************************" << endl;
		cout << "welcome to company inventory\n";
		cout << "search for things you wana buy:\n";
		cout << "enter your choice:1 for isb and  2 for rawalpindi:";
			cin >> j;
			if (j == 1)
			{
				cout << "enter's islamabd store:";
				islamabad isb; isb.prod();
				cout << "*****now money transfer****" << endl;
				cout << "1.e-payment\n2.bank transfer" << endl;
				cout << "enter:";
				cin >> y;
				if (y == 1)
				{
					payment it; it.e_transfer();
				}
				else
				{
					payment it;
					it.banktransfer();
				}
				feedback twt;
				twt.tweet();
			}
			else if (j == 2)
			{
				cout << "enter's rawalpindi store:";
				rawalpindi rwl;
				rwl.prod();
				cout << "*****now money transfer****" << endl;
				cout << "1.e-payment\n2.bank transfer" << endl;
				cout << "enter:";
				cin >> y;
				if (y == 1)
				{
					payment it; it.e_transfer();
				}
				else
				{
					payment it;
					it.banktransfer();
				}
				feedback twt;
				twt.tweet();
			}

		break;
	case 2:
		//
		cout << "manager's are not given any authority over these things yet" << endl;
		cout << "enter 1. to return to menu:"<<endl;
		cout << "enter 2. to restart the submenu:" << endl;
		cout << "enter'z:"; cin >> p;
		if (p == 1)
		{
			MainMenu();
		}
		else
		{
			SubMenu(1);
		}
		break;
	case 3:
		system("cls");
		cout << "******************************************" << endl;
		cout << "welcome to company inventory\n";
		cout << "1.enter product:\n";
		cout << "2.search product:\n";
		int inp;
		cin >> inp;
		if (inp == 1)
		{
			int x;
			cout << "welcome to inventory/catalogue:\n";
			cout << "1.islamabad\n";
			cout << "2.rawalpindi\n";
			cout << "enter: "; cin >> x;
			if (x == 1)
			{
				islamabad isb;
				isb.addproduct();
			}
			else if (x == 2)
			{
				rawalpindi rwl;
				rwl.addproduct();
			}
		}
		else if (inp == 2)
		{
			int x;
			cout << "welcome to inventory/catalogue:\n";
			cout << "1.islamabad\n";
			cout << "2.rawalpindi\n";
			cout << "enter: "; cin >> x;
			if (x == 1)
			{
				islamabad isb;
				isb.DisplayProduct();
			}
			else if (x == 2)
			{
				rawalpindi rwl;
				rwl.DisplayProduct();
			}
		}
	}
}

//*****************************USER CLASS************************//
//{
//setteres.......
User::User()
{
	//default constructor has no such good pupose right here...
}
void User::setuser_cnic(string cnic)
{
	cnic += '\0';	//concatenating the character with a nullz...
	strcpy_s(user_cnic , cnic.c_str());
}

void User::setuser_passw(string pass)
{
	pass += '\0';//concatenating the character with a nullz...
	strcpy_s(user_passw, pass.c_str());
}
void User::setuser_gend(char g)
{
	// strcpy_s(user_passw, pass.c_str());
	user_gend[0]=g;
}
void User::setuser_phone(string ufone)
{
	ufone += '\0';//concatenating the character with a nullz...
	strcpy_s(user_phone, ufone.c_str());
}
void User::setuser_address(string add)
{
	add += '\0';//concatenating the character with a nullz...
	strcpy_s(user_addres, add.c_str());
}
void User::setuser_age(int ag)
{
	age = ag;
}
void User::setuser_email(string mail)
{
	mail += '\0';//concatenating the character with a nullz...
	strcpy_s(user_email, mail.c_str());
}
void User::setuser_name(string n)
{
	n += '\0';//concatenating the character with a nullz...
	strcpy_s(user_name, n.c_str());
}

void User::Registration()
{
	//polymorphic aur virtual function ka istemal yahan par paya jata hai...
}
bool User::Login()
{
	///login be true so it can be called...
	return true;
}

//getter;;;
char* User::getuser_cnic()
{
	return user_cnic;
}
char* User::getuser_passw()
{
	return user_passw;
}
char* User::getuser_gend()
{
	return user_gend;
}
char* User::getuser_phone()
{
	return user_phone;
}
char* User::getuser_address()
{
	return user_addres;
}
int User::getuser_age()
{
	return age;
}
char* User::getuser_email()
{
	return user_email;
}
char* User::getuser_name()
{
	return user_name;
}
//===================================================================customer class===================================//
bool Customer::Login()
{
	//logang for liphe idk
	int ans;

	bool validity = false; 
	bool equaling = false; 
	bool completed = false;
	bool verified = true;

	string pass2;
	string name;
	string pass;




	//instance
	Customer cat;

	do {
		system("CLS");
		cout << "Enter  Username : ";
		cin >> name;

		cout << " Enter   Password : ";
		cin >> pass;

		verified = false;
		ifstream file("customer'sData", ios::in | ios::binary);
		
		if (file.is_open())
		{
			while (file.read((char*)&cat, sizeof(Customer)))
			{
				

				if (strcmp(cat.getuser_passw(), pass.c_str()) == 0)
				{

					if (strcmp(cat.getuser_name(), name.c_str()) == 0)
					{
					
						
						verified = true;
						cout << "Match found,Congratz.... !" << endl;
						completed = true;
						break;
					
					
					
					}
				}

				else 
				{
				
					verified = false;
					completed = false;
			
				
				}
				
			}
			
			if (verified == false)
			{
				cout << "The username or Password might be invalid. or not register at all" << "\n\n\n";
				system("pause");
			}
			
		
		
		}





	} while (verified == false);




	///to tell whether search was succesful or not...
	return completed;
}



//===============================================================
void Customer::Registration()
{
	int answer2;
	int price;
	int input;
	int output;
	int amount = 3500;

	string pass,
		pass2,
		gender,
		name,
		email,
		number,
		user_cnc,
		address,
		
		feelzgood;
	
	bool taken = false, 
		match = false,
		valid = true,
		cnicistaken = false;
	
	Customer cat;
	Customer* ct_ptr = &cat;

	cin.ignore();
	cout << " User to Enter your name : ";
	cin.getline(cat.user_name, 15);


	CnicVerification(ct_ptr);

	UsernameVerification(ct_ptr);//user verification

	PasswordValidation(ct_ptr);

	cin.ignore();

	cout << "Enter your Address : ";
	cin.getline(cat.user_addres, 100);



	cat.Savecustdata(cat, "customer'sData");
}


//=================================================
void Customer::UsernameVerification(Customer* retr)
{

	//for username verification

	string name;
	//instances
	Customer cat;

	bool aschecked = false,
		checkerx = false;

	do 
	{

		system("CLS");
		aschecked = false;

		cout << "Enter a Username : ";
		cin >> name;

		ifstream jkfile("customer'sData", ios::in | ios::binary);

		if (jkfile.is_open())
		{
			while (jkfile.read((char*)&cat, sizeof(cat)))
			{


				//here two character'z array compare horaheen takai batasakai kiya karna hai ya nhee karnaa
				if (strcmp(cat.getuser_name(), name.c_str()) == 0)
				{
					aschecked = true;
					cout << "This Username might be already taken, please try a new one." << endl;
					break;
				}
				///condition satisfiable.....

				else
				{
					aschecked = false;
				}
			}


			jkfile.close();
		}



	} while (aschecked == true);
	
	
	retr->setuser_name(name);
	
}

//=============================================
void Customer::PasswordValidation(Customer *retr)
{
	
		bool equalable = false;
		bool validity;
		
		int upper_case = 0,
			lower_case = 0,
			special_keyz = 0, num = 0;
		
		string inputkeyz, 
			secinputkeyz2;

		do {
			string temp;
			cout << "Choose a Password : ";
			cin >> inputkeyz;

			do {

				system("CLS");
				
				//yai wala loop check kar raha hai kai hamara password bilkul sahee hai ya nhee
				for (int i = 0; inputkeyz[i] != '\0'; i++)
				{
					
					if (inputkeyz[i] >= 65 && inputkeyz[i] <= 90)
					{
						upper_case++;
					}
					
					else if (inputkeyz[i] >= 97 && inputkeyz[i] <= 122)
					{
						lower_case++;
					}
					
					else if (inputkeyz[i] >= 48 && inputkeyz[i] <= 57)
					{
						num++;
					}
					
					else
					{
						special_keyz++;
					}
				}

				if (inputkeyz.length() == 8 && upper_case >= 1 && lower_case >= 1 && special_keyz >= 1 && num >= 1)
				{
					validity = true;
				}
				else
				{
					validity = false;
					cout << "The password is not according to the requirements, please try again!";
					system("CLS");
				}
			} while (validity == false);

			cout << "Re-Enter the Password : ";
			cin >> temp;

			
			
			if (temp == inputkeyz)
			{
				equalable = true;//
			}
			
			
			
			if (equalable == true)
			{
				break;//
			}
			
			
			else
			{
				cout << "The password does not match,please try again !\n" << endl;
			}




		} while (equalable == false);




		//setting up password.....
		retr->setuser_passw(inputkeyz);
		
}



//============================================
void Customer::CnicVerification(Customer* custard)
{
	string usercnic;
	Customer cat;
	
	bool stolend = false;

	do {
		stolend = false;
		
		if (stolend == false)
		{
			system("CLS");
		}
		//
		cout << "Enter your CNIC number : ";
		cin >> usercnic;


		while (usercnic.length() > 13 || usercnic.length() < 13)
		{
		
			system("CLS");
			//-------------------
			
			cout << "The length of CNIC is not valid."
				<< "Please try again.later ";
			cout << "PLease may you enter a valid CNIC here : ";
			cin >> usercnic;
		
		
		
		}

		ifstream custfile("customer'sData", ios::in | ios::binary);

		if (custfile.is_open())
		{
			while (custfile.read((char*)&cat, sizeof(cat)))
			{
				
				if (strcmp(cat.getuser_cnic(), usercnic.c_str()) == 0)
				{
					stolend = true;
					cout << "This CNIC is already registered, please try a new one." << endl;
				
					//have a break from looop.....
					break;
				}
				else
				{
					stolend = false;
				}
				//}
			}
			custfile.close();



		}  // checking if the cnic is already registered. or not for a whike
	} while (stolend == true);





	strcpy_s(custard->user_cnic, usercnic.c_str());
}


void Customer::Savecustdata(Customer custrd, string FileName)
{
	//file saving taking place

	ofstream file("customer'sData", ios::out | ios::binary | ios::app);   // writing obj 4r customer in a binary file
	
	
	if (!file)
	{
		cout << "The file could not be opened !" << endl;
	}
	
	
	
	file.write((char*)&custrd, sizeof(custrd));         // writing ends here for customer
	
	
	file.close();
}

//}


//======================================================================================MANAGER=================================================//
bool Manager::Login()
{

	//logang for liphe idk
	int ans;

	bool validity = false,
		equalable = false,
		finished = false,
		verifiable = true;

	string pass2,
		uzername,
		pass;

		Manager man;
	//Customer cat;

	do {
		//system("CLS");
		cout << "Enter  Username : ";
		cin >> uzername;

		cout << " Enter   Password : ";
		cin >> pass;

		verifiable = false;
		
		ifstream file("manager'sData", ios::in | ios::binary);

		if (file.is_open())
		{
			while (file.read((char*)&man, sizeof(Manager)))
			{


				if (strcmp(man.getuser_passw(), pass.c_str()) == 0)
				{

					if (strcmp(man.getuser_name(), uzername.c_str()) == 0)
					{
						verifiable = true;

						cout << "Match found for the credentials !" << endl;
						finished = true;
						
						
						
						break;
					}

				}

				else
				{
					verifiable = false;
					finished = false;
				}

			}
			if (verifiable == false)
			{
				cout << "The username or Password are invalid.\n\n";
			}
			//file close here...
		}

	} while (verifiable == false);

	return finished;

}

//==============================================Admin=========================================================//
bool Admin::Login()
{
	//class instance
	Admin admin;
	
	//string containing the password fir the admin'z controlzz................sheeesh...
	string nme = "admin",//username 
		pss = "21i0727";//password
	
	//here function for admins username
	admin.setuser_name(nme);

	//here function for adminzzz password
	admin.setuser_passw(pss);

	ofstream admfile("admin'sData", ios::out | ios::binary);
	if (admfile.is_open())
	{
		admfile.write((char*)&admin, sizeof(Admin));
		admfile.close();
	}
	//login for admin'z

	//logang for liphe idk
	int inputans;

	bool validity = false,
		equalable = false,
		finished = false,
		verifiable = true;

	string pass2, 
		name,
		pass;

	Admin adm;
	//Customer cat;

	do {
		system("CLS");
		cout << "Enter  Username : ";
		cin >> name;

		cout << " Enter   Password : ";
		cin >> pass;

		verifiable = false;
		
		
		
		
		ifstream file("admin'sData", ios::in | ios::binary);

		if (file.is_open())
		{
			while (file.read((char*)&adm, sizeof(Admin)))
			{

				//yo two conditions satisfiying easily
				if (strcmp(adm.getuser_passw(), pass.c_str()) == 0)
				{

					if (strcmp(adm.getuser_name(), name.c_str()) == 0)
					{
						verifiable = true;
						cout << "Match found for the credentials !" << endl;
						finished = true;
		
						
						///idk taking break from karachi?.........
						break;
					}
				}

				else
				{
					verifiable = false;
					finished = false;
				}

			}
			if (verifiable == false)
			{
			
				
				cout << "The username or Password are invalid." << endl;
			}
			//file close here...
		}

	} while (verifiable == false);








	return finished;




}
void Admin::Registration()
{
	//registration for manager'z
		int ans2, 
			rate,
			in,
			out,
			amount = 3500;
		cout << "welcome sir who you may register today" << endl;
	string pass,
		pass2, 
		gender,
		name,
		email,
		number,
		cnic,
		address,
		input,
		special;



	bool taken = false,
		match = false,
		valid = true,
		cnicistaken = false;
	//Manager man;
	//Manager* obj_ptr_doc = &man;
	//Customer cat;
	//Customer* obj_ptr = &cat;
	Admin adm;
	Admin* obj_ptr = &adm;
	cin.ignore();
	cout << " User to Enter your name : ";
	cin.getline(adm.user_name, 15);




	UsernameVerification(obj_ptr);//user verification

	PasswordValidation(obj_ptr);



	//cat.WalletSetter(amount);

	adm.Saveadmdata(adm, "manager'sData");
}

void Admin::Saveadmdata(Admin admn, string FileName)
{
	//file saving taking place

	ofstream nowfile("manager'sData", ios::out | ios::binary | ios::app);   // writing the object manager'z in a binary file
	
	
	
	if (!nowfile)
	{
		cout << "The file could not be opened !" << endl;
	}
	
	
	
	nowfile.write((char*)&admn, sizeof(admn));         //binary file writing ends here for manager'z
	nowfile.close();
}

void Admin::PasswordValidation(Admin* adm_obj)
{

	bool equalable = false;
	bool validity;
	int upper_case = 0,
		lower_case = 0,
		feelzgud = 0,
		num = 0;
	string pass,
		pass2;

	do {
		string temp;
		
		
		
		cout << "Choose a Password : ";
		cin >> pass;

		do {
			system("CLS");
			for (int i = 0; pass[i] != '\0'; i++)
			{
				if (pass[i] >= 65 && pass[i] <= 90)
				{
					upper_case++;
				}
				else if (pass[i] >= 97 && pass[i] <= 122)
				{
					lower_case++;
				}
				else if (pass[i] >= 48 && pass[i] <= 57)
				{
					num++;
				}
				else
				{
					feelzgud++;
				}
			}

			if (pass.length() == 8 && upper_case >= 1 && lower_case >= 1 && feelzgud >= 1 && num >= 1)
			{
				validity = true;
			}
			else
			{
				validity = false;
				cout << "The password is not according to the requirements, please try again!";
				system("pause");
				system("CLS");
			}
		} while (validity == false);

		cout << "Re-Enter the Password : ";
		cin >> temp;

		if (temp == pass)
		{
			equalable = true;
		}
		if (equalable == true)
		{	break;
		}
		else
		{
			cout << "The password does not match !" << endl;
		}
	} while (equalable == false);



	adm_obj->setuser_passw(pass);

}
void Admin::UsernameVerification(Admin* obj_adm)
{

	//for username verification

	string name;
	
	Admin adm;
	bool stolen = false;
		

	do
	{

		system("CLS");
		stolen = false;

		cout << "Enter a Username : ";
		cin >> name;

		ifstream manfile5("manager'sData", ios::in | ios::binary);

		if (manfile5.is_open())
		{
			while (manfile5.read((char*)&adm, sizeof(adm)))
			{
				
				if (strcmp(adm.getuser_name(), name.c_str()) == 0)
				{
					stolen = true;
					
					
					
					cout << "This Username is already taken, please try a new one." << endl;
				
					
					
					system("pause");
				
					
					
					//loop exiting
					break;
				}
				
				
				else
				{
					stolen = false;
			
				}
			
			
			}
		
			
			//file closing
			manfile5.close();
		}



	} while (stolen == true);
	
	
	//object pointing towards mutator
	obj_adm->setuser_name(name);

}
//================================product catalog=============================//
void productcat::setproductname(string prod) {
	prod += '\0';
	strcpy_s(productname, prod.c_str());
}
void productcat::setprodprice(int p)
{
	prodprice = p;
}
void productcat::setidno(int i)
{
	idno = i;
}
void productcat::setprice(int x)
{
	price = x;
}

//getter
int productcat::getprice()
{
	return price;
}
char* productcat::getproductname()
{
	return productname;
}
int productcat::getprodprice()
{
	return prodprice;
}
int productcat::getidno()
{
	return idno;
}
void productcat::addproduct() 
{
	//same as in registration
}
void productcat::editproduct()
{
	//same as in editing address will seee....
}

//======islamabad================catalog....

void islamabad::addproduct()
{
	int ans2, 
		rate,
		in,
		out,
		amount = 3500;

	string pass,
		gender,
		name,
		email,
		number;
	
	bool taken = false,
		match = false,
		valid = true,
		cnicistaken = false;
	
	islamabad pdc;
//	cin.ignore();
	cout << " User to Enter item name : ";
	cin.getline(pdc.productname, 15);
	cin.ignore();
	
	cout << "enter idno. of item:";
	cin >> pdc.idno;
	
	cout << "enter product price:";
	cin >> pdc.prodprice;


	

	

	pdc.Saveproddata(pdc, "islamabad'sData");

}

void islamabad::Saveproddata(islamabad isbd, string FileName)
{
	ofstream file("islamabad'sData", ios::out | ios::binary | ios::app);   
	
	if (!file)
	{
		cout << "The file could not be opened !" << endl;
	}
	
	file.write((char*)&isbd, sizeof(isbd));        
	
	file.close();

}
void islamabad::DisplayProduct()
{
	char name[15];
	islamabad isbd;
	
	cout << "enter name of prod for search:";
	cin >> name;
	
	ifstream isbfile("islamabad'sData", ios::in | ios::binary);
	bool stolen = false,
		equalable = false,
		validity = true,
		cnicistaken = false;
	
	
	
	if (isbfile.is_open())
	{
		while (isbfile.read((char*)&isbd, sizeof(isbd)))
		{
			
			if (strcmp(isbd.productname, name) == 0)
			{
				stolen = true;
				cout << "product Details : \n" 
					<< "Name : " << isbd.productname
					<< "\nprice : " << isbd.prodprice
					<< "\nid Number : " << isbd.idno << endl;

			}
			else
			{ 
				stolen = false;
			}
		}
		isbfile.close();



	}
}
void islamabad::prod()
{
	cout << "inventory:" << endl;
	cout << "1.meat\n 2.egg\n 3. dishes\n 4. soap\n5.fish" << endl;

	static int k;
	char name[15];
	islamabad isbd;

	cout << "enter name of prod for search:";
	cin >> name;

	ifstream isbfile("islamabad'sData", ios::in | ios::binary);
	bool stolen = false,
		equalable = false,
		validity = true,
		cnicistaken = false;
	int i = 0;


	if (isbfile.is_open())
	{
		while (isbfile.read((char*)&isbd, sizeof(isbd)))
		{

			if (strcmp(isbd.productname, name) == 0)
			{
				stolen = true;
				cout << "product Details : \n"
					<< "item name : " << isbd.productname
					<< "\nprice : " << isbd.prodprice
					<< "\nid Number : " << isbd.idno << endl;
				k += isbd.idno;
				cout << "if wish to continue: press 1 or exit then press anything else 1:\n";
				cin >> i;
				if(i==1)
				{
					prod();
				}
				
			}
			else
			{
				stolen = false;
			}
		}
		isbfile.close();

		price += k;

	}

}


//============================rawalpindi===========================//


void rawalpindi::addproduct()
{
	int ans2,
		rate,
		in;

	string pass,
		gender,
		name,
		email,
		number;

	bool taken = false,
		match = false,
		valid = true,
		cnicistaken = false;

	rawalpindi pdc;
	//	cin.ignore();
	cout << " User to Enter item name : ";
	cin.getline(pdc.productname, 15);
	cin.ignore();

	cout << "enter idno. of item:";
	cin >> pdc.idno;

	cout << "enter product price:";
	cin >> pdc.prodprice;






	pdc.Saveproddata(pdc, "rawal'sData");

}

void rawalpindi::Saveproddata(rawalpindi isbd, string FileName)
{
	ofstream file("rawal'sData", ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "The file could not be opened !" << endl;
	}

	file.write((char*)&isbd, sizeof(isbd));

	file.close();

}
void rawalpindi::DisplayProduct()
{
	char name[15];
	rawalpindi isbd;

	cout << "enter name of prod for search:";
	cin >> name;

	ifstream isbfile("rawal'sData", ios::in | ios::binary);
	bool stolen = false,
		equalable = false,
		validity = true,
		cnicistaken = false;



	if (isbfile.is_open())
	{
		while (isbfile.read((char*)&isbd, sizeof(isbd)))
		{

			if (strcmp(isbd.productname, name) == 0)
			{
				stolen = true;
				cout << "product Details : \n"
					<< "Name : " << isbd.productname
					<< "\nprice : " << isbd.prodprice
					<< "\nid Number : " << isbd.idno << endl;

			}
			else
			{
				stolen = false;
			}
		}
		isbfile.close();



	}
}
void rawalpindi::prod()
{
	cout << "inventory:" << endl;
	cout << "1.meat\n 2.egg\n 3. dishes\n 4. soap\n5.fish" << endl;

	static int k;
	char name[15];
	rawalpindi isbd;

	cout << "enter name of prod for search:";
	cin >> name;

	ifstream isbfile("islamabad'sData", ios::in | ios::binary);
	bool stolen = false,
		equalable = false,
		validity = true,
		cnicistaken = false;
	int i = 0;


	if (isbfile.is_open())
	{
		while (isbfile.read((char*)&isbd, sizeof(isbd)))
		{

			if (strcmp(isbd.productname, name) == 0)
			{
				stolen = true;
				cout << "product Details : \n"
					<< "item name : " << isbd.productname
					<< "\nprice : " << isbd.prodprice
					<< "\nid Number : " << isbd.idno << endl;
				k += isbd.idno;
				cout << "if wish to continue: press 1 or exit then press anything else 1:\n";
				cin >> i;
				if (i == 1)
				{
					prod();
				}

			}
			else
			{
				stolen = false;
			}
		}
		isbfile.close();

		price += k;
		payment::setmoney(k);

	}

}








int main()
{ 
	cout << endl << endl << endl << "\n\n\n\n" << endl;;
	cout<<"\t\t\t\t\t" << "WELCOME TO GROCERY STORE!" << endl;
	system("pause");

	Newgrocery n;
	n.MainMenu();
	n.SubMenu(1);
//	islamabad isb;
//	isb.addproduct();
//	isb.DisplayProduct();

//	isb.prod();

	//Customer c;
	//c.Registration();
	//c.Login();
	//Admin adm;
	//adm.Registration();
	//Manager man;
	//man.Login();
	//adm.Login();
}


/*so basically make a user function that has all the user related queuries and then make a grocery class that has all the thing related to
shopping than combine multiple sub classes to these so we can navigate to one to another class in a loop easily
and call the main class in a main function to start that loop among classes.....
*/