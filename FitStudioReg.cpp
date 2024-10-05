/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each phone nunber is a search key
 *
 * Author: AL, Yewon Park
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;

//Description: Add a new member variable to the list. 
//		Each person's phone number is a search key
//		If the person who want to join has already joined, then tell them "You have already joined" 
//		If the person has not joined, then the function allow them to type their Name, Email, and Credit card Number

void add(List* ppl)
{
	string num, na, em, ca;
	cout << "Enter your phone number: ";
	cin >> num;
	Member mb = Member(num);
	ppl -> search(mb);
	if(ppl-> search(mb) == NULL)
	{
		cout << "=====Welcome=====" << endl;
		cout << "Enter your Name: ";
		getline(cin>> ws, na);
		
		cout << "Enter your Email: ";
		getline(cin>> ws, em);
		
		cout << "Enter your credit card number: ";
		getline(cin>> ws, ca);
		
		
		Member newUser(na, num, em, ca);
		ppl->insert(newUser);
		
		cout << "You have joined! Thank you!" << endl;
	}
		
	else
	cout << "You have already joined" << endl;
}
 
//Description: Remove people's information
//		Phone numbers are search keys  
void remove(List *ppl)
{
	string num;
	cout << "Enter your phone number: ";
	cin >> num;
	Member mb = Member(num);
	if(ppl -> remove(mb))
		cout << "Removed" << endl;
	else
		cout << "Failed" << endl;
}

//Description: Search people's information
//		Phone numbers are search keys
//		If the function can search a person's phone number, then It shows the person's information
void search(List *ppl)
{
	string num;
	cout << "Enter your phone number: ";
	cin >> num;
	Member mb = Member(num);
	if(ppl->search(mb) == NULL)
		cout << "We can't find it" << endl;
		
	else
	{
		cout << "We found it" << endl;
		cout << "=====Your Information====="<< endl;
		cout << *(ppl->search(mb));
	}
}

//Description: People modify their Name, Credit card number, Email
//		People's phone numbers are search keys
//		After finishing modifying user's information, the function shows the modified information
void modify(List *ppl)
{
	int num;
	bool done = false;
	string numm;
	cout << "Enter your phone number: ";
	cin >> numm;
	Member m(numm);
	Member * mb = ppl->search(m);
	if(mb == NULL)
		cout << "We can't find it" << endl;

	else
	{
		
		while (not done)
		{
			string na;
			cout << "----Which one you want to change?----" << endl;
			cout << "1. Name" << endl;
			cout << "2. Credit card Number" << endl;
			cout << "3. Email" << endl;
			cout << "4. Exit" << endl;
			cin >> num;
		
			switch(num)
			{
				case 1:
					cout << "Type your new Name" << endl;
					getline(cin>> ws, na);
					mb->setName(na);
					cout << "Your name has changed" << endl;
					break;
				case 2:
					cout << "Type your credit card number" << endl;
					getline(cin>> ws, na);
					mb->setCreditCard(na);
					cout << "Your credit card number has changed" << endl;
					break;
				case 3:
					cout << "Type your new Email" << endl;
					getline(cin>> ws, na);
					mb->setEmail(na);
					cout<< "Your Email has changed" << endl;
					break;
				case 4:
					cout << "=====Your information has been modified====="<< endl;
					cout << *mb;
					done = true;
					break;
				default: cout << "Type the correct number please" << endl;
			}
		}
		
		
	}
	
		
}

//Description: print all members in the List
void print(List *ppl){
	if(ppl->getElementCount() == 0)
		cout << "Empty" << endl;
	else
		ppl->printList();
	
}
int main() {

    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		switch(input) {
            case 'a': add(Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}

