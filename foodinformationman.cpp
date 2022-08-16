#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<cstring>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<fstream>
using namespace std;

void menu()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\FOOD INFORMATION MANAGEMENT SYSTEM";
    cout<<endl;
    cout<<endl;
    cout<<"Program Developed by:"<<endl;
    cout<<endl;
    cout<<"1.Shiv Ranjan Gupta \t\tRoll:39"<<endl;
    cout<<"2.Shrutii jha       \t\tRoll:41"<<endl;
    cout<<"3.Manish Thapa      \t\tRoll:21"<<endl;
    cout<<"3.Menuka Sharma      \t\tRoll:23"<<endl;
    cout<<endl;
    cout<<"press any key to continue"<<endl;
    getch();
}

///Logic Functions

   /// Update & Insert Function
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);


    ///Delete & Count Function
void deletefood(int serial);
int countitem();




///extra design Function

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);


        ///START function class to display Here

class Node{
public:
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;
	void insrtmid(int pos, int data, char foodname[25], int quantity, float price);
void insrtend(int data, char foodname[25], int quantity, float price);

};
  /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();


   ///Global Type

typedef struct Node node ;

node *head, *list;

int main(){
    menu();
    system("cls");

	system("Food Menu System");
	system("mode con: cols=88 lines=30");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1,"Pork Ribs",23,120.23);
	insertend(2,"Chicken Biryani",13,100.67);
	insertend(3,"Sandwich",8,720.83);
	insertend(4,"KFC Wings",46,70.23);
	insertend(5,"Chicken Pizza",46,70.23);
	insertend(6,"French Fries",34,60.23);
	insertend(7,"nan roti panari",34,257);



	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); cin>>main_menu_choice;

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			cout<<"=> 0. Main Menu ";
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  cout<<"1. Main Menu\n\n\t"; Sleep(300);
			cout<<"Please Enter Password or ( 1 to Back in Main Menu ) : ";


			fflush(stdin);  cin>>admin_panel_choice;

			if(admin_panel_choice==1234567){



				node *temp;

				temp = list;

				adminchoise:

				cls();  br(3); pre(4); echo(">>>> Admin Section <<<<   \n\n");
				pre(4);
				cout<<" 1. Total Cash Today \n\n";Sleep(250);pre(4);
				cout<<" 2. View Card Pay \n\n";Sleep(250);pre(4);
				cout<<" 3. Add Food To Menu\n\n";Sleep(250);pre(4);
                cout<<" 4. Delete Food \n\n";Sleep(250);pre(4);
				cout<<" 5. Instant Food List \n\n";Sleep(250);pre(4);
				cout<<" 6. Total Food List Counter \n\n";Sleep(250);pre(4);
				cout<<" 7. Backup System\n\n";Sleep(250);pre(4);
				cout<<" 8. Instant Food Order Preview\n\n";Sleep(250);pre(4);
				cout<<" 0. Main Menu \n\n";
                cout<<"Enter Your From [1-0]: ";
				Sleep(250);

				int adminchoise;



				fflush(stdin);   cin>>adminchoise;

				if(adminchoise==1){

					cls();  middle1(); pre(4);   cout<<"Todays Total Cash : "<< totalmoney<<endl;

					Sleep(2000);

					goto adminchoise;
				}
				else if(adminchoise==2){

					if(c!=0){

						cls();  br(3); pre(4);

						cout<<" ____________________________\n";pre(4);
						cout<<"|   Card NO.   |   Money $   |\n";pre(4);
						cout<<"------------------------------\n";pre(4);

						for(int z=1; z<=c;z++){


							cout<<setw(2)<<cardno[z]<<setw(27)<<cardmoney[z];pre(4);
							cout<<"------------------------------\n";pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					cout<<"No Card History\n";}
					Sleep(1500);
					goto adminchoise;
				}

				else if(adminchoise==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      cout<<" Enter Your Food Name :  ";

					fflush(stdin);     cin>>ffoodname;
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					cout<<" Total Order :  ";

					cin>>fquantity; fflush(stdin);

                        foodserial:
					br(2);pre(4);  cout<<" Enter Food ID :  ";
                      cin>>fdata;
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  cout<<" Food Already Exist, Please Re-Enter  "; Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  cout<<" Enter Food Price :  ";fflush(stdin);

					cin>>fprice;



					br(2);pre(4);  cout<<"Submitting your data";for(int cs=0;cs<4;cs++){cout<<" .";Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      cout<<"Adding Food  Successfull.......\n";

					Sleep(2000);

					goto adminchoise;

				}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					cout<<"Enter Serial No of the Item To Delete : ";
					fdelete:
					int fdelete;
					fflush(stdin); cin>>fdelete;
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); cout<<"Please Enter Correct Number :  "; Sleep(500);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  cout<<"1. <-- back  \n\n";pre(5);



					fflush(stdin);   cin>>any;

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						cout<<"Counting available food..... ";
						cout<<cs;
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					cout<<"Total Item Item is \n"<<citem; Sleep(2000); //look boss as "total item is
					goto adminchoise;

				}

                        ///Backup System
				else if(adminchoise==7){


					char date[35]="july 17 20129";

					strcat(date,".txt");
					//FILE *fptr;
        fstream file;
					//fptr=fopen(date,"w");
        file.open("date.txt",ios::in|ios::out);
					backuploader();
					//if(fptr==NULL)
        if(file.eof()!=0)
                        {
						br(3); pre(3);
                    cout<<"Error!"; Sleep(500);
						goto adminchoise;
					}
					//fprintf(fptr,"Total Cash Generated Today : %0.2f\n\n\n",totalmoney);
        cout<<"total cash generated today:"<<setw(10)<<totalmoney<<"\n\n\n";
					//fprintf(fptr,"Card No ------- Money \n\n");
        cout<<"card no--------money"<<"\n\n\n";
					for(int l=1; l<=c;l++)
                        {
						//fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
    cout<<cardno[1]<<"\n\n\n\n\n"<<cardmoney[1];
					}
					br(2);pre(4); cout<<"Backup Successfull..."; Sleep(3500);



					//fclose(fptr);
	file.close();
					goto adminchoise;
				}
				else if(adminchoise==8){

					cls();br(2);pre(2);
					ccolor(26);
					cout<<"\n\t\t"; ccolor(240);
					cout<<"______________________________________________________ "; ccolor(26);
					cout<<"\n\t\t";  ccolor(240);
					cout<<"|  Order No.  |   Food Name   |  Quantity |  In Stock |"; ccolor(26);
					cout<<"\n\t\t";  ccolor(240);
					cout<<"------------------------------------------------------"; ccolor(26);
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  cout<<"1. <-- back  \n\n";pre(5);

					fflush(stdin);   cin>>any;

					goto adminchoise;



				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); cout<<"Please Select From Food List :  "; Sleep(500);
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  cout<<"Please Enter Correct Choice";
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); cout<<"Thank You For Using Our System. \n\t\t\tBrought To You By firstyear second part  \n\n\n\n\n\n\n"<<endl<<"Have a good time";
			Sleep(4000);

			exit(1);

		}

	}
	else{
		br(2); pre(4); cout<<"Please Enter Correct Choice"; Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	cout<<"Place Your Order: " ;
	cin>>get_food_choice;

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choose Food From List: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		cout<<"Enter Food Quantity : ";

		int fcquantity;

		fflush(stdin); cin>>fcquantity; cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); cout<<"Quantity Can not be Zero "; Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); cout<<"Oppps!! sorry Food is Out of Stock ! "; Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4);  cout<<"Choice item  "<<temp->foodname<<"its price is "<< temp->price*fcquantity;pre(4);
		cout<<"1. Confirm to buy this \n\n";pre(4);
		cout<<"2. Food List \n\n";
		cout<<"Press 1 to confirm and 2 to back to list :";

		confirm:
		int confirm;

		fflush(stdin); cin>>confirm;

		if(confirm == 1 ){

			br(2);pre(4);
			cout<<" 1. Cash ";
			br(2);pre(4);
            cout<<" 2. Credit\n";
            cout<<"Select Method Of payment 1-2: ";
			payment:
			int payment;

			fflush(stdin);  cin>>payment;

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  cout<<"===>THANK YOU<===";
				br(2);pre(4);  cout<<"Food Ordered Successfully ...";
				br(2);pre(4);  cout<<"1. Want Another? ";
				br(2);pre(4);  cout<<"2. Main Menu \n";
				br(2);pre(4);   cout<<"Select: ";
				psmenu:
				int ps_menu;

				fflush(stdin);  cin>>ps_menu;

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);cout<<"Please Choice from list : "; goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				cls();middle1();pre(4); cout<<"Enter Your Card No : ";

				fflush(stdin);   cin>>card_number[c];



				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  cout<<"Enter Your Card Pin [we never save your pin]  : ";

				fflush(stdin);     cin>>pin;

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  cout<<"Payment Success...";
				br(2);pre(4);   cout<<"1. Wanna Buy Another Delicious Food ? ";
				br(2);pre(4);    cout<<"2. Main Menu \n";
				br(2);pre(4);   cout<<"select: ";
				psmenu2:
				int ps_menu2;

				cin>>ps_menu2;

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);cout<<"Please Choice from list : "; goto psmenu2;}

			}

			else{

				br(2);pre(4);   cout<<"Enter Choice from List : ";

				goto payment;


			}


		}    ///END Confirm Y/y



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			br(2);pre(4);    cout<<"Enter Choice from List : ";

			goto confirm;


		}  ///end confirm;


	}  ///end get food choice if line


	else{

		br(2);pre(4);  echo("Please Choose From List "); br(2); Sleep(300);

		goto foodlist;

	}  ///end get food choice
}

void cls(){

	system("cls");

}

void echo(char print[]){

	cout<<print;
}

void br(int line){
	for(int i=0; i<line;i++){
		cout<<"\n";
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		cout<<"\t";
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		cout<<" ";
	}

}

void main_menu(){

	cls();
	br(5); pre(3); echo(">> 1. Food Lists"); Sleep(400);
	br(2); pre(3); echo(">> 2. Admin Section"); Sleep(400);
	br(2); pre(3); echo(">> 3. Exit");  Sleep(400);
	br(2); pre(3); echo("=> 4. Admin Panel");  Sleep(400);  //

	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

	//    free(temp);
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			cout<<"\n\n\n\n\t\t\tDeleting Food Item "<<serial;for(int cs=0;cs<4;cs++){cout<<" .";Sleep(400);}

			cout<<"\n\n\n\n\t\t\tDeleted Successfully \n"; Sleep(500);

		}
		else{
			cout<<"\n\n\n\n\t\t\t Food Not Found\n"; Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		cout<<"\n\n\n\n\t\t\tDeleting Item "<<serial;for(int cs=0;cs<4;cs++)cout<<" .";Sleep(400);}

		cout<<"\n\n\n\n\t\t\tDeleted Successfully \n"; Sleep(500);

		head = temp ;

		list=head;

}

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

}
void foodlist(){

	ccolor(0);

	cout<<"\n\t\t"; ccolor(240);
	cout<<"______________________________________________________ ";ccolor(26);
	cout<<"\n\t\t"; ccolor(240);
	cout<<"|  Item No.  |   Food Name   |  Price  |   In Stock   |";ccolor(26);
	cout<<"\n\t\t"; ccolor(240);
	cout<<"-------------------------------------------------------";ccolor(26);

	node *temp;

	temp = list;

	while(temp != NULL){

		ccolor(26);


		cout<<"\n\t\t"; ccolor(62);
		cout<<setw(2)<<temp->data<<setw(27)<<temp->foodname<<setw(10)<<temp->price<<setw(10)<< temp->quantity;
		ccolor(26);
		cout<<"\n\t\t"; ccolor(62);
		cout<<"-------------------------------------------------------";


		temp = temp->next ;

		Sleep(100);

	}

	ccolor(26);

	//  free(temp);

}


void order_view(int order, int quantity, int or_no){



	ccolor(26);

	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){

		ccolor(26);

		cout<<"\n\t\t"; ccolor(62);
		cout<<or_no<<temp->foodname<<quantity<<temp->quantity;
		ccolor(26);
		cout<<"\n\t\t"; ccolor(62);
		cout<<"-------------------------------------------------------";

		Sleep(100);

	}

	ccolor(26);

}

void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

//the above code displays colorful background. if you want colorful then you can remove the above comment but not the code, only comment//
}


///HEERE PRINTF STYLE FUNCTION

void pwellcome(){
	ccolor(26);

	char welcome[50]="Welcome";
	char welcome2[50]=" To";
	char welcome3[50]=" Food Information";
	char welcome4[50]=" And Order System";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		cout<<welcome[wlc];
		Sleep(100);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		cout<<welcome2[wlc2];
		Sleep(100);
	}
	ccolor(26);
	cout<<"\n\n\n\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			cout<<welcome3[wlc3];
		}
		else{

			cout<<welcome3[wlc3];
		}

		Sleep(100);
	}
	ccolor(26);
	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			cout<<welcome4[wlc3];
		}
		else{

			cout<<welcome4[wlc3];
		}
		Sleep(100);
	}
	ccolor(26);

}
void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		cout<<i<<" % Loading...\n\n\t\t";

		cout<<"";

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			cout<<" ";
			ccolor(26);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}
void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<i<<" %% Backing UP DATA...\n\n\t\t";

		cout<<"";

		for (int j=0; j<i;j+=2){

			ccolor(120+j);
			cout<<" ";
			ccolor(26);

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}


void middle1(void){

	cout<<"\n\n\n\n\n\n\n";
}

void middtab1(void){
	cout<<"\t\t\t\t\t";
}

