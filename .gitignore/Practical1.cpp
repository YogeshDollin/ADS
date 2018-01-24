#include<iostream>

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
	//static int count_chap;
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

void Book_d::insert(int choice){
	switch(choice){
		case 1:{
			Node* temp=head;
			while(temp->next!=NULL){
				
			}
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

void Book_d::display(){//Node* link){
	Node *temp=head,*temp2;//->next->down_link;
	
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
			cout<"\n\t\t----->"<<temp->name<<" : ";
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
	b.create_tree();
	//cout<<"\n display : "<<endl;
	b.display();
	return 0;
}
