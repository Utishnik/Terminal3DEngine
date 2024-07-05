#pragma once

#include <string>

class EngineConfig {
	public:
		struct Singleton {
			std::string name;
			//Object* ptr = nullptr; todo imp object
			std::string class_name; // Used for binding generation hinting.
			// Singleton scope flags.
			bool user_created = false;
			bool editor_only = false;

			Singleton(const std::string *p_name/*, Object* p_ptr = nullptr*/, const std::string* p_class_name);
		};
	private:
		uint64_t frames_drawn = 0;
		uint32_t _frame_delay = 0;
		uint64_t _frame_ticks = 0;
		double _process_step = 0;

		int ips = 60;
		double physics_jitter_fix = 0.5;
		double _fps = 1;
		int _max_fps = 0;
		int _audio_output_latency = 0;
		double _time_scale = 1.0;
		uint64_t _physics_frames = 0;
		int max_physics_steps_per_frame = 8;
		double _physics_interpolation_fraction = 0.0f;
		bool abort_on_gpu_errors = false;
		bool use_validation_layers = false;
		bool generate_spirv_debug_info = false;
		int32_t gpu_idx = -1;

		uint64_t _process_frames = 0;
		bool _in_physics = false;

		Singleton *singletons;
		//HashMap<StringName, Object*> singleton_ptrs; todo import hashmap

		bool editor_hint = false;
		bool project_manager_hint = false;
		bool extension_reloading = false;

		bool _print_header = true;

		static EngineConfig* singleton;

		std::string write_movie_path;
		std::string shader_cache_path;

		static constexpr int SERVER_SYNC_FRAME_COUNT_WARNING = 5;
		int server_syncs = 0;
		bool frame_server_synced = false;
	public:
		static EngineConfig* get_singleton();

		virtual void set_physics_ticks_per_second(int p_ips);
		virtual int get_physics_ticks_per_second() const;

		virtual void set_max_physics_steps_per_frame(int p_max_physics_steps);
		virtual int get_max_physics_steps_per_frame() const;

		void set_physics_jitter_fix(double p_threshold);
		double get_physics_jitter_fix() const;

		virtual void set_max_fps(int p_fps);
		virtual int get_max_fps() const;

		virtual void set_audio_output_latency(int p_msec);
		virtual int get_audio_output_latency() const;

		virtual double get_frames_per_second() const { return _fps; }

		uint64_t get_frames_drawn();

		uint64_t get_physics_frames() const { return _physics_frames; }
		uint64_t get_process_frames() const { return _process_frames; }
		bool is_in_physics_frame() const { return _in_physics; }
		uint64_t get_frame_ticks() const { return _frame_ticks; }
		double get_process_step() const { return _process_step; }
		double get_physics_interpolation_fraction() const { return _physics_interpolation_fraction; }

		void set_time_scale(double p_scale);
		double get_time_scale() const;

		void set_print_error_messages(bool p_enabled);
		bool is_printing_error_messages() const;

		void set_frame_delay(uint32_t p_msec);
		uint32_t get_frame_delay() const;

		void add_singleton(const Singleton& p_singleton);
		void get_singletons(List<Singleton>* p_singletons);
		bool has_singleton(const StringName& p_name) const;
		//Object* get_singleton_object(const StringName& p_name) const; todo add
		void remove_singleton(const StringName& p_name);
		bool is_singleton_user_created(const StringName& p_name) const;
		bool is_singleton_editor_only(const StringName& p_name) const;

};