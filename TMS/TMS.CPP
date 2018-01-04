#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<time.h>
class start
{
	private:
	char name[20];
	public:
	void password();
	void display_current_date_getting_started();
	void get_name()
	{
		clrscr();
		char ch[2];
		cin.getline(ch,2);
		cout<<"Enter your name: ";
		cin.getline(name,20);
	}
	const char* show_name()
	{
		return name;
	}
};
start s;
class tasks
{
	protected:
	int task,package;
	void view_packages();
	void FAQ();
	void contacts();
	void guide_book();
	void travel_tips();
	void login();
};
class tasks_customer:public tasks
{
	void booking();
	void give_feedback();
	public:
	void select_task();
};
class tasks_admin:public tasks
{
	void view_feedback();
	void software_details();
	void previous_booking_details();
	public:
	void select_task();
};
int res=0;
class book_package
{
	private:
	char name[20],address[50],city[20],state[20],country[20],email[30];
	char pincode[7],contact_no[11];
	int package_ID,no_of_guests;
	public:
	void get();
	void show();
	void res_no();
};
void book_package::get()
{
	clrscr();
	char ch[2];
	cin.getline(ch,2);
	cout<<"Name : ";
	strcpy(name,s.show_name());
	cout<<name<<endl;
	cout<<"Address : ";
	cin.getline(address,50);
	cout<<"City : ";
	cin.getline(city,20);
	cout<<"State : ";
	cin.getline(state,20);
	cout<<"Country : ";
	cin.getline(country,20);
	cout<<"Pincode : ";
	cin.getline(pincode,7);
	cin.getline(ch,2);
	cout<<"Contact no : ";
	cin.getline(contact_no,11);
	cin.getline(ch,2);
	cout<<"Email ID : ";
	cin.getline(email,30);
	again:
	cout<<"Package ID : ";
	cin>>package_ID;
	if(package_ID>4||package_ID<1)
	{
		cout<<"Wrong input. Enter again"<<endl;
		goto again;
	}
	cout<<"Number of guests : ";
	cin>>no_of_guests;
	cout<<"Your resistration number is "<<res<<" and you have to pay an ammount of Rs ";
	switch(package_ID)
	{
		case 1:
		cout<<(long)20000*no_of_guests;
		break;
		case 2:
		cout<<(long)167000*no_of_guests;
		break;
		case 3:
		cout<<(long)74999*no_of_guests;
		break;
		case 4:
		cout<<(long)200000*no_of_guests;
	}
	cout<<" to \nconfirm your resistration.";
	cout<<"\nThanks for using our service.";
}
void book_package::show()
{
	cout<<"Name : "<<name<<endl;
	cout<<"Address : "<<address<<endl;
	cout<<"City : "<<city<<endl;
	cout<<"State : "<<state<<endl;
	cout<<"Country : "<<country<<endl;
	cout<<"Pincode : "<<pincode<<endl;
	cout<<"Contact no : "<<contact_no<<endl;
	cout<<"Email ID : "<<email<<endl;
	cout<<"Package ID : "<<package_ID<<endl;
	cout<<"Number of guests : "<<no_of_guests<<endl;
}
void book_package::res_no()
{
	fstream fobj("D:\\RES.txt",ios::out|ios::in|ios::binary);
	res=fobj.get();
	if(fobj.eof())
	{
		res=1;
		fobj.close();
		fobj.open("D:\\RES.txt",ios::out|ios::trunc);
		fobj.put(res);
	}
	else
	{
		res++;
		fobj.close();
		fobj.open("D:\\RES.txt",ios::out|ios::trunc);
		fobj.put(res);
	}
	fobj.close();
}
class contact_info
{
	private:
	char contact_no[11];
	char email_ID[30];
	public:
	void view_contacts();
	void edit_contacts();
};
contact_info ci;
void contact_info::edit_contacts()
{
	clrscr();
	fstream obj("D:\\Contacts.txt",ios::out|ios::in);
	char ch=obj.get();
	if(obj.eof())
	{
		cout<<"no contact information is saved yet.\nAdd now(y/n)\n";
		cin>>ch;
		if(ch=='n'||ch=='N')
		{
			obj.close();
		}
		else
		{
			cout<<"Phone no : ";
			char ch[2];
			cin.getline(ch,2);
			cin.getline(contact_no,11);
			cin.getline(ch,2);
			cout<<"Email ID : ";
			cin.getline(email_ID,30);
			fstream fobj("D:\\Contacts.txt",ios::out|ios::binary);
			fobj.write((char*)&ci,sizeof(ci));
			fobj.close();
		}
	}
	else
	{
		fstream obj("D:\\Contacts.txt",ios::out|ios::in);
		obj.read((char*)&ci,sizeof(ci));
		cout<<"Phone no : "<<contact_no;
		cout<<"\nEmail ID : "<<email_ID;
		cout<<"\nEdit contact information(y/n)\n";
		cin>>ch;
		if(ch=='n'||ch=='N')
		{
			obj.close();
		}
		else
		{
			cout<<"Phone no : ";
			char ch[2];
			cin.getline(ch,2);
			cin.getline(contact_no,11);
			cin.getline(ch,2);
			cout<<"Email ID : ";
			cin.getline(email_ID,30);
			fstream fobj("D:\\Contacts.txt",ios::out|ios::binary|ios::trunc);
			fobj.write((char*)&ci,sizeof(ci));
			fobj.close();
		}
	}
}
void contact_info::view_contacts()
{
	clrscr();
	fstream obj("D:\\Contacts.txt",ios::out|ios::in);
	obj.get();
	if(obj.eof())
	{
		cout<<"no contact information is saved yet.\nPress any key to exit.";
	}
	else
	{
		obj.seekg(0);
		obj.read((char*)&ci,sizeof(ci));
		cout<<"Phone no : "<<contact_no;
		cout<<"\nEmail ID : "<<email_ID;
	}
	obj.close();
}
book_package info;
tasks t;
tasks_customer tc;
tasks_admin ta;
int l;
void main()
{
	clrscr();
	gotoxy(10,15);
	cout<<"welcome to...";
	cout<<"\n\n                  ***TRAVEL AND TOUR MANAGEMENT SOFTWARE***"<<endl;
	getch();
	clrscr();
	s.password();
	getch();
}
void start::display_current_date_getting_started()
{
	clrscr();
	char date[9];
	char time[9];
	_strdate(date);
	_strtime(time);
	cout<<"Today's Date: "<<date<<"Time: "<<time<<endl;
}
void start::password()
{
	clrscr();
	char arr[]="annptms";
	cout<<"1. Administrator login";
	cout<<"\n2. Customer login";
	cout<<"\nenter login serial";
	int a;
	cin>>a;
	if(a==1)
	{
		l=1;
		int attempts=1;
		do
		{
			clrscr();
			char arr2[7];
			cout<<"Enter password : ";
			for(int i=0;i<=6;i++)
			{
				arr2[i]=getch();
				cout<<"*";
			}
			getch();
			for(i=0;i<7;i++)
			{
				if(arr[i]!=arr2[i])
				{
					break;
				}
			}
			if(i==7)
			{
				break;
			}
			else
			{
				attempts++;
				cout<<"\nPassword incorrect, re enter the password";
				getch();
			}
		}while(attempts<=3);
		if(attempts>3)
		{
			clrscr();
			cout<<"Sorry, you can't be logged in as admin";
			cout<<"\nThank you for using this software. Press any key to exit";
			getch();
			exit(0);
		}
		s.get_name();
		s.display_current_date_getting_started();
		ta.select_task();
	}
	if(a==2)
	{
		l=2;
		s.get_name();
		s.display_current_date_getting_started();
		tc.select_task();
	}
	else
	{
		cout<<"Wrong entry, enter again";
		s.password();
	}
}
void tasks_customer::select_task()
{
	cout<<"\nHello "<<s.show_name()<<endl;
	cout<<"You are using..."<<endl;
	cout<<"\n                  ***TRAVEL AND TOUR MANAGEMENT SOFTWARE***"<<endl;
	cout<<"                         ****************************";
	cout<<"\n\nPlease select any task to do..."<<endl;
	cout<<"1. View our packages"<<endl;
	cout<<"2. Guide Book"<<endl;
	cout<<"3. Book your trip"<<endl;
	cout<<"4. Traveling tips"<<endl;
	cout<<"5. FAQ"<<endl;
	cout<<"6. Give Feedback"<<endl;
	cout<<"7. Contacts"<<endl;
	cout<<"8. Login with another user"<<endl;
	cout<<"9. Exit from the program"<<endl;
	cout<<"Enter your task serial: ";
	cin>>task;
	switch(task)
	{
		case 1:
			view_packages();
			break;
		case 2:
			guide_book();
			break;
		case 3:
			booking();
			break;
		case 4:
			travel_tips();
			break;
		case 5:
			FAQ();
			break;
		case 6:
			give_feedback();
			break;
		case 7:
			contacts();
			break;
		case 8:
			login();
			break;
		case 9:
		{
			clrscr();
			cout<<"Thank You for trying this software !!!\n\tThis is the end of program....\nPress any key to exit....";
			getch();
			exit(0);
		}
		default:
		{
			clrscr();
			cout<<"Invalid task serial.\nPress any key to continue....";
			getch();
			s.display_current_date_getting_started();
			tc.select_task();
		}
	}
}
void tasks_admin::select_task()
{

	cout<<"\nHello "<<s.show_name()<<endl;
	cout<<"You are using..."<<endl;
	cout<<"\n                  ***TRAVEL AND TOUR MANAGEMENT SOFTWARE***"<<endl;
	cout<<"                         ****************************";
	cout<<"\n\nPlease select any task to do..."<<endl;
	cout<<"1. View packages"<<endl;
	cout<<"2. Guide Book"<<endl;
	cout<<"3. Traveling tips"<<endl;
	cout<<"4. FAQ"<<endl;
	cout<<"5. View Feedback"<<endl;
	cout<<"6. View previous booking details"<<endl;
	cout<<"7. Contacts"<<endl;
	cout<<"8. View Software deatils"<<endl;
	cout<<"9. Login with another user"<<endl;
	cout<<"10. Exit from the program"<<endl;
	cout<<"Enter your task serial: ";
	cin>>task;
	switch(task)
	{
		case 1:
			view_packages();
			break;
		case 2:
			guide_book();
			break;
		case 3:
			travel_tips();
			break;
		case 4:
			FAQ();
			break;
		case 5:
			view_feedback();
			break;
		case 6:
			previous_booking_details();
			break;
		case 7:
			contacts();
			break;
		case 8:
			software_details();
			break;
		case 9:
			login();
			break;
		case 10:
		{
			clrscr();
			cout<<"Thank You for trying this software !!!\n\tThis is the end of program....\nPress any key to exit....";
			getch();
			exit(0);
		}
		default:
		{
			clrscr();
			cout<<"Invalid task serial.\nPress any key to continue....";
			getch();
			s.display_current_date_getting_started();
			ta.select_task();
		}
	}
}
void tasks::view_packages()
{

	clrscr();
	cout<<"\n  Enjoy your holidays at...";
	cout<<"\n\n  1. Beauty of Himalayas and Taj Mahal\n  2. South African Delight\n  3. Gorgeous Maldives\n  4. Classic Italy";
	cout<<"\n\nEnter serial number of package: ";
	cin>>package;
	switch(package)
	{
		case 1:
		{
			clrscr();
			gotoxy(20,4);
			cout<<"Beauty of Himalayas and Taj Mahal";
			cout<<"\n                     *****************************";
			cout<<"\n\n     Catagory    :  *****";
			cout<<"\n     Duration    :  10 Days/9 Nights";
			cout<<"\n     Route       :  >Delhi>Srinagar>Delhi>Agra>Jaipur>Delhi";
			cout<<"\n     Validity    :  From 1st May 2011to 30th June 2011";
			cout<<"\n     Departure   :  Every Tuesday form Delhi";
			cout<<"\n     Total expences including reservation, travel and\n     accomodation: Rs 20,000 per head";
			cout<<"\n     Package ID  :  001";
			getch();
			break;
		}
		case 2:
		{
			clrscr();
			gotoxy(28,4);
			cout<<"South African Delight";
			cout<<"\n                             *****************";
			cout<<"\n\n     Catagory    :  *****";
			cout<<"\n     Duration    :  10 Nights & 11 Days";
			cout<<"\n                    Oudtshoorn | 1 Night\n\t\t    Knysna | 3 Night\n\t\t    Cape Town | 2 Night\n\t\t    Kruger National Park | 2 Night\n\t\t    Sun City | 1 Night Johannesburg";
			cout<<"\n     Validity    :  From 10th May 2011 to 22th August 2011";
			cout<<"\n     Departure   :  From Mumbai or delhi";
			cout<<"\n     Total expences including reservation, flight and\n     accomodation: Rs 1,67,000 per head";
			cout<<"\n     Package ID  :  002";
			getch();
			break;
		}
		case 3:
		{
			clrscr();
			gotoxy(30,4);
			cout<<"Gorgeous Maldives";
			cout<<"\n                               *************";
			cout<<"\n\n     Catagory    :  *****";
			cout<<"\n     Duration    :  3 Nights & 4 Days";
			cout<<"\n     Hotel       :  Taj Exotic Resort & Spa";
			cout<<"\n     Validity    :  10th May 2011 to 22nd August 2011";
			cout<<"\n     Departure   :  From New Delhi, Mumbai, Banglore, Chennai.";
			cout<<"\n     Total expences including reservation, flight and\n     accomodation: Rs 74,999 per head";
			cout<<"\n     Package ID  :  003";
			getch();
			break;
		}
		case 4:
		{
			clrscr();
			gotoxy(32,4);
			cout<<"Classic Italy";
			cout<<"\n                                 *********";
			cout<<"\n\n     Catagory    :  *****\n     Duration    :  12 Days and 11 Nights";
			cout<<"\n     Tour Details:";
			cout<<"\n     Day 1: Rome";
			cout<<"\n     Day 2: Rome – Assisi – Siena – Florence";
			cout<<"\n     Day 3: Florence";
			cout<<"\n     Day 4: Florence – Bologna – Padova – Venice";
			cout<<"\n     Day 5: Venice";
			cout<<"\n     Day 6: Venice – Montepulciano – Rome";
			cout<<"\n     Day 7: Rome";
			cout<<"\n     Day 8: Rome – Naples – Pompei – Sorrento";
			cout<<"\n     Day 9: Sorrento";
			cout<<"\n     Day 10: Sorrento – Capri";
			cout<<"\n     Day 11: Capri – Rome";
			cout<<"\n     Day 12: Rome";
			cout<<"\n     Validity    : 15th May 2011 to 1st September 2011";
			cout<<"\n     Departure   :  From New Delhi, Mumbai";
			cout<<"\n     Total expences including reservation, flight and\n     accomodation: Rs 2,00,000 per head";
			cout<<"\n     Package ID  :  004";
			getch();
			break;
		}
		default:
		{
			clrscr();
			cout<<"Invalid package serial.\nPress any key to continue....";
			getch();
		}
	}
	s.display_current_date_getting_started();
	if(l==2)
	{
		tc.select_task();
	}
	else
	{
		ta.select_task();
	}
}
void tasks::FAQ()
{
	clrscr();
	cout<<"\n\t\t\t\tFAQ";
	cout<<"\n\t\t\t       *****\n\n";
	fstream obj;
	obj.open("D:\\FAQ.txt",ios::out|ios::in|ios::app);
	obj.seekg(0);
	char c;
	c=obj.get();
	while(obj.eof()==0)
	{
		cout<<c;
		c=obj.get();
	}
	if(l==2)
	{
		cout<<"Ask a question(y/n)\n";
		cin>>c;
		if(c=='y'||c=='Y')
		{
			int i=0;
			cout<<"Enter your question here\n";
			cout<<"Q ";
			obj<<"Q ";
			char str[100];
			char ch[2];
			cin.getline(ch,2);
			cin.getline(str,100);
			while(str[i]!='\0')
			{
				c=str[i];
				obj.put(c);
				i++;
			}
			obj<<endl;
			char arr[20];
			strcpy(arr,s.show_name());
			for(int j=0;arr[j]!='\0';j++)
			{
				obj.put(arr[j]);
			}
			obj<<endl<<endl;
		}
	}
	if(l==1)
	{
		cout<<"Answer a question(y/n)\n";
		cin>>c;
		if(c=='y'||c=='Y')
		{
			int i=0;
			cout<<"Enter the answer here\n";
			cout<<"A ";
			obj<<"A ";
			char str[100];
			char ch[2];
			cin.getline(ch,2);
			cin.getline(str,100);
			while(str[i]!='\0')
			{
				c=str[i];
				obj.put(c);
				i++;
			}
			obj<<endl;
			char arr[20];
			strcpy(arr,s.show_name());
			for(int j=0;arr[j]!='\0';j++)
			{
				obj.put(arr[j]);
			}
			obj<<endl<<endl;
		}
	}
	obj.close();
	getch();
	s.display_current_date_getting_started();
	if(l==2)
	{
		tc.select_task();
	}
	else
	{
		ta.select_task();
	}
}
void tasks::guide_book()
{
	clrscr();
	cout<<"BEAUTY OF HIMALAYAS AND TAJ MAHAL:";
	cout<<"\n\n\tIndia is a medley of fascinating colors & culture, an historical legency, a canvas of architectural masterpieces, & an extravagant exuberance of royal splendour and home to the eternal symbol of love- the Taj Mahal. Taj Mahal is the finest example of Mughal architecture, a style that combines elements from Persian, Islamic and Indian architectural styles and stands at no. 1 position among 7 wonders of world. There is also Himalayas, the mountain range in Asia, separating the Indian subcontinent from the Tibetan Plateau. Its the home of all 14 of the world's highest peaks, including Mount Everest. There are many dazzling hill stations located at these mountain ranges which gives snoothing environment to the tourists.";
	cout<<"\n\n\nSOUTH AFRICAN DELIDHT:";
	cout<<"\n\n\tAfrica is the world's second-largest and second most-populous continent, after Asia. South Africa has an abundance of natural beauty. Its breathtaking scenery, prolific wildlife and the diversity of our vibrant cultures and people are there for everyone to see and enjoy.";
	cout<<"\n\n\nGORGEOUS MALDIVES:";
	cout<<"\n\n\tThe Maldives are an archipelago of 1,190 coral islands grouped into 26 coral atolls (200 inhabited islands, plus 80 islands with tourist resorts) in the Indian Ocean.Maldives is very famous for its natural beauty which includes the blue ocean and white beaches, accompanied by clean air and pleasant temperatures. The climate of the Maldives is ideal for visitors to get engaged in water sports such as swimming, fishing, scuba diving, snorkeling, water-skiing and windsurfing.Due to its extraordinary underwater scenery and clean water, Maldives is ranked among the best recreational diving destinations of the world.";
	cout<<"\n\n\nCLASSIC ITALY:";
	cout<<"\n\n\tWith more than 43.2 million tourists a year, Italy is the fourth highest tourist earner,[1] and fifth most visited country in the world,taly is an especially popular tourist destination in Europe, as well as in the rest of the world. The history and geography of the country can explain why it can be a tourist must-see. The Roman Empire, Middle Ages, and Renaissance all helped give rise to the many cultural phenomena that attract visitors year-round. Tourists flock to Italy to see sites, such as the Colusseum in Rome, the Statue of David in Florence and the ruins of Pompeii. Rome, the capital city, is also the host to the Vatican, the mecca of Roman Catholicism.Italy has some of the world's most ancient tourist resorts, dating back to the time of the Roman Republic, when destinations such as Pompeii, Naples Ischia, Capri and especially Baiae were popular with the rich of Roman society.";
	getch();
	s.display_current_date_getting_started();
	if(l==2)
	{
		tc.select_task();
	}
	else
	{
		ta.select_task();
	}
}
void tasks::travel_tips()
{
	clrscr();
	gotoxy(30,4);
	cout<<"TRAVELING TIPS\n";
	cout<<"                               **********\n";
	cout<<"\n* Be Aware of What Not to Bring in Checked Baggage on Airlines and Airline Carry On Baggage.";
	cout<<"\n\n* Pack Smart & Spend Less Time in Airport Security Lines";
	cout<<"\n\n* Prefer green travel, Use environmentally responsible services";
	cout<<"\n\n* Look for all inclusive packages, such as resorts and travel";
	cout<<"\n\n* Ask your travel agent about locations that may be less costly as they are in their 'off season'.";
	cout<<"\n\n* Buy travel insurance, it may cost more upfront, but has the potential to save you thousands.";
	cout<<"\n\n* Arrive early. Difficult airport parking, long lines at security checkpoints and the possibility of the airline overselling the flight and bumping passengers, should all be considered when deciding what time to arrive at the airport. Give yourself plenty of extra time.";
	cout<<"\n\n* Prefer using a Travel Agent. Strong working relationships with travel suppliers and the latest in computer reservations technology enable travel agents to access the most up-to-date information on how to get you the best value.";
	cout<<"\n\n* Taking the necessary steps to make sure you and your family have a safe and healthy trip.";
	cout<<"\n\n* Always have your travel agent's contact information with you. It's good to have an ally back home you can call whenever a problem arises.";
	getch();
	s.display_current_date_getting_started();
	if(l==2)
	{
		tc.select_task();
	}
	else
	{
		ta.select_task();
	}
}
void tasks::contacts()
{
	if(l==1)
	{
		ci.edit_contacts();
	}
	else
	{
		ci.view_contacts();
	}
	getch();
	s.display_current_date_getting_started();
	if(l==2)
	{
		tc.select_task();
	}
	else
	{
		ta.select_task();
	}
}
void tasks::login()
{
	char a[2];
	cin.getline(a,2);
	s.password();
}
void tasks_customer::booking()
{
	fstream fobj("D:\\Booking.txt",ios::in|ios::out|ios::binary|ios::app);
	info.res_no();
	info.get();
	fobj.write((char*)&info,sizeof(info));
	fobj.close();
	getch();
	s.display_current_date_getting_started();
	tc.select_task();
}
void tasks_customer::give_feedback()
{
	clrscr();
	cout<<"\n\t\t\t\tFEEDBACK";
	cout<<"\n\t\t\t       **********\n\n";
	fstream obj;
	obj.open("D:\\Feedback.txt",ios::out|ios::in|ios::app);
	obj.seekg(0);
	char c;
	c=obj.get();
	while(obj.eof()==0)
	{
		cout<<c;
		c=obj.get();
	}
	cout<<"Submit your feedback(y/n)\n";
	cin>>c;
	if(c=='y'||c=='Y')
	{
		int i=0;
		cout<<"Enter your feedback here\n";
		cout<<"=> ";
		obj<<"=> ";
		char str[100];
		char ch[2];
		cin.getline(ch,2);
		cin.getline(str,100);
		while(str[i]!='\0')
		{
			c=str[i];
			obj.put(c);
			i++;
		}
		obj<<endl;
		char arr[20];
		strcpy(arr,s.show_name());
		for(int j=0;arr[j]!='\0';j++)
		{
			obj.put(arr[j]);
		}
		obj<<endl<<endl;
	}
	obj.close();
	getch();
	s.display_current_date_getting_started();
	tc.select_task();
}
void tasks_admin::view_feedback()
{
	clrscr();
	cout<<"\n\t\t\t\tFEEDBACK";
	cout<<"\n\t\t\t       **********\n\n";
	fstream obj;
	obj.open("D:\\Feedback.txt",ios::out|ios::in|ios::app);
	obj.seekg(0);
	char c;
	c=obj.get();
	while(obj.eof()==0)
	{
		cout<<c;
		c=obj.get();
	}
	obj.close();
	getch();
	s.display_current_date_getting_started();
	ta.select_task();
}
void tasks_admin::software_details()
{
	clrscr();
	gotoxy(20,5);
	cout<<"***Software Specification***"<<endl;
	cout<<"\nPrograming language         : C++"<<endl;
	cout<<"Aim                         : Developing a software which can be in Travel                                    Agencies providing better user experience."<<endl;
	cout<<"Hope you like it...\nThank You for using this program\nPress any key to return to the main task menu......";
	getch();
	clrscr();
	s.display_current_date_getting_started();
	ta.select_task();
}
void tasks_admin::previous_booking_details()
{
	int count;
	ifstream obj("D:\\RES.txt",ios::in);
	res=obj.get();
	obj.close();
	ifstream fobj("D:\\Booking.txt",ios::in|ios::out|ios::binary);
	clrscr();
	if(res==-1)
	{
		cout<<"No one is resistered till now";
		getch();
		s.display_current_date_getting_started();
		ta.select_task();
	}
	else
	{
		again:
		cout<<"Enter resistration no : ";
		cin>>res;
		fobj.seekg(0,ios::end);
		count=fobj.tellg()/sizeof(info);
		if(count>=res&&res>0)
		{
			fobj.seekg((res-1)*sizeof(info),ios::beg);
			fobj.read((char*)&info,sizeof(info));
			info.show();
			fobj.close();
			getch();
			s.display_current_date_getting_started();
			ta.select_task();
		}
		else
		{
			cout<<"Invalid resistration number"<<endl<<"Enter again";
			getch();
			clrscr();
			goto again;
		}
		fobj.close();
	}
}
