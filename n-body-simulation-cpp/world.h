#pragma once
#include <vector>
#include <iostream>
#include "body.h"

class World
{
private:
	std::vector<Body> bodies;

public:
	World();
	World(std::vector<Body> bodies);
	std::vector<Body> get_nearest_bodies(Body& center_body, int max_num_to_get) const;
	float get_distance_between_bodies(const Body& start, const Body& finish);

	// This stuff allows users to iterate over the bodies
	typedef std::vector< Body >::iterator iterator;
	iterator begin() { return bodies.begin(); }
	iterator end() { return bodies.end(); }

	void apply_forces();

	void print_forces() const;
};

