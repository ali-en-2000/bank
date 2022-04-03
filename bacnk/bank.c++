//.................................................[ ali reza mohammadi        :982125702 ]................................................// 
//.................................................[ mohamad reza mohammadi    :982125582 ]................................................//
#include <iostream>
#include <vector>
#include<windows.h>
using namespace std;

	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE );													//kode rang
	int tedad_moshtari=10;
	vector<vector<string> >karbar(tedad_moshtari,vector<string>(5));							//vector for name , last name , account type , active or un active
	vector<vector<int> >karbar_n(tedad_moshtari,vector<int>(3));								//vector for account number and inventory
	int w;

class user_father{																				//class pedar
	public:	
		void get(){																				//tabe daryaft ettelaate moshtari
			char sharte_daryafte_moshtari;
			do{
				++w;																			//shomarande tedad moshtari
				string active_unactive,ac="active",unac="unactive";								// motagqyer baraye active kardane moshtari
				for(int e=1;e<=4;) {															//daryafte name ,laste name , account type , active or un active
					cout<<"enter your name: ";
					cin>>karbar[w][e];
					cout<<"enter your last name: ";e++; 
					cin>>karbar[w][e];
					cout<<"enter your type account: ";e++ ;
					cin>>karbar[w][e];
					cout<<"enter your active or unactive: ";e++;
					cin>>active_unactive;
					
					if(active_unactive==ac){
						karbar[w][e]=active_unactive;}
					
					if(active_unactive==unac){
						karbar[w][e]=active_unactive;}
					e++;
				}

				for(int e=1;e<=2;) {															//daryafte account number , inventory
					cout<<"enter your account number: ";
					cin>>karbar_n[w][e];
					cout<<"enter your inventory: ";e++;  
					cin>>karbar_n[w][e];
					e++;
					system("cls");
				}
				
			
				cout<<"\n\n                do you want that enter person else to the bank (y/n)";
				cin>>sharte_daryafte_moshtari;
				system("cls");

			}while(sharte_daryafte_moshtari=='y');
	    }
	};
	
class user_child:public user_father{															//class cild
		public:
	    void show(){																			//tabe namayeshe list 
	    	
	    	cout<<"name / last name / type account / active_unactive / account number / inventory\n\n";
	    	cout<<"\n________________________________________________________________________________\n";
			for(int a=1;a<tedad_moshtari;a++) {
	    		if (karbar_n[a][1]==0){
	    			break;
				}
							
				for(int b=1;b<=4;b++) {
					cout<<karbar[a][b]<<" / ";
				}
				
				for(int b=1;b<=2;b++) {
					cout<<karbar_n[a][b]<<" / ";
				}
				
	    		cout<<"\n________________________________________________________________________________\n";
			}
	    }
	    
	    int search(){																			//tabe jostojo moshteri
	    	cout<<"for finding your user account pleas enter your account number: ";
	    	int userr;																			//shomare hesabe daryaftii az moshtari
	    	cin>>userr;
	    	
	    	for(int r=1;r<=tedad_moshtari;r++) {
	    		if(karbar_n[r][1]==userr){
	    			userr=karbar_n[r][1];
	    			cout<<"your account information is: \n";
		    		for(int g=1;g<=4;g++) {
		    			
		    			cout<<karbar[r][g]<<"  ,  ";
		    			
					}
		    		for(int g=1;g<=2;g++) {
		    			
		    			cout<<karbar_n[r][g]<<"  ,  ";
		    		}
		    		return 2;
		    	}
		    	
		    }
		}
	    
	    void chang_inventory(){																	//tabe tagiire mojodi
	    	cout<<"pleas enter your account number: ";
	    	int userr;																			//shomare hesabe daryaftii az moshtari
	    	cin>>userr;
			
	    	for(int r=1;r<=tedad_moshtari;r++) {													//jostojo moshtari
	    		if(karbar_n[r][1]==userr){
	    			if(karbar[r][4]=="active"){													//aya moshtari active ast
			    		cout<<"your account inventory is: "<<karbar_n[r][2];
						cout<<"\n\n                              select decision.\n\n\n\n";
						cout<<" 1:deposit to account \t\t\t\t\t    take from account:2";
						int u;
						cin>>u;
						
						switch(u){
							case 1:
								cout<<"pleas enter your amount that you want to deposit to account: ";
								int amounti;
								cin>>amounti;
								karbar_n[r][2]+=amounti;
								cout<<"your new inventory is:"<<karbar_n[r][2];
								break;
							case 2:
								cout<<"pleas enter your amount that you want to take at account: ";
								int amount;
								cin>>amount;
								if(amount>(karbar_n[r][2]-5)){
									cout<<"The amount you choose is not allowed.";
								}
								else {
								karbar_n[r][2]-=amount;
								cout<<"your new inventory is:"<<karbar_n[r][2];
								break;}
						}
					}
					else
					system("cls");
					cout<<"excuse me , Your account has been disabled. ";
				}
			}
	    }
	    
	    void max_inventory(){																		//tabe baraye namayesh bishtarin mojodi6
	    	int min,max;																			//motagayer haye komaki
	        for(int i=0; i<=tedad_moshtari; i++){														//peyda kardane bishtarin mojodi
				karbar_n[i][2];
    		    if(i==0)
					min=karbar_n[i][2];
				if(karbar_n[i][2]>max)
					max=karbar_n[i][2];
				if(karbar_n[i][2]<=min)
					min=karbar_n[i][2];
			}
			for(int i=1;i<=tedad_moshtari;i++){
				if(karbar_n[i][2]==max){															//peyda kardane shomare hesabe bishtarin mojodi
					cout<<"\nThe account number "<<karbar_n[i][1]<<" has the most inventory, which is equal to "<<max;
				}
			}
		}
		
		void un_active(){																			//active ya un active kardane hesab
			int u,v;
			cout<<"\t\t\t\t    SELECT  \n\n\n 1:Active account\t\t\t\t\t     Unactive account:2   ";
			cin>>u;
			switch(u){		
				case 1:
					cout<<"\n\nenter your account number  ";
					cin>>v;
					for(int r=1;r<=tedad_moshtari;r++) {												//peyda kardane hesab
			    		if(karbar_n[r][1]==v){
						karbar[r][4]="active";
						cout<<"Your account has been successfully activated.";
						}
					}
				break;
				
				case 2:
					cout<<"\n\nenter your account number  ";
					cin>>v;
					for(int r=1;r<=tedad_moshtari;r++) {												//peyda kardane hesab
			    		if(karbar_n[r][1]==v){
						karbar[r][4]="unactive";
						cout<<"Your account has been successfully disabled.";
						}
					}		
				break;
			}	
		}	
		
	};

int main(){
	system("color 9f");																				//kode rang	

	cout<<"enter size of list of bank.";
	cin>>tedad_moshtari;
	tedad_moshtari+=1;
	system("cls");																					//paak kardane safhe
				
	user_child ob;
	
	int z;																							//moatagayer bareye entekhabe noee estefade
	char payane_barname;
	do {
		cout<<"\t\t\t\t"<<"PLEASE SELECT \n\n\n\n";
		cout<<"1:Add Customer \t\t\t\t\t\t       Search Customer:2\n\n\n\n\n\n";
		cout<<"3:Active OR Inactive Account\t\t\t\t      Change Inventory:4\n\n\n\n\n\n";  
		cout<<"5:Show List \t\t\t\t\t\t         Max Inventory:6 \n\n";
		cout<<"\n\n\t\t\t\tyour choice is: "; cin>>z;
		system("cls");
		switch(z) {
			case 1:
				ob.get();
				break;
			
			case 2:
				int a;
				a=ob.search();
				if (a!=2 ){
					cout<<"you haven't account this bank.";					
				}
				break;	

			case 3:
				ob.un_active();
				break;

			case 4:
				ob.chang_inventory();
				break;
			
			case 5:
				ob.show();
				break;
			 
			case 6:
				ob.max_inventory();
				break;				
		
		}
		cout<<"\n\n\n\t\t\tDo you have another request? (y/n)";	
		cin>>payane_barname;
		system("cls");
	}while(payane_barname=='y');
	
	return 0;
	}
