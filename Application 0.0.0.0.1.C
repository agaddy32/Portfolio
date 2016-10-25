// An oroboros C++ program to show understanding of Linux system administration.
// An attempt has been made to leverage common Linux commands to perform as many functions as possible
// Must be compiled with a name in the format of "Application 0.0.0.0.1" but the part which appears as a version number can contain any characters.
// Austin Gaddy.

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//initializing variables.
	char ltra[1];
	char ltrb[1];
	char ltrc[1];
	bool final = false;
	char filename[25];
	char filenold[25];

	//Set current and next filename via runtime argument. Nested for loops would have been a cleaner and more compact implementation.
	strcpy(filenold, argv[0]);
	strcpy(filename, argv[0]);
	if(int(filename[22]) != 88){
		if(int(filename[22]) > 88){
			filename[22]=48;
		}
		filename[22]=filename[22]+1;
	}
	else if(int(filename[20]) != 85){
		if(int(filename[20]) > 85){
			filename[20]=48;
		}
		filename[20]=filename[20]+1;
	}
	else if(int(filename[18]) != 78){
		if(int(filename[18]) > 78){
			filename[18]=48;
		}
		filename[18]=filename[18]+1;
	}
	else if(int(filename[16]) != 73){
		if(int(filename[16]) > 73){
			filename[16]=48;
		}
		filename[16]=filename[16]+1;
	}
	else if(int(filename[14]) != 76){
		if(int(filename[14]) > 76){
			filename[14]=48;
		}
		filename[14]=filename[14]+1;
	}
	else{
		final = true;
	}

	//Clear the screenbuffer.
	system("clear");

	//Printing current filename.
	cout << filenold << "\n";

	//Getting linux system info.
	system("uname -a");

	//Show contents of folder.
	system("ls -l | grep -i Application");

	//Show running file, I deprecated this feature as it is too slow in runtime (lsof creates a large amount of data and takes a while to complete, this caused my program to go very slow.
	//string buffer = "lsof | grep -i \"";
	//buffer.append(filenold);
	//buffer.append("\"");
	//system(buffer.c_str());

	//Show addressing.
	system("ifconfig | grep -i inet");

	//Show free disk space.
	system("df | grep -i /dev");

	//Show process.
	buffer.clear();
	buffer = "ps aux | grep -i \"";
	buffer.append(filenold);
	buffer.append("\"");
	system(buffer.c_str());

	//Close if complete.
	if(final){
		return 0;
	}

	//Copy source
	buffer.clear();
	buffer = "cp \"";
	buffer.append(filenold);
	buffer.append(".C\" \"");
	buffer.append(filename);
	buffer.append(".C\"");
	system(buffer.c_str());

	//Delete old files
	buffer.clear();
	buffer = "rm \"";
	buffer.append(filenold);
	buffer.append(".C\" \"");
	buffer.append(filenold);
	buffer.append("\"");
	system(buffer.c_str());

	//Compile
	buffer.clear();
	buffer = "g++ \"";
	buffer.append(filename);
	buffer.append(".C\" -o \"");
	buffer.append(filename);
	buffer.append("\"");
	system(buffer.c_str());

	//Run
	buffer.clear();
	buffer = "\"";
	buffer.append(filename);
	buffer.append("\"");
	system(buffer.c_str());
}
