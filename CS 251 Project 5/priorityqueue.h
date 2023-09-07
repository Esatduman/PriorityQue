/// @file priorityqueue.h
///
///
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023
//-------------------------------------
// Name: Esat Duman
// Course: Data Structures CS 251 
// UIN:662726641
// Project #5: Priority Queue
//-------------------------------------
#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)


    //-------------------------------------------------------------------
    // helper for toString 

void recursiveToString(NODE* node, stringstream& output) const {
    if (!node) 
        return;
    // Traverse the left subtree
    recursiveToString(node->left, output);
    // Append the priority and value of the current node to the output string
    output << node->priority << " value: " << node->value << endl;
    // Traverse the link subtree
    recursiveToString(node->link, output);
    // Traverse the right subtree
    recursiveToString(node->right, output);
}
//-------------------------------------------------------------------------
 

//---------------------
void insertRecursive(NODE* current, NODE* parent) {
    // If the current node has lower priority than the parent, it should be added to the left subtree.
    if (current->priority < parent->priority) {
         // If the parent's left subtree is empty, add the current node as the new left child.
        if (parent->left == nullptr) {
            parent->left = current;
            current->parent = parent;
            // Otherwise, recursively insert the node into the parent's left subtree.
        } else {
            insertRecursive(current, parent->left);
        }
        // If the current node has the same priority as the parent, it should be added to the parent's linked list.
    } else if (current->priority > parent->priority) {
        if (parent->right == nullptr) {
            parent->right = current;
            current->parent = parent;
        } else {
            insertRecursive(current, parent->right);
        }
    } else if (current->priority == parent->priority) {
     if (parent->link == nullptr) {
            parent->link = current;
            current->parent = parent;
         // Otherwise, recursively insert the node into the parent's linked list.
        } else {
            insertRecursive(current, parent->link);
        }
    }

}

void clearREC(NODE* &node) {
    // If the node is null, there is nothing to clear, so just return
    if (node == nullptr) {
        return;
    } else {
        // Recursively clear the left child of the current node
        clearREC(node->left);
        // Recursively clear the right child of the current node
        clearREC(node->right);
         // Recursively clear the link node of the current node
        clearREC(node->link);
         // Delete the current node
        delete node;
        
    }
}
//------------------
void copyT(NODE* other)
{
    // If the `other` tree is empty, there is nothing to copy.
    if (other == nullptr) {
            return;
        } 
        // Otherwise, copy the current node and recursively copy its left child, right child, and sibling.
        else {
           enqueue(other->value, other->priority); // call function 
            // Copy the current node.
           copyT(other->left);
            // Recursively copy the left child.
           copyT(other->right);
            // Recursively copy the right child.
           copyT(other->link);
            // Recursively copy the sibling.
    
           

        }
}
//-----------------------------------------------------------------------------------
bool compareBSTs(NODE* node1, NODE* node2) const {
    // If both nodes are null, then they match
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    // If only one node is null, then they don't match
    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    // Compare the current node's value and its left and right subtrees
    if (node1->priority == node2->priority) {
        return compareBSTs(node1->left, node2->left) && compareBSTs(node1->right, node2->right);
    }

    // If the priorities don't match, then the BSTs are not equal
    return false;
}

T findValues(NODE* node) const {
    if (node == nullptr) {
        return T();
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->value;
}
//----------------------------------------------------------------------------------------
public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
        
        root = nullptr; // setting root pointer to nullptr
        size = 0;       // setting the size to 0 
        curr = nullptr; // setting current to nullptr
    
        
    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        if (this != &other) {
        clear();
        copyT(other.root);
    }
    return *this;
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        // Call the recursive function to delete all nodes
        clearREC(this->root);
        // Reset root pointer to null
        this->root = nullptr;
        // Reset size to 0
        this->size = 0;
        // Reset curr pointer to null
        this->curr = nullptr;

        // TO DO: write this function.
        
        
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {

        clear(); // clear
    
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    void enqueue(T value, int priority) {
        // Create a new node and initialize its value and priority
        NODE* child = new NODE();
        NODE* now = this->root;
        child->value = value;
        child-> priority = priority;
         // If the root is null, set the root to the new node and return
        if (this->root == nullptr)
        {
            this-> root = child;
            //this->size++;
        } else {
            insertRecursive(child, now);

        }
        // Increment the size of the priority queue
        this->size++;
        
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T dequeue() {

        if (root == nullptr) {
            return T(); // return the default 
        }
        
   T valueOut = root->value;
    NODE* oldRoot = root;

    if (root->left == nullptr) {
        root = root->right;
    } else if (root->right == nullptr) {
        root = root->left;
    } else {
        NODE* parent = root;
        NODE* child = root->left;

        while (child->right != nullptr) {
            parent = child;
            child = child->right;
        }

        valueOut = child->value;
        oldRoot = child;

        if (parent == root) {
            root->left = child->left;
        } else {
            parent->right = child->left;
        }
    }

    delete oldRoot;
    size--;
    return valueOut;
        
        
    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        
        return size;
       
        
        
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {

// First, we check if the root of the tree is null 
    if (root == nullptr) {
        curr = nullptr;
        return;
    }
    
    // Otherwise, we traverse all the way to the leftmost node, which will be the first node in the inorder traversal
    curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }

        
        
    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
       
       value = curr->value;
       priority = curr->priority;

       // If there is a link (right child), move to it
       if(curr->link != nullptr) {
        curr = curr->link;
        return true;

       } else {
        // If there is no link (right child), move up the tree until a parent with a different priority is found
        while(curr->parent != nullptr && curr ->priority == curr->parent->priority) {
            curr = curr->parent;
        }
       }
         // If there is a right child, move down the tree to the leftmost node with that priority
       if(curr->right != nullptr) {
        curr = curr->right;

        while(curr->left != nullptr) {
            curr = curr->left;
        }
       }
       else {
         // If there is no right child, move up the tree until a parent with a lower priority is found
        while(curr->parent != nullptr && curr->priority > curr->parent->priority)
        {
            curr = curr->parent;
        }
        curr = curr->parent;

        if (curr == nullptr) 
        {
            return false;
        }
       }
         // TO DO: write this function.
        return true; // TO DO: update this return
        
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {

        stringstream ss; // stringstream required here. 
        recursiveToString(this->root, ss);
        return ss.str();

        // TO DO: write this function.
       // string str = "";
        //return str; // TO DO: update this return
    }
    
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T peek() {
        
       if (root == nullptr) {
        // return a default value when the priority queue is empty
        return T();
    }

        // find the smallest value in the priority queue
        NODE* node = root;
        while (node->left != nullptr) {
            node = node->left;
        }

        return node->value;
        
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        // Compare sizes of the two priority queues
        if (size != other.size) {
            return false;
        }

        // Compare the underlying custom BSTs recursively
        return compareBSTs(root, other.root);
            
    }
    
    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
