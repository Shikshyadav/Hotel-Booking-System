#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS



class hotel
{

	int room_no;
	char name[30];
	char address[50];
	char phone[10];

	public:

		void main_menu();		//to dispay the main menu
		void add();			//to book a room
		void display(); 		//to display the customer record
		void rooms();			//to display alloted rooms
		int check(int);			//to check room status
		void modify();		//to modify the record
		void delete_rec();		//to delete the record
		void bill();                 //for the bill of a record
		void main_display();


};
    //END OF CLASS



	//FOR DISPLAYING MAIN MENU



	void hotel::main_menu()
	{
		hotel object;
		int choice;
		while(choice!=5)
		{

  			system("cls");
			cout<<"\n\t\t\t\t\t*************************";
			
			cout<<"\n\t\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
			cout<<"\n\t\t\t\t\t      * MAIN MENU *";
			
			cout<<"\n\t\t\t__________________________________________________________________________";
			cout<<"\n\t\t\t**************************************************************************";
			
			
			cout<<"\n\n\n\t\t\t1.Book A Room";
			cout<<"\n\t\t\t2.Customer Records";
			cout<<"\n\t\t\t3.Rooms Allotted";
			cout<<"\n\t\t\t4.Modify customer record";
			cout<<"\n\t\t\t5.Delete Customer record";
			cout<<"\n\t\t\t6.Bill Of Customer";
			cout<<"\n\t\t\t7.Exit";
			cout<<"\n\t\t\t__________________________________________________________________________";
			
			cout<<"\n\n\t\t\tEnter Your Choice: ";
			cin>>choice;

			switch(choice)
			{

				case 1:	add();
				break;

				case 2: display();
				break;

				case 3: rooms();
				break;

				case 4:modify();
				break;

				case 5:delete_rec();
				break;

				case 6: bill();
				break;

				case 7: exit(0);
				

				default:
				{

					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to   continue....!!";
					getch();

				}	

			}	

		}	

	}	


	//END OF MENU FUNCTION


	//FUNCTION FOR BOOKING OF ROOM


	void hotel::add()
	{

  		system("cls");
		int r,flag;
		ofstream fout("Record.txt",ios::app);
		
		cout<<"\n\t\t\t\t\t--BOOK ROOM-------";
		cout<<"\n\t\t\t__________________________________________________________________________";
		cout<<"\n\t\t\t**************************************************************************";
		cout<<"\n\t\t\t Enter Customer Detalis";
		cout<<"\n\t\t\t ----------------------";
		cout<<"\n\n\t\t\t Room no: ";
		cout<<"\n\t\t\t Total no. of Rooms - 50";
		cout<<"\n\n\t\t\t Ordinary Rooms \n\t\t\t No. of beds = 1 single bed \n\t\t\t Price: NRS 2000 \n\t\t\t choice = 1 - 30";
		cout<<"\n\n\t\t\t Family Rooms \n\t\t\t No. of beds = 1 queen sized bed with 1 single bed \n\t\t\t Price: NRS 5000 \n\t\t\t choice = 31 - 45";
		cout<<"\n\n\t\t\t Suit Rooms \n\t\t\t No.of beds = 1 king sized bed with private spa \n\t\t\t Price: NRS 7000 \n\t\t\t choice = 46 - 50";
		cout<<"\n\n\t\t\t__________________________________________________________________________";
		
		cout <<"\n\t\t\t Enter The Room no. you want to stay in :- ";
		cin>>r;
		fflush(stdin);
		flag=check(r);

		if(flag)
		{
			cout<<"\n Sorry..!!!Room is already booked";
			cout<<"\n\t\t\t__________________________________________________________________________";
		}

		else
		{	

			room_no=r;
			fflush(stdin);
			cout<<"\t\t\t Name of the customer: ";
			cin>>name;
			fflush(stdin);
			cout<<"\t\t\t Address : ";
			cin>>address;
			fflush(stdin);
			cout<<" \t\t\tPhone No: ";
			cin>>phone;
			fflush(stdin);

			fout.write((char*)this,sizeof(*this));
			cout<<"\n\t\t\t Room is booked...!!!";
			cout<<"\n\t\t\t__________________________________________________________________________";
			
			
		//	break;
			//goto labal;
		

		}	
     //  labal:
		cout<<"\n\n\n\t\t Press any key to continue.....!!";

		getch();	
		fout.close();

	}


	//END OF BOOKING FUNCTION


	//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD





	void hotel::display()
	{

  		system("cls");

		ifstream fin("Record.txt",ios::in);
		int r,flag=0;
		
		cout<<"\n\t\t\t\t\t--CUSTOMER DETAILS-------";
		cout<<"\n\t\t\t__________________________________________________________________________";
		cout<<"\n\t\t\t**************************************************************************";
		cout<<"\n\t\t\t Enter room no. for a particular customer`s details :- ";
		cin>>r;
		

		while(!fin.eof())
		{

			fin.read((char*)this,sizeof(hotel));
			if(room_no==r)
			{

  				system("cls");
				cout<<"\n\t\t\t\t\t Customer Details";
				cout<<"\n\t\t\t__________________________________________________________________________";
				cout<<"\n\t\t\t**************************************************************************";			
				cout<<"\n\t\t\t ----------------";
				cout<<"\n\n\t\t\t Room no: "<<room_no;
				cout<<"\n\t\t\t Name: "<<name;
				cout<<"\n\t\t\t Address: "<<address;
				cout<<"\n\t\t\t Phone no: "<<phone;
				cout<<"\n\t\t\t__________________________________________________________________________";
				cout<<"\n\t\t\t**************************************************************************";			
				flag=1;
				break;

			}
			

		}

		if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant....!!";
		cout<<"\n\n Press any key to continue....!!";

		getch();
		fin.close();
	}


	//END OF DISPLAY FUNCTION

	//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


	void hotel::rooms()
	{

  		system("cls");

		ifstream fin("Record.txt",ios::in);
		cout<<"\n\t\t\t    List Of Rooms Allotted";
		
		
		cout<<"\n____________________________________________________________________________________________________";
		cout<<"\n****************************************************************************************************";	
		cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";		
		fin.read((char*)this,sizeof(hotel));
		while(!fin.eof())
		{

			
			cout<<"\n\n "<<room_no<<"\t\t"<<name;
			cout<<"\t\t"<<address<<"\t\t"<<phone;
			fin.read((char*)this,sizeof(hotel));
			

		}
		cout<<"\n___________________________________________________________________________________________________";
		cout<<"\n***************************************************************************************************";	

		cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
		getch();
		fin.close();

	}	




	int hotel::check(int b)
	{
	
		int flag=0;

	

		ifstream fin("Record.txt",ios::in);
		fin.read((char*)this,sizeof(hotel));
		while(!fin.eof())
		{

			
			if(room_no==b)
			{

				flag=1;
				break;

			}
			fin.read((char*)this,sizeof(hotel));

		}

		fin.close();
		return flag;

	}


	//FUNCTION TO MODIFY CUSTOMERS RECORD


	void hotel::modify()
	{

		int r;
		long pos,flag=0;

		cout<<"\n Enter room no: " ;
		cin>>r;

		fstream file("Record.txt",ios::in|ios::out|ios::binary);

		while(!file.eof())
		{

			pos=file.tellg();
			file.read((char*)this,sizeof(hotel));

			if(room_no==r)
			{
				system("cls");
				cout<<"\n\t\t\t\t\t-----MODIFICATION PAGE-------";
				cout<<"\n\t\t\t__________________________________________________________________________";
				cout<<"\n\t\t\t**************************************************************************";
				cout<<"\n Enter New Details";
				cout<<"\n -----------------";
				
				cout<<"\n Name: ";
				cin>>name;
				fflush(stdin);
				
				cout<<" Address: ";
				cin>>address;
				fflush(stdin);
				
				cout<<" Phone no: ";
				cin>>phone;
				fflush(stdin);
				
				file.seekg(pos);
				file.write((char*)this,sizeof(hotel));
				cout<<"\n Record is modified....!!";
				flag=1;
				break;

			}	

		}

		if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
		file.close();

	}


	//END OF MODIFY FUNCTION


	//FUNCTION FOR DELETING RECORD


	void hotel::delete_rec()
	{

		int flag=0,r;
		char ch;
		cout<<"\n Enter room no: " ;
		cin>>r;
		ifstream fin;
		ofstream fout;
	 	fin.open("Record.txt",ios::in);  //reads from the file
		 fout.open("temp.txt",ios::out);  //write to temp
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			
		   if(r!=room_no)
		   {
		   		fout.write((char*)this,sizeof(hotel));
		   }
			fin.read((char*)this,sizeof(*this));


		}

		fin.close();
		fout.close();
	 	fin.open("temp.txt",ios::in);  //reads from the file
		 fout.open("Record.txt",ios::out | ios::trunc );

		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			fout.write((char*)this,sizeof(*this));
			fin.read((char*)this,sizeof(*this));
	   	}
	   	fin.close();
		fout.close();
		cout<<"\n\n\t\t\tRecord deleted!";
	}


	//END OF DELETE FUNCTION


	//FUNCTION FOR CUSTOMER`S BILL
	void printBill(int price)
	{
		double vat;
		double dis;
		vat=0.1*price;
		dis=0.08*price;
        cout << "\n\n\n\t\t\t\t--------ABC Hotel and Restaurent--------" << endl;
        cout << "\t\t\t\t-------------Bill-------------" << endl;
        cout << "\t_____________________________________________________________________________________________________-" << endl;  					
		cout<<"\t\t\t\tRoom price         =  "<<price;
		cout<<"\n\t\t\t\tVAT amount       ="<<"\t"<<vat;
		cout<<"\n\t\t\t\tDiscount amount  ="<<"\t"<<dis;
		cout<<"\n\t\t\t\tTotal amount     ="<<"\t"<<(price-vat+dis);
		cout<<"\n\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\t\t\t\tyour bill = "<<(price-vat+dis);
		cout<<"\n\n\n\n\t\t\t\t-----------------THANK YOU for visiting------------------!!";
		 cout << "\n\t_____________________________________________________________________________________________________-" << endl;  
		
	}

	void hotel::bill()
	{
		int r;

		hotel h1;
		cout<<"\n Enter room no: " ;
		cin>>r;
		ifstream f1;
 		f1.open("record.txt",ios::in|ios::binary);
 		

		if(!f1)
 		cout<<"cannot open";

 		else
 		{

  			while(f1)

  			{
  				system("cls");

  				f1.read((char*)&h1,sizeof(hotel));

	  			
	
	  			if (!r == h1.room_no)
	  			{
	  				 cout<<"room no. not found";
	

	
	  			}
	  				
	
	  			else
	  			{ 
	  				if(r>=1&&r<=30)
	  				{
	  					printBill(2000);
	  					
					  }
	
	  			
	
	  				else if (r>=31&&r<=45)
	  				{
	  					printBill(5000);
	  					
					  }
	
	  				else
	  				{
	  					printBill(7000);
	  					
					}
				 
				}
			break;
				
			}
			
  		}

  		f1.close();
 		 getch();

	}

	//END OF BILLING FUNCTION

	//START OF MAIN PROGARM


	void main_display()
	{

		hotel h;

  		system("cls");

		cout<<"\n\t\t\t****************************************************************************************************************\n";
		cout<<"\n\t\t\t****************************************************************************************************************\n\n\n";
		cout<<"\t\t| $$  | $$            | $$              | $$      | $$__  $$                    | $$      |__/                           \n";
		cout<<"\t\t| $$  | $$  /$$$$$$  /$$$$$$    /$$$$$$ | $$      | $$  \\ $$  /$$$$$$   /$$$$$$ | $$   /$$ /$$ /$$$$$$$   /$$$$$$        \n";
		cout<<"\t\t| $$$$$$$$ /$$__  $$|_  $$_/   /$$__  $$| $$      | $$$$$$$  /$$__  $$ /$$__  $$| $$  /$$/| $$| $$__  $$ /$$__  $$       \n";
		cout<<"\t\t| $$__  $$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$__  $$| $$  \\ $$| $$  \\ $$| $$$$$$/ | $$| $$  \\ $$| $$  \\ $$       \n";
		cout<<"\t\t| $$  | $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  \\ $$| $$  | $$| $$  | $$| $$_  $$ | $$| $$  | $$| $$  | $$       \n";
		cout<<"\t\t| $$  | $$|  $$$$$$/  |  $$$$/|  $$$$$$$| $$      | $$$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\  $$| $$| $$  | $$|  $$$$$$$       \n";
		cout<<"\t\t|__/  |__/ \\______/    \\___/   \\_______/|__/     |_______/  \\______/  \\______/ |__/  \\__/|__/|__/  |__/ \\____  $$       \n";
		cout<<"\t\t                                                                                                        /$$  \\ $$       \n";
		cout<<"\t\t                                                                                                        |  $$$$$$/       \n";
		cout<<"\t\t                                                                                                         \\______/        \n";
		cout<<"\t\t                                                                                 /$$                                     \n";
		cout<<"\t\t                                                                                | $$                                     \n";
		cout<<"\t\t                          /$$$$$$   /$$$$$$   /$$$$$$  /$$  /$$$$$$   /$$$$$$$ /$$$$$$                                   \n";
		cout<<"\t\t                         /$$__  $$ /$$__  $$ /$$__  $$|__/ /$$__  $$ /$$_____/|_  $$_/                                   \n";
		cout<<"\t\t                        | $$  \\ $$| $$  \\__/| $$  \\ $$ /$$| $$$$$$$$| $$        | $$                                     \n";
		cout<<"\t\t                        | $$  | $$| $$      | $$  | $$| $$| $$_____/| $$        | $$ /$$                                 \n";
		cout<<"\t\t                        | $$$$$$$/| $$      |  $$$$$$/| $$|  $$$$$$$|  $$$$$$$  |  $$$$/                                 \n";
		cout<<"\t\t                        | $$____/ |__/       \\______/ | $$ \\_______/ \\_______/   \\___/                                   \n";
		cout<<"\t\t                        | $$                     /$$  | $$                                                               \n";
		cout<<"\t\t                        | $$                    |  $$$$$$/                                                               \n";
		cout<<"\t\t                        |__/                     \\______/                                                                \n";



	cout<<"\n\t\t\t****************************************************************************************************************";
	cout<<"\n\t\t\t****************************************************************************************************************";                                                                                                        
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPress any key to continue....!!";

	getch();

	h.main_menu();

	}

	//END OF MAIN PROGRAM



	void login();
	void regstr();
	void forgot();

	int main()
	{

		int ch;
		cout<<"\n\n\t\t\t\t\t\t---ADMIN PAGE---";
		
		cout<<"\n\t\t\t__________________________________________________________________________";
		cout<<"\n\t\t\t**************************************************************************";
		cout<<"\n\t\t\t\t\t\t1.Register";
		cout<<"\n\t\t\t\t\t\t2.Login";
		cout<<"\n\t\t\t\t\t\t3.Forgot credential";
		cout<<"\n\n\t\t\t\t\t\tEnter your choice:";
		cin>>ch;
		cout<<"\n\t\t\t__________________________________________________________________________";
		
		switch(ch)
		{
			case 1:
				regstr();
				
				break;
				
			case 2:
				login();
				break;
			case 3:
				forgot();
				break;
			default:
				cout<<"\t\tSorry, wrong choice selected."<<endl;
		}
		cout<<endl;
		char x;
		cout<<"\t\tEnter  m to go to main menu:";
		cin>>x;
		if(x=='m')
		{
		
			system("cls");
			main();
		}
		else
		{
			return 0;
		}
	}
	
	
	void regstr()
	{
		int t=0;
		string usr,pas,u,p;
		system("cls");
		cout<<"\t\t\t\t\t------------REGISTER PAGE----------";
		cout<<"\n\t\t\t__________________________________________________________________________";
		cout<<"\n\t\t\t**************************************************************************";
		cout<<"\n\t\t\tEnter username:";
		cin>>usr;
		ofstream write("username.txt",ios::app); 
		ifstream read("username.txt");
		while(read>>u>>p)
		{
			if(u==usr)
			{
				t=1;
				break;
			}
		}
		if(t==1)
		{
			cout<<"\n\t\tUsername is already taken."<<endl;
		}
		else
		{
			cout<<"\n\t\t\tEnter password:";
			cin>>pas;
			

			write<<usr<<" "<<pas<<endl;
			system("cls");
			cout<<"\n\t\t\tRegistration is successfull."<<endl;
			
			cout<<"\n\t\tplease login now!!\n\n";
			login();
		}
		write.close();
	}
	void login()
	{
		int i=0;
		int t=0;
		string usr,u,p;
		char pas[32];
		cout<<"\t\t\t\t\t------------LOGIN PAGE----------";
		cout<<"\n\t\t\t__________________________________________________________________________";
		cout<<"\n\t\t\t**************************************************************************";
		cout<<"\n\t\tEnter your credentials:\n";
		cout<<"\n\t\tEnter the username: ";
		cin>>usr;
		cout<<"\n\t\tEnter the password: ";
		fflush(stdin);
  	  	char a;//a Temp char
  	 	 for(i=0;;)//infinite loop
  	 	 {
  			a=getch();//stores char typed in a
     	   if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
     	       //check if a is numeric or alphabet
     	   {
     	       pas[i]=a;//stores a in pass
     	       ++i;
     	       cout<<"*";
     	   }
	        if(a=='\b'&&i>=1)//if user typed backspace
 	           //i should be greater than 1.
	        {
  	          cout<<"\b \b";//rub the character behind the cursor.
 	           --i;
 	       	}
        	if(a=='\r')//if enter is pressed
        	{
       		     pas[i]='\0';//null means end of string.
        	    break;//break the loop
        	}
    	}

		ifstream read("username.txt"); //ifstream uses here for reading the file
		while(read>>u>>p) // while loop uses here for reading the file till end and in each iteration registered username and password store in u and p respectively
		{
			if(u==usr && p==pas)
			{
				t=1;
				break;
			}
		}
		read.close();
		if(t==1)
		{
			cout<<"\n\t\tLogin successfull"<<endl;
			main_display();
		}
		else
		{
			cout<<"\n\t\tLogin error."<<endl;
		
		}
	}
	void forgot()
	{
		int ch;
		system("cls");
		cout<<"1.Search your account by username\n";
		cout<<"2.Search Your account by password\n";
		cout<<"3.Mainmenu\n";
		cout<<"4.Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int t=0;
				string su,u,p;
				cout<<"\n\t\tEnter your remembered username:";
				cin>>su;
				ifstream read("username.txt");
				while(read>>u>>p)
				{
					if(su==u)
					{
						t=1;
						break;
					}
				}
				read.close();
				if(t==1)
				{
					cout<<"\n\t\tCongrats! account found\nPassword is: "<<p<<endl;
				}
				else
				{
					cout<<"\n\t\tSorry, account not found"<<endl;
				}
				break;
			}
			case 2:
				{
					int t=0;
					string sp,u,p;
					cout<<"\n\t\tEnter your remembered password:";
					cin>>sp;
					ifstream read("username.txt");
					while(read>>u>>p)
					{
						if(sp==p)
						{
							t=1;
							break;
						}
					}
					read.close();
					if(t==1)
					{
						cout<<"\n\t\tCongrats! account found\nUsername is: "<<u<<endl;
					}
					else
					{
						cout<<"\n\t\tSorry, account not found"<<endl;
					}
					break;
				}
	   		 case 3:
		 	   {
			    	cout<<endl;
			    	main();
			    	break;
				}
			default:
			{
				cout<<"\n\t\tWrong choice selected.press a key to try again!"<<endl;
				forgot();
			}
			
	}
}

