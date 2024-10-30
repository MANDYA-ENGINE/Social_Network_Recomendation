#include <iostream>
#include <string>              // Loaded Libraries.
     
using namespace std;           //  Using namespace for convenience.

const int MAX_USERS = 10;      // No of Users is Customisable , gives Flexibility.
const int MAX_FRIENDS = 10; 

    struct User {                    // A function(Structure) to create a User which in turn holds no of friends in a string and count of friends 
        string name;   
        string friends[MAX_FRIENDS]; // string which which holds the names of friends
        int friendCount;             // count of friends
    };

    User users[MAX_USERS];           // Array of users , space allocated to max users ensuring there is no memory leak  
    int userCount = 0;               // usercount initialised to 0
    

    // IMP: void function used 
    void addUser(string name)               //void function to add user
    {
        if(userCount < MAX_USERS)           // checking whether the username is less than the max_users 
        {
           users[userCount].name = name;    // first index(0) name is updated to first user 
           users[userCount].friendCount = 0;// the ne user has no friends initially 
           userCount++;                     // now the usercount is incremented by 1 so when the function runs again for next person it will run for second index (1)
        }
    
        else
        {
            cout << "Maximum users reached.\n";
        }
    }
    

    int findUserIndex(string name) // IMP: int function returns a int value , here returns the index of user 
    {
        for (int i = 0; i < userCount; i++) 
        {
            if (users[i].name == name)
               return i;
        }

        return -1;

    }

    // void function to add friendship strictly between two users .
    void addFriendship(string user1, string user2) {

        int i1 = findUserIndex(user1);   // finding and storing index of user1 in i1 variable
        int i2 = findUserIndex(user2);   // finding and storing index of user2 in i2 variable
    
        if (i1 == -1 || i2 == -1)        // To ensure that both users exist
        {
           cout << "User not found.\n";  // this will be shown if one of the user is not found 
           return;
        }
    
        if (users[i1].friendCount < MAX_FRIENDS && users[i2].friendCount < MAX_FRIENDS) // Confirming that both users have space left to add friendship
        {
            users[i1].friends[users[i1].friendCount++] = user2;   //  adding user2 to user1's friend list parallely increasing the user1's friendcount by one each time 
            users[i2].friends[users[i2].friendCount++] = user1;   //   adding user1 to user2's friend list parallely increasing the user2's friendcount by one each time
        } 

        else { cout << "Maximum friends reached for one of the users.\n"; } //  if one of the user has reached max_friends then this will be shown
        
    }
    
    void displayFriends(string name)     // function to display friends list of one user at a time
    {
        int index = findUserIndex(name); // finding the index of user in users array
    
        if (index == -1) {
            cout << "User not found.\n"; // making sure user exists 
            return;
        }
    
        cout << name << "'s friends: ";  // displaying the name of user whose friends list is being displayed

        for (int i = 0; i < users[index].friendCount; i++) // to print out all friends list at once 
        {
          cout << users[index].friends[i];
          if (i < users[index].friendCount - 1) cout << ", ";
        }

        cout << endl;
    }
    
    // The below function to check whether the user is friend with another user or not is the important function
    // and heart of the whole program 
    bool areFriends(string user1, string user2)            //  function to check if two users are friends or not
    { 
        int index = findUserIndex(user1);                  //  finding the index of user1 in users array
      
        if (index == -1) return false;                     //   if user1 is not found then return false
    
        for (int i = 0; i < users[index].friendCount; i++) //  to check if user2 is in user1's friend list  
        {   
            if (users[index].friends[i] == user2)          //   if user2 is found in user1's friend list then return true
               return true;
        }
        return false;                                      //   if user2 is not found in user1's friend list then return false
    }
// below is like the brain of the whole program where all the functions are being called and the recommendation
void recommendFriends(string name) {
    int index = findUserIndex(name);
    
    if (index == -1) {
        cout << "User not found.\n";
        return;
    }
    
    cout << "Friend recommendations for " << name << ":\n";
    for (int i = 0; i < userCount; i++) {
        if (i == index) continue; // Skip current user (shouldnt be included as friend so)
        
        if (!areFriends(name, users[i].name)) { // Recommend if not already a friend
            int mutualFriends = 0;
            
            for (int j = 0; j < users[i].friendCount; j++) {
                if (areFriends(name, users[i].friends[j])) mutualFriends++;
            }
            
            if (mutualFriends > 0) {
                cout << users[i].name << " (" << mutualFriends << " mutual friends)\n";
                cout << "Do you want to add " << users[i].name << " as a friend? (y/n): ";
                char response;
                cin >> response;
                if (response == 'y' || response == 'Y') {
                    addFriendship(name, users[i].name);
                    cout << users[i].name << " added as a friend.\n";
                } else {
                    cout << "Friend request ignored.\n";
                }
            }
        }
    }
}

void clearData() {
    for (int i = 0; i < userCount; i++) {
        users[i].name = "";
        users[i].friendCount = 0;
        for (int j = 0; j < MAX_FRIENDS; j++) {
            users[i].friends[j] = "";
        }
    }
    userCount = 0;
    cout << "All user and friend data cleared.\n";
}

void menu() {
    int choice;
    string name, friendName;
    
    while (true) {
        cout << "\nSocial Network Friend Recommendation System\n";
        cout << "1. Add User\n";
        cout << "2. Add Friendship\n";
        cout << "3. Display Friends\n";
        cout << "4. Recommend Friends\n";
        cout << "5. Exit\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter user name: ";
                cin >> name;
                addUser(name);
                break;
            case 2:
                cout << "Enter first user's name: ";
                cin >> name;
                cout << "Enter second user's name: ";
                cin >> friendName;
                addFriendship(name, friendName);
                break;
            case 3:
                cout << "Enter user name: ";
                cin >> name;
                displayFriends(name);
                break;
            case 4:
                cout << "Enter user name: ";
                cin >> name;
                recommendFriends(name);
                break;
             case 5:
                clearData();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}