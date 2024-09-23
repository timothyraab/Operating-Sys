#include "wish.h"
#include <ctype.h>  // isspace
#include <regex.h>  // regcomp, regexec, regfree
#include <stdio.h>  // fopen, fclose, fileno, getline, feof
#include <stdlib.h> // exit
#include <sys/types.h>
#include <sys/wait.h> // waitpid
//#include <stdbool.h> // booleans
//#include <string.h> // string functions
#include <dirent.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//g++ -o wish wish.cpp for compiling


int main(int argc, char *argv[]) {
  // YOUR CODE HERE
	  
	  char error_message[50] = "An error has occurred\n";
	  string path = "bin";
	  int result = chdir(path.c_str()); // changing the local directory to the one specified in path

	  
    //printf("%s", error_message);
  	//printf("%d\n", argc);

		if(argc == 1)
		{
			bool loopCondition = true;
			while(loopCondition)
			{
				char Prompt[] = "wish> "; // Prompt
				printf("%s", Prompt);

			
				string command_line;
				string command;
				getline(cin, command_line);
				stringstream ss(command_line);

				ss >> command;

				string arguement;
				ss >> arguement;
				cout << arguement << endl;
				

				if(command_line.compare("exit") == 0) // exit command. kill program
				{
					exit(0);
				}
				else if(command.compare("ls") == 0)
				{

					int returnCode = system(command_line.c_str());
 
    				// checking if the command was executed successfully
    				if (returnCode == 0) {
        				//cout << "Command executed successfully." << endl;
					}
    				else {
        				cout << "Command execution failed or returned "
                		"non-zero: "
             			<< returnCode << endl;
    				}
				}
				else if(command.compare("path") == 0)
				{
					//string arguement;
					//ss >> arguement;
					string extra_error;
					ss >> extra_error;

					if(extra_error.compare("") != 0) // bad command only 1 arguemnt allowed. give error and reprint Prompt
					{
						//cout << "Extra arg error" << endl;
						printf("%s", error_message); // error message
					}
					else
					{
						path = path + " " + arguement;
						//cout << "New Path: " << path << endl;
					}


				}
				else if(command.compare("cd") == 0)
				{
					//string arguement;
					string extra_error;
					//ss >> arguement;
					//cout << arguement << endl;
					ss >> extra_error;

					if(extra_error.compare("") != 0) // bad command. give error and reprint Prompt
					{
						//cout << "Extra arg error" << endl;
						printf("%s", error_message); // error message

					}
					else
					{
						int result = chdir(arguement.c_str()); // changing the local directory to the one specified in path

	        			if (result == 0) // if change is successful
	        			{
		       			//output = "change directory complete";
            			//cout << "Changing directory to " << arguement << endl;
	        			}//end if
	        			else // if change Fails
	        			{
		        			//output = "failed to change directory";
							printf("%s", error_message); // error message
            				//cout << "Invalid path entered." << endl;
	        			}//end else
					}

				}
				//else if (command[0] == '.' && command[1] == '/') // inbuilt commands done. execution time
				//{
					//int returnCode = system(command_line.c_str());
					

				//}
				else
				{
					int returnCode = system(command_line.c_str());
					// checking if the command was executed successfully
    				if (returnCode == 0) {
        				//cout << "Command executed successfully." << endl;
					}
    				else {
        				printf("%s", error_message); // error message
    				}
				}

			}

		}
		else if(argc == 2)
		{
			//printf("BATCH MODE ACTIVATED\n");
			ifstream file;
			string read;
			file.open(argv[1]);

			if (!file.is_open()) {
				//Bad Batch file. terminate program.
				//cout << "BAD BATCH" << endl;
  				printf("%s", error_message); // error message
				exit(1);
			}

			
			while (getline(file, read)) {
  				string command_line;
				string command;
				getline(cin, command_line);
				stringstream ss(command_line);

				ss >> command;

				string arguement;
				ss >> arguement;
				cout << arguement << endl;
				

				if(command_line.compare("exit") == 0) // exit command. kill program
				{
					exit(0);
				}
				else if(command.compare("ls") == 0)
				{

					int returnCode = system(command_line.c_str());
 
    				// checking if the command was executed successfully
    				if (returnCode == 0) {
        				//cout << "Command executed successfully." << endl;
					}
    				else {
        				cout << "Command execution failed or returned "
                		"non-zero: "
             			<< returnCode << endl;
    				}
				}
				else if(command.compare("path") == 0)
				{
					//string arguement;
					//ss >> arguement;
					string extra_error;
					ss >> extra_error;

					if(extra_error.compare("") != 0) // bad command only 1 arguemnt allowed. give error and reprint Prompt
					{
						//cout << "Extra arg error" << endl;
						printf("%s", error_message); // error message
					}
					else
					{
						path = path + " " + arguement;
						//cout << "New Path: " << path << endl;
					}


				}
				else if(command.compare("cd") == 0)
				{
					//string arguement;
					string extra_error;
					//ss >> arguement;
					//cout << arguement << endl;
					ss >> extra_error;

					if(extra_error.compare("") != 0) // bad command. give error and reprint Prompt
					{
						//cout << "Extra arg error" << endl;
						printf("%s", error_message); // error message

					}
					else
					{
						int result = chdir(arguement.c_str()); // changing the local directory to the one specified in path

	        			if (result == 0) // if change is successful
	        			{
		       			//output = "change directory complete";
            			//cout << "Changing directory to " << arguement << endl;
	        			}//end if
	        			else // if change Fails
	        			{
		        			//output = "failed to change directory";
							printf("%s", error_message); // error message
            				//cout << "Invalid path entered." << endl;
	        			}//end else
					}

				}
				//else if (command[0] == '.' && command[1] == '/') // inbuilt commands done. execution time
				//{
					//int returnCode = system(command_line.c_str());
					

				//}
				else
				{
					int returnCode = system(command_line.c_str());
					// checking if the command was executed successfully
    				if (returnCode == 0) {
        				//cout << "Command executed successfully." << endl;
					}
    				else {
        				printf("%s", error_message); // error message
    				}
				}

			}
			file.close();
			exit(0); // file over, end program return 0 because it succesfully made it to the end

		}
		else
		{
			printf("%s", error_message);
			exit(1);
			//ERROR
		}



  return 0;
}