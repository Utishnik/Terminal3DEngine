#pragma once
struct CameraAttributes
{
	float exposure_multiplier = 1.0;
	float exposure_sensitivity = 100.0; 
	bool auto_exposure_enabled = false;
	float auto_exposure_min = 0.01;
	float auto_exposure_max = 64.0;
	float auto_exposure_speed = 0.5;
	float auto_exposure_scale = 0.4;
};