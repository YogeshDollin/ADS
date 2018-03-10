/*Convert given binary tree into threaded binary tree. Analyze time and space complexity of the
algorithm.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
using namespace std;

class Node{
public:
	char data;
	Node *right;
	bool right_flag;
	bool left_flag;
	Node *left;
};

class TBT{
	Node *temp,*temp_follower;
	 vector <Node*> arr;
	 stack <Node*> Stack; 
public:
	Node* create_node(){
		Node *p=new(Node);
		cin>>p->data;
		p->right=NULL;p->left=NULL;
		p->right_flag=0;p->left_flag=0;
		return p;
	}
	Node* create_binary_tree(Node*);
	//Node* insert_to_binary_tree(Node*);
	void convert_to_threaded(Node*);
	void display_nonrecursive(Node*);
	void threading(Node*);
	void display_threaded(Node*);
};

void TBT::display_threaded(Node* link){
	Node *root=link,*temp=link;
	do{
		link=link->left;
	}while(link->left!=root);

	do{
		temp=temp->right;
	}while(temp->right!=root);

	cout<<link->data<<"-->";
	do{
		if(link->right_flag==1){
			link=link->right;
			cout<<link->data<<"-->";
		}else{
			if(link->right->right_flag==1){
				link=link->right;
				cout<<link->data<<"-->";
			}else{
				link=link->right->left;
				cout<<link->data<<"-->";
			}
		}
	}while(link!=temp);
}

void TBT::convert_to_threaded(Node* link){
	
	temp=link;
	if(temp==NULL)
		return;
	else{
		while(1){

			while(temp!=NULL){
				Stack.push(temp);
				temp=temp->left;
			}
			if(temp==NULL && Stack.empty())
				break;
			else if(temp==NULL && !Stack.empty()){
				temp=Stack.top();
				arr.push_back(temp);
				Stack.pop();
				temp=temp->right;
			}
		}
	}
}

void TBT::threading(Node* link){
	convert_to_threaded(link);
	for(int i=0;i<arr.size();i++){
		if(i==0){
			if(arr[i]->left==NULL && arr[i]->right==NULL){
				arr[i]->left=link;
				arr[i]->left_flag=1;
				arr[i]->right=arr[i+1];
				arr[i]->right_flag=1;
			}

		}
		else if(i==arr.size()-1){
			if(arr[i]->left==NULL && arr[i]->right==NULL){
				arr[i]->left=arr[i-1];
				arr[i]->left_flag=1;
				arr[i]->right=link;
				arr[i]->right_flag=1;
			}
		}
		else{
			if(arr[i]->left==NULL && arr[i]->right==NULL){
				arr[i]->left=arr[i-1];
				arr[i]->left_flag=1;
				arr[i]->right=arr[i+1];
				arr[i]->right_flag=1;
			}
		}
	}
	cout<<"\n\n display non recursive : ";
	display_threaded(link);
}

Node* TBT::create_binary_tree(Node *root){
		cout<<"\n enter data : ";
		Node *p=create_node();
		temp_follower=root;temp=root;
		if(root==NULL)
			root=p;
		else{
			int choice;
			while(temp!=NULL){
				cout<<"\n\n 1.to the left of "<<temp->data<<" \n2.to the right of "<<temp->data<<" \n\n enter choice : ";
				cin>>choice;
				switch(choice){
					case 1:
							temp_follower=temp;
							temp=temp->left;
							break;
					case 2:
							temp_follower=temp;
							temp=temp->right;	
							break;
				}
			}	
			if(choice==1)
					temp_follower->left=p;
				else if(choice==2)
					temp_follower->right=p;
		}
		return root;
}

void TBT::display_nonrecursive(Node* link){
	temp=link;
	if(link==NULL)
		return;
	else{
		while(1){

			while(temp!=NULL){
				Stack.push(temp);
				temp=temp->left;
			}
			if(temp==NULL && Stack.empty())
				break;
			else if(temp==NULL && !Stack.empty()){

				temp=Stack.top();
				cout<<temp->data<<"-->";
				Stack.pop();
				temp=temp->right;
			}
		}
	}
}

int main(){
	system("clear");
	TBT t;
	Node *root=NULL;
	int number;
	int choice;
	while(1){
		cout<<"\n1.create binary \n2.convert \n3.display \n4.exit";
		cout<<"\n\n enter choice : ";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"\n enter total number of data to enter : ";
				cin>>number;
				for(int i=0;i<number;i++)
				root=t.create_binary_tree(root);
				break;

			case 2:
					t.threading(root);
					break;

			case 3:
					cout<<"\n\n inorder display of binary tree : \n\n \t";
					t.display_nonrecursive(root);
					cout<<endl;
					
					break;
			case 4:
					exit(0);		
		}
	}
	
	return 0;
}
