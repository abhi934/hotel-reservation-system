/* HOTEL Reservation SYSYTEM



*/

#include<iostream>


#include<string.h>
#include<fstream>
using namespace std;

class hotel
{
public :
                 long int cost,j,nights,temp;
string a,email;
                char date[20];
long int phno,roomaa,roomna,roomab,roomnb,no;

/*roomab=room ac booked
roomaa=room ac available
roomna=room non ac available
roomnb=room non ac booked
*/

                        hotel()
                        {


                        roomaa=10;
                        roomna=10;
                        roomab=0;
                        roomnb=0;
                        /*
                        roomaa=10-roomab;
                        roomna=10-roomna;
                        */
                        no=0;

                        }
   void acceptdata()
                {
                    cout<<"enter the number of rooms to book"<<endl;
                    cin>>no;


                    cout<<"enter type of room:1)AC    2)non-AC"<<endl;
                    cin>>j;



                    cout<<"Enter  Name:"<<endl;
                    cin.ignore();
   getline(cin,a);
   cout<<"for how many nights are you looking forward to stay?"<<endl;
   cin>>nights;
   cout<<"enter your check in date"<<endl;
   cin>>date;
   cout<<"enter your mobile number"<<endl;
  cin>>phno;
              cout<<"enter email id"<<endl;
               cin.ignore();
              getline(cin,email);


}

                void AC()
                {       ifstream k;

                        if(no>0&&roomaa>=no)
                    {
                    k.open("hotelinfo.txt",ios::app|ios::binary);
                    k.read((char*)&(*this),sizeof(*this));
                        roomaa=roomaa-no;
                     roomab=roomab+no;
                     k.close();


                     cout<<"ac room booked successfully"<<endl<<""<<endl;
    cout<<"the total cost of your stay is: "<<no*nights*2500<<"Rs"<<endl<<""<<endl;
                }   else cout<<"no AC rooms available"<<endl<<""<<endl;
                }


                void nAC()
                {       if(no>0&&roomna>=no)
                    {
                        roomna=roomna-no;
                      roomnb=roomnb+no;
cout<<"non ac room booked successfully"<<endl<<""<<endl;
cout<<"the total cost of your stay is: "<<no*nights*1500<<"Rs"<<endl<<""<<endl;
                }   else cout<<"no non-AC rooms available"<<endl<<""<<endl;
                }



                void displayitem()
{

   cout<<"Your details are as follows:"<<endl<<""<<endl;
   cout<<"name:"<<a<<endl<<""<<endl;
   cout<<"no of rooms:"<<no<<endl<<""<<endl;
   cout<<"no of nights:"<<nights<<endl<<""<<endl;
   cout<<"check in date:"<<date<<endl<<""<<endl;
   cout<<"mobile number:"<<phno<<endl<<""<<endl;
            cout<<"email id:"<<email<<endl<<""<<endl;



}

void admindata()
{


            fstream newfile1;
newfile1.open("hotelinfo.txt",ios::app|ios::binary);
newfile1.read((char*)&(*this),sizeof(*this));
   //cout<<"The number of available ac rooms and non ac rooms are  "<<roomaa<<"  and "<<roomna<<endl;
   //cout<<"The number of booked ac rooms and non ac rooms are  "<<roomab<<"  and "<<roomnb<<endl;


}


};

int main()
{


               int z,roomaa,roomna,roomab,roomnb,f;
                string password;
                hotel h;


                do
                {
                cout<<"choose among the following:"<<endl<<"1.User"<<endl<<"2.Admin"<<endl<<"3.exit"<<endl;
                cin>>z;
                ofstream l;
                switch(z)
                {
                case 1:

                    //fout.open("hotelinfo.txt",ios::app|ios::binary);
                    h.acceptdata();
                    //fout.write((char *)&h, sizeof(h)); //write data to file
                    //fout.close();
                    switch(h.j)
                        {
                                case 1:

                                     l.open("hotelinfo.txt",ios::app|ios::binary);
                                    roomaa=10-roomab;

                                h.AC();

                                    l.write((char *) &h,sizeof(h));
                                    l.close();

                                break;


                                case 2:

                                     l.open("hotelinfo.txt",ios::app|ios::binary);
                                    roomna=10-roomnb;

                                h.nAC();

                                    l.write((char *) &h,sizeof(h));;
                                    l.close();



                                break;

//                                default:cout<<"enter a valid choice"<<endl;
  //                              break;
                        }


                                cout<<"Do You Wish To Confirm?"<<endl<<"1.Confirm"<<endl<<"2.Cancel"<<endl;
                                cin>>f;
                                if(f==1)
                                {
                                    h.displayitem();
                                }
                                else cout<<"booking canceled successfully"<<endl;
                    break;
                        case 2:
                            cout<<"enter admin password"<<endl;
                            cin.ignore();
                            getline(cin,password);
                            if(password=="pqr")
                                {
                                    cout<<"access granted"<<endl;
                                     ifstream g;
                                     g.open("hotelinfo.txt",ios::app|ios::binary);
                                     while(!g.eof()){ g.read((char *) &h,sizeof(h));}
                                      cout<<"the number of booked ac rooms are:" <<h.roomab<<endl;
                                      cout<<"the number of available ac rooms are:" <<h.roomaa<<endl;
                                      cout<<"the number of booked non ac rooms are:" <<h.roomnb<<endl;
                                      cout<<"the number of available non ac rooms are:" <<h.roomna<<endl;
                                      cout<<h.roomnb<<endl;
                                    g.close();


                                }
                            else cout<<"access denied"<<endl;
                    break;

                }
                }while(z<2);


return 0;


}

/*   output:
choose among the following:
1.User
2.Admin
3.exit
1
enter the number of rooms to book
20
enter type of room:1)AC    2)non-AC
1
Enter  Name:
a
for how many nights are you looking forward to stay?
4
enter your check in date
28/09/2019
enter your mobile number
99757788
enter email id
abhi@gmail.com
no AC rooms available

Do You Wish To Confirm?
1.Confirm
2.Cancel
1
Your details are as follows:

name:a

no of rooms:20

no of nights:4

check in date:28/09/2019

mobile number:99757788

email id:abhi@gmail.com

choose among the following:
1.User
2.Admin
3.exit
1
enter the number of rooms to book
-1
enter type of room:1)AC    2)non-AC
1
Enter  Name:
nach
for how many nights are you looking forward to stay?
4
enter your check in date
27/09/2019
enter your mobile number
765890
enter email id
nac@gmail.com
no AC rooms available

Do You Wish To Confirm?
1.Confirm
2.Cancel
1
Your details are as follows:

name:nach

no of rooms:-1

no of nights:4

check in date:27/09/2019

mobile number:765890

email id:nac@gmail.com

choose among the following:
1.User
2.Admin
3.exit
1
enter the number of rooms to book
3
enter type of room:1)AC    2)non-AC
1
Enter  Name:
kun
for how many nights are you looking forward to stay?
4
enter your check in date
20/09/2000
enter your mobile number
9975778
enter email id
kun@gmail.com
ac room booked successfully

the total cost of your stay is: -20000Rs

Do You Wish To Confirm?
1.Confirm
2.Cancel
1
Your details are as follows:

name:abhishek desai

no of rooms:-2

no of nights:4

check in date:28/09/2019

mobile number:2147483647

email id:

choose among the following:
1.User
2.Admin
3.exit
1
enter the number of rooms to book
10000
enter type of room:1)AC    2)non-AC
2
Enter  Name:
a
for how many nights are you looking forward to stay?
4
enter your check in date
28/09/2019
enter your mobile number
99876
enter email id
nsh@gmail.com
no non-AC rooms available

Do You Wish To Confirm?
1.Confirm
2.Cancel
1
Your details are as follows:

name:a

no of rooms:10000

no of nights:4

check in date:28/09/2019

mobile number:99876

email id:nsh@gmail.com

choose among the following:
1.User
2.Admin
3.exit
1
enter the number of rooms to book
*/




