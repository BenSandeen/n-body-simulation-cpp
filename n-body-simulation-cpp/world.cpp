#include "world.h"
#include <algorithm>
#include <math.h>

World::World()
{
	bodies = std::vector<Body>();
}

World::World(std::vector<Body> bodies)
{
	this->bodies = bodies;
}

// This will naturally be quite slow, but it should yield accurate results
std::vector<Body> World::get_nearest_bodies(Body& center_body, int max_num_to_get) const
{
    if (max_num_to_get <= 0) {
        max_num_to_get = bodies.size();
    }
    std::vector<std::pair<Body, float>> neighbor_dists{};
    for (auto body : bodies) {
        neighbor_dists.push_back(std::pair<Body, float>{body, (center_body.get_distance_between_bodies(body))});
    }

    std::sort(neighbor_dists.begin(), neighbor_dists.end(), [](auto& left, auto& right) {
        return left.second < right.second;
    });

    neighbor_dists.resize(max_num_to_get);
    std::vector<Body> bodies;
    std::transform(neighbor_dists.begin(), neighbor_dists.end(), bodies.begin(), [](auto& body) {
        return body.first;
        });
    return bodies;
}

float World::get_distance_between_bodies(const Body& start, const Body& finish)
{
	return start.get_distance_between_bodies(const_cast<Body&>(finish));
}

void World::apply_forces()
{
    // Accumulates all the forces for each body for this timestep
    for (Body& body : bodies)
    {
        for (Body& other_body : bodies.begin) {
            if (body != other_body)
            {
                float force = body.get_force_magnitude_between_bodies(other_body);
                glm::vec3 direction = body.get_vector_between_bodies(other_body);
                direction = glm::normalize(direction);
                body.add_force(force * direction);
                other_body.add_force(-force * direction);
            }
        }
    }
}

void World::print_forces() const
{
    for (auto body : bodies) {
        glm::vec3 forces = body.get_force_this_time_step();
        std::cout << "( " << forces.x << ", " << forces.y << ", " << forces.z << " )" << std::endl;
    }
}
