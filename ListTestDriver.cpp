/*
 * ListTestDriver.cpp
 *
 * Class Description: Testing List works or not.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - there is no order of storing data in the list
 *
 * Author: Yewon Park
 */
 

#include "List.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    //creat an List to test constructor
    List Ls;
    
    //check the empty list
    cout << "=====Check the list if it is empty at first=====" << endl << endl;
    Ls.printList();
    
    //creat Member constructors
    Member p1("Yewon Park","111-222-3333", "yewon777@gmail.com", "1234 5678 9012 3456");
    Member p2("Yetwo Kim", "123-456-7899", "yetwo2018@naver.com", "4567 3456 1235 7890");
    Member p3("YeYe Xiao", "345-667-8976", "howdy8282@hanmail.net", "1234 2345 3456 5678"); // Wrong phone number
    Member p4("778-667-5546"); //Phone number only
    
    
    //insert members in the list
    cout << "=====Insert members in the list=====" << endl;
    if(Ls.insert(p1) && Ls.insert(p2) && Ls.insert(p3) && Ls.insert(p4))
    	cout << "All members have been inserted successfully" << endl << endl;
    
    //Print to check the list
    cout << "=====Print the List to check if all members are inserted=====" << endl;
    Ls.printList();
    cout << endl;
    
    //remove an element from the list
    cout << "=====Remove p2 and p3 from the list=====" << endl;
    if(Ls.remove(p2) && Ls.remove(p3))
    	cout << "p2 and p3 have been removed from the list" << endl << endl;
    
    
    //Print to check the list, is the element got removed
    cout << "=====Print to check if the element got removed=====" << endl;
    Ls.printList();
    cout << endl;
    
    //check the getElementCount()
    cout << "=====Check how many elements are in the List=====" << endl;
    cout<<"there are "<< Ls.getElementCount() <<" number of member in FitStudio club "<<endl << endl;
    
    //creat p5 to check Member()
    Member p5;
    Ls.insert(p5);
    
    //print
    cout << "=====Print the list after inserting p5=====" << endl;
    Ls.printList();
    cout << endl;
    
    //check the search function
    Member* Mem = Ls.search(p1);
    cout << "=====Search p1 in the list=====" << endl;
    cout << Mem->getName() << ", " << Mem->getPhone() << ", " << Mem->getEmail() << ", " << Mem->getCreditCard() << endl << endl;
    
    //remove all element from the list - removeAll()
    Ls.removeAll();
    
    //print
    cout << "=====Print the list after removing all elements=====" << endl;
    Ls.printList();
    cout << endl;
    
   //Insert elements again
    cout << "=====Insert members in the list again=====" << endl;
    if(Ls.insert(p1) && Ls.insert(p2) && Ls.insert(p3) && Ls.insert(p4))
    	cout << "All members have been inserted successfully" << endl << endl;
    
   
    //print
    cout << "=====Print the list to check if all members are inserted or not=====" << endl;
    Ls.printList();
    
    
    return 0;
}
