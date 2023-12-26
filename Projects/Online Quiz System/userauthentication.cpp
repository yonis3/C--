#include "userauthentication.h"

// Simple hash function
std::string hashPassword(const std::string& password) {
  std::hash<std::string> hasher;
  return std::to_string(hasher(password));
}

UserAuthentication::UserAuthentication() {
  loadUserData();
}

UserAuthentication::~UserAuthentication() {
  saveUserData();
}

void UserAuthentication::registerUser(const std::string& username, const std::string& password) {
  // Encrypt password
  std::string salt = generateSalt();  // Add a function to generate a random salt
  std::string encrypted = encryptPassword(password, salt);

  // Create new user object
  User newUser;
  newUser.username = username;
  newUser.encryptedPassword = encrypted;
  newUser.salt = salt;  // Set the salt

  // Add to registered users
  registeredUsers.push_back(newUser);

  // Save updated data
  saveUserData();
}

bool UserAuthentication::login(const std::string& username, const std::string& password) {
  // Find user by username
  auto it = std::find_if(registeredUsers.begin(), registeredUsers.end(),
                         [&](const User& u) { return u.username == username; });

  if (it == registeredUsers.end()) {
    // User not found
    std::cout << "User not found." << std::endl;
    return false;
  }

  // Check if entered password matches the stored encrypted password
  std::string enteredPasswordHash = encryptPassword(password, it->salt);
  std::cout << "Entered Password Hash: " << enteredPasswordHash << std::endl;
  std::cout << "Stored Password Hash : " << it->encryptedPassword << std::endl;

  if (it->encryptedPassword == enteredPasswordHash) {
    return true;
  } else {
    return false;
  }
}

std::string UserAuthentication::encryptPassword(const std::string& password, const std::string& salt) {
  return hashPassword(salt + password);
}

void UserAuthentication::saveUserData() {
  // Open output file
  std::ofstream outfile("users.dat");

  // Write user data
  for (const auto& user : registeredUsers) {
    outfile << user.username << "\n";
    outfile << user.encryptedPassword << "\n";
    outfile << user.salt << "\n";  // Save the salt
  }

  // Close file
  outfile.close();
}

void UserAuthentication::loadUserData() {
  // Open input file
  std::ifstream infile("users.dat");

  // Read and store user data
  while (infile) {
    std::string username, encryptedPassword, salt;
    std::getline(infile, username);
    std::getline(infile, encryptedPassword);
    std::getline(infile, salt);  // Read the salt

    User user;
    user.username = username;
    user.encryptedPassword = encryptedPassword;
    user.salt = salt;
    registeredUsers.push_back(user);
  }

  // Close file
  infile.close();
}

std::string UserAuthentication::generateSalt() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis('0', 'z');  // ASCII range from '0' to 'z'

  std::string salt;
  for (int i = 0; i < 8; ++i) {
    salt += static_cast<char>(dis(gen));
  }

  return salt;
}
