/*************************************************************************
** Author : Journey Timmermans
** Program : hw5, q1
** Date Created : April 14, 2024
** Date Last Modified : April 15, 2024
** Problem:
Read a text file with presidents and states and store the
 information
*************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "MyList.h"

using namespace std;

//Definition for Profile struct with name and state
struct Profile {
    std::string fullname;
    std::string state;

    //Overloading == and !=
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};

//Overloading << operator
std::ostream& operator<< (std::ostream &out, Profile &user) {
    out << user.fullname<<"--" <<user.state;
    return out;
}

//Function to search in a deque
bool searchDeque(deque<Profile>& pq, Profile& president) {
    for (const auto& profile : pq) {
        if (profile == president) {
            president = profile;
            return true;
        }
    }
    return false;
}


int main() {
    MyList<Profile> pMyList;
    deque<Profile> pDeque;
    Profile temp;
    string line;

    //Opening file
    ifstream file("presidentsWstates.txt");
    MyList<Profile> pMyList;

    //Checking if file is open
    if (file.is_open()) {

        //Reading and inserting info into profile
        while (getline(file,line)) {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertAtHead(temp); //Inserts into Mylist
            pDeque.push_front(temp); // Push into deque
        }
        file.close();
    }
    else {
        std::cout << "Error opening file" << endl;
    }

    cout<<"Printing queue members by using pop and front***********************"<<endl;
    while (!pMyList.isEmpty()) {
        Profile frontProfile = pMyList.deleteHead();
        cout << frontProfile << endl;
    }

    cout<<"Printing deque members with iterator***********************"<<endl;
    for (deque<Profile>::iterator it = pDeque.begin(); it != pDeque.end(); ++it) {
        cout << *it << endl;
    }

    cout << "Printing deque members with indices***********************" << endl;
    for (size_t i = 0; i < pDeque.size(); ++i) {
        cout << pDeque[i] << endl;
    }

    //Searching for a profile
    temp.fullname = "Gerald R. Ford";
    if (searchDeque(pDeque, temp)) {
        cout << "Found: " << temp << endl;
    } else {
        cout << "Not found: " << temp << endl;
    }

    return 0;
}