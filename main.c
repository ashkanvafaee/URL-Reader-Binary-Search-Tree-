//main.c: used to test functionality of binary search tree methods
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "assignment-6.h"

int compareArrays(char ar1[][MAX_URL_LENGTH],char ar2[][MAX_URL_LENGTH],int compare_till){
    int i;
    for(i=0;i<compare_till;i++){
        if(strcmp(ar1[i],ar2[i]) !=0)
            return 0;
    }
    return 1;
}

int compare_numArrays(int* num_ar1, int* num_ar2,int compare_till){
    int i;
    for(i=0;i<compare_till;i++){
        if(num_ar1[i]!= num_ar2[i])
            return 0;
    }
    return 1;
}

void test_print(struct tnode* p, int expectedResult, char expectedArray[][MAX_URL_LENGTH], int expected_freq[11]){
	char node_urls[11][MAX_URL_LENGTH];
	int url_frequency[11];
    if ( expectedResult != tree_traversal(0,p, node_urls, url_frequency) ) {
        printf("Test TREE PRINT Failed.\n");
    }
    else{
        if(compareArrays(expectedArray, node_urls,expectedResult))
            if(compare_numArrays(expected_freq, url_frequency, expectedResult)){
                printf("Test TREE PRINT Passed.\n");
                return;
            }
        printf("Test TREE PRINT Failed.\n");
    }
}

int main(void) {
	struct tnode* root;
	char node_urls[11][MAX_URL_LENGTH];
	int url_frequency[11];
 	
    char Expected_URLs[11][MAX_URL_LENGTH]= {"amazon.com","apple.com", "boardingarea.com", "dealsofamerica.com", "facebook.com", "frys.com", "gmail.com", "google.com", "homeroomedu.com", "ideone.com", "mail.yahoo.com"};
    char Expected_URLs_small[7][MAX_URL_LENGTH]= {"amazon.com", "dealsofamerica.com","frys.com","google.com", "homeroomedu.com", "ideone.com", "mail.yahoo.com"};

    int Expected_Url_Freq[11] = {7225, 597, 7112, 3636, 7029, 4361, 7030, 753, 6474, 3672, 20};
    int Expected_Url_Freq_small[7] = {5, 12, 15, 29, 3, 19, 20};
 
    root = NULL;
	/*populate_tree("test.txt", &root);
	int x= tree_traversal(0, root, node_urls, url_frequency);
	populate_tree("test.txt", &root);

	populate_tree("test.txt", &root);
	x = lookup(root, "gmail.com");
	tree_traversal(0, root, node_urls, url_frequency);*/

	/*populate_tree("test2.txt", &root);
	int x = lookup(root, "bbc.com");
	x++;*/



	root = add_to_tree(root, "google.com");
	root = add_to_tree(root, "google.com");
	assert( root->count == 2);
	root = add_to_tree(root, "amazon.com");
 	assert(tree_traversal(0,root,node_urls, url_frequency) == 2);
	
    populate_tree("small_url.txt", &root);
	
	test_print(root, 7, Expected_URLs_small, Expected_Url_Freq_small);
	tree_traversal(0, root, node_urls, url_frequency);					
    
    populate_tree("long_url.txt", &root);
	//assert( lookup(root, "vonage.com") == 2323);
	test_print(root, 11, Expected_URLs, Expected_Url_Freq);

	//int x = lookup(root, "mail.yahoo.com");

	tree_traversal(0, root, node_urls, url_frequency);

	int x = lookup(root, "zzz.com");
	
	return 0;
}

