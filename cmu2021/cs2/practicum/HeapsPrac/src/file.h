/*
	This file contains the definition for class file.
 
    Sherine Antoun
    Colorado Mesa University
*/

#ifndef FILE

class file{
	public:	
		file();

		file(char filename[]);
		void associate(char filename[]);

	private:
		char* buffer;

};

#endif FILE
	
