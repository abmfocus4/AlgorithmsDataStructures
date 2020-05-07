/****************************************************
 * Create an instance of the Trie_tester<int>
 * or Trie_tester<double> classes and call
 * the member function run().
 *
 * The member function run() will interpret the
 * input appropriately and exit when the interpreter
 * receives either the command 'exit' or and
 * end-of-file.
 ****************************************************/

#include <iostream>
#include <cstring>
#include "Trie_tester.h"

int main( int argc, char *argv[] ) {
	std::cout << "Starting Test Run" << std::endl;

	Trie_tester tester;

	tester.run();

	std::cout << "Finishing Test Run" << std::endl;

	return 0;
}