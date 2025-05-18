#  Bank Account Manager  #

A terminal-based C++ program that simulates a simple banking system with user account management, password security, and persistent file storage.

Built entirely in C++.
**object-oriented design**, **file I/O**, **dynamic memory management**, and **input validation** and other real-world software development skills.



## Key Features ##

- **Create and manage user accounts**
- **Secure login system** with password verification
- **Deposit and withdraw money** after authentication
- **Persistent storage** using file I/O (`ofstream`/`ifstream`)
- **Auto-save on exit** so account data is never lost
- **Input validation** to prevent crashes and handle bad input
- Built using **OOP principles** (Account class w/ encapsulation)



## Skills Demonstrated ##

| Skill | Description |
|-------|-------------|
| **Object-Oriented Programming (OOP)** | Defined a modular `Account` class with private members and public methods |
| **File Handling (I/O)** | Used `fstream` to read/write account data to a `.txt` file |
| **Multi-file Project Design** | Separated logic into `main.cpp`, `Account.cpp`, and `Account.h` for organization |
| **User Authentication** | Implemented ID + password login and access control |
| **Data Structures** | Used `vector<Account>` to manage multiple dynamic accounts |
| **Input Validation** | Caught invalid user inputs using `cin.fail()`, `cin.ignore()`, and loop handling |
| **State Management** | Handled logged-in vs. not-logged-in states with conditional menus |

---

## File Structure ##

```plaintext
BankAccountManager/
├── main.cpp        # Handles user interface and core program loop
├── Account.cpp     # Implements Account class methods
├── Account.h       # Declares the Account class
├── accounts.txt    # Auto-saved user account data (generated at runtime)
├── README.md       # You're here!
