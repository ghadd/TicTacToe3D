#include "Point3D.hpp"

short Point3D::flat() const {
	return this->x + this->y * size + this->z * size * size;
}

bool Point3D::valid() const {
	return this->x >= 0 && this->y >= 0 && this->z >= 0 &&
		this->x < size&& this->y < size&& this->z < size;
}

Point3D Point3D::operator+(const Point3D& other) const {
	return { this->x + other.x, this->y + other.y, this->z + other.z };
}
