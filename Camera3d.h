#include "RID.h"
#include "CameraAttributes.h"
#include "VelocityTracker3D.h"


class Camera3D{

public:
	enum ProjectionType {
		PROJECTION_PERSPECTIVE,
		PROJECTION_ORTHOGONAL,
		PROJECTION_FRUSTUM
	};

	enum KeepAspect {
		KEEP_WIDTH,
		KEEP_HEIGHT
	};

	enum DopplerTracking {
		DOPPLER_TRACKING_DISABLED,
		DOPPLER_TRACKING_IDLE_STEP,
		DOPPLER_TRACKING_PHYSICS_STEP
	};

private:
	bool force_change = false;
	bool current = false;

	ProjectionType mode = PROJECTION_PERSPECTIVE;

	float fov = 75.0;
	float size = 1.0;
	//Vector2 frustum_offset;
	// _ prefix to avoid conflict with Windows defines.
	float _near = 0.05;
	float _far = 4000.0;
	float v_offset = 0.0;
	float h_offset = 0.0;
	KeepAspect keep_aspect = KEEP_HEIGHT;

	RID camera;
	RID scenario_id;

	// String camera_group;

	unsigned int layers = 0xfffff;

	//Environment *environment;
	CameraAttributes *attributes;
	//Compositor *compositor;
	void _attributes_changed();

	// void _camera_make_current(Node *p_camera);
	friend class Viewport;
	void _update_audio_listener_state();
	//TypedArray<Plane> _get_frustum() const;

	DopplerTracking doppler_tracking = DOPPLER_TRACKING_DISABLED;
	VelocityTracker3D *velocity_tracker;

	RID pyramid_shape;
	//Vector<Vector3> pyramid_shape_points;

protected:
	void _update_camera();
	virtual void _request_camera_update();
	void _update_camera_mode();

	void _notification(int p_what);
	//void _validate_property(PropertyInfo& p_property) const;

	static void _bind_methods();

	//Projection _get_camera_projection(real_t p_near) const;

public:
	enum {
		NOTIFICATION_BECAME_CURRENT = 50,
		NOTIFICATION_LOST_CURRENT = 51
	};

	//void set_perspective(real_t p_fovy_degrees, real_t p_z_near, real_t p_z_far);
	///void set_orthogonal(real_t p_size, real_t p_z_near, real_t p_z_far);
	//void set_frustum(real_t p_size, Vector2 p_offset, real_t p_z_near, real_t p_z_far);
	void set_projection(Camera3D::ProjectionType p_mode);

	void make_current();
	void clear_current(bool p_enable_next = true);
	void set_current(bool p_enabled);
	bool is_current() const;

	//RID get_camera() const;
	/*
	real_t get_fov() const;
	real_t get_size() const;
	real_t get_far() const;
	real_t get_near() const;
	Vector2 get_frustum_offset() const;

	ProjectionType get_projection() const;

	void set_fov(real_t p_fov);
	void set_size(real_t p_size);
	void set_far(real_t p_far);
	void set_near(real_t p_near);
	void set_frustum_offset(Vector2 p_offset);

	virtual Transform3D get_camera_transform() const;
	virtual Projection get_camera_projection() const;

	virtual Vector3 project_ray_normal(const Point2& p_pos) const;
	virtual Vector3 project_ray_origin(const Point2& p_pos) const;
	virtual Vector3 project_local_ray_normal(const Point2& p_pos) const;
	virtual Point2 unproject_position(const Vector3& p_pos) const;
	bool is_position_behind(const Vector3& p_pos) const;
	virtual Vector3 project_position(const Point2& p_point, real_t p_z_depth) const;

	Vector<Vector3> get_near_plane_points() const;

	void set_cull_mask(uint32_t p_layers);
	uint32_t get_cull_mask() const;

	void set_cull_mask_value(int p_layer_number, bool p_enable);
	bool get_cull_mask_value(int p_layer_number) const;

	virtual Vector<Plane> get_frustum() const;
	bool is_position_in_frustum(const Vector3& p_position) const;

	void set_environment(const Ref<Environment>& p_environment);
	Ref<Environment> get_environment() const;

	void set_attributes(const Ref<CameraAttributes>& p_effects);
	Ref<CameraAttributes> get_attributes() const;

	void set_compositor(const Ref<Compositor>& p_compositor);
	Ref<Compositor> get_compositor() const;

	void set_keep_aspect_mode(KeepAspect p_aspect);
	KeepAspect get_keep_aspect_mode() const;

	void set_v_offset(real_t p_offset);
	real_t get_v_offset() const;

	void set_h_offset(real_t p_offset);
	real_t get_h_offset() const;

	void set_doppler_tracking(DopplerTracking p_tracking);
	DopplerTracking get_doppler_tracking() const;

	Vector3 get_doppler_tracked_velocity() const;

	RID get_pyramid_shape_rid();

	Camera3D();
	~Camera3D();
	*/
};