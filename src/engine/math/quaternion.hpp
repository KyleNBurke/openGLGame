#pragma once

class Quaternion {
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Quaternion& q);

		float x;
		float y;
		float z;
		float w;
};