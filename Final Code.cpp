#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

const int MAX_CARS=100;

struct car
{
    string maker;
    string model;
    int year;
    bool available;
};

void dispMenu();
void login();
void reg();

void displayMenu();
void addCar(car cars[], int);
void displayCar(car cars[], int);
void rentCar(car cars[], int);
void returnCar(car cars[], int);
int main()
{
	char option;
	cout<<"\n\t\t\t\t *******************************************";
	cout<<"\n\t\t\t\t| Welcome to Car Rental management system   |";
	cout<<"\n\t\t\t\t *******************************************";
	cout<<"\n\n Please LOGIN or REGISTER yourself first.";
	dispMenu();
	a:
	cout<<"\n\t\t\t Please select from above mentioned choices: ";
	cin>>option;
	
	switch(option)
	{
		case '1':
			reg();
			break;
			
		case '2':
			login();
			break;
			
		case '3':
			return 0;
			break;
			
		default:
			cout<<"\n Invalid choice. ";
			goto a;
			break;
			
	}
	
	car cars[MAX_CARS];
	char choice;
	int num_of_cars=0;
	
	do
	{
	    displayMenu();
	    cout<<"\n\t\t\t Please select from above mentioned choices: ";
	    cin>>choice;
	    
        switch(choice)
	    {
	        case '1':
	        system("cls");
		    cout<<"\n Enter number of cars to be added: ";
	        cin>>num_of_cars;
		    addCar(cars,num_of_cars);
	        break;
					
	        case '2':
	        system("cls");
		    displayCar(cars,num_of_cars);
		    break;
					
	        case '3':
	        system("cls");
	        rentCar(cars,num_of_cars);
		    break;
		    
	        case '4':
	        system("cls");
	        returnCar(cars,num_of_cars);
		    break;
		    
	        case '5':
		    cout<<"\n Exited successfully.";
		    return 0;
		    break;
		    
	        default:
		    system("cls");
		    cout<<"\n\t\t Invalid choice.";
		    choice='0';
		    break;
	    }
				  	
	} while(choice!='5');
	
	        return 0;
}

void dispMenu()
{
	cout<<"\n 1. REGISTER.";
    cout<<"\n 2. LOGIN.";
    cout<<"\n 3. Exit.";
}

void login()
{
	string userID,password,ID,pass;
	cout<<"\n Enter Username: ";
	cin.ignore();
	getline(cin,userID);
    cout<<"\n Enter Password: ";
    getline(cin,password);
    ifstream get("C:\\Users\\Ahmed's PC\\Desktop\\login credentials.txt");
    while(get>>ID>>pass)
    {
    	if(userID==ID && password==pass)
    	{
    		system("cls");
    		cout<<"\n\t\t\t\t Congratulations! You are logged in.";
    		get.close();
		}
		else
		{
			system("cls");
			cout<<"\n Login unsuccessful.";
			cout<<"\n Please enter correct details.";
			main();
		}
	}
	return;
}

void reg()
{
	string r_userID, r_pass;
	cout<<"\n Enter Username: ";
	cin.ignore();
	getline(cin,r_userID);
    cout<<"\n Enter Password: ";
    getline(cin,r_pass);
    ofstream put("C:\\Users\\Ahmed's PC\\Desktop\\login credentials.txt",ios::app);
    put <<r_userID<<"  "<< r_pass<<endl;
    system("cls");
    cout<<"\n\t\t\t\t Registration is successful.";
    put.close();
    return;
}

void displayMenu()
{
	cout<<"\n\n\t\t\t\t***** Main Menu *****";
	cout<<"\n 1. Add Cars.";
    cout<<"\n 2. Display available cars.";
    cout<<"\n 3. Rent a car.";
    cout<<"\n 4. Return a car.";
    cout<<"\n 5. Exit.";
}

void addCar(car cars[],int num_of_cars)
{
	for(int i=0;i<num_of_cars;i++)
	{
		cout<<"\n Please enter details of car "<<i+1<< ".";
		cout<<"\n Enter maker of car: ";
		cin.ignore();
		getline(cin,cars[i].maker);
	    cout<<"\n Enter model of car: ";
	    getline(cin,cars[i].model);
		cout<<"\n Enter year of car: ";
		cin>>cars[i].year;
		cars[i].available=true;
	}
	cout<<"\n\t\t Cars added successfully.";
	return;
}

void displayCar(car cars[],int num_of_Cars)
{
	if(num_of_Cars!=0)
	{
	    cout<<setw(10)<<"Make"<<setw(15)<<"Model"<<setw(10)<<"Year"<<setw(15)<<"Available"<<endl;
	    for(int i=0;i<num_of_Cars;i++)
		     cout<<setw(10)<<cars[i].maker<<setw(15)<<cars[i].model<<setw(10)<<cars[i].year<<setw(15)<<(cars[i].available?"Yes":"No")<<endl;		
	}
	else
	cout<<"\n\t\t First initialize cars.";
	return;
}

void rentCar(car cars[], int num_of_Cars)
{
	displayCar(cars,num_of_Cars);
    string model;
    cout<<" Enter the model of the car you want to rent: ";
    cin.ignore();
    getline(cin,model);
    for(int i=0; i<num_of_Cars; i++)
	{
        if (cars[i].model==model && cars[i].available)
		{
            cars[i].available = false;
            cout <<" Car rented successfully. Enjoy your ride!\n";
            return;
        }
    }
    cout<<" Sorry, the requested car is not available for rent.\n";
}

void returnCar(car cars[], int num_of_Cars)
{
	displayCar(cars,num_of_Cars);
    string model;
    cout<<" Enter the model of the car you want to return: ";
    cin.ignore();
    getline(cin,model);
    for(int i=0;i<num_of_Cars;i++)
	{
        if (cars[i].model==model && !cars[i].available)
		{
            cars[i].available = true;
            cout <<" Car returned successfully. Thanks!\n";
            return;
        }
    }
    cout<<" Sorry, the requested car is not rented by you.\n";
}






















