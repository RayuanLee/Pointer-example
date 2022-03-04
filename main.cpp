//
//  main.cpp
//  Assignment #18 CIS 27
//
//  Created by rayuan lee on 5/21/17.
//  Copyright © 2017 rayuan lee. All rights reserved.
//

#include <iostream>

using namespace std;

struct node {
    
    int sample;
    node  *next;
    
};

class list{
private:
    /*here we are creating some pointers for the beginning of our node to the end of it*/
    
    node *head, *tail;
    
public:
    /* This is where we declare our list in the program and make sure that the list is initially empty so we make the head and the tail empty*/
    
    
    list(){
        head = NULL;
        
        tail = NULL;
    }
    //Here we create a methode for when we need to create a new node and get a new value
    void createnode (int value){
        
        node *temp = new node;
        temp -> sample = value;
        temp -> next = NULL;
        
        if(head != NULL){
            
            head = temp;
            tail = temp;
            temp = NULL;
        }
        
        else{
            
            /*tail-> next=temp;*/
            tail = temp;
        }
    }
    
    /*This will place our values from our list in order and show them */
    
    void display(){
        
        cout <<"List: ";
        
        node *temp = new node;
        temp = head;
        
        while (temp != NULL){
            
            cout << temp -> sample << " \t";
            temp = temp ->next;
        }
        
        cout << endl;
    }
    
    /* We will put the first number into the starting position*/
    void insert_start (int value) {
        
        node *temp = new node;
        temp-> sample = value;
        temp -> next = head;
        head = temp;
    }
    
    
    /*This is going to give us the position of the new node*/
    
    void insert_position (int pos, int value)
    {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        
        for (int i = 1; i< pos; i++){
            
            pre = cur;
            cur = cur -> next;
        }
        
        temp -> sample = value;
        pre -> next =temp;
        temp -> next =cur;
    }
    
    void delete_first() {
        
        node *temp = new node;
        temp = head;
        head = head-> next;
        delete temp;
        
    }
    
    void delete_back(){
        
        if (head != NULL)
        {
            node *end = head;
            node *pre_end = new node;
            
            while (end-> next != NULL) {
                
                pre_end = end;
                
                end = end-> next;
                
            }
            
            pre_end ->next = 0;
            delete end;
        }
    }
    
    int size(){
        
        int count =0;
        node* temp = head;
        
        while ( temp != NULL)
        {
            count++;
            
            temp = temp-> next;
        }
        return count;
    }
};

int main(){
    
    list test;
    
    test.createnode(2);
    test.createnode(4);
    test.createnode(6);
    test.display();
    
    test.insert_start(26);
    test.display();
    
    test.delete_first();
    test.insert_position(5, 20);
    test.display();
    
    test.delete_back();
    test.delete_first();
    test.display();
    
    test.insert_start(2);
    test.delete_back();
    test.display();
    cout<< "Size of the list: "<<test.size() << endl;
    
    return 0;
}
