#ifndef WEIGHTED_GRAPH_TESTER_H
#define WEIGHTED_GRAPH_TESTER_H
#define PARAMETERIZED

#include "Exception.h"
#include "Tester.h"
#include "Weighted_graph.h"

#include <iostream>
#include <limits>
#include <cmath>


class Weighted_graph_tester:public Tester<Weighted_graph> {
	using Tester< Weighted_graph >::object;
	using Tester< Weighted_graph >::command;

	public:
		Weighted_graph_tester( Weighted_graph *obj = 0 ):Tester<Weighted_graph>( obj ) {
			// empty
		}

		void process();
};

/****************************************************
 * void process()
 *
 * Process the current command.  For singly-linked lists, these include:
 *
 *  Accessors
 *   edge_count n      edge_count    the edge count is n
 *   degree m n        degree        the degree of vertex m is n
 *   adjacent m n d    adjacent      checks if the adjacency of m and n is d
 *   adjacent! m n     adjacent      checks if adjacent throws an exception
 *                                   when checking if m and n are adjacent
 *   nonadjacent m n   adjacent      checks if the adjacency of m and n is inf
 *   mst m d           minimum_spanning_tree
 *                                   Checks if the minimum spanning tree
 *                                   starting with vertex m is d
 *   mst! m            minimum_spanning_tree
 *                                   checks if the minimum spanning tree
 *                                   starting at vertex m throws an exception
 *   is_connected b    is_connected  checks if the graph is connected
 *
 *  Mutators
 *   insert m n d      insert        insert an edge of weight d between m and n
 *   insert! m n d     insert        insert throws an exception when inserting
 *                                   an edge of weight d between m and n
 *  Others
 *   cout            cout << graph   print the graph (for testing only)
 *   summary                         prints the amount of memory allocated
 *                                   minus the memory deallocated
 *   details                         prints a detailed description of which
 ****************************************************/

void Weighted_graph_tester::process() {
	if ( command == "edge_count" ) {
		// check if the edge count equals the next integer read

		int expected_count;

		std::cin >> expected_count;

		int actual_count = object->edge_count();

		if ( actual_count == expected_count ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in edge_count(): expecting the value '" << expected_count << "' but got '" << actual_count << "'" << std::endl;
		}
	} else if ( command == "degree" ) {
		int vertex;
		std::cin >> vertex;

		int expected_degree;
		std::cin >> expected_degree;

		int actual_degree = object->degree( vertex );

		if ( actual_degree == expected_degree ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in degree(" << vertex << "): expecting the value '" << expected_degree << "' but got '" << actual_degree << "'" << std::endl;
		}
	} else if ( command == "degree!" ) {
		int v;
		std::cin >> v;

		try {
			object->degree( v );
			std::cout << "Failure in degree(" << v << "): expecting to catch an exception" << std::endl;
		} catch( illegal_argument ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failure in adjacent(" << v << "): expecting an illegal argument exception but caught a different exception" << std::endl;
		}
	} else if ( command == "adjacent" ) {
		int v1, v2;
		std::cin >> v1;
		std::cin >> v2;

		double expected_weight;
		std::cin >> expected_weight;

		double actual_weight = object->adjacent( v1, v2 );

		if ( actual_weight == expected_weight ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting the value '" << expected_weight << "' but got '" << actual_weight << "'" << std::endl;
		}
	} else if ( command == "adjacent!" ) {
		int v1, v2;
		std::cin >> v1;
		std::cin >> v2;

		try {
			object->adjacent( v1, v2 );
			std::cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting to catch an exception" << std::endl;
		} catch( illegal_argument ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting an illegal argument exception but caught a different exception" << std::endl;
		}
	} else if ( command == "nonadjacent" ) {
		int v1, v2;
		std::cin >> v1;
		std::cin >> v2;

		double actual_weight = object->adjacent( v1, v2 );

		if ( actual_weight == std::numeric_limits<double>::infinity() ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting the value 'inf' but got '" << actual_weight << "'" << std::endl;
		}
	} else if ( command == "is_connected" ) {
		bool expected_connected;
		std::cin >> expected_connected;

		bool actual_connected = object->is_connected();

		if ( actual_connected == expected_connected ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in is_connected(): expecting the value '" << expected_connected << "' but got '" << actual_connected << "'" << std::endl;
		}
	} else if ( command == "mst" ) {
		int v;
		std::cin >> v;

		double expected_distance;
		std::cin >> expected_distance;

		double actual_distance = object->minimum_spanning_tree( v );

		if ( fabs( actual_distance - expected_distance ) < 1e-10 ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in minimum_spanning_tree(" << v << "): expecting the value '" << expected_distance << "' but got '" << actual_distance << "'" << std::endl;
		}
	} else if ( command == "mst!" ) {
		int v;
		std::cin >> v;

		try {
			object->minimum_spanning_tree( v );
			std::cout << "Failure in minimum_spanning_tree(" << v << "): expecting to catch an exception" << std::endl;
		} catch( illegal_argument ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failure in minimum_spanning_tree(" << v << "): expecting an illegal argument exception but caught a different exception" << std::endl;
		}
	} else if ( command == "insert" ) {
		int v1, v2;
		std::cin >> v1;
		std::cin >> v2;

		double weight;
		std::cin >> weight;

		object->insert( v1, v2, weight );
		std::cout << "Okay" << std::endl;
	} else if ( command == "insert!" ) {
		int v1, v2;
		std::cin >> v1;
		std::cin >> v2;

		double weight;
		std::cin >> weight;

		try {
			object->insert( v1, v2, weight );
			std::cout << "Failure in insert(" << v1 << ", " << v2 << ", " <<  weight<< "): expecting to catch an exception" << std::endl;
		} catch( illegal_argument ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failure in insert(" << v1 << ", " << v2 << ", " <<  weight<< "): expecting an illegal argument exception but caught a different exception" << std::endl;
		}
	} else if ( command == "cout" ) {
		std::cout << *object << std::endl;
	} else {
		std::cout << command << "Command not found." << std::endl;
	}
}

#endif
