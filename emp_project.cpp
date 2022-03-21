#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<windows.h>


using namespace std;

class emp
{
	private:
		int emp_id,sal,grp_id;
		string address,name;
    public:
    
    void menu();
    void insert();
    void display();
    void search();
    void modify();
    void dele();
    void group();
    void search_group_record();
    void show_group();
};

void login()
{
	a:
	string user,pass;
	char ch;
 cout<<"\n\n\n\n\n";
 cout<<"\t\t\t\t\t=================================";
 cout<<"\n\n\t\t\t\t\t\t  LOGIN PROCESS"<<endl;
 cout<<"\n\t\t\t\t\t=================================";
 cout<<"\t\n\n\nEnter User Name: ";
 cin>>user;
 cout<<"\t\n\nEnter User Password: ";
 for(int i=1;i<=7;i++)
 {
 	ch=getch();
 	pass+=ch;
 	cout<<"*";
 	
 }
 if(user=="apple@gmail.com" && pass=="zeeshan")
 {
 	getch();

 	cout<<"\n\nCongratulations Login Successfully.... ";
 	cout<<"          |^ ^|"<<endl;
 	cout<<"                                                 | ~ |";
 	cout<<"\n\n\t\t\tLoading ";
 	for(int i=1;i<=6;i++)
	 {
	 	Sleep(1000);
	 	cout<<".";
	 }

 }
  else if(user!="apple@gmail.com" && pass=="zeeshan")
 {
 	

 	cout<<"\n\n\t\tUserName is Wrong .... ";
 	getch();
    goto a;
}

 else if(user=="apple@gmail.com" && pass!="zeeshan")
 {
 	

 	cout<<"\n\n\t\tPassword is Wrong .... ";
 	getch();
    goto a;
}

 else if(user!="apple@gmail.com" && pass!="zeeshan")
 {
 	

 	cout<<"\n\n\t\tUsername and password both are Wrong .... ";
 	getch();
    exit(0);
}

 
}

void emp::menu()
{
    q: 
    int choice;
    
    cout<<"\n\t\t\t Control_Panal:\n"<<endl;
    cout<<"1.Insert Record"<<endl;
    cout<<"2.Display Record"<<endl;
    cout<<"3.Search Record"<<endl;
    cout<<"4.Modified Record"<<endl;
    cout<<"5.Delete Record"<<endl;
    cout<<"6.Group Record"<<endl;
    cout<<"7.Search Group Record"<<endl;
    cout<<"8.Show All group Record"<<endl;
    cout<<"9.Exit"<<endl<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        	insert();
          break;
        case 2:
        	display();
          break;
        case 3:
        	search();
          break;
        case 4:
        	modify();
          break;
        case 5:
        	 dele();
          break;
        case 6:
        	group();
          break;
        case 7:
        	search_group_record();
          break;
        case 8:
        	show_group();
          break;
        case 9:
          exit(0);
          break;
        default:
         cout<<"\t\t\t Invalid value... Please Try Again..";
         
         
    }

    getch();
    
    goto q;
    
}


void emp::insert()
{
	int test_id,found=0;
	fstream file1,file2;
	cout<<"\n       Employee Name: ";
	cin>>name;
	cout<<"\nEmployee Id: ";
	cin>>emp_id;
	cout<<"\n     Employee Address: ";
	cin>>address;
	cout<<"\nEmployee Salary: ";
	cin>>sal;
	cout<<"\n     Employee group ID: ";
	cin>>grp_id;
	file1.open("emp.txt",ios::out|ios::app);
     file1<<name<<" "<<emp_id<<" "<<address<<" "<<sal<<" "<<grp_id<<"\n";
	file1.close();
	file2.open("group.txt",ios::out|ios::app);
	 file2<<" "<<grp_id<<" "<<emp_id<<" "<<sal<<"\n";
	file2.close();
	
	file1.open("GroupId.txt",ios::in);
	if(!file1)
	{
		file2.open("GroupId.txt",ios::out|ios::app);
		file2<<" "<<grp_id<<"\n";
		file2.close();
	}
	else
	{
		file1>>test_id;
		while(!file1.eof())
		{
			if(test_id==grp_id)
			{
				found++;
			}
		file1>>test_id;
			
		}
		file1.close();
		if(found==0)
		{
		file2.open("GroupId.txt",ios::out|ios::app);
		file2<<" "<<grp_id<<"\n";
		file2.close();	
		}
	}
}

void emp::display()
{
	fstream file;
	cout<<"\n\n.............Display Record............\n\n\n"<<endl;
	file.open("emp.txt",ios::in);
	if(!file)
	{
		cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	file>>name>>emp_id>>address>>sal>>grp_id;
	while(!file.eof())
	{    
	    cout<<"........................................"<<endl;
		cout<<"Employee Name: "<<name;
		cout<<"\n\t\t\tEmployee Id:  "<<emp_id;
		cout<<"\nEmployee Address:  "<<address;
		cout<<"\n\t\t\tEmployee Salary:  "<<sal;
		cout<<"\nEmployee Group Id:  "<<grp_id<<"\n";
		cout<<"........................................"<<endl<<endl<<endl;
		file>>name>>emp_id>>address>>sal>>grp_id;
	}
	file.close();
}	
	
void emp::search()
{
	fstream file;
	int EM_ID,found=0;
	cout<<"\n\nSearch record by Employee_ID "<<endl;
	cout<<"\nEnter Employee_ID   ";
	cin>>EM_ID;
	
	file.open("emp.txt",ios::in);
	if(!file)
	{
		cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	file>>name>>emp_id>>address>>sal>>grp_id;
	while(!file.eof())
	{    
	    if(emp_id==EM_ID)
		{
		
	    cout<<"........................................"<<endl;
		cout<<"Employee Name: "<<name;
		cout<<"\n\t\t\tEmployee Id:  "<<emp_id;
		cout<<"\nEmployee Address:  "<<address;
		cout<<"\n\t\t\tEmployee Salary:  "<<sal;
		cout<<"\nEmployee Group Id:  "<<grp_id<<"\n";
		cout<<"........................................"<<endl<<endl<<endl;
		found++;
		}
		file>>name>>emp_id>>address>>sal>>grp_id;
	}
	file.close();
	
	if(found==0)
	{
		cout<<"\n**********Failed to Find the Employee_ID.************";
	}
	
}	

void emp:: modify()
{
	int test_emp_id,sall,found=0;
	string address1,name1;
	fstream file,file1,file2,file3;
	
	file.open("emp.txt",ios::in);
	file2.open("group.txt",ios::in);
	if(!file || !file2)
	{
	  cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	cout<<"\n                          Modify_Record."<<endl;
	cout<<"\n Modify your record using Employee_id:";
	cout<<"\n\n Enter your Employee Id:  ";
	cin>>test_emp_id;
	
	file1.open("emp1.txt",ios::out|ios::app);
	file>>name>>emp_id>>address>>sal>>grp_id;
	while(!file.eof())
	{
		
	if(test_emp_id==emp_id)
	{
	cout<<"\n\t\t\tModified Employee Name: ";
	cin>>name1;
	cout<<"\nModified Employee Address:  ";
	cin>>address1;
	cout<<"\n\t\t\tModified Employee Salary:  ";
	cin>>sall;
	file1<<name1<<" "<<emp_id<<" "<<address1<<" "<<sall<<" "<<grp_id<<"\n";
	found++;
    }
    else
	{
      file1<<name<<" "<<emp_id<<" "<<address<<" "<<sal<<" "<<grp_id<<"\n";
	}
	
	file>>name>>emp_id>>address>>sal>>grp_id;
	}
	file.close();
	file1.close();
	remove("emp.txt");
	rename("emp1.txt","emp.txt");
	
	file2>>grp_id>>emp_id>>sal;
	file3.open("group1.txt",ios::out|ios::app);
	while(!file2.eof())
	{
		if(test_emp_id==emp_id)
		{
			file3<<" "<<grp_id<<" "<<emp_id<<" "<<sall<<"\n";

		}
		else
		{
		  	file3<<" "<<grp_id<<" "<<emp_id<<" "<<sal<<"\n";
	
		}
		file2>>grp_id>>emp_id>>sal;

	}
	file2.close();
	file3.close();
	remove("group.txt");
	rename("group1.txt","group.txt");
	

	
	if(found==0)
	{
     	cout<<"\n**********Failed to Find the Employee_ID.************";

	}
	else
	{
		cout<<"Record Modified Successfully......";
	}
} 



void emp::dele()
{
	int test_id,found=0;
	cout<<"\n\t\t\tDelete Record by Employee Id:";
	cout<<"\nEnter Employee Id:  ";
	cin>>test_id;
		fstream file,file1,file2,file3;

	file.open("emp.txt",ios::in);
	file1.open("emp1.txt",ios::out|ios::app);
	file2.open("group.txt",ios::in);
	file3.open("group1.txt",ios::out|ios::app);
	if(!file || !file2)
	{
	  cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	file>>name>>emp_id>>address>>sal>>grp_id;
	while(!file.eof())
	{
		if(test_id==emp_id)
		{
			cout<<"\n\t\t\tRecord is Deleted successfully...";
			found++;
		}
		else
		{
		    file1<<name<<" "<<emp_id<<" "<<address<<" "<<sal<<" "<<grp_id<<"\n";
		}
		file>>name>>emp_id>>address>>sal>>grp_id;

	}
	file.close();
	file1.close();
	remove("emp.txt");
	rename("emp1.txt","emp.txt");
	
	file2>>grp_id>>emp_id>>sal;
	while(!file2.eof())
	{
		if(test_id!=emp_id)
		{
			file3<<" "<<grp_id<<" "<<emp_id<<" "<<sal<<"\n";

		}
		
		file2>>grp_id>>emp_id>>sal;

	}
	file2.close();
	file3.close();
	remove("group.txt");
	rename("group1.txt","group.txt");
	
	if(found==0)
	{
     	cout<<"\n**********Failed to Find the Employee_ID.************";

	}

}

void emp::group()
{
	cout<<"\n\t\t\tGroup_Record:"<<endl;
	fstream file;
	file.open("group.txt",ios::in);
	if(!file)
	{
	  cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	file>>grp_id>>emp_id>>sal;
	while(!file.eof())
	{   cout<<"........................................"<<endl;
		cout<<"\nGroup_id: "<<grp_id;
		cout<<"\n\tEmployee_id: "<<emp_id;
		cout<<"\nSalary: "<<sal;
		cout<<"\n........................................"<<endl<<endl<<endl;
		file>>grp_id>>emp_id>>sal;
		
	}
	file.close();
}

void emp::search_group_record()
{
	int test_id,found=0,emp_count=0,salary_count=0;
	fstream file;
	file.open("group.txt",ios::in);
	if(!file)
	{
	  cout<<"*********** File Opening Error? ********";
		getch();
		menu();
	}
	
	cout<<"\n\t\t\tSearch_Group_Record:";
	cout<<"\n\n\tSearch your Record by using Group id:";
	cout<<"\n\n\tEnter Group_id:  ";
	cin>>test_id;
	file>>grp_id>>emp_id>>sal;
	system("cls");
	while(!file.eof())
	{   
	    if(test_id==grp_id)
		{
	    cout<<"........................................"<<endl;
		cout<<"\nGroup_id: "<<grp_id;
		cout<<"\n\tEmployee_id: "<<emp_id;
		cout<<"\nSalary: "<<sal;
		cout<<"\n........................................"<<endl<<endl<<endl;
		found++;
		emp_count++;
		salary_count=salary_count+sal;
		}
		
		file>>grp_id>>emp_id>>sal;
	}
	file.close();	
	if(found!=0)
		{
		cout<<"Total Employees: "<<emp_count;
		cout<<"\n\nTotal Salary: "<<salary_count;
		}
		else
		{
     	cout<<"\n**********Failed to Find the Employee_ID.************";
		}
}

void emp::show_group()
{
	system("cls");
}


int main()
{
  emp e1;
  login();
  e1.menu();
}








