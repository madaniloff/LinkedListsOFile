//This program creates a student list using linked lists and nodes
//First and last name, id, and gpa are all stored
//Author: Mark Daniloff
//12/17/2019

#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//Initialize functions
void addStudent(char* infname, char* inlname, int inid, float ingpa);
void printStudent(Node* next);

//Node at the beginning of the linked list
Node* head = NULL;

int main() {
  bool on = true;
  while (on == true) {
    char input[7];
    cout << "Enter ADD, PRINT, or QUIT" << endl;
    cin.get(input, 7);
    cin.ignore();
    //ADD
    if (strcmp(input, "ADD")==0) {
      //Ask user to input first and last names, id, and gpa
      char* infname = new char[30];
      char* inlname = new char[30];
      int inid;
      float ingpa;
      cout << "First name: " << endl;
      cin.get(infname, 30);
      cin.ignore();
      cout << "Last name: " << endl;
      cin.get(inlname, 30);
      cin.ignore();
      cout << "ID: " << endl;
      cin >> inid;
      cin.ignore();
      cout << "GPA: " << endl;
      cin >> ingpa;
      cin.ignore();
      //Add all of the fields to addStudent method
      addStudent(infname, inlname, inid, ingpa);
    }
    //PRINT
    if (strcmp(input, "PRINT")==0) {
      printStudent(head);
    }
    //QUIT
    if (strcmp(input, "QUIT")==0) {
      on = false;
    }
  }
}

//Function to add a student to the linked list
void addStudent(char* infname, char* inlname, int inid, float ingpa) {
  Student* newStudent = new Student(infname, inlname, inid, ingpa);
  //sets the node current to the beginning of the linked list
  Node* current = head;
  //If current (the first index) is empty
  if (current == NULL) {
    //Create a new head
    head = new Node();
    //Set the student to the node at the head
    head->setStudent(newStudent);
  }
  //If the first index isn't empty
  else {
    //While the next index after current isn't empty
    while (current->getNext() != NULL) {
      //Set the current to the item after it
      current = current->getNext();
    }
    //Set the next index after current to be a new node
    current->setNext(new Node());
    current->getNext()->setStudent(newStudent);
  }
}

//Function to print out the contents of the linked list
void printStudent(Node* next) {
  //If the next node is the head
  if (next == head) {
    cout << "Students:" << endl;
    cout << "--------------------" << endl;
  }
  //If the next item in the linked list isn't empty
  if (next != NULL) {
    cout << "First name: " << next->getStudent()->getfname() << endl;
    cout << "Last name: " << next->getStudent()->getlname() << endl;
    cout << "ID: " << next->getStudent()->getid() << endl;
    cout << "GPA: " << std::fixed << std::setprecision(2) <<  next->getStudent()->getgpa() << endl;
    cout << "--------------------" << endl;
    //Use recursion to print out the next item in the linked list
    printStudent(next->getNext());
  }
}

