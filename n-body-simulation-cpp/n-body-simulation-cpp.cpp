#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "body.h"
#include "world.h"

int main() {
    std::vector<Body> bodies { Body(), Body() };

    bodies[0].set_position(glm::vec3(-1, 0, 0));
    bodies[1].set_position(glm::vec3(1, 0, 0));

    World world{ bodies };
    world.apply_forces();

    world.print_forces();
    std::cout << "bodies[0] == bodies[1]: " << std::boolalpha << (bodies[0] == bodies[1]) << std::endl;
    std::cout << "bodies[0] == bodies[0]: " << std::boolalpha << (bodies[0] == bodies[0]) << std::endl;

    return 0;
}