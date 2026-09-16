Bank & Currency Management System
A comprehensive banking and currency exchange management system built using advanced Object-Oriented Programming (OOP) concepts and an interconnected Console User Interface (Console UI). This project provides a secure, efficient administration dashboard for managing clients, financial transactions, users, and currency exchange rates.

🌟 Overview
The project is a multi-screen banking administration platform composed of several modular subsystems. It features strict separation of concerns across screen handlers, fine-grained user permission controls, and real-time login audit logging.

🚀 Features & Modules
1. Main Dashboard & Client Management

View Client List: Displays detailed records of all registered clients. 
Add New Client: Registers new client accounts into the system.  
Update & Delete Clients: Modifies existing client profiles or removes them permanently.  
Find Client: Direct lookup functionality to search for specific client details.  

2. Financial Transactions Management
Core Transactions: Handles deposit, withdrawal, and inter-account money transfer operations.  
Total Balances: Generates aggregate financial reports and tracks overall account balances.

3. User & Access Management
Permission Control: Validates access rights before granting entry to administrative modules.  
User Operations: Supports creating new users, editing permissions, deleting accounts, and querying user details. 


4. Security & Authentication System
Secure Login: Features a failed attempt counter (locks out after 3 failed attempts) to prevent unauthorized access.  
Login Register Log: An audit screen for administrators to inspect full login histories (Timestamp, Username, Password, and Permission bitmasks).

5. Currency Exchange Subsystem
List Currencies: Displays available currencies along with their current exchange rates.  
Find Currency: Searches for specific currency exchange rates.  
Update Rates: Enables real-time modification of currency conversion rates.  
Currency Calculator: Converts monetary amounts between different currencies based on live system rates.  

🏗 System Architecture      
Subsystem / Module                  Primary Responsibility
Main Screen                         Central navigation hub connecting all core modules.
Login Screen                        System entry point enforcing user authentication and failed attempt limits.
Login Register                      Security audit log tracking user sessions with timestamps.
Manage Users                        User access management and permission assignment.
Currency Exchange                   Standalone module managing currency conversions and rate updates.

🔄 System Workflow
Authentication: The application launches at the Login Screen to authenticate user credentials.  
Audit Logging: Upon successful verification, the session is recorded in the Login Register log, and access to the Main Screen is granted.  Navigation: The Main Menu routes administrators to Client Operations, Transactions, User Management, or Currency Exchange.  
Access Control: Access rights are verified dynamically; users without specific administrative permissions are restricted from sensitive screens.  Session Termination: Users can log out at any time to return to the secure Login Screen. 