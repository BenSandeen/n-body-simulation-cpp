#include <vector>
#include "body.h"

Body::Body() {
	position = { 0,0,0 };
	velocity = { 0,0,0 };
	//acceleration = { 0,0,0 };
	orientation = { 0,0,0 };
	mass = 1;
	net_force = { 0,0,0 };
}

void Body::set_position(glm::vec3 position)
{
	this->position = position;
}

void Body::set_velocity(glm::vec3 velocity)
{
	this->velocity = velocity;
}

void Body::set_orientation(glm::vec3 orientation)
{
	this->orientation = orientation;
}

glm::vec3 Body::get_position() const {
	return position;
}

glm::vec3 Body::get_velocity() const {
	return velocity;
}

glm::vec3 Body::get_orientation() const {
	return orientation;
}

float Body::get_distance_between_bodies(Body& other) const
{
	if (*this == other) {
		return 0.0f;
	}
	else {
		glm::vec3 displacement{ this->get_vector_between_bodies(other) };

		// Yes, this is hardcoded and ugly, but for now, it'll have to do
		return sqrtf(displacement.x * displacement.x +
			displacement.y * displacement.y +
			displacement.z * displacement.z);
	}
}

glm::vec3 Body::get_vector_between_bodies(Body& other) const
{
	if (*this == other) {
		return glm::vec3{ 0,0,0 };
	}
	else {
		glm::vec3 start_pos{ this->get_position() };
		glm::vec3 finish_pos{ other.get_position() };
		glm::vec3 displacement{};

		displacement.x = finish_pos.x - start_pos.x;
		displacement.y = finish_pos.y - start_pos.y;
		displacement.z = finish_pos.z - start_pos.z;

		return displacement;
	}
}

float Body::get_force_magnitude_between_bodies(Body& other) const
{
	float dist = this->get_distance_between_bodies(other);
	return this->mass * other.mass / (dist * dist);
}

glm::vec3 Body::get_force_this_time_step() const
{
	return net_force;
}

void Body::update_position(float time_step) {
	position += velocity * time_step;
}

void Body::update_velocity(float time_step) {
	//velocity += acceleration * time_step;
}

void Body::update_acceleration(float time_step) {
	//acceleration += friction * time_step;
}

void Body::apply_force(Body& other) {
	//float dist = this->get_distance_between_bodies(other);
	//glm::vec3 force = this->mass * other.mass / (dist * dist);
}

void Body::add_force(glm::vec3 force)
{
	net_force += force;
}

int Body::get_n_dims() const
{
	return (int)position.length;
}

bool Body::operator==(const Body& other) const
{
	return this == &other;
}
