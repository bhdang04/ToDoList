# To-Do List Application

## Description

This is a simple **To-Do List** application written in C++ that allows users to add, remove, and manage items on their to-do list. The application provides an interactive interface with five options:

1. Add an item to the to-do list.
2. Remove an item from the to-do list.
3. Manage the to-do list by swapping two items.
4. View the current to-do list.
5. Exit the application.

The program uses basic C++ features such as arrays, loops, conditionals, and functions for each operation. It also demonstrates user input handling and terminal control to create a smooth user experience.

## Features

- **Add Item**: Users can add new items to the to-do list.
- **Remove Item**: Users can remove a specific item from the list by choosing its position.
- **Manage List**: Users can swap the positions of two items on the list.
- **View List**: Displays the current items in the to-do list.
- **Exit Application**: Closes the application after pressing any key.

## Requirements

- A C++ compiler (e.g., g++, clang++).
- POSIX-compliant system (for terminal control and key reading features, such as `tcgetattr` and `read`).

## Code Overview

### Main Features

1. **view()**: Displays the current to-do list with numbered items.
2. **add()**: Adds an item to the to-do list at the next available position.
3. **remove()**: Removes an item from the to-do list and shifts the subsequent items up.
4. **manage()**: Swaps two items in the to-do list.
5. **exit()**: Prompts the user to press any key to exit the program and captures the input.

### Program Flow

- The program runs in a loop displaying a menu of options (Add, Remove, Manage, View, Quit).
- Based on the user’s input, the corresponding action is executed.
- After each action, the screen is cleared, and the user is returned to the menu to choose another option until they decide to quit the application.

## How to Compile and Run

1. **Compile the Program**:
   Use the following command to compile the C++ program using `g++`:
   
   ```bash
   g++ -o ToDoList main.cpp
   ```
2. **Run The Program**: After compiling, run the program with the following command:

   ```bash
   ./ToDoList
   ```
## Example Output
```mathematica
<-------- Choose Options (1-5) -------->
1. Add to List
2. Remove to List
3. Manage List
4. View List
5. Quit Application 
Pick a number to select that option: 2 
Select the number to remove from your To-Do List (0 = clear all): 1 
Deleted Successfully 
Press Any Key To Exit...
```
