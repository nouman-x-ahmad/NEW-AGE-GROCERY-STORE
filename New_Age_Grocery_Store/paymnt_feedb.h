#pragma once
#include<iostream>
//#include<string>
using namespace std;
class payment {
protected:
	int money;
public:
	payment()
	{

	}
	static void setmoney(int x)
	{
		//money = x;
	}
	int getmoney()
	{
		return money;
	}

	void e_transfer()
	{
		cout << "e-transfer payment successful" << endl;
	}
	void banktransfer()
	{
		cout << "bank transfer payment has been done" << endl;
	}
};
class feedback {
protected:
	char cmnt[100];
public:
	feedback()
	{

	}
	void setcmnt()
	{
		cmnt[0] = NULL;
	}
	char* getcmnt()
	{
		return cmnt;
	}

	void tweet()
	{
		char yt[20];
		cout << "enter your tweet:";
		cin.getline(yt, 15);


		ofstream nowfile("twt'sData", ios::out | ios::binary | ios::app);   // writing the object manager'z in a binary file



		if (!nowfile)
		{
			cout << "The file could not be opened !" << endl;
		}



		nowfile.write((char*)yt, sizeof(yt));         //binary file writing ends here for manager'z
		nowfile.close();
	}

};