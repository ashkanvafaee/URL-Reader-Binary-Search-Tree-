/*
Name:Vafaee, Ashkan
UT EID : av28837
Section : 16320
EE312 - Assignment 6

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment-6.h"
#include "fileReader.h"



/*
 * add a new node to the tree or update an existing node within the tree
 * if a new node is created then a pointer to said node is returned (new node should still be inserted into tree)
 * parameters: root (pointer to the root of a tree), URL (string URL that needs to be inserted into tree)
 */
struct tnode* add_to_tree(struct tnode* root, char* URL) {
	struct tnode* Temp = root;

	if (root == NULL) {
		struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
		temp->count = 1;
		temp->key = (char*)malloc(sizeof(char)*MAX_URL_LENGTH);						//****
		strcpy(temp->key, URL);
		temp->left = NULL;
		temp->right = NULL;
		return(temp);
	}

	if (strcmp(URL, Temp->key) == 0) {												//URL match
		Temp->count = Temp->count + 1;
		return(Temp);
	}

	if (strcmp(URL, Temp->key) >0) {												//URL is larger (right)

		if (Temp->right == NULL) {
			struct tnode* right = (struct tnode*)malloc(sizeof(struct tnode));
			right->count = 1;
			right->key = (char*)malloc(sizeof(char)*MAX_URL_LENGTH);				//*****
			strcpy(right->key, URL);
			right->left = NULL;
			right->right = NULL;
			Temp->right = right;													//connetion
			return(Temp);
		}
		

		add_to_tree(Temp->right, URL);
	}

	if (strcmp(URL, Temp->key) <0) {												//URL smaller (left)

		if (Temp->left == NULL) {
			struct tnode* left = (struct tnode*)malloc(sizeof(struct tnode));
			left->count = 1;
			left->key = (char*)malloc(sizeof(char)*MAX_URL_LENGTH);
			strcpy(left->key, URL);
			left->left = NULL;
			left->right = NULL;
			Temp->left = left;														//connetion
			return(Temp);
		}
		add_to_tree(Temp->left, URL);
	}

	return(root);
    //fix the broken implementation
}


/*
 * add all URLs within the URL_file into the tree that R points to
 * parameters: URL_file (file name that needs to opened, read from, and closed), R (pointer to the root pointer of the tree)
 * take a look at fileReader.h to learn how to manipulate a file
 */ 
 void populate_tree(char* URL_file, struct tnode** R) {
	 char* string=(char*)malloc(sizeof(char)*MAX_URL_LENGTH);

	 openFile(URL_file);
	 readURL(string);

	 while (*(string) != '\0') {
		
		 *R = add_to_tree(*R, string);
		 readURL(string);
		
	 }

	 closeFile();


    //implement this section :) 
 }





/* 
 * looks up the URL within the tree and returns the frequency of the specific URL
 * parameters: root (pointer to the root of a tree), URL (string URL that is being searched for)
 * return: return the frequency of URL within tree
 */
 int lookup(struct tnode* p, char* url) {
	 int frequency=0;
	 struct tnode *temp = p;

	 if (temp == NULL) {						/////
		 return(0);
	 }

	 if (strcmp(url, temp->key) == 0) {		//match
		 return(temp->count);
	 }

	 if (strcmp(url, temp->key) >0) {		//larger (right)
		 frequency = lookup(temp->right, url);
	
	 }

	 if (strcmp(url, temp->key) <0) {		//smaller (left)
		 frequency = lookup(temp->left, url);
		 

	 }
    //fix the broken implementation
    return frequency;
 }


 /* tree_traversal:  in-order traversal of tree p
  * set the URLs (that are stored in the tree) into the passed in array in alphabetical fashion 
  * also set their respective frequencies in a second int array
  * return the number of elements set into the array
  * size: how many elements you have currently inserted into the array(s)
  * p: pointer to the root of the (sub)tree
  * URL_array: array to store URLs in
  * frequencies: integer array to store frequencies in
  */ 
int tree_traversal(int size, struct tnode* p, char URL_array[][MAX_URL_LENGTH], int* frequencies) {
	if (p->left != NULL) {
		size = tree_traversal(size, p->left, URL_array, frequencies);
	}
	strcpy(URL_array[size], p->key);
	frequencies[size] = p->count;
	size++;


	if (p->right != NULL) {
		size = tree_traversal(size, p->right, URL_array, frequencies);
	}


    return (size);
}

