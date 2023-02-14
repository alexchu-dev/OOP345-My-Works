// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
   CannotOpenFile = 1, // An input file cannot be opened
   BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
   std::cout << "Command Line:\n";
   std::cout << "--------------------------\n";
   for (int i = 0; i < argc; i++)
      std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
   std::cout << "--------------------------\n\n";

   // get the books
   sdds::Book library[7];
   if (argc == 2) {

      // TODO: load the collection of books from the file "argv[1]".
      std::ifstream file(argv[1]);

      // - if the file cannot be open, print a message to standard error console and
      //   exit from application with error code "AppErrors::CannotOpenFile"
      if (!file)
      {
         std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
         exit(AppErrors::CannotOpenFile);
      }

      std::string strBook;
      size_t cnt = 0;
      do {

         // - read one line at a time, and pass it to the Book constructor
         std::getline(file, strBook);
         if (file) {

            // - lines that start with "#" are considered comments and should be ignored
            if (strBook[0] != '#') {

               // - store each book read into the array "library"
               library[cnt] = Book(strBook);
               ++cnt;
            }
         }
      } while (file);
      file.close();
   }
   else
   {
      std::cerr << "ERROR: Incorrect number of arguments.\n";
      exit(AppErrors::BadArgumentCount);
   }

   double usdToCadRate = 1.3;
   double gbpToCadRate = 1.5;

   // TODO: create a lambda expression that fixes the price of a book accoding to the rules
   // - the expression should receive a single parameter of type "Book&"

   auto fixPrice = [usdToCadRate, gbpToCadRate](Book& book) {
      // - if the book was published in US, multiply the price with "usdToCadRate"
      // and save the new price in the book object
      if (book.country() == "US") {
         book.price() *= usdToCadRate;
      }
      // - if the book was published in UK between 1990 and 1999 (inclussive),
      // multiply the price with "gbpToCadRate" and save the new price in the book object
      else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
         book.price() *= gbpToCadRate;
      }
      // - for the rest of the books do nothing
   };


   std::cout << "-----------------------------------------\n";
   std::cout << "The library content\n";
   std::cout << "-----------------------------------------\n";
   // TODO: iterate over the library and print each book to the screen
   for (auto& book : library)
   {
      std::cout << book;
   }

   std::cout << "-----------------------------------------\n\n";

   // TODO: iterate over the library and update the price of each book
   //         using the lambda defined above.
   for (auto& book : library)
   {
      fixPrice(book);
   }


   std::cout << "-----------------------------------------\n";
   std::cout << "The library content (updated prices)\n";
   std::cout << "-----------------------------------------\n";
   // TODO: iterate over the library and print each book to the screen
   for (auto& book : library)
   {
      std::cout << book;
   }

   std::cout << "-----------------------------------------\n";

   return 0;
}
