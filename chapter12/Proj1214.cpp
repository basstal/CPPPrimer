#include<memory>
using namespace::std;
struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);
void f(destination &d){
	connection c=connect(&d);
	shared_ptr<connection> ptr(&c,[](connection *p)->void{disconnect(*p);});
}
void end_connection(connection *p){
	disconnect(*p);
}
