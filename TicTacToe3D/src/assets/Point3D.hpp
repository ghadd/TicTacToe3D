#pragma once

const short size = 3;

struct Point3D {
	short x, y, z;
	short flat() const;
	bool valid() const;

	Point3D operator+(const Point3D& other) const;
};
