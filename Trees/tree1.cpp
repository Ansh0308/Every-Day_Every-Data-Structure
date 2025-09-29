#include<iostream>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
class Node{
    
    
    public:
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;

    }
};


    void preorder(Node* node){
        if(node==nullptr) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);

    }
    void inorder(Node* node){
        if(node==nullptr) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    void postorder(Node* node){
        if(node==nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

    Node* insert(Node* node, int data){
        if(node==nullptr){
            return new Node(data);
        }
        if(data<node->data){
            node->left=insert(node->left,data);
        }
        else{
            node->right=insert(node->right,data);
        }
        return node;
    }
    int heightTree(Node* root){
        if(root->left==nullptr && root->right==nullptr){
            return 0;
        }
        return 1 +max(heightTree(root->left) ,heightTree(root->right)); 

    }
    int diameter(Node* root){
        if(root==nullptr)return 0;

        int v1=heightTree(root->left)+heightTree(root->right)+2;
        int v2=max(diameter(root->left),diameter(root->right));
        return max(v1,v2);
        
    }
    Node* dummy_tree(){
        Node* root=new Node(1);
        root->left=new Node(2);
        root->right=new Node(3);
        root->left->left=new Node(4);
        root->left->right=new Node(5);
        root->right->left=new Node(6);
        root->right->right=new Node(7);
        
        return root;
    }
    void BFS(Node* head){
        queue<Node*> que;
        Node* temp=head;
        que.push(temp);
        while(!que.empty()){
            int val=que.front()->data;
            cout<<val<<" ";
            if(que.front()->left!=nullptr){
                que.push(que.front()->left);
            }
            if(que.front()->right!=nullptr){
                que.push(que.front()->right);
                
            }
            que.pop();


        }
        return;
    }
    void BFS_magic(Node* head){
        queue<Node*> que;
        Node* temp=head;
        que.push(temp);
        while(!que.empty()){
            int gen=que.size();
            for(int i=0;i<gen;i++){
            int val=que.front()->data;
            cout<<val<<" ";

            if(que.front()->left!=nullptr){
                que.push(que.front()->left);
            }
            if(que.front()->right!=nullptr){
                que.push(que.front()->right);
                
            }

            que.pop();

            }
            cout<<"\n";
            
            


        }
        return;
    }
    void reverseQueue(queue<Node*>& q) {
    stack<Node*> st;
    
    // Transfer all elements from queue to stack
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    
    // Transfer all elements back from stack to queue
    // This reverses the order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}
    void BFS_magic2(Node* head) {
    if (!head) return;
    queue<Node*> q;
    q.push(head);
    bool leftToRight = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; ++i) {
            Node* node = q.front(); q.pop();
            level.push_back(node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (!leftToRight) reverse(level.begin(), level.end());
        for (int val : level) cout << val << " ";
        cout << "\n";
        leftToRight = !leftToRight;
    }
}
vector<int> TopView(Node* root){
    if(!root)return {};
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node* node=q.front().first;
        int index=q.front().second;
        q.pop();
        if(m.find(index)==m.end()){
            m[index]=node->data;
        }
        if(node->left)q.push({node->left,index-1});
        if(node->right)q.push({node->right,index+1});
    }
    vector<int> res;
    for(auto it=m.begin();it!=m.end();it++){
        res.push_back(it->second);
    }
    return res;
}
    void DFS(Node* head){
        
    }


int main(){
    // BFS_magic2(dummy_tree());
    cout<<heightTree(dummy_tree());

    return 0;
}