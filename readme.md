Social Network Friend Recommendation System

This project made by Nishka and Poorvi is a basic social network system where users can add friends, view their friends and get friend recommendations based on mutual connections. The system is implemented in C++ and uses arrays to manage users and friendships.

Features

 1. Add User:
Users can be added to the social network by entering a unique username. Each user can then add friends or receive friend recommendations. The system currently supports up to 10 users (modifiable in the code).
 2. Add Friendship:
Users can connect with each other by adding friendships. When a friendship is added, both users are listed as each other’s friends.
 3. Display Friends:
For any given user, you can view a list of their current friends. This is helpful to see connections and check friend lists easily.
 4. Friend Recommendations:
Users can receive friend recommendations based on mutual friends. If two users share one or more common friends but are not yet connected, they will be suggested to each other as potential friends. When a recommendation is shown, users have the option to accept or reject it.
 5. Clear All Data:
This feature allows the user to clear all data in the social network, including all users and their friend lists. This can be helpful for resetting the system for a fresh start or for testing purposes.
 6. Exit:
This exits the program safely.

Here’s an example session
Social Network Friend Recommendation System

1. Add User
2. Add Friendship
3. Display Friends
4. Recommend Friends
5. Clear All Data
6. Exit
Choose an option: 1

Enter user name: Poorvi
User added.

Choose an option: 1

Enter user name: Nishka
User added.

Choose an option: 1

Enter user name: Hrushitha
User added.

Choose an option: 2

Enter first user's name: Poorvi
Enter second user's name: Nishka
Friendship added between Poorvi and Nishka.

Choose an option: 2

Enter first user's name: Poorvi
Enter second user's name: Hrushitha
Friendship added between Poorvi and Hrushitha.

Choose an option: 3

Enter user name: Poorvi
Poorvi's friends: Nishka, Hrushitha

Choose an option: 4

Enter user name: Nishka
Friend recommendations for Nishka:
Hrushitha (1 mutual friend)
Do you want to add Hrushitha as a friend? (y/n): y
Hrushitha added as a friend.

Choose an option: 3

Enter user name: Nishka
Nishka's friends: Poorvi, Hrushitha

Choose an option: 5
All user and friend data cleared.

Choose an option: 6
Program exited.

Code Structure

The project consists of the following main sections:

 1. User Structure:
The User structure holds essential details of each user, including:
 • name: The name of the user.
 • friends: An array to store the names of the user’s friends.
 • friendCount: Tracks the number of friends each user has.
 2. Functions:
 • addUser: Adds a new user to the network.
 • findUserIndex: Searches for a user by name and returns their index in the users array.
 • addFriendship: Establishes a friendship between two users by adding each other to their friends list.
 • displayFriends: Displays a list of friends for a given user.
 • areFriends: Checks if two users are already friends.
 • recommendFriends: Recommends friends to a user based on mutual friends.
 • clearData: Clears all user and friend data, resetting the network.
 • menu: Provides an interactive menu for users to navigate through features.
 3. Main Program:
The main function initializes the program by calling the menu function, which runs an interactive loop allowing users to choose different options.
