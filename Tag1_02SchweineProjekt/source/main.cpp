#include <iostream>
#include "services/DependencyImpl.h"
#include "services/MyServiceUsingDependency.h"
int main() {

    DependencyImpl impl;

    MyServiceUsingDependency service{impl};



	service.f("Hallo") ;

}