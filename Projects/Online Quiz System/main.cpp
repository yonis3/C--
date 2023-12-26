#include "userauthentication.h"
#include <iostream>

int main() {
  UserAuthentication auth;

  // Register a new user
  std::string username = "john";
  std::string password = "password123";
  auth.registerUser(username, password);

  // Login with correct password
  if (auth.login(username, password)) {
    std::cout << "Login successful!" << std::endl;
  } else {
    std::cout << "Invalid credentials." << std::endl;
  }

  // Login with incorrect password
  if (auth.login(username, "wrongpass")) {
    std::cout << "Login successful!" << std::endl;
  } else {
    std::cout << "Invalid credentials." << std::endl;
  }

  return 0;
}
