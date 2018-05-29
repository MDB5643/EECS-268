/**
* @file main.cpp
* @author Matt Bailey
* @since 10-2-2016
*/
// #include "BuildingExecutive.h"
//
// BuildingExecutive::BuildingExecutive(char* argv[])
// {
//   std::string NewFile = argv[1];
//   std::ifstream inp(NewFile);
//
//   while (std::getline(inp, item))
//   {
//     std::stringstream sstr(item);
//
//     while (getline(sstr, command, ' '))
//     {
//       if (command == "WAIT")
//       {
//         getline(sstr, name, ' ');
//         line->enqueue(name);
//       }
//       else if (command == "DROP_OFF")
//       {
//         getline(sstr, num, ' ');
//         dropnum = stoi(num);
//         for (int i = 0; i < dropnum; i++)
//         {
//           elevator->pop();
//         }
//       }
//       else if (command == "INSPECTION")
//       {
//         std::cout << "Elevator status:\n";
//         if (elevator->isEmpty())
//         {
//           std::cout << "Elevator is empty.\n";
//           try
//           {
//             lname = line->peekFront();
//             std::cout << lname << " will be the next person to enter on the elevator.\n";
//           }
//           catch(PrecondViolatedExcep)
//           {
//             std::cout << "Line is empty too.\n";
//           }
//         }
//         else
//         {
//           std::cout << "Elevator is not empty.\n";
//         try
//         {
//           ename = elevator->peek();
//         }
//         catch(PrecondViolatedExcep)
//         {
//           std::cout << "Peek attempted on empty stack.\n";
//         }
//         try
//         {
//           lname = line->peekFront();
//         }
//         catch(PrecondViolatedExcep)
//         {
//           std::cout << "Line is empty.\n";
//         }
//           std::cout << ename << " will be next person to exit the elevator.\n";
//           std::cout << lname << " will be next person to enter the elevator. \n";
//         }
//       }
//       else if (command == "PICK_UP")
//       {
//         for (int i = 0; i < 7; i++)
//         {
//           if (!(line->isEmpty()))
//           {
//             elevator->push(line->peekFront());
//             line->dequeue();
//           }
//         }
//       }
//     }
//   }
//
//
//
//   inp.close();
//   return 0;
//
// }
