# **ATM System with Account Management**

**Description**  
This is a command-line ATM system built in C++ that allows users to manage their bank accounts securely and efficiently. It includes features like account balance inquiries, deposits, withdrawals, transaction history, and PIN-based authentication. The system supports multiple users and enforces daily withdrawal limits for enhanced security.

---

## **Table of Contents**

1. [Features](#features)  
2. [How It Works](#how-it-works)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements)  
6. [License](#license)  

---

## **Features**

### **1. Account Management**
- Multiple account types (e.g., Savings, Checking).  
- Display account type upon login.

### **2. Enhanced Security**
- PIN-based authentication.  
- Account lock after three consecutive failed PIN attempts.  
- Ability to change PIN.

### **3. Deposit and Withdrawal**
- Deposit money with validation for positive amounts.  
- Withdraw money with:  
  - Validation for sufficient balance.  
  - Daily withdrawal limit enforcement ($1000).  
  - Notification when nearing the daily withdrawal limit (80% threshold).  

### **4. Balance Inquiry**
- View current account balance.

### **5. Transaction History**
- View transaction history (deposits and withdrawals).  
- Export transaction history to a file.

### **6. Daily Withdrawal Limit Management**
- Prevent withdrawals beyond the daily limit.  
- Notify users when approaching the limit.

### **7. User-Friendly Interface**
- Intuitive menu system with numbered options.  
- Clear error messages and feedback for invalid inputs.

### **8. Multi-User Support**
- Supports multiple users with:  
  - Unique account numbers.  
  - Separate PINs.  
  - Individual balances and transaction histories.

### **9. Extensibility**
- Easily extensible to add new features like:  
  - Admin controls for managing accounts.  
  - Interest calculations.  
  - Loan management.

### **10. Portability**
- Minimal dependencies ensure compatibility across platforms.

---

## **How It Works**

1. **Authentication**:  
   - Users log in with their account number and PIN.  
   - After three failed attempts, the account locks automatically for security.  

2. **Menu Options**:  
   - **Check Balance**: Displays the current account balance.  
   - **Deposit Money**: Allows users to deposit funds with validation for positive amounts.  
   - **Withdraw Money**: Ensures sufficient balance and enforces a daily withdrawal limit of $1000.  
   - **View Transaction History**: Shows all deposits and withdrawals.  
   - **Change PIN**: Provides an option to change the account PIN securely.  
   - **Export Transaction History**: Saves the transaction history to a specified file.  
   - **Exit**: Ends the session.  

3. **Daily Withdrawal Limit**:  
   - Tracks total withdrawals and prevents exceeding the $1000 daily limit.  
   - Notifies users when nearing 80% of the limit.

4. **Multi-User Functionality**:  
   - Supports multiple users with separate accounts, balances, and histories.  

---

## **Installation**

Follow these steps to set up and run the ATM system locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd ATM-System
   ```

2. Compile the program:
   ```bash
   g++ -o atm atm.cpp
   ```

3. Run the program:
   ```bash
   ./atm
   ```

---

## **Technologies Used**

- **Language**: C++  

---

## **Future Enhancements**

- Add admin controls for managing user accounts.  
- Implement interest calculations for savings accounts.  
- Add loan management features.  
- Integrate with a database for persistent storage of user data and transaction histories.  
- Create a graphical user interface (GUI) for better usability.  

---

## **License**

This project is licensed under the MIT License.  

---
