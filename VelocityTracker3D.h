#pragma once

#include "Vector3.h"

class VelocityTracker3D
{
	struct PositionHistory {
		unsigned long long frame = 0;
		Vector3 position;
	};

	bool physics_step = false;
	PositionHistory *position_history;
	int position_history_len = 0;

};