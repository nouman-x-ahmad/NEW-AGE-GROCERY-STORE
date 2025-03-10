# New Age Grocery Store Management System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub last commit](https://img.shields.io/github/last-commit/nouman-x-ahmad/NEW-AGE-GROCERY-STORE)](https://github.com/nouman-x-ahmad/NEW-AGE-GROCERY-STORE/commits/main)


## Overview

Welcome to the **New Age Grocery Store Management System**! This C++ project provides a foundational object-oriented system for managing a grocery store, designed to handle customer, manager, and admin functionalities. It offers features for user registration, login, product catalog management, and basic payment and feedback handling, making it a comprehensive solution for small to medium-sized grocery operations.

This project is a testament to the power of object-oriented programming in creating practical and scalable applications. It demonstrates the use of C++ for building robust systems that can manage complex data and user interactions.

## Features

- **User Management:**
    - Comprehensive user role management including Customer, Manager, and Admin.
    - Secure user registration and login functionalities.
    - Rigorous username, password, and CNIC verification processes.
- **Product Catalog:**
    - Efficient product management for multiple store locations (Islamabad and Rawalpindi).
    - Features to add, search, and display products with ease.
    - Basic inventory management to keep track of stock.
- **Payment and Feedback:**
    - Flexible payment options including e-transfer and bank transfer.
    - Integrated feedback system to gather customer insights.
- **Object-Oriented Design:**
    - Leverages inheritance and polymorphism for efficient code reuse and scalability.
    - Modular design with well-organized header and source files for easy maintenance.
- **File Handling:**
    - Robust data persistence using binary files, ensuring data integrity and reliability.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Windows

### Compilation

1. Clone the repository:
   ```bash
   !git clone https://github.com/nouman-x-ahmad/NEW-AGE-GROCERY-STORE.git
   cd NEW-AGE-GROCERY-STORE
2. Compile the source files:
   ```bash
   g++ Source.cpp -o grocery
3. Run the Executable:
   ```bash
   ./grocery

### Project Structure:
```
NEW-AGE-GROCERY-STORE/
├── Header.h
├── Source.cpp
├── admin.h
├── catalog.h
├── customer.h
├── manager.h
├── payment_feedb.h
├── user.h
├── admin_sData
├── customer_sData
├── islamabad_sData
└── README.md
```

### File Descriptions
- **Header.h**: Contains class declarations and necessary includes, serving as the blueprint for the project's structure.
- **Source.cpp**: The heart of the application, containing the main implementation of the system functionalities.
- **admin.h, catalog.h, customer.h, manager.h, payment_feedb.h, user.h**: Header files for respective classes, each encapsulating specific functionalities.
- **admin_sData, customer_sData, islamabad_sData**: Binary files for data persistence, ensuring data is securely stored.
- **README.md**: This file, providing an overview and guide to the project.

## UML Diagrams:
### Class Diagram:

```mermaid
classDiagram
    class User {
        - char user_cnic[14]
        - char user_passw[20]
        - char user_gend[1]
        - char user_phone[15]
        - char user_addres[100]
        - char user_info[100]
        - char user_email[20]
        - char user_name[15]
        - int age
        + User()
        + void setuser_cnic(string)
        + void setuser_passw(string)
        + void setuser_gend(char)
        + void setuser_phone(string)
        + void setuser_address(string)
        + void setuser_age(int)
        + void setuser_email(string)
        + void setuser_name(string)
        + void updateuser_address(string)
        + void updateuser_passw(string)
        + char* getuser_cnic()
        + char* getuser_passw()
        + char* getuser_gend()
        + char* getuser_phone()
        + char* getuser_address()
        + char* getuser_name()
        + int getuser_age()
        + char* getuser_email()
        + virtual bool Login()
        + virtual void Registration()
    }
    class Customer {
        + bool Login()
        + void Registration()
        + void UsernameVerification(Customer*)
        + void PasswordValidation(Customer*)
        + void CnicVerification(Customer*)
        + void Savecustdata(Customer, string)
    }
    class Manager {
        + bool Login()
    }
    class Admin {
        + bool Login()
        + void Registration()
        + void Saveadmdata(Admin, string)
        + void UsernameVerification(Admin*)
        + void PasswordValidation(Admin*)
    }
    class Newgrocery {
        + void MainMenu()
        + void Showinventory(Manager, int)
        + void Viewcatalogue(char*)
        + void SubMenu(int)
    }
    class productcat {
        - char productname[20]
        - int prodprice
        - int idno
        - int price
        + void setprice(int)
        + int getprice()
        + void setproductname(string)
        + void setprodprice(int)
        + void setidno(int)
        + char* getproductname()
        + int getprodprice()
        + int getidno()
        + virtual void addproduct()
        + virtual void editproduct()
    }
    class islamabad {
        + void addproduct()
        + void Saveproddata(islamabad, string)
        + void DisplayProduct()
        + void prod()
    }
    class rawalpindi {
        + void addproduct()
        + void Saveproddata(rawalpindi, string)
        + void DisplayProduct()
        + void prod()
    }
    class payment {
        - int money
        + static void setmoney(int)
        + int getmoney()
        + void e_transfer()
        + void banktransfer()
    }
    class feedback {
        - char cmnt[100]
        + void setcmnt()
        + char* getcmnt()
        + void tweet()
    }

    User <|-- Customer
    User <|-- Manager
    User <|-- Admin
    productcat <|-- islamabad
    productcat <|-- rawalpindi

```
---
### Sequence Diagram: 
```mermaid
sequenceDiagram
    participant MainMenu
    participant Customer
    participant Admin
    participant Manager
    participant SubMenu
    participant Islamabad
    participant Rawalpindi
    participant Payment
    participant Feedback

    MainMenu->>Customer: Registration/Login
    MainMenu->>Admin: Manager Registration/Login
    MainMenu->>Manager: Login
    Customer->>SubMenu: Customer Options
    Admin->>SubMenu: Admin Options
    Manager->>SubMenu: Manager Options
    SubMenu->>Islamabad: Add/Display Products
    SubMenu->>Rawalpindi: Add/Display Products
    SubMenu->>Payment: Process Payment
    SubMenu->>Feedback: Collect Feedback

```

This sequence diagram illustrates the flow of interactions between different components of the system. It shows how the MainMenu interacts with Customer, Admin, and Manager for registration and login. Then, based on user roles, the SubMenu is invoked, which further interacts with Islamabad and Rawalpindi classes for product management, Payment for processing payments, and Feedback for collecting customer feedback.

This diagram provides a visual representation of the system's dynamic behavior, making it easier to understand how different parts of the application interact with each other.

---

## License:
*License
This project is licensed under the MIT License - see the LICENSE file for details.*
