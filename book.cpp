#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Node{
public: 
	bool flag;
	string name;
	Node *down_link;
	Node *next;
};

class Book_d{
	Node *head=NULL;
public:
	Node* create_node(bool);
	Node* subsection(int);
	Node* section(int);
	Node* chapter(int);
	void create_tree();
	void display();
	void chapter_display(Node*);
	void section_display(Node*);
	void insert(int);
	void delete_(int,Node*);
};

Node* Book_d::create_node(bool choice){
	Node *p=new(Node);
	switch(choice){
		case 0:
				p->flag=0;
				cin>>p->name;
				p->next=NULL;
				break;

		case 1:
				p->flag=1;
				p->down_link=NULL;
				p->next=NULL;
				break;		
	}
}

void Book_d::delete_(int choice,Node* link){
	Node* temp=head;
	temp=temp->next;
	bool flagd=0;
	int choice;
	char chapter_number;
	string str1,str2;

	switch(choice){
		case 1:{
				cout<<"\n enter chapter number : ";
				cin>>chapter_number;
				while(temp!=NULL){
					if(temp->down_link->name[0]==chapter_number){
						flagd=1;
						Node* del_chap_temp;
						if(temp->down_link->next==NULL){
							del_chap_temp=temp->down_link;
							temp->down_link==NULL;
							delete(del_chap_temp);
						}
						else{
							//temp=temp->down_link;
							 if(temp->down_link->next != NULL && temp->down_link->next->flag==0){
								del_chap_temp=temp->down_link;
								temp->down_link=temp->down_link->next;
								//del_chap_temp->next=NULL;
								delete(del_chap_temp);
							}
							else{
								if(temp->down_link->next->next==NULL){
									delete_(2,temp->down_link->next);
									temp->down_link->next=NULL;
									del_chap_temp=temp->down_link;
									temp->down_link=NULL;
									delete(del_chap_temp);
								}
								else{
									del_chap_temp=temp->down_link;
									temp->down_link=temp->down_link->next->next;
									del_chap_temp->next->next=NULL;
									delete_(2,del_chap_temp->next);
									del_chap_temp->next==NULL;
									delete(del_chap_temp);
								}
							}
						}
						break;
					}
					else{
						temp=temp->down_link;
						while(temp!=NULL){
							if(temp->next->name[0]==chapter_number){
								flagd=1;
								Node* del_chap_temp;
								if(temp->next->next==NULL){
								del_chap_temp=temp->next;
								temp->next==NULL;
								delete(del_chap_temp);
								}
								else{
									//temp=temp->down_link;
									 if(temp->next->next->flag==0){
										del_chap_temp=temp->next;
										temp->next=temp->next->next;
										del_chap_temp->next=NULL;
										delete(del_chap_temp);
									}
									else{
										if(temp->next->next->next==NULL){
											delete_(2,temp->next->next);
											temp->next->next=NULL;
											del_chap_temp=temp->next;
											temp->next=NULL;
											delete(del_chap_temp);
										}
										else{
											del_chap_temp=temp->next;
											temp->next=temp->next->next->next;
											del_chap_temp->next->next=NULL;
											delete_(2,del_chap_temp->next);
											del_chap_temp->next==NULL;
											delete(del_chap_temp);
										}
									}
								}
							}
							else
						}
					}
					if(flagd==0)
						cout<<"\n data not found";
					break;
				}
		}

		case 2:{
			
		}
	}
}

void Book_d::insert(int choice){
	int count;
	Node* temp=head;
			temp=temp->next->down_link;
	switch(choice){
		case 1:{
			
			while(temp->next!=NULL)
			temp=temp->next;
			cout<<"\n enter number of chapter to add : ";
			cin>>count;
			temp->next=chapter(count);
			break;
		}

		case 2:{
				cout<<"\n enter chapter number : ";
				char str;
				cin>>str;
				bool flag=0;
				while(temp!=NULL){
					if(temp->name[0]==str){
						flag=1;
						temp=temp->next->down_link;
						while(temp->next!=NULL)
							temp=temp->next;
						cout<<"\n enter number of sections to add : ";
						cin>>count;
						temp->next=section(count);
						break;
					}
					else
						temp=temp->next;
				}
				if(flag==0){
					cout<<"\n chapter not found ";
					flag=0;
				}
				break;
			}	

		case 3:{
				cout<<"\n enter chapter and section number : ";
				char str1;string str2;
				cin>>str1>>str2;
				bool flag1=0;
				while(temp!=NULL){
					if(temp->name[0]==str1){
						flag1=1;
						temp=temp->next->down_link;
						bool flag2=0;
						while(temp!=NULL){
							if(temp->name==str2){
								flag2=1;
								if(temp->next==NULL){
									temp->next=create_node(1);
									cout<<"\n enter number of subsection to add : ";
									cin>>count;
									temp->next->down_link=subsection(count);
									break;
								}
								else if(temp->next->flag==0){
									Node* temo=temp->next;
									temp->next=create_node(1);
									temp->next->next=temo;
									cout<<"\n enter number of subsection to add : ";
									cin>>count;
									temp->next->down_link=subsection(count);
									break;
								}
								else if(temp->next->flag==1){
									temp=temp->next->down_link;
									while(temp->next!=NULL)
									temp=temp->next;
									cout<<"\n enter number of subsection to add : ";
									cin>>count;
									temp->next=subsection(count);
									break;
								}
							}
							else
								temp=temp->next;
						}
							if(flag2==0){
								cout<<"\n section not found";
								flag2=0;
							}
							break;
					}
					else
						temp=temp->next;
				}
				if(flag1==0){
					cout<<"\n chapter not found ";
					flag1=0;	
				}
				break;
			}	
		}
}

Node* Book_d::subsection(int count_subsection){
	if(count_subsection!=0){
		count_subsection--;
		cout<<"enter subsection name :";
		Node* p=create_node(0);
		p->next=subsection(count_subsection);
		return p;
	}
	return NULL;
}

Node* Book_d::section(int count_section){
	if(count_section!=0){
		count_section--;
			cout<<"\n enter section name : ";
		Node *p=create_node(0);
			int subsection_count;
		cout<<"\n enter total number of subsections contained : ";
			cin>>subsection_count;

			if(subsection_count>0){
				p->next=create_node(1);
				p->next->down_link=subsection(subsection_count);
				p->next->next=section(count_section);
				return p;
			}
			if(subsection_count==0){
				p->next=section(count_section);
				return p;
			}
	}else
	return NULL;

}

Node* Book_d::chapter(int count_chap)
{
	if(count_chap!=0){
		count_chap--;
		cout<<"\n enter chapter name : ";
		Node *p=create_node(0);
		int section_count;
			cout<<"\n enter total number of sections contained : ";
			cin>>section_count;

		if(section_count>0){
			p->next=create_node(1);
			p->next->down_link=section(section_count);
			p->next->next=chapter(count_chap);
			return p;
		}
		if(section_count==0){
			p->next=chapter(count_chap);
			return p;
		}
	}else
	return NULL;	
}

void Book_d::create_tree(){
	cout<<"\n enter book name : ";
	head=create_node(0);
	int choice;
	cout<<"enter total chapter contained : ";
	cin>>choice;
	if(choice==0)
		return;
	else{
		
		head->next=create_node(1);
		
		head->next->down_link=chapter(choice);
	}
//	display(head);
}

void Book_d::display(){
	Node *temp=head,*temp2;
	
	while(temp!=NULL){
		if(temp->flag==0){
			cout<<"\n \t----->"<<temp->name<<" :";
			temp=temp->next;
		}else{
		temp2=temp->down_link;
		chapter_display(temp2);
		temp=temp->next;
		//display(temp);
		}
	}
}

void Book_d::chapter_display(Node* link){
	Node *temp=link,*temp2;
	while(temp!=NULL){
		if(temp->flag==0){
			cout<<"\n\t\t----->"<<temp->name<<" : ";
			temp=temp->next;
		}
		else{
			temp2=temp->down_link;
			cout<<endl;
			section_display(temp2);
			temp=temp->next;
		}
	}
}

void Book_d::section_display(Node* link){
	Node* temp=link;
	while(temp!=NULL){
		if(temp->flag==0){
			cout<<"\n\t\t\t----->"<<temp->name<<" : ";
			temp=temp->next;
		}
		else{
			cout<<endl;
			section_display(temp->down_link);
			temp=temp->next;
		}
	}
}

int main(){
	Book_d b;
	system("clear");
while(1){
	cout<<"\n 1.create tree"<<"\n 2.insert tree"<<"\n3.display"<<"\n 4.delete ";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
				b.create_tree();
				break;

		case 2:{
				int choice;
				cout<<"\n 1.add chapter"<<"\n 2.add section"<<"\n 3.add subsection";
				cout<<"\n enter choice : ";
				cin>>choice;
				b.insert(choice);
				break;
				}

		case 3:
				b.display();
				break;
		case 4:
				cout<<"\n 1.chapter"<<"\n 2.section"<<"\n 3.subsection";
				int choice;
				cin>>choice;
				b.delete_(choice);
				break;

		default:
				cout<<"\ninvalid choice";								
		}
	}
	return 0;
}
