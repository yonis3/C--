#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

struct User {
  std::string username;
  std::string encryptedPassword;
  std::string salt;  // New member for storing the salt
};

class UserAuthentication {
public:
  UserAuthentication();
  ~UserAuthentication();

  void registerUser(const std::string& username, const std::string& password);
  bool login(const std::string& username, const std::string& password);

private:
  std::string encryptPassword(const std::string& password, const std::string& salt);
  void saveUserData();
  void loadUserData();
  std::string generateSalt();  // New function to generate a random salt

  std::vector<User> registeredUsers;
};

#endif // USERAUTHENTICATION_H
