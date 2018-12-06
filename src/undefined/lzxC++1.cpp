#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;
void println(string s);
void println(string s,int i);
void helpOrContinue(string s);
int check(string password);
int controler();
int normal();
int program();
bool bo = 0;

int main(){
	string str;
	printf("+------------------------------+\n");
	printf("|  welecom to LIN 1.0 system   |\n");
	printf("+------------------------------+\n\n");
	Sleep(500);
	printf("+----+      +----+  +---+  +--+\n");
	printf("|    |      |    |  |    \\ |  |\n");
	printf("|    |      |    |  |     \\|  |\n");
	printf("|    +---+  |    |  |  |\\     |\n");
	printf("|        |  |    |  |  | \\    |\n");
	printf("+--------+  +----+  +--+  +---+ \n");
	printf("| Enter your name(pinyin with no capital letters and spaces):");
	cin >> str;
	printf("| ");
	for(int i = 0;i < 20;i ++){
		Sleep(100);
		printf(">");
	}
	printf("\n");
	if(str == "lzx"){
		cout << "| Please Enter lzx,s password:";
		string password;
		cin >> password;
		int back = check(password);
		if(back == 0){
			return back;
		}else{
			bo = 1;
		}
	}else{
		cout << "| Hi," << str << "!\n";
		println("| It's nice to meet you.\n",100);
	}
	if(bo){
		controler();
	}else{
		normal();
	}
}
void println(string s){
	cout << s << "\n";
}
void println(string s,int i){
	Sleep(i);
	cout << s << "\n";
}
int check(string password){
	if(password == "Iamyourmaster"){
		println("| welecom back,master lzx.",100);
	}else{
		println("| you are not lzx..",100);
		println("| LIN 1.0 shutting down..",100);
		for(int i = 0;i < 20;i ++){
			Sleep(200);
			cout << ".";
		}
		return 0;
	}
}
void helpOrContinue(string s){
	if(s == "help"){
		println("| This is a program powered lzx",100);
		printf("| you are in ");
		if(bo){
			printf("controler");
		}else{
			printf("normal");
		}
		println(" mode.");
		println("| Enter \"help\" to get this",100);
	}else{
		println("| You didn't ask for help",100);
	}
}
int controler(){
	println("| this is in controler",100);
	program();
}
int normal(){
	println("| this is in normal",100);
	program();
}
int program(){
	string input;
	cout << "| Enter \"help\" to get more help,Enter other keys to continue:";
	cin >> input;
	helpOrContinue(input);
	Sleep(100);
	println("| This is the main program>>>>>>>>>>");
	Sleep(2000);
}
