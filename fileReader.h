
/*
 * openFile takes a string that names a text file
 * then continues to open the file for reading only
 */
void openFile(const char*);

/*
 * closeFile ensures that once we are done reading the text we properly close the file
 */
void closeFile(void);

/*
 * readURL expects a pointer that has enough space to store a URL from the openedFile
 * readURL places NULL within the char pointer provided to indicate that there are no more URLs to read
 */ 
void readURL(char*);
