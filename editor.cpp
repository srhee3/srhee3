#include <iostream>
#include <fstream>
#include <string>

// Part #1 

int main

(int argc, char*argv[]) {

  std::string line;
  std::fstream myfile{};
  if (myfile.is_open()) // opens the file

  {
    while (getline(myfile,line))
    {
      std::cout << line << '\n';
    }
    myfile.close();  // closes the file 
  }

  else std::cout << "Too few command-line arguments.";

  return 0;
}



// Part 2

if(user_input == "q")
{
    std::cout >> quit 
}

// Part 3



// Part 4

char command;

 std::cout << "Enter command:"
 cin >> command; 

if(user_input == "a") {   // if user inputs 'a', then cursor moves right 
    std::cout >> * right
}
if(user_input == "d") {            // if user inputs 'd', cursor moves left
    
   std::cout << * left
}

// Part 5

if(user_input == "s") {             // if input is 's', cursor moves up
    std::cout >> up

if(user_input == "w") {         // cursor moves down 
    std::cout >> down 
}

// Part 6

// Part 7

// Part 8

if(user_input == "i ");

// Part 9 

std::stack

if(user_input == "u")           // undo function
{
   std::cout >> undo 

}

if(user_input == "r")           // redo function 

{
    std::cout >> redo 


}