#include<iostream>
using namespace std;
class treeDemo{
	class GetNode{
		public:
		int data;
		GetNode *leftChild;
		GetNode *rightChild;
		GetNode(int value){
			leftChild=NULL;
			data=value;
			rightChild=NULL;
		}
		
	};
	public:
		GetNode *root=NULL;
		void insert(int value){

			root=insertT(root,value);
			cout<<"data inserted";
		}
		GetNode *insertT(GetNode *root,int value){
			if(root==NULL){
				root=new GetNode(value);
				return root;
			}
			if(value<root->data){
				root->leftChild=insertT(root->leftChild,value);
			}else{
				root->rightChild=insertT(root->rightChild,value);
			}
			return root;
		}
        void search(int value){

			root=searchT(root,value);
			cout<<"value present";
		}
		GetNode *searchT(GetNode *root,int value){
			if(root==NULL){
				root=new GetNode(value);
				return root;
			}
			if(value<root->data){
				root->leftChild=insertT(root->leftChild,value);
			}else if(value>root->data){
				root->rightChild=insertT(root->rightChild,value);
			}else if(value==root->data){
                cout<<" value present";
            }
			return root;
		}
		
	void inorder(){
		inorderT(root);
		cout<<"inorder traversal";
	}
	void inorderT(GetNode *root){
		if(root!=NULL){
		inorderT(root->leftChild);
		cout<<root->data<<" ";
		inorderT(root->rightChild);
	}
	}
	
	void preorder(){
		cout<<"preorder traversal";
		preorderT(root);
	}
	void preorderT(GetNode *root){
		if(root!=NULL){
		cout<<root->data;
		preorderT(root->leftChild);
		preorderT(root->rightChild);
	}
}
	
	void postorder(){
		cout<<"postOrder";
		postorderT(root);
	}
	void postorderT(GetNode *root){
		if(root!=NULL){
		postorderT(root->leftChild);
		postorderT(root->rightChild);
     	cout<<root->data;
	}
}
};
int main(){
int n,value;
    treeDemo obj;
    while(1){
        cout<<endl;
    cout<<"1.append"<<endl;
    cout<<"2.inorder traversal"<<endl;
    cout<<"3.preorder traversal"<<endl;
    cout<<"4. postorder traversal"<<endl;
    cout<<"5. search"<<endl;
    cout<<"0.exit"<<endl;
    cout<<"Select any choice"<<endl;
    cin>>n;
	switch(n){
        case 1:	cout<<"enter value:";
			cin>>value;
		obj.insert( value);
        break;
        case 2:obj.inorder();
        break;
        case 3:obj.preorder();
        break;
        case 4:obj.postorder();
        break;
        case 5:
            cout<<"enter value:";
			cin>>value;
            obj.search(value);
        break;
    }
}
	return 0;
}