/*BANK LINE SIMULATION
-Carson Case

-Input goes in a file titled "input.txt"

-Output is to console

-Number of tellers is a pre-processor defined value (defaulted to 1)

-Additional notes:
Excelent project. Was fun and not only tested my ability to implement the data structures we're learning
but also left a lot of room for creative problem solivng. Finding ways to keep code organized, save space
and plan for future functionality was a welcome challenge in this project. I am quite proud of this code
and think this is probably my best work so far. I'll probably think it's auful a while from now but hey
it's a big improvement from last project :)

04/05/20:10:55PM
(1hr and 5 minutes before due)

*/

#include <iostream>
#include "queue.h"
//#include "queue.cpp"
#include "priorityQueue.h"
#include "priorityQueue.cpp"
#include "simEvent.h"
#include "Customer.h"
#include <fstream>

#define NUMBER_OF_TELLERS 1
using namespace std;

const Customer NULL_CUSTOMER;			//NULL_CUSTOMER is a value we can set to a teller that is empty

//Utility function to return true if the tellers are all assisting customers
bool tellers_full(Customer* tellers) {
	for (int i = 0; i < NUMBER_OF_TELLERS; i++) {
		if (*tellers++ == NULL_CUSTOMER) { return false; }
	}
	return true;
}
//Utility function to return true if the tellers are empty
bool tellers_empty(Customer* tellers) {
	for (int i = 0; i < NUMBER_OF_TELLERS; i++) {
		if (!(*tellers++ == NULL_CUSTOMER)) { return false; }
	}
	return true;
}

int main() {
	/*Simulation! Finaly!*/
	size_t NUMBER_OF_CUSTOMERS=0;

	//The Priority Queue of Events is our Output
	priorityQueue<simEvent> events;

	//The line is the literal line in the bank. Represented by Queues
	queue<Customer> line;

	//Time Variable
	size_t time_stamp = 1;


	//Array of Customers at tellers
	Customer at_teller[NUMBER_OF_TELLERS];

	//Read the input file to create a queue of customers
	queue<Customer> customers;

	ifstream fp("input.txt");
	Customer temp;
	while (fp >> temp) {
		customers.push_back(temp);
		NUMBER_OF_CUSTOMERS++;
	}
	
	//set each teller to NULL_CUSTOMER to show them as empty
	for (int i = 0; i < NUMBER_OF_TELLERS; i++) {
		at_teller[i] = NULL_CUSTOMER;
	}
	/*
	MAIN SIMULATION LOOP
	Continue until the customers are done being added to the simulation and the line within the simulation is empty
	NOTE: There are three queues in use.
	1)"Customers"->A queue just because it's convinent. Can be thought of as the external customers yet to arrive
	2)"Line"->The line within the bank waiting for a teller
	3)"Events"-> stores the events so we can have an output
	*/
	simEvent startEvent(time_stamp, "Simulation_Begins");
	events.insert(startEvent);
	while (!customers.empty() || !line.empty() || !tellers_empty(at_teller)) {
		
		//WHILE THERE IS AN ARRIVAL TO PROCESS...
		while (!customers.empty() && customers.peek_front().get_arrival_time() == time_stamp) {		//Includes not empty because on the last iteration of the last customer it tries to peek an empty queue. Which results in an error. Since this is an and operation it won't run that code if it's empty first
			//create and insert an arival event for the customer
			simEvent newEvent(time_stamp, "arrival");
			events.insert(newEvent);
			//Now that the customer has arrived. Add him to the line within the bank
			line.push_back(customers.peek_front());

			//Finally pop him from the queue of external customers
			customers.pop_front();
		}
		//WHILE THERE ARE CUSTOMERS IN LINE AND AVAILABLE TELLERS
		while (!line.empty()&&!tellers_full(at_teller)) {
			//check to see if a teller is available
			for (int i = 0; i < NUMBER_OF_TELLERS; i++) {
				//If nobody at teller (measured by a time_left of 0 or less)
				if (at_teller[i].get_time_required()<=0) {
					//Add the customer to the teller and remove him from line
					at_teller[i] = line.peek_front();
					line.pop_front();
					//break the teller search loop
					break;
				}
			}
			break;		//Once all tellers have been observed
		}

		//Must update here as the customers are updated to reflect the passing of a tic of time next
		time_stamp++;

		//Update all customers at the tellers (THAT ARE NOT NULL CUSTOMERS). If customer is done, remove from the teller and create departure event
		for (int i = 0; i < NUMBER_OF_TELLERS; i++) {
			if (!(at_teller[i]==NULL_CUSTOMER) && at_teller[i].update()) {
				at_teller[i] = NULL_CUSTOMER;
				simEvent departure(time_stamp, "departure");
				events.insert(departure);
			}
		}

		//Lastly update the wait time for every customer that's waiting in line
		Customer::wait(line.get_size());
		
		
	}
	std::cout << events;
	std::cout << "FINAL STATS:" << endl;
	std::cout << "Number of Customers: " << NUMBER_OF_CUSTOMERS<<endl;
	std::cout <<"Average Wait Time: "<< (double)Customer::get_total_wait_time()/NUMBER_OF_CUSTOMERS;
	return 0;
}