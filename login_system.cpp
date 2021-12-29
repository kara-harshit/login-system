#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
void sign_up();
using namespace std;
void menu();
class user{
	public:
		string name;
		long pwd;
		void sign_up();
		void login();		
};
void user::sign_up()
{
	long check_pw;
	cout<<"\n\n\t\t\t-----------------------|| 	REGISTER WINDOW		||---------------------------\n\n\n\n"<<endl;
	cout<<"\n\n\t\t\tENTER YOUR USER NAME (should not contain space in name) : ";
	cin.ignore();
	getline(cin,name);
	cout<<"\n\n\t\t\tENTER NEW PASSWORD : ";
	cin>>pwd;
	cout<<"\n\n\t\t\tENTER PASSWORD AGAIN : ";
	cin>>check_pw;
	if(check_pw==pwd)
	{
		ofstream fileout("sign_up.txt",ios::app);
		fileout<<name<<" "<<pwd<<endl;
		fileout.close();
		cout<<"\t\t\tRegistering.";
		for(int i=1;i<=8;i++)
		{
			Sleep(500);
			cout<<".....";
		}
		cout<<"\n\n\n\t\t\t YOU ARE SIGNED UP SUCCESSFULLY !!"<<endl;
		cout<<"\n\nEnter any key to continue";
		getch();
	}else{
		cout<<"\t\t\tPASSWORD DON'T MATCH"<<endl;
		getch();
		system("CLS");
		sign_up();
	}
	
}
void user::login()
{
	char ch;
	cout<<"\n\n\t\t\t-----------------------|| 	LOGIN WINDOW		||---------------------------\n\n\n\n"<<endl;
	user log_user;
	string fname,lname;
	long wd;
	cout<<"\n\n\t\t\tENTER YOUR USER NAME : ";
	cin.ignore();
	getline(cin,log_user.name);
	cout<<"\n\n\t\t\tENTER YOUR PASSWORD : ";
	cin>>log_user.pwd;
	ifstream filein("sign_up.txt",ios::in);
	do{
		filein>>fname>>wd;
		if(fname==log_user.name && wd==log_user.pwd)
		{
			cout<<"\n\n\t\t\tVerifying.";
			for(int i=1;i<=8;i++)
			{
				Sleep(500);
				cout<<"...";
			}
			cout<<"\n\n\t\t\tLOGGED SUCCESSFULLY"<<endl;
			cout<<"\n\n\t\t\tEnter any key to continue"<<endl;
			ch='a';
			getch();
			break;
		}
	}while(!filein.eof());
	
	if(ch=='a')
	{
		//system("CLS"); //uncomment this 
		//menntion function you want to show after login
	}else{
		cout<<"\n\n\t\t\tVerifying.";
			for(int i=1;i<=8;i++)
			{
				Sleep(500);
				cout<<"...";
			}
			cout<<"\n\n\t\t\tACCESS DENIED !!\n\n"<<endl;
		system("PAUSE");
		system("CLS");
		menu();
	}
	filein.close();
}
int main()
{
	menu();
	return 0;
}
void menu()
{
	int choice;
	cout<<"\n\t\t\t\t||				WELCOME		 		  ||\n\n\n\n"<<endl;
	cout<<"\t\t\t----------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t          || REGISTER [1] 			    	lOGIN [2] ||"<<endl;
	cout<<"\t\t\t----------------------------------------------------------------------------"<<endl;
	cout<<"\n\n\t\t\tENTER YOUT CHOICE : ";
	cin>>choice;
	switch(choice)
	{
		case 1: 
		{
			
			user new_user;
			system("CLS");
			new_user.sign_up();
			system("CLS");
			menu();
			break;
		}
		case 2:
			{
			user new_login;
			system("CLS");
			new_login.login();
			break;
			}
	}
}

