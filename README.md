# 📒 Address Book Management System in C

## 📌 Project Overview

This project is a **console-based Address Book Management System** developed using **C programming**.

The application allows users to manage contact information such as **Name, Phone Number, and Mail ID**. Contacts can be created, searched, edited, deleted, and displayed in a sorted format.

The contact information is stored in a **CSV file**, allowing the data to be loaded when the application starts and saved when the application exits.

---

## 🎯 Features

- ➕ Create a new contact
- 🔍 Search contacts by:
  - Name
  - Phone Number
  - Mail ID
- ✏️ Edit existing contact details
- 🗑️ Delete contacts
- 📋 List all saved contacts
- 🔤 Display contacts sorted by name
- 💾 Save contacts to a CSV file
- 📂 Load contacts automatically from CSV file
- ✅ Name validation
- ✅ Phone number validation
- ✅ Mail ID validation
- 🚫 Prevent duplicate phone numbers
- 🚫 Prevent duplicate mail IDs

---

## 🖥️ Address Book Menu

    --------------------------------------
          ADDRESS BOOK MENU
    --------------------------------------

    1) Create contact
    2) Search contact
    3) Edit contact
    4) Delete contact
    5) List all contacts
    6) Save and Exit

---

## ⚙️ Functionalities

### 1. Create Contact

Users can add a new contact by entering:

- Name
- Phone Number
- Mail ID

The application validates each field before storing the contact.

---

### 2. Search Contact

Contacts can be searched using:

- Name
- Phone Number
- Mail ID

The search operation uses case-insensitive comparison for names and mail IDs.

If multiple matching contacts are found, the user can select the required contact using its serial number.

---

### 3. Edit Contact

Existing contact details can be modified.

Users can edit:

- Name
- Phone Number
- Mail ID

The updated information is validated before replacing the existing data.

---

### 4. Delete Contact

Users can delete a selected contact.

Before deletion, the application asks for confirmation:

    Are you sure you want to delete this contact? (Y/N):

After deletion, the remaining contacts are shifted to maintain the contact list.

---

### 5. List Contacts

All saved contacts are displayed in a formatted table.

Contacts are copied into a temporary array and sorted **alphabetically by name** before displaying them.

Example:

    ====================================================================
    |S.NO |NAME                |PHONE.NO       |MAIL ID
    ====================================================================
    |1    |Arun                |9876543210     |arun@gmail.com
    |2    |Vicky               |9876501234     |vicky@gmail.com
    ====================================================================

---

## ✅ Data Validation

### Name Validation

The name:

- Must not be empty
- Can contain alphabets
- Can contain spaces
- Does not allow special characters or numbers

### Phone Number Validation

The phone number:

- Must contain exactly **10 digits**
- Must contain only numeric characters
- Must be unique

### Mail ID Validation

The mail ID:

- Must contain `@`
- Must end with `.com`
- Must be unique

---

## 💾 File Handling

The project uses a CSV file named:

    contact.csv

The contact data is loaded automatically when the application starts.

When the user selects **Save and Exit**, all contacts are written back to the CSV file.

Example CSV format:

    #2
    Arun,9876543210,arun@gmail.com
    Vicky,9876501234,vicky@gmail.com

---

## 📂 Project Structure

    .
    ├── main.c
    ├── contact.c
    ├── contact.h
    ├── save.c
    ├── contact.csv
    └── a.out

---

## 🧩 File Description

| File | Description |
|---|---|
| `main.c` | Contains the main menu and controls program execution |
| `contact.c` | Implements contact creation, search, edit, delete, list and validation functions |
| `contact.h` | Contains structures, constants and function declarations |
| `save.c` | Handles loading and saving contact data using CSV files |
| `contact.csv` | Stores contact information permanently |

The project uses two main structures: `Contact` and `AddressBook`. The `AddressBook` structure stores up to **100 contacts** along with the current contact count. :contentReference[oaicite:2]{index=2}

---

## 🧠 Concepts Used

- C Programming
- Structures
- Arrays
- Pointers
- Functions
- String Handling
- File Handling
- CSV File Operations
- Command-line/Console Programming
- Searching
- Sorting
- Bubble Sort
- Input Validation
- Dynamic Data Management
- Modular Programming

---

## 🔄 Program Flow

    Start
      |
      v
    Initialize Address Book
      |
      v
    Load Contacts from CSV
      |
      v
    Display Menu
      |
      +----> Create Contact
      |
      +----> Search Contact
      |
      +----> Edit Contact
      |
      +----> Delete Contact
      |
      +----> List Contacts
      |
      +----> Save and Exit
                    |
                    v
               Save to CSV
                    |
                    v
                   End

The main program initializes the address book, loads existing contacts, provides the menu-driven operations, and saves the contacts before exiting. :contentReference[oaicite:3]{index=3}

---

## 🛠️ Compilation

Compile the project using GCC:

    gcc main.c contact.c save.c -o addressbook

Run the program:

    ./addressbook

---

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

- Designing a menu-driven C application
- Using structures to organize data
- Implementing CRUD operations
- Searching and sorting records
- Performing input validation
- Working with files and CSV data
- Using pointers and arrays
- Creating modular C programs
- Handling persistent data storage

---

## 🚀 Future Improvements

Possible future enhancements:

- Add partial/fuzzy search
- Support more email formats
- Add contact groups
- Add date of birth and address fields
- Improve CSV parsing
- Add password protection
- Add a graphical user interface

---

## 👨‍💻 Author

**Vigneshwaran**

### Project: Address Book Management System in C
