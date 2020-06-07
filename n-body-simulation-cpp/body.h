#pragma once
#include <glm/vec3.hpp>

class Body
{
private:
	glm::vec3 position;
	glm::vec3 velocity;
	//glm::vec3 acceleration;
	glm::vec3 orientation;
	float mass;
	//float friction;
	glm::vec3 net_force;

public:
	Body();
	void set_position(glm::vec3 position);
	void set_velocity(glm::vec3 velocity);
	void set_orientation(glm::vec3 orientation);

	glm::vec3 get_position() const;
	glm::vec3 get_velocity() const;
	glm::vec3 get_orientation() const;
	float get_distance_between_bodies(Body& other) const;
	glm::vec3 get_vector_between_bodies(Body& other) const;
	float get_force_magnitude_between_bodies(Body& other) const;
	glm::vec3 get_force_this_time_step() const;

	void update_position(float time_step);
	void update_velocity(float time_step);
	void update_acceleration(float time_step);
	//void apply_force(glm::vec3 force);
	void apply_force(Body& other);
	void add_force(glm::vec3 force);

	bool operator==(const Body& other) const;
	int get_n_dims() const;
};

