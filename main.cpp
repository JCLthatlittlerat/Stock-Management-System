#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

struct items{
    int id;
    char name[50];
    int qty;
    int pr;

};
// functions declaration
void intro();
void create_list();
void display_all();
void display_sp();
void modify_account();
void adding_items();
void saling_item();
void delete_item();
void clear_store();
void display();


int main()
{
items ac;
char ch;
int num;
intro();
system("cls");

do
{
cout<<"\n\n\n\t        MENU";
cout<<"\n\n\t1.ADD NEW ITEM";
cout<<"\n\n\t2.ADD SOME QUANTITY TO PRESENT ITEM";
cout<<"\n\n\t3.WITHDRAW ITEM";
cout<<"\n\n\t4.INFORMATION OF SPECIFIC ITEM";
cout<<"\n\n\t5.INFORMATION OF ALL ITEMS IN STORE";
cout<<"\n\n\t6.DELETE SPECIFIC ITEM";
cout<<"\n\n\t7.MODIFY INFORMATION OF SPECIFIC ITEM";
cout<<"\n\n\t8.DELETE INFORMATION OF ALL ITEMS IN STORE";
cout<<"\n\n\t9.EXIT";
cout<<"\n\n\tselect your choice from 1 to 9\n\n\n";
cin>>ch;
    switch(ch)
    {
    case'1':
        create_list();
        break;
    case'2':
        adding_items();
        break;
    case'3':
        saling_item();
        break;
    case'4':
        display_sp();
        break;
    case'5':
        display_all();
        break;
    case'6':
        delete_item();
        break;
    case'7':
        modify_account();
        break;
    case'8':
        clear_store();
        break;
    case'9':
        cout<<"\n\n\t*************************************";
        cout<<"\n\n\t********THANK YOU DEAR USER!*********";
        cout<<"\n\n\t*******HAVE A NICE WORKING DAY*******";
        cout<<"\n\n\t*************************************";
        break;
    default:
        cout<<"\n\n\t*************************************************************";
        cout<<"\n\n\t************************invalid input************************";
        cout<<"\n\n\t**please enter your choice number only from the given range**";
        cout<<"\n\n\t*************************************************************";
        break;
    }
}while(ch!='9');
return 0;
}


void intro()
{
cout<<"*************************************************\n";
cout<<"****************welcome Dear customer************\n";
cout<<"*************************************************\n";
cout<<"************press enter to start!***************\n";
cin.get();
}

void create_list()
{
items ac;
ofstream outfile;
outfile.open("store.dat",ios::binary|ios::app);
cout<<"\n\tEnter ID number:";
cin>>ac.id;
cout<<"\n\tEnter the name of item:\n";
cin.ignore();
cin.getline(ac.name,50);
cout<<"\n\tEnter the amount to be stored:";
cin>>ac.qty;
cout<<"\n\tEnter the price(in ETB) of each item: ";
cin>>ac.pr;
cout<<"\t"<<ac.name<<" stored successfully\n";
cout<<"\tplease press enter to continue";
outfile.write(reinterpret_cast<char *> (&ac),sizeof(items));
outfile.close();
cin.ignore();
cin.get();
system("cls");
}

void adding_items()
{
  int amt;
  bool found=false;
  items ac;
  fstream file;
  file.open("store.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
      cout<<"SORRY! YOUR STORE IS EMPTY. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
  cin.ignore();
  cin.get();

  return;
  }
  else
  {
    display();
    cout<<"\n\n\twhich item do you want to add? \n\tEnter it's id number: ";
   int n;
   cin>>n;
  while(!file.eof() && found==false)
    {
        file.read(reinterpret_cast<char *> (&ac), sizeof(items));
  if(ac.id==n)
    {
        cout<<"\n\n\ID NUMBER:"<<setw(26)<<ac.id<<endl;
        cout<<"NAME OF ITEM:"<<setw(27)<<ac.name<<endl;
        cout<<"CURRENT PRESENT NUMBER OF ITEMS:   "<<ac.qty<<endl;
        cout<<"PRICE:"<<setw(30)<<ac.pr<<" ETB";
        cout<<endl<<endl;
       cout<<"\n\n\t TO ADD NEW ITEMS";
       cout<<"\nEnter the amount you want to add: ";
       cin>>amt;
       ac.qty+=amt;
   int pos=(-1)*static_cast<int>(sizeof(ac));
   file.seekp(pos,ios::cur);
   file.write(reinterpret_cast<char *> (&ac), sizeof(items));
   file.close();
   cout<<"\n\n\t item updated successfully!";
   found=true;
    }
  }
  if(found==false)
  {
      cout<<"\n\n\n\n\tsorry! item with ID "<<n<<" not found";
  }
  }
  cout<<"\n\n\npress enter to continue";
  cin.ignore();
  cin.get();
  system("cls");
}
  void saling_item()
  {
  int amt;
  bool found=false;
  items ac;
  fstream file;
  file.open("store.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
      cout<<"SORRY! YOUR STORE IS EMPTY. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
  cin.ignore();
  cin.get();
  return;
  }
  else
  {
  display();
  cout<<"\n\n\twhich item do you want to withdraw? \n\tEnter it's id number: ";
  int n;
  cin>>n;
  while(!file.eof() && found==false)
    {
        file.read(reinterpret_cast<char *> (&ac), sizeof(items));
  if(ac.id==n)
    {
        cout<<"\n\n\ID NUMBER:"<<setw(26)<<ac.id<<endl;
        cout<<"NAME OF ITEM:"<<setw(27)<<ac.name<<endl;
        cout<<"CURRENT PRESENT NUMBER OF ITEMS:   "<<ac.qty<<endl;
        cout<<"PRICE:"<<setw(30)<<ac.pr<<" ETB";
        cout<<endl<<endl;
       cout<<"\n\n\t TO WITHDRAW ITEMS\n";
       cout<<"Enter the amount you want to withdraw: ";
       cin>>amt;
       int bal=ac.qty-amt;
       int tp;
       tp=ac.pr*amt;
       if(bal==0)
       {
           ac.qty-=amt;
           cout<<"\n\n\n\n\n                             bill                                   ";
           cout<<"\n====================================================================" << endl;
           cout<<" ac.id "<<setw(10)<<" ac.name "<<setw(30)<<"withdrawn amount"<<setw(21)<<"total price"<<endl;
           cout<<"====================================================================" << endl;
           cout<<" "<<ac.id<<setw(10)<<ac.name<<setw(30)<<amt<<setw(21)<<tp<<" ETB";
           cout<<"\n\n\tyou have withdrawn all "<<ac.name<<" from your store!\n";
           cout<<"\tplease store more "<<ac.name;
       }
       else
        {
         cout<<"\n\n\n\n\n                             bill                                   ";
        cout<<"\n====================================================================" << endl;
        cout<<" ac.id "<<setw(10)<<" ac.name "<<setw(30)<<"withdrawn amount"<<setw(21)<<"total price"<<endl;
        cout<<"====================================================================" << endl;
        cout<<" "<<ac.id<<setw(10)<<ac.name<<setw(30)<<amt<<setw(21)<<tp<<" ETB";
        ac.qty-=amt;
        }
   int pos=(-1)*static_cast<int>(sizeof(ac));
   file.seekp(pos,ios::cur);
   file.write(reinterpret_cast<char *> (&ac), sizeof(items));
   file.close();
   found=true;
    }
 }
    if(found==false)
    {
        cout<<"\n\n\nitem with ID "<<n<<" not found!";
    }
  }
    cout<<"\n\npress enter to continue";
    cin.ignore();
    cin.get();
    system("cls");
}
void display_sp()
  {
   items ac;
   bool flag=false;
   ifstream infile;
   infile.open("store.dat", ios::binary);
   if(!infile)
   {
      cout<<"SORRY! YOUR STORE IS EMPTY. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
  cin.ignore();
  cin.get();
       return;
   }
   else
   {
      cout<<"please! Enter ID number: ";
      int n;
      cin>>n;
        while(infile.read(reinterpret_cast<char *> (&ac), sizeof(items)))
        {
            if(ac.id==n)
            {
                cout<<" Information of "<<ac.name<<" available in your store";
                cout<<"\n\n\ID NUMBER:"<<setw(26)<<ac.id<<endl;
                cout<<"NAME OF ITEM:"<<setw(27)<<ac.name<<endl;
                cout<<"CURRENT PRESENT NUMBER OF ITEMS:   "<<ac.qty<<endl;
                cout<<"PRICE:"<<setw(30)<<ac.pr<<" ETB"<<endl;
                flag=true;
                cout<<"\npress any key to continue";
            }
        }
       if( flag==false )
       {
           cout<<"\n\nItem does not exist\n\n";
           cout<<"press any key to continue";
       }
    infile.close();
   }
    cin.ignore();
    cin.get();
    cout<<"\n\n\n\n";
  }
void display_all()
  {
    items ac;
    ifstream infile;
    infile.open("store.dat",ios::binary);
    if(!infile)
    {
      cout<<"SORRY! YOUR STORE IS EMPTY. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\t\tLIST OF ALL ITEMS PRESENT IN YOUR STORE\n";
    cout<<"======================================================================" << endl;
    cout<<"ID Number"<<setw(20)<<"Name of item"<<setw(19)<<"Amount present"<<setw(21)<<"price of item"<<endl;
    cout<<"======================================================================" << endl;
    while(infile.read(reinterpret_cast<char *> (&ac), sizeof(items)))
    {
    cout<<"  "<<ac.id<<setw(20)<<ac.name<<setw(15)<<ac.qty<<setw(20)<<ac.pr<<"ETB"<<endl;

    }
cout<<"\n\n\n\n\tpress enter to continue";
cin.ignore();
cin.get();
  }
void delete_item()
{
  items ac;
  ifstream infile;
  ofstream outfile;
  infile.open("store.dat",ios::binary);
  if(!infile)
  {
      cout<<"THERE IS NOTHING TO BE DELETED. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
      cin.ignore();
      cin.get();
      return;
  }
  else
  {
    display();
    cout<<"\n\n\twhich item do you want to delete? \n\tEnter it's id number: ";
    int num;
    cin>>num;
   outfile.open("temporary.dat",ios::binary);
   infile.seekg(0,ios::beg);
   while(infile.read(reinterpret_cast<char *> (&ac), sizeof(items)))
   {
       if(ac.id!=num)
       {
           outfile.write(reinterpret_cast<char *> (&ac), sizeof(items));
       }

   }
infile.read(reinterpret_cast<char *> (&ac), sizeof(items));
     if(ac.id==num)
       {
       infile.close();
       outfile.close();
       remove("store.dat");
       cout<<"\n\nrecord deleted!\n";
       }
     else
       {
       infile.close();
       outfile.close();
        remove("store.dat");
        cout<<"\nitem with ID "<<num<<" not found";
       }
rename("temporary.dat","store.dat");
cout<<"\n\npress enter to continue";
  }
cin.ignore();
cin.get();
system("cls");
}
void modify_account()
{
  bool found=false;
  items ac;
  fstream file;
  file.open("store.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
      cout<<"THERE NOTHING TO BE MODIFIED. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
      cin.ignore();
      cin.get();
      return;
  }
  else
  {
    display();
    cout<<"\n\n\twhich item do you want to modify? \n\tEnter it's id number: ";
    int n;
    cin>>n;
  while(!file.eof() && found==false)
  {
      file.read(reinterpret_cast<char *> (&ac), sizeof(items));
      if(ac.id==n)
      {
        cout<<"\n\n\ID NUMBER:"<<setw(26)<<ac.id<<endl;
        cout<<"NAME OF ITEM:"<<setw(27)<<ac.name<<endl;
        cout<<"CURRENT PRESENT NUMBER OF ITEMS:   "<<ac.qty<<endl;
        cout<<"PRICE:"<<setw(30)<<ac.pr<<" ETB";
        cout<<endl<<endl;
        cout<<"Enter the new details of items: \n";
        cout<<"Id of item"<<ac.id<<endl;
        cout<<"\nif you want to modify the name item press<1> otherwise press<0>:";
        int c;
        cin>>c;
        if(c==1)
        {
         cout<<"\tmodify name: ";
         cin.ignore();
         cin.getline(ac.name,50);
        }
        cout<<"if you want to modify the current amount of item press<1> otherwise press<0>:";
        int c2;
        cin>>c2;
        if(c2==1)
          {

        cout<<"\nmodify current amount: ";
        cin>>ac.qty;
          }
          cout<<"if you want to modify the price of item press<1> otherwise press<0>:";
        int c3;
        cin>>c3;
        if(c3==1)
          {
        cout<<"\nmodify price : ";
        cin>>ac.pr;
          }
        int pos=(-1)*static_cast<int>(sizeof(items));
        file.seekp(pos,ios::cur);// ke current position of cursor wede pos yigotital.
        file.write(reinterpret_cast<char *> (&ac) , sizeof(items));
        cout<<"\n\n************ congratulation ************\n************record updated!***************\n";
        found=true;
        cout<<"\n\n\tpress enter to continue";
      }
  }
  file.close();
  if(found==false)
    {
      cout<<"sorry! item with ID number "<<n<< " not found";

    }
  }
cout<<"\n\npress enter to continue";
cin.ignore();
cin.get();
system("cls");
}
void clear_store()
{
    ifstream infile;
    infile.open("store.dat",ios::binary);
    if(!infile)
    {
      cout<<"THERE IS NOTHING TO BE DELETED. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
       infile.close();
        cin.ignore();
        cin.get();
        return;
    }
    else
    {
    cout<<"  Are you sure to delete all information in your store?\n  if yes press<1> otherwise press<0>";
    int c;
    cin>>c;
    if(c==1)
      {
    infile.close();
    remove("store.dat");
    cout<<"\n\nInformation of store deleted successfully\n";
    cout<<"\n\npress enter to continue";
      }
    }
cin.ignore();
cin.get();
    }
void display()
  {
    items ac;
    ifstream infile;
    infile.open("store.dat",ios::binary);
    if(!infile)
    {
      cout<<"SORRY! YOUR STORE IS EMPTY. USE OPTION NUMBER <1> TO ADD ITEMS TO YOUR STORE\n\npress enter key to continue";
      cin.ignore();
      cin.get();
        return;
    }
    cout<<"\n\n\t\tYOU HAVE THE FOLLOWING ITEMS IN YOUR STORE\n";
    cout<<"======================================================================" << endl;
    cout<<"ID Number"<<setw(20)<<"Name of item"<<setw(19)<<"Amount present"<<setw(21)<<"price of item"<<endl;
    cout<<"======================================================================" << endl;

    while(infile.read(reinterpret_cast<char *> (&ac), sizeof(items)))
    {
    cout<<"  "<<ac.id<<setw(20)<<ac.name<<setw(15)<<ac.qty<<setw(20)<<ac.pr<<" ETB"<<endl;

    }
  }
