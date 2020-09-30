#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left,*right;
    // node* right;
};
node* build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node* temp=new(node);
    temp->data=d;
    temp->left=temp->right=NULL;
    temp->left=build_tree();
    temp->right=build_tree();
    return temp;
}
void print(node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int height(node* root)
{
    if(root==NULL)
    return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void printKthlevel(node* root,int k)
{
    if(root==NULL)
    return;
    if(k==1)
    {cout<<root->data<<" ";return;}
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);
    return;
}
void printAllLevels(node* root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {printKthlevel(root,i);cout<<"\n";}
    
    return;
}
void levelOrder(node * root)
{
    queue<node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty())
    {
        node* data=q.front();
        // if(data==NULL)
        // {
        //     cout<<endl;
        //     q.pop();
        //     if(!q.empty())
        //     q.push(NULL);
        // }
        // else{   
        cout<<data->data<<" ";
        q.pop();
        if(data->left!=NULL)
        q.push(data->left);
        if(data->right!=NULL)
        q.push(data->right);
        // }
    }
    return;
}
int count_nodes(node* root)
{
    if(root==NULL)
    return 0;
    int ls=count_nodes(root->left);
    int rs=count_nodes(root->right);
    return ls+rs+1;
}
int sum_of_nodes(node* root)
{
    if(root==NULL)
    return 0;
    return root->data+sum_of_nodes(root->left)+sum_of_nodes(root->right);
}
int diameter(node* root)
{
    if(root==NULL)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    return max(h1+h2,max(diameter(root->left),diameter(root->right)));
}
pair<int,int> diameter_fast(node* root)
{
    pair<int,int> p;
    if(root==NULL)
    {p.first=0;p.second=0;return p;}
    pair<int,int> left=diameter_fast(root->left);   
    pair<int,int> right=diameter_fast(root->right);  
    p.first=max(left.first,right.first)+1;
    p.second=max(left.first+right.first,max(left.second,right.second));
    return p;
}
int replace_sum(node* root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL&&root->right==NULL)
    return root->data;
    int ls=replace_sum(root->left);
    int rs=replace_sum(root->right);
    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
}
bool is_height_balanced(node* root,int& height)
{
    int l=0;int r=0;
    int lh=0;int rh=0;
    if(root==NULL)
    {
        height=0;
        return 1;
    }
    l=is_height_balanced(root->left,lh);
    r=is_height_balanced(root->right,rh);
    height=(max(lh,rh)+1);
    if(abs(lh-rh)>=2)
    return 0;
    else return l&&r;

}
node* build_height_balanced_tree(int* a,int s,int e)
{
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    node* root=new node;
    root->data=a[mid];root->left=NULL;root->right=NULL;
    root->left=build_height_balanced_tree(a,s,mid-1);
    root->right=build_height_balanced_tree(a,mid+1,e);
    return root;
}
vector<int> v;
void right_view(node* root,int lvl)
{
    if(root==NULL)
    return;
    static int max_level=-1;
    if(max_level<lvl)
    {
        v.push_back(root->data);
        max_level=lvl;
    }
    right_view(root->right,lvl+1);
    right_view(root->left,lvl+1);
    return;

}
// lca
class custom{
    public:
    bool has_key_p;
    bool has_key_q;
    node* node;
};
custom* helper(node* root,node* p,node* q)
{
    if(root==NULL) return NULL;
    custom* leftans=helper(root->left,p,q);
    if(leftans!=NULL&&leftans->node!=NULL)return leftans;
    custom* rightans=helper(root->right,p,q);
    if(rightans!=NULL&&rightans->node!=NULL)return rightans;
    custom* result=new custom;
    if(leftans!=NULL&&rightans!=NULL)
    {
    result->node=root;
    result->has_key_p=true;
    result->has_key_q=true;
    return result;
    }
    else if(root->data==p->data)
    {
        result->has_key_p=true;
        result->has_key_q=leftans?leftans->has_key_q:false||rightans?rightans->has_key_q:false;
        if(result->has_key_p&&result->has_key_q)
        result->node=root;
        return result;
    }
    else if(root->data==q->data)
    {
        result->has_key_q=true;
        result->has_key_p=leftans?leftans->has_key_p:false||rightans?rightans->has_key_p:false;
        if(result->has_key_p&&result->has_key_q)
        result->node=root;
        return result;
    }
    else if(leftans) return leftans;
    else if(rightans) return rightans;
    return NULL;

}
node* lca(node*root,node* p,node* q)
{
    custom* result=helper(root,p,q);
    if(result==NULL)
    return NULL;
    return result->node;
}
node* insert_int_bst(node* root,int d)
{
    if(root==NULL)
    {
        node* temmp=new node;
        temmp->data=d;
        temmp->left=temmp->right=NULL;
        return temmp;
    }
    if(root->data>=d)
    root->left=insert_int_bst(root->left,d);
    else root->right=insert_int_bst(root->right,d);
    return root;
}
node* buid_bst()
{
    int d;cin>>d;
    node* root=NULL;
    while(d!=-1){
    root=insert_int_bst(root,d);
    cin>>d;
    }
    return root;

}
bool search(node* root,int k)
{
    if(root==NULL)
    return false;
    if(root->data==k)
    return true;
    if(k<=root->data)
    return search(root->left,k);
    return search(root->right,k);
    
}
bool isBST(node* root,int minV=INT_MIN,int maxV=INT_MAX)
{
    if(root==NULL)
    return true;
    if(root->data>=minV&&root->data<=maxV&&isBST(root->left,minV,root->data)&&isBST(root->right,root->data,maxV))
    return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // node* root=build_tree();
    // print(root);
    // printAllLevels(root);//worst case O(n^2) for skewed binary tree
    // levelOrder(root);
    // cout<<count_nodes(root);
    // cout<<sum_of_nodes(root);
    // cout<<diameter(root);
    // pair<int,int> p=diameter_fast(root);
    // cout<<p.first<<" "<<p.second;
    // replace_sum(root);
    // levelOrder(root);
    // int h=0;
    // if(is_height_balanced(root,h))cout<<"balanced" ;else cout<<"not balanced";
    // int a[]={1,2,3,4,5,6,7};
    // int n=7;
    // node* root=build_height_balanced_tree(a,0,n-1);
    // levelOrder(root);
    // right_view(root,0);
    // for(auto i:v)
    // cout<<i<<" ";
    // node*root=buid_bst();
    // levelOrder(root);
    // int s=7;
    // if(search(root,s)) cout<<"Present";else cout<<"not present";
    // if(isBST) cout<<"YES";else cout<<"Not a BST";

    return 0;   
}