#include <iostream>
#include <memory>
#include "DependencyImpl.h"
#include "MyServiceUsingDependency.h"
int main() {
	std::unique_ptr<Dependency> dep = std::make_unique<DependencyImpl>();
    MyServiceUsingDependency myServiceUsingDependency{std::move(dep)};
    auto result = myServiceUsingDependency.g("Hallo");
    std::cout << result << std::endl;
}