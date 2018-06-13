// cpp29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OperatingSystem.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const string cmd_help = "help";
const string cmd_exit = "exit";
const string cmd_tree = "tree";
const string cmd_libs = "libs";
const string cmd_new_process = "proc";
const string cmd_new_thread = "thread";
const string cmd_new_lib_ref = "lib";
const string cmd_delete_process = "del-proc";
const string cmd_delete_thread = "del-thread";
const string cmd_delete_lib_ref = "del-lib";

OperatingSystem os;

vector<string> split(string s) {
	vector<string> vecStr;
	istringstream ss(s);
	string str;
	while (ss >> str)
		vecStr.push_back(str);
	return vecStr;
}

void printHelp() {
	cout << "commands: " << "\n";
	cout << "-- " << cmd_help << "\n";
	cout << "-- " << cmd_exit << "\n";
	cout << "-- " << cmd_tree << "\n";
	cout << "-- " << cmd_libs << "\n";
	cout << "-- " << cmd_new_process << " 'process_name'" << " 'memory'" << "\n";
	cout << "-- " << cmd_delete_process << " 'process_name'" << "\n";
	cout << "-- " << cmd_new_thread << " 'process_name'" << " 'thread_name'" << " 'memory'" << "\n";
	cout << "-- " << cmd_delete_thread << " 'process_name'" << " 'thread_name'" << "\n";
	cout << "-- " << cmd_new_lib_ref << " 'process_name'" << " 'thread_name'" << " 'lib_name'" << " 'memory'" << "\n";
	cout << "-- " << cmd_delete_lib_ref << " 'process_name'" << " 'thread_name'" << " 'lib_name'" << "\n";
	cout << "\n";
}

int callCmd(string cmd, vector<string> args) {
	if (cmd == cmd_help) {
		if (args.size() != 0)
			throw "Invalid number of arguments";
		printHelp();
		return 0;
	}
	if (cmd == cmd_tree) {
		if (args.size() != 0)
			throw "Invalid number of arguments";
		os.PrintTree();
		return 0;
	}
	if (cmd == cmd_delete_process) {
		if (args.size() != 1)
			throw "Invalid number of arguments";
		os.RemoveProcess(args[0]);
		return 0;
	}
	if (cmd == cmd_delete_thread) {
		if (args.size() != 2)
			throw "Invalid number of arguments";
		os.RemoveThread(args[0], args[1]);
		return 0;
	}
	if (cmd == cmd_delete_lib_ref) {
		if (args.size() != 3)
			throw "Invalid number of arguments";
		os.RemoveLibRef(args[0], args[1], args[2]);
		return 0;
	}
	if (cmd == cmd_libs) {
		if (args.size() != 0)
			throw "Invalid number of arguments";
		os.PrintLibs();
		return 0;
	}
	if (cmd == cmd_new_process) {
		if (args.size() != 2)
			throw "Invalid number of arguments";
		os.CreateProcess(args[0], atoi(args[1].c_str()));
		return 0;
	}
	if (cmd == cmd_new_thread) {
		if (args.size() != 3)
			throw "Invalid number of arguments";
		os.CreateThread(args[0], args[1], atoi(args[2].c_str()));
		return 0;
	}
	if (cmd == cmd_new_lib_ref) {
		if (args.size() != 3)
			throw "Invalid number of arguments";
		os.AddLibRef(args[0], args[1], args[2]);
		return 0;
	}
	return 1;
}

int main()
{
	string cmd;
	vector<string> args;

	os.CreateProcess("process1", 16);
	os.CreateProcess("process2", 32);
	os.CreateThread("process1", "thread1", 8);
	os.CreateThread("process1", "thread2", 64);
	os.CreateThread("process1", "thread4", 32);
	os.CreateThread("process2", "thread3", 8);
	os.CreateThread("process2", "thread5", 8);
	os.AddLibRef("process1", "thread2", "dll1");
	os.AddLibRef("process1", "thread2", "dll2");
	os.AddLibRef("process2", "thread5", "dll3");

	printHelp();
	do {
		string input;
		vector<string> vecStr;
		cout << "enter your command: ";
		getline(cin, input);
		cout << "\n";
		vecStr = split(input);
		cmd = vecStr.front();
		if (cmd == cmd_exit)
			break;
		vecStr.erase(vecStr.begin());

		int res = 0;
		try {
			res = callCmd(cmd, vecStr);
		}
		catch (char* ex) { cout << "error:" << ex << "\n"; }

		if (res) {
			cout << "error: invalid command" << "\n";
			printHelp();
		}
	} while (cmd != cmd_exit);

	return 0;
}
