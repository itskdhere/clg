/*
Name: Krishnendu Das
Roll No.: 39
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

class Book
{
public:
  int id;
  string title;
  string author;
  string genre;
  int publicationYear;
  bool isAvailable;

  Book(int id, string title, string author, string genre, int publicationYear)
      : id(id), title(title), author(author), genre(genre), publicationYear(publicationYear), isAvailable(true) {}
};

class Member
{
public:
  int memberId;
  string name;
  string address;
  string contactInfo;
  vector<int> borrowedBooks;

  Member(int memberId, string name, string address, string contactInfo)
      : memberId(memberId), name(name), address(address), contactInfo(contactInfo) {}
};

class LibrarySystem
{
private:
  vector<Book> books;
  vector<Member> members;

public:
  void addBook(int id, string title, string author, string genre, int publicationYear)
  {
    books.push_back(Book(id, title, author, genre, publicationYear));
    cout << "Book added successfully." << endl;
  }

  void updateBook(int id, string title, string author, string genre, int publicationYear)
  {
    for (auto &book : books)
    {
      if (book.id == id)
      {
        book.title = title;
        book.author = author;
        book.genre = genre;
        book.publicationYear = publicationYear;
        cout << "Book updated successfully." << endl;
        return;
      }
    }
    cout << "Book not found." << endl;
  }

  void removeBook(int id)
  {
    for (auto it = books.begin(); it != books.end(); ++it)
    {
      if (it->id == id)
      {
        books.erase(it);
        cout << "Book removed successfully." << endl;
        return;
      }
    }
    cout << "Book not found." << endl;
  }

  void showBooks()
  {
    cout << "Books:" << endl;
    for (const auto &book : books)
    {
      cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << ", Publication Year: " << book.publicationYear << ", Availability: " << (book.isAvailable ? "Available" : "Not Available") << endl;
    }
  }

  // Search: Allow users to search for books by title, author, or genre.
  void searchBooks(string query)
  {
    cout << "Books:" << endl;
    for (const auto &book : books)
    {
      if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.genre.find(query) != string::npos)
      {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << ", Publication Year: " << book.publicationYear << ", Availability: " << (book.isAvailable ? "Available" : "Not Available") << endl;
      }
    }
  }

  void registerMember(int memberId, string name, string address, string contactInfo)
  {
    members.push_back(Member(memberId, name, address, contactInfo));
    cout << "Member registered successfully." << endl;
  }

  void updateMember(int memberId, string name, string address, string contactInfo)
  {
    for (auto &member : members)
    {
      if (member.memberId == memberId)
      {
        member.name = name;
        member.address = address;
        member.contactInfo = contactInfo;
        cout << "Member updated successfully." << endl;
        return;
      }
    }
    cout << "Member not found." << endl;
  }

  void removeMember(int memberId)
  {
    for (auto it = members.begin(); it != members.end(); ++it)
    {
      if (it->memberId == memberId)
      {
        members.erase(it);
        cout << "Member removed successfully." << endl;
        return;
      }
    }
    cout << "Member not found." << endl;
  }

  void showMembers()
  {
    cout << "Members:" << endl;
    for (const auto &member : members)
    {
      cout << "ID: " << member.memberId << ", Name: " << member.name << ", Address: " << member.address << ", Contact Info: " << member.contactInfo << endl;
    }
  }

  void borrowBook(int memberId, int bookId)
  {
    for (auto &book : books)
    {
      if (book.id == bookId && book.isAvailable)
      {
        for (auto &member : members)
        {
          if (member.memberId == memberId)
          {
            book.isAvailable = false;
            member.borrowedBooks.push_back(bookId);
            cout << "Book borrowed successfully." << endl;
            return;
          }
        }
        cout << "Member not found." << endl;
        return;
      }
    }
    cout << "Book not available." << endl;
  }

  void returnBook(int memberId, int bookId)
  {
    for (auto &book : books)
    {
      if (book.id == bookId && !book.isAvailable)
      {
        for (auto &member : members)
        {
          if (member.memberId == memberId)
          {
            book.isAvailable = true;
            auto it = find(member.borrowedBooks.begin(), member.borrowedBooks.end(), bookId);
            if (it != member.borrowedBooks.end())
            {
              member.borrowedBooks.erase(it);
              cout << "Book returned successfully." << endl;
              return;
            }
          }
        }
        cout << "Member not found." << endl;
        return;
      }
    }
    cout << "Book not found." << endl;
  }

  void generateReport()
  {
    cout << "Currently borrowed books:" << endl;
    for (const auto &book : books)
    {
      if (!book.isAvailable)
      {
        cout << "Book ID: " << book.id << ", Title: " << book.title << endl;
      }
    }
  }

  void showOverdueList()
  {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    cout << "Overdue books:" << endl;
    for (const auto &member : members)
    {
      for (const auto &bookId : member.borrowedBooks)
      {
        for (const auto &book : books)
        {
          if (book.id == bookId)
          {
            if (currentYear > book.publicationYear + 1)
            {
              cout << "Member ID: " << member.memberId << ", Book ID: " << book.id << ", Title: " << book.title << endl;
            }
            else if (currentYear == book.publicationYear + 1)
            {
              if (currentMonth > 1)
              {
                cout << "Member ID: " << member.memberId << ", Book ID: " << book.id << ", Title: " << book.title << endl;
              }
              else if (currentMonth == 1)
              {
                if (currentDay > 1)
                {
                  cout << "Member ID: " << member.memberId << ", Book ID: " << book.id << ", Title: " << book.title << endl;
                }
              }
            }
          }
        }
      }
    }
  }

  void saveData()
  {
    ofstream bookFile("books.txt");
    for (const auto &book : books)
    {
      bookFile << book.id << "," << book.title << "," << book.author << "," << book.genre << "," << book.publicationYear << "," << book.isAvailable << endl;
    }
    bookFile.close();
    cout << "Books data saved successfully." << endl;

    ofstream memberFile("members.txt");
    for (const auto &member : members)
    {
      memberFile << member.memberId << "," << member.name << "," << member.address << "," << member.contactInfo << endl;
      for (const auto &bookId : member.borrowedBooks)
      {
        memberFile << bookId << " ";
      }
      memberFile << endl;
    }
    memberFile.close();
    cout << "Members data saved successfully." << endl;
  }

  void loadData()
  {
    ifstream bookFile("books.txt");
    string line;
    while (getline(bookFile, line))
    {
      int id, publicationYear;
      string title, author, genre;
      bool isAvailable;
      sscanf(line.c_str(), "%d,%[^,],%[^,],%[^,],%d,%d", &id, &title[0], &author[0], &genre[0], &publicationYear, &isAvailable);
      books.push_back(Book(id, title, author, genre, publicationYear));
      books.back().isAvailable = isAvailable;
    }
    bookFile.close();
    cout << "Books data loaded successfully." << endl;

    ifstream memberFile("members.txt");
    while (getline(memberFile, line))
    {
      int memberId;
      string name, address, contactInfo;
      sscanf(line.c_str(), "%d,%[^,],%[^,],%[^,]", &memberId, &name[0], &address[0], &contactInfo[0]);
      members.push_back(Member(memberId, name, address, contactInfo));
      getline(memberFile, line);
      istringstream iss(line);
      int bookId;
      while (iss >> bookId)
      {
        members.back().borrowedBooks.push_back(bookId);
      }
    }
    memberFile.close();
    cout << "Members data loaded successfully." << endl;
  }
};

int main()
{
  LibrarySystem library;
  cout << "Loading data from files..." << endl;
  library.loadData();

  cout << "\n< Library Management System >" << endl;
  int choice;

  while (true)
  {
    cout << endl;
    cout << "Menu:" << endl;
    cout << " 1  - Add Book" << endl;
    cout << " 2  - Remove Book" << endl;
    cout << " 3  - Update Book" << endl;
    cout << " 4  - Show Books" << endl;
    cout << " 5  - Search Books" << endl;
    cout << " 6  - Register Member" << endl;
    cout << " 7  - Remove Member" << endl;
    cout << " 8  - Update Member" << endl;
    cout << " 9  - Show Members" << endl;
    cout << " 10 - Borrow Book" << endl;
    cout << " 11 - Return Book" << endl;
    cout << " 12 - Generate Report" << endl;
    cout << " 13 - Show Overdue List" << endl;
    cout << " 14 - Exit" << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
    {
      int id, publicationYear;
      string title, author, genre;
      cout << "Enter book ID: ";
      cin >> id;
      cout << "Enter book title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter book author: ";
      getline(cin, author);
      cout << "Enter book genre: ";
      getline(cin, genre);
      cout << "Enter publication year: ";
      cin >> publicationYear;
      library.addBook(id, title, author, genre, publicationYear);
      break;
    }
    case 2:
    {
      int id;
      cout << "Enter book ID: ";
      cin >> id;
      library.removeBook(id);
      break;
    }
    case 3:
    {
      int id, publicationYear;
      string title, author, genre;
      cout << "Enter book ID: ";
      cin >> id;
      cout << "Enter book title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter book author: ";
      getline(cin, author);
      cout << "Enter book genre: ";
      getline(cin, genre);
      cout << "Enter publication year: ";
      cin >> publicationYear;
      library.updateBook(id, title, author, genre, publicationYear);
      break;
    }
    case 4:
    {
      library.showBooks();
      break;
    }
    case 5:
    {
      string query;
      cout << "Enter search query: ";
      cin.ignore();
      getline(cin, query);
      library.searchBooks(query);
      break;
    }
    case 6:
    {
      int memberId;
      string name, address, contactInfo;
      cout << "Enter member ID: ";
      cin >> memberId;
      cout << "Enter member name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter member address: ";
      getline(cin, address);
      cout << "Enter member contact info: ";
      getline(cin, contactInfo);
      library.registerMember(memberId, name, address, contactInfo);
      break;
    }
    case 7:
    {
      int memberId;
      cout << "Enter member ID: ";
      cin >> memberId;
      library.removeMember(memberId);
      break;
    }
    case 8:
    {
      int memberId;
      string name, address, contactInfo;
      cout << "Enter member ID: ";
      cin >> memberId;
      cout << "Enter member name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter member address: ";
      getline(cin, address);
      cout << "Enter member contact info: ";
      getline(cin, contactInfo);
      library.updateMember(memberId, name, address, contactInfo);
      break;
    }
    case 9:
    {
      library.showMembers();
      break;
    }
    case 10:
    {
      int memberId, bookId;
      cout << "Enter member ID: ";
      cin >> memberId;
      cout << "Enter book ID: ";
      cin >> bookId;
      library.borrowBook(memberId, bookId);
      break;
    }
    case 11:
    {
      int memberId, bookId;
      cout << "Enter member ID: ";
      cin >> memberId;
      cout << "Enter book ID: ";
      cin >> bookId;
      library.returnBook(memberId, bookId);
      break;
    }
    case 12:
    {
      library.generateReport();
      break;
    }
    case 13:
    {
      library.showOverdueList();
      break;
    }
    case 14:
    {
      cout << "Saving data to files..." << endl;
      library.saveData();
      cout << "Exiting..." << endl;
      return 0;
    }
    }
  }

  return 0;
}