#pragma once

struct Vector3
{
	static const int AXIS_COUNT = 3;

	enum Axis {
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
	};

	union {
		struct {
			float x;
			float y;
			float z;
		};

		float coord[3] = { 0 };
	};
};