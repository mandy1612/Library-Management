#include<graphics.h>
#include<iostream.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
struct member{
	      int id;
	      char name[20];
	      char address[100];
	      char ph_no[11];
	     };
struct book{
	    int bookid;
	    char name[30];
	    char author[30];
	    char type[20];
	   };
void menu();
void add_book();
int calculate_book_id();
void see_book();
void delete_book();
void update_book();
void add_member();
int calculate_member_id();
void see_member();
void delete_member();
void update_member();
void add_book()
{
 clrscr();
 book temp;
 cout<<"Enter Book Name : ";
 gets(temp.name);
 cout<<"Enter Author's Name : ";
 gets(temp.author);
 cout<<"Enter Type : ";
 gets(temp.type);
 temp.bookid = calculate_book_id();
 cout<<"Id : "<<temp.bookid;
 ofstream f;
 f.open("books.txt",ios::app);
 f.write((char*)&temp,sizeof(temp));
 f.close();
 getch();
 menu();
}
int calculate_book_id()
{
 fstream f;
 f.open("books.txt",ios::in|ios::ate|ios::out);
 int s = f.tellg()/sizeof(book);
 f.close();
 return ++s;
}
void see_book()
{
 clrscr();
 book tem;
 int temp;
 cout<<"Enter Id : ";
 cin>>temp;
 fstream f;
 f.open("books.txt",ios::in|ios::binary);
 while(f.read((char*)&tem,sizeof(tem)))
      {
       if(temp == tem.bookid)
	 {
	  cout<<"Book Name : "<<tem.name<<endl;
	  cout<<"Author : "<<tem.author<<endl;
	  cout<<"Type : "<<tem.type<<endl;
	  break;
	 }
      }
 f.close();
 getch();
 menu();
}
void delete_book()
{
 clrscr();
 int temp;
 cout<<"Enter Id : ";
 cin>>temp;
 book s;
 fstream f,f1;
 f1.open("tempbook.txt",ios::out|ios::app);
 f.open("books.txt",ios::in|ios::out|ios::binary);
 while(f.read((char*)&s,sizeof(s)))
      {
       if(s.bookid!=temp)
	 {
	  f1.write((char*)&s,sizeof(s));
	 }else{
	  cout<<"\nBook deleted : "<<s.name;
	 }
      }
 f1.close();
 f.close();
 remove("books.txt");
 rename("tempbook.txt","books.txt");
 getch();
 menu();
}
void update_book()
{
 clrscr();
 cout<<"Enter Id : ";
 int temp;
 cin>>temp;
 book s;
 fstream f;
 f.open("books.txt",ios::in|ios::out|ios::binary);
 while(!f.eof())
      {
       long pos = f.tellg();
       f.read((char*)&s,sizeof(s));
       if(temp==s.bookid)
	 {
	  cout<<"Add new Details for Id : "<<s.bookid;
	  cout<<"\nEnter Book Name : ";
	  gets(s.name);
	  cout<<"Enter Author's Name : ";
	  gets(s.author);
	  cout<<"Enter Type : ";
	  gets(s.type);
	  f.seekg(pos);
	  f.write((char*)&s,sizeof(s));
	  cout<<"\nData Modified";
	  break;
	 }
      }
 f.close();
 getch();
 menu();
}
void add_member()
{
 clrscr();
 member temp;
 cout<<"Enter Name : ";
 gets(temp.name);
 cout<<"Enter Address : ";
 gets(temp.address);
 cout<<"Enter Phone No. : ";
 gets(temp.ph_no);
 temp.id = calculate_member_id();
 cout<<"Id : "<<temp.id;
 ofstream f;
 f.open("members.txt",ios::app|ios::binary);
 f.write((char*)&temp,sizeof(temp));
 f.close();
 getch();
 menu();
}
int calculate_member_id()
{
 fstream f;
 f.open("members.txt",ios::in|ios::ate|ios::out);
 int s = f.tellg()/sizeof(member);
 f.close();
 return ++s;
}
void see_member()
{
 clrscr();
 member tem;
 int temp;
 cout<<"Enter Id : ";
 cin>>temp;
 fstream f;
 f.open("members.txt",ios::in|ios::binary);
 while(f.read((char*)&tem,sizeof(tem)))
      {
       if(temp == tem.id)
	 {
	  cout<<"Name : "<<tem.name<<endl;
	  cout<<"Address : "<<tem.address<<endl;
	  cout<<"Phone No. : "<<tem.ph_no<<endl;
	  break;
	 }
      }
 f.close();
 getch();
 menu();
}
void delete_member()
{
 clrscr();
 int temp;
 cout<<"Enter Id : ";
 cin>>temp;
 member s;
 fstream f,f1;
 f1.open("tempmem.txt",ios::out|ios::app|ios::binary);
 f.open("members.txt",ios::in|ios::out|ios::binary);
 while(f.read((char*)&s,sizeof(s)))
      {
       if(s.id!=temp)
	 {
	  f1.write((char*)&s,sizeof(s));
	 }else{
	  cout<<"\nMember deleted : "<<s.name;
	 }
      }
 f1.close();
 f.close();
 remove("members.txt");
 rename("tempmem.txt","members.txt");
 getch();
 menu();
}
void update_member()
{
 clrscr();
 cout<<"Enter Id : ";
 int temp;
 cin>>temp;
 member s;
 fstream f;
 f.open("members.txt",ios::in|ios::out|ios::binary);
 while(!f.eof())
      {
       long pos = f.tellg();
       f.read((char*)&s,sizeof(s));
       if(temp==s.id)
	 {
	  cout<<"Add new Details for Id : "<<s.id;
	  cout<<"\nEnter Name : ";
	  gets(s.name);
	  cout<<"Enter Address : ";
	  gets(s.address);
	  cout<<"Enter Phone No. : ";
	  gets(s.ph_no);
	  f.seekg(pos);
	  f.write((char*)&s,sizeof(s));
	  cout<<"\nData Modified";
	  break;
	 }
      }
 f.close();
 getch();
 menu();
}
void menu()
{
 clrscr();
 cout<<"\n1.Add Book";
 cout<<"\n2.View Book";
 cout<<"\n3.Delete Book";
 cout<<"\n4.Update Book";
 cout<<"\n5.Add Member";
 cout<<"\n6.View Member";
 cout<<"\n7.Delete Member";
 cout<<"\n8.Update Member";
 cout<<"\n9.Exit";
 cout<<"\n\nEnter Your Choice : ";
 int c;
 cin>>c;
 switch(c)
       {
	case 1:add_book();break;
	case 2:see_book();break;
	case 3:delete_book();break;
	case 4:update_book();break;
	case 5:add_member();break;
	case 6:see_member();break;
	case 7:delete_member();break;
	case 8:update_member();break;
	default: exit(0);
       }
}
void main()
{
 clrscr();
 int gd=DETECT,gp;
 initgraph(&gd,&gp,"C:\\TURBOC3\\BGI");
 setbkcolor(RED);
 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t****WELCOME****";
 cout<<"\n\t\t           Library Management System";
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tMade by-";
 cout<<"\n\t\t\t\t\t\t\t\tManas Shukla";
 cout<<"\n\t\t\t\t\t\t\t\tID:201851063";
 cout<<"\n\t\t\t\t\t\t\t\tSec:1";
 cout<<"\n\t\t\t\t\t\t\t\tLab:A";
 delay(2000);
 closegraph();
 menu();
 getch();
}
