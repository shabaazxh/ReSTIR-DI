#version 450

layout(location = 0) in vec2 uv;
layout(location = 0) out vec2 fragColor;

layout(set = 0, binding = 0) uniform sampler2D g_buffer_world_positions;

layout(set = 0, binding = 1) uniform CurrentCameraTransform
{
	mat4 model;
	mat4 view;
	mat4 projection;
    vec4 cameraPosition;
    vec2 viewportSize;
	float fov;
	float nearPlane;
	float farPlane;
} current_camera_transform;

layout(set = 0, binding = 2) uniform PreviousCameraTransform
{
	mat4 model;
	mat4 view;
	mat4 projection;
    vec4 cameraPosition;
    vec2 viewportSize;
	float fov;
	float nearPlane;
	float farPlane;
} previous_camera_transform;

vec2 world_to_screen_space_uv(vec3 world_pos, mat4 projection, mat4 view)
{
	vec4 project = projection * view * vec4(world_pos, 1.0);
	project.xyz /= project.w;
	return project.xy * 0.5 + 0.5;
}

void main()
{
	vec3 current_world_pos = texture(g_buffer_world_positions, uv).xyz;

	vec2 curr_uv = world_to_screen_space_uv(current_world_pos, current_camera_transform.projection, current_camera_transform.view);
	vec2 prev_uv = world_to_screen_space_uv(current_world_pos, previous_camera_transform.projection, previous_camera_transform.view);

	vec2 motion_vector = prev_uv - curr_uv;

	fragColor = vec2(motion_vector);
}