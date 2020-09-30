#include<bits/stdc++.h>
using namespace std;

class Trie{
	public:
		Trie* child[26];
		bool eos;
};


Trie* newNode()
{
	Trie* temp=new Trie;
	temp->eos=false;
	for(int i=0;i<26;i++)
	temp->child[i]=NULL;

	return temp;
}

void insert(Trie* root,string s)
{
	Trie* cur=root;

	for(int i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!cur->child[index])
		cur->child[index]=newNode();
		
		cur=cur->child[index];
		

	}
	cur->eos=true;
}

int countChildren(Trie* root,int* index)
{
	int c=0;
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL) 
		{
		c++;
		*index=i;
		}
	}

	return c;
}
//solve for longest common prefix
string solve(Trie* root)
{
	Trie* cur=root;
	int index;
	string s;

	while(countChildren(cur,&index)==1&&cur->eos==false)
	{
		cur=cur->child[index];
		s.push_back('a'+index);
	}
		
	return s;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	Trie* root=newNode();
 	string s[]={"hello","heat","heater"};
	
	for(auto i:s)
	insert(root,i);

	string ans=solve(root);
	cout<<ans.length()<<"\n"<<ans;
	

    return 0;
}