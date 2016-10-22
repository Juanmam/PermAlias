#include <iostream>   //cin cout
#include <cstdlib>
#include <string>     //I'm lazy, that why.
#include <regex>      //I'm evil, that why.
#include <fstream>    //To write files.

using namespace std;

string bash  = "~/.bash_aliases";
string alias = "alias ";

string convcts(int argc, char* argv[]){
  string result = "";
  
  for(int i = 1; i<argc; i++){
    result += string(argv[i]);
    if (i!=argc-1) result += " ";
  }

  return result;
}

void sync(){
  string text;
  string file = "bin/example.sh";
  ofstream sh(file);
  
  sh << "#!/bin/bash\nsource ~/.bash_aliases";
  
  sh.close();
  
  string arg;

  arg= "chmod 500 " + file; //Execution and Read only mode.
  if(system(arg.c_str())>0)
    cout << "Error: Couldn't change " << file << " mode." << endl;
  
  arg= "./" + file; //Console command for execution of file.sh
  if(system(arg.c_str())>0)
    cout << "Error: Couldn't execute " << file << "." << endl;
}

int main(int argc, char* argv[]){
  
  //Find current url
  
  if(system( NULL )){
    //The program can execute normally.
    //string nick = string(argv[1]);
    string nick = convcts(argc,argv);
    
    if(argc==2){
      if(nick.compare("-h")==0
	 ||nick.compare("--help")==0
	 ||nick.compare("-?")==0){
	cout << "Usage:" << endl;
	cout << "./PermAlias [NICKNAME]=[COMMAND]" << endl;
	cout << "[NICKNAME]: Alias name." << endl;
	cout << "[COMMAND]:  Instruction that wants to be linked with the alias." << endl;
	cout << endl;
	cout << "Example:" << endl;
	cout << "./PermAlias Hello=echo \"World\"" << endl;
	cout << "Result:" << endl;
	cout << "Hello" << endl;
	cout << "World" << endl;
      } else if (nick.compare ("-v")==0
		 ||nick.compare("--version")==0){
	cout << "Version 1.0.0" << endl;
      } else if (nick.compare("-a")==0
		 ||nick.compare("--about")==0){
	cout << "About:" << endl;
	cout << " PermAlias is a program design to assign permanent alias." << endl;
      }
      return 0;
    }
    
    if (argc >= 2) {
      regex reg("(.*)=(.*)");
      if(regex_match (nick, reg)){
	size_t found = nick.find_first_of("=");
	//Change format to mash alias format
	
	alias += nick.substr(0,found+1);
	alias += "'";
	alias += nick.substr(found+1);
	alias += "'";
	
	string argument = "echo \"" + alias + "\" >> ~/.bash_aliases";
	
	system(argument.c_str());
        
	sync();
	
	argument = "#!/bin/bash && source ~/.bash_aliases";
	
	system(argument.c_str());
	
      } else {
        cout << "Error: Incorrect alias format. Check manual for more info on how to use or use alias help to get more details." << endl;
	return 1;
      }
    } else {
      cout << "Error: Incorrect input size." << endl;
      return 2;
    }
  } else {
    cout << "Error: No terminal available." << endl;
    return 1;
  }
  
  return 0;
}
