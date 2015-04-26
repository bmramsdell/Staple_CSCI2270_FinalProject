#include "convert.h"
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

void Converter::Converter()
{
	for(int i = 0;i<10;i++){
        hashtable[i]->text = "empty";
        hashtable[i]->next = NULL;
    }
}

void Converter::~Converter(){}

stringLinkedList Converter::ConvertArrToLinkedList(string array, int size)
{
	stringLinkedList *head = new stringLinkedList;
	stringLinkedList *root = new stringLinkedList;
	head->title = array[0];
	root = head;
	for(int i=1; i<size; i++)
	{
		head->next->title = array[i];
		head = head->next;
	}
	cout<<"This is your array"<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<array[i]<<endl;
	}
	cout<<"This is your Linked List"<<endl;
	while(root->next != NULL)
	{
		cout<<root->title<<endl;
		root = root->next;
	}
	return root;
}

string* Converter::ConvertLLToArray(stringLinkedList root)
{
	int count = 0;
	stringLinkedList *temp = new stringLinkedList;
	temp = root;
	while(root->next != NULL)
	{
		count++;
		root = root->next;
	}
	string array[count];
	for(int i=0; i<count; i++)
	{
		array[i] = root->title;
		root = root->next;
	}
	string *pointer = array;
	cout<<"This is your Linked List"<<endl;
	while(temp->next != NULL)
	{
		cout<<temp->title<<endl;
		temp = temp->next;
	}
	cout<<"This is your array"<<endl;
	for(int i=0; i<count; i++)
	{
		cout<<array[i]<<endl;
	}
	return pointer;
}

vector<string> Converter::ConvertLLToVector(stringLinkedList root)
{
	vector<string> vect;
	int count;
	stringLinkedList *temp = new stringLinkedList;
	temp = root;
	while(root->next != NULL)
	{
		count++;
		root = root->next;
	}
	for(int i=0; i<count; i++)
	{
		vect.add(root->title)
		root = root->next;
	}
	cout<<"This is your Linked List"<<endl;
	while(temp->next != NULL)
	{
		cout<<temp->title<<endl;
		temp = temp->next;
	}
	cout<<"This is your vector"<<endl;
	for(int i=0; i<vect.size(); i++)
	{
		cout<<vect[i]<<endl;
	}
	return vect;
}

vector<string> Converter::arrayToVector(string[] str)
{
    vector<string> vec;
    for(int i = 0; i < sizeof(str); i++)
    {
        vec.add(str[i]);
    }
    return vec;
}

string* Converter::vectorToArray(vector<string> vec)
{
    string str[vec.size()] = {};
    for(int i = 0; i < vec.size(); i++)
    {
        str[i] = vec[i];
    }
    string *pointer = str;
    return pointer;
}

stringLinkedList Converter::vectorToLinkedList(vector<string> vec)
{
    stringLinkedList *head = new stringLinkedList;
    stringLinkedList *root = new stringLinkedList;
    head->title = vec[0];
    root = head
    for(int i=1; i<vec.size(); i++)
    {
        head->next->title = vec[i];
        head = head->next;
    }
    return root;
}

void Converter::ArrayToHT(string a[]){
    int sum = 0;
    char letter;
    for(int i = 0; i<sizeof(a);i++){
        bool check = true;
        for(int j = 0; i<a[i].length();i++){
            letter = (char)a[i][j];
            sum = sum + (int)letter;
        }
        sum = sum%10;
        if(hashtable[sum]->text == "empty"){
            hashtable[sum]->text = a[i];
            check = false;
        }
        HT *m = new HT;
        m->text = a[i];
        HT *x = hashtable[sum];
        while(check == true){
            if(x->next == NULL){
                x->next = m;
                check = false;
            }
            x = x->next;
        }
    }

    for(int i = 0;i<10;i++){
        if(hashtable[i]->text != "empty"){
            cout<<"Index["<<i<<"] "<<hashtable[i]->text<<"->";
            HT *x = hashtable[i];
            while(x->next != NULL){
                cout<<x->next->text<<"->";
                x=x->next;
            }
            cout<<endl;
        }
        else{
            cout<<"Index["<<i<<"] Empty"<<endl;
        }
    }
}

string* Converter::HTToArray(){
    int count = 0;
    int arrayCount = 0;
    for(int i = 0;i<10;i++){
        if(hashtable[i]->text != "empty"){
            count += 1;
            HT *x = hashtable[i];
            while(x->next != NULL){
                count += 1;
                x = x->next;
            }
        }
    }
    string array[count];
    for(int i = 0;i<10;i++){
        if(hashtable[i]->text != "empty"){
            array[arrayCount] = hashtable[i]->text;
            arrayCount += 1;
            if(hashtable[i]->next != NULL){
                HT *x = hashtable[i]->next;
                while(x != NULL){
                    array[arrayCount] = x->text;
                    arrayCount += 1;
                    x = x->next;
                }
            }
        }
    }
    for(int i = 0;i<10;i++){
        hashtable[i]->text = "empty";
        hashtable[i]->next = NULL;
    }
    string *pointer = array;
    return pointer;
}