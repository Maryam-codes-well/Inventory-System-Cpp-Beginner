#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
const int MAX=100;
string name[MAX];
string id[MAX];
int quantity[MAX];
float price [MAX];
int count=0;

void loaddata(){
	ifstream file("Inventory data.txt");
	if(!file.is_open()){
		cerr<<"File not found"<<endl;
	}else{
		count=0;
		while(file>>name[count]>>id[count]>>quantity[count]>>price[count]){
			count++;
		}
	}
	file.close();
}
void savedata(){
	ofstream file("Inventory data.txt");
	if(file.is_open()){
		for(int i=0;i<count;i++){
			file<<name[i]<<" "<<id[i]<<" "<<quantity[i]<<" "<<price[i]<<endl;
		}
	} else{
	cerr<<"File not found"<<endl;
	}
	file.close();
}
void addproduct(int n){
	loaddata();
	if(count>=MAX){
		cout<<"Inventory is full"<<endl;
	}else{
	for(int i=0;i<n;i++){
		cin.ignore();
		cout<<"Enter the name of the " <<i+1<<" Item"<<endl;
		getline(cin,name[count]);
		cout<<"Enter Id of the Item"<<endl;
		getline(cin,id[count]);
		cout<<"Enter quantity of the Item"<<endl;
		cin>>quantity[count];
		cout<<"Enter price of the Item"<<endl;
		cin>>price[count];	
	count++;
	system("cls");
	}
	savedata();
	cout<<"Items added successfully"<<"\n"<<endl;
}
system("pause");
 system("cls");
}
	void viewitems(){
		loaddata();
		if(count==0){
			cerr<<"No items in the inventory"<<endl;
			}
	     for(int i=0;i<count;i++){
		cout<<"Name: "<<name[i]<<"\n"<<"ID: "<<id[i]<<"\nQuantity:"<<quantity[i]<<"\nPrice:"<<price[i]<<"\n"<<endl;
		}
		system("pause");
		 system("cls");
	}
	void searchbyname(string bName){
	     loaddata();
	     bool found=false;
		for(int i=0;i<count;i++){
		if(name[i].find(bName)!=string::npos){
		cout<<"Name: "<<name[i]<<"\n"<<"ID: "<<id[i]<<"\n"<<"Price: "<<price[i]<<"\n"<<"Quantity: "<<quantity[i]<<"\n"<<endl;
		found=true;
		}
	}
		if(!found){
			cerr<<"Item not found"<<"\n"<<endl;
		}
		system("pause");
 system("cls");
	}
	void searchbyid(string bId){
		loaddata();
		bool found=false;
		for(int i=0;i<count;i++){
			if(bId==id[i]){
				cout<<"Item found"<<endl;
				cout<<"Name: "<<name[i]<<"\n"<<"ID: "<<id[i]<<"\n"<<"Price: "<<price[i]<<"\n"<<"Quantity: "<<quantity[i]<<"\n"<<endl;
				found=true;
			}
		}
		if(!found){
				cerr<<"Item not found\n"<<endl;
			} 
			system("pause");
 system("cls");
	}
	void deleteitem(string ID){
		loaddata();
		bool found=false;
		for(int i=0;i<count;i++){
			if(ID==id[i]){
				cout<<"\nName: "<<name[i]<<"\n"<<"ID: "<<id[i]<<"\n"<<"Price: "<<price[i]<<"\n"<<"Quantity: "<<quantity[i]<<"\n"<<endl;
			for(int j=i;j<count-1;j++){
				name[j]=name[j+1];
				id[j]=id[j+1];
				price[j]=price[j+1];
				quantity[j]=quantity[j+1];				
			}
			count--;
			found=true;
			break;
			}
		}
		if(found==true){
			savedata();
			cout<<"Item deleted successfully"<<endl;
		}
		if(!found){
				cerr<<"Item not found or already deleted"<<endl;
			}
		
	}
	void updateitem(){
		loaddata();
		string key;
		int num;
		bool found=false;
		cout<<"Enter ID of the item"<<endl;
		cin.ignore();
		getline(cin,key);
		for(int i=0;i<count;i++){
			if(key==id[i]){
				found=true;
				cout<<"Name: "<<name[i]<<"\nID: "<<id[i]<<"\nPrice:"<<price[i]<<"\nQuantity: "<<quantity[i]<<endl;
		do{
		cout<<"\nUpdate"<<endl;
		cout<<"1. Name"<<endl;
		cout<<"2. ID"<<endl;
		cout<<"3. Price"<<endl;
		cout<<"4. Quantity"<<endl;
		cout<<"5. Exit Update menu"<<endl;
		cout<<"select option"<<endl;
		cin>>num;
		system("cls");
		switch(num){
			case 1:{
			string newname;
				cout<<"Enter new name"<<endl;
				cin.ignore();
				getline(cin,newname);
				name[i]=newname;
				cout<<"Name updated successfully"<<endl;
				savedata();
				system("pause");
				system("cls");
				break;
			}
				case 2: {
			string newid;
				cout<<"Enter new ID"<<endl;
				getline(cin,newid);
				id[i]=newid;
				cout<<"ID updated successfully"<<endl;
				savedata();
				system("pause");
				system("cls");
				break;
			}
		case 3: {
			float newprice;
				cout<<"Enter new Price"<<endl;
                     cin>>newprice;
				price[i]=newprice;
				cout<<"Price updated successfully"<<endl;
				savedata();
				system("pause");
				system("cls");
				break;
			}
		case 4: {
			int newquantity;
				cout<<"Enter updated quantity"<<endl;
                    cin>>newquantity;
				quantity[i]=newquantity;
				cout<<"Name updated successfully"<<endl;
				savedata();
				system("pause");
				system("cls");
				break;
			}
		case 5: cout<<"Update completed successfully"<<endl;
		system("pause");
		system("cls");
				return;
				break;
		default: cout<<"Invalid option selected!"<<endl;
						
	}
} while(num!=5);
} 
}if(!found){
	cout<<"Item not found"<<endl;
}
}
int main(){
	int option, n;
	string sid,sname;
	cout<<"====WELCOME TO INVENTORY SYSTEM====\n"<<endl;
	do{
		cout<<"select option:"<<endl;
		cout<<"1. Add Items"<<endl;
		cout<<"2. View Items"<<endl;
		cout<<"3. Search Item by name"<<endl;
		cout<<"4. Search Item by ID"<<endl;
		cout<<"5. Total Items in Inventory"<<endl;
		cout<<"6. Update item"<<endl;
		cout<<"7. Delete item"<<endl;
		cout<<"0. Exit inventory"<<endl;
		cin>>option;
		system("cls");	
		switch(option){
			case 1: cout<<"how many items you want to add ?"<<endl;
			        cin>>n;
			        addproduct(n);
			        system("pause");
			        break;
			case 2:      viewitems();
			break;
			system("pause");
			case 3: cout<<"Enter name of product"<<endl;
			          cin.ignore();
			          getline(cin,sname);
			          searchbyname(sname);
			          system("cls");
			          break;
			case 4: cout<<"enter ID of the product"<<endl;
			        cin>>sid;
			        searchbyid(sid);
			            system("pause");
			             system("cls");
			        break;
			    
			 case 5: loaddata();
			  cout<<"Total items in inventory are: "<<count<<endl;
			      system("pause");
			        break;
			 case 6:  updateitem();
			 break;
			case 7: cout<<"Enter id of Product you want to delete"<<endl;
			           cin>>sid;     
					   deleteitem(sid); 
					   system("pause"); 
					   system("cls");
					   break;  
			case 0: cout<<"Exiting Inventory system...."<<endl;
			break;		   
			default: cout<<"Invalid option selected!"<<endl;		   
		}
	}while(option!=0);
	return 0;
	
}
	


