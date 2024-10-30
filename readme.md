# Social Network Friend Recommendation System

This project, developed by **Nishka** and **Poorvi**, is a basic social network simulation where users can add friends, view their friends, and receive friend recommendations based on mutual connections. The system is implemented in C++ and uses arrays to manage users and friendships.

## Features

1. **Add User**  
   Users can be added to the social network by entering a unique username. Each user can add friends or receive friend recommendations. The system currently supports up to 10 users (this limit can be modified in the code).

2. **Add Friendship**  
   Users can connect with each other by establishing friendships. When a friendship is added, both users are listed as each other’s friends.

3. **Display Friends**  
   For any given user, you can view a list of their current friends. This feature helps check connections and see friend lists easily.

4. **Friend Recommendations**  
   Users can receive friend recommendations based on mutual friends. If two users share one or more common friends but are not directly connected, they will be suggested as potential friends. When a recommendation appears, users can choose to accept or reject it.

5. **Clear All Data**  
   This feature allows the user to reset the entire social network, including all users and friendships. This is useful for a fresh start or for testing.

6. **Exit**  
   Exits the program safely.

---

## Example Session

```plaintext
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
