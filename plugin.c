// Copyright 2020 Valentin Vanelslande
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common_types.h"

#ifdef _WIN32
#define VVCTRE_PLUGIN_EXPORT __declspec(dllexport)
#else
#define VVCTRE_PLUGIN_EXPORT
#endif

static const char* required_function_names[] = {
    "vvctre_settings_set_audio_volume",
    "vvctre_settings_set_custom_textures",
    "vvctre_settings_set_background_color_red",
    "vvctre_settings_set_background_color_green",
    "vvctre_settings_set_background_color_blue",
    "vvctre_settings_set_resolution",
    "vvctre_settings_set_layout",
    "vvctre_settings_set_multiplayer_ip",
    "vvctre_settings_set_multiplayer_port",
    "vvctre_settings_set_nickname",
};

typedef void (*vvctre_settings_set_audio_volume_t)(float value);
static vvctre_settings_set_audio_volume_t vvctre_settings_set_audio_volume;
typedef void (*vvctre_settings_set_custom_textures_t)(bool value);
static vvctre_settings_set_custom_textures_t vvctre_settings_set_custom_textures;
typedef void (*vvctre_settings_set_background_color_red_t)(float value);
static vvctre_settings_set_background_color_red_t vvctre_settings_set_background_color_red;
typedef void (*vvctre_settings_set_background_color_green_t)(float value);
static vvctre_settings_set_background_color_green_t vvctre_settings_set_background_color_green;
typedef void (*vvctre_settings_set_background_color_blue_t)(float value);
static vvctre_settings_set_background_color_blue_t vvctre_settings_set_background_color_blue;
typedef void (*vvctre_settings_set_resolution_t)(u16 value);
static vvctre_settings_set_resolution_t vvctre_settings_set_resolution;
typedef void (*vvctre_settings_set_layout_t)(int value);
static vvctre_settings_set_layout_t vvctre_settings_set_layout;
typedef void (*vvctre_settings_set_multiplayer_ip_t)(const char* value);
static vvctre_settings_set_multiplayer_ip_t vvctre_settings_set_multiplayer_ip;
typedef void (*vvctre_settings_set_multiplayer_port_t)(u16 value);
static vvctre_settings_set_multiplayer_port_t vvctre_settings_set_multiplayer_port;
typedef void (*vvctre_settings_set_nickname_t)(const char* value);
static vvctre_settings_set_nickname_t vvctre_settings_set_nickname;

VVCTRE_PLUGIN_EXPORT int GetRequiredFunctionCount() {
    return 10;
}

VVCTRE_PLUGIN_EXPORT const char** GetRequiredFunctionNames() {
    return required_function_names;
}
      
VVCTRE_PLUGIN_EXPORT void PluginLoaded(void* core, void* plugin_manager, void* required_functions[]) {
    vvctre_settings_set_audio_volume = (vvctre_settings_set_audio_volume_t)required_functions[0];
    vvctre_settings_set_custom_textures = (vvctre_settings_set_custom_textures_t)required_functions[1];
    vvctre_settings_set_background_color_red = (vvctre_settings_set_background_color_red_t)required_functions[2];
    vvctre_settings_set_background_color_green = (vvctre_settings_set_background_color_green_t)required_functions[3];
    vvctre_settings_set_background_color_blue = (vvctre_settings_set_background_color_blue_t)required_functions[4];
    vvctre_settings_set_resolution = (vvctre_settings_set_resolution_t)required_functions[5];
    vvctre_settings_set_layout = (vvctre_settings_set_layout_t)required_functions[6];
    vvctre_settings_set_multiplayer_ip = (vvctre_settings_set_multiplayer_ip_t)required_functions[7];
    vvctre_settings_set_multiplayer_port = (vvctre_settings_set_multiplayer_port_t)required_functions[8];
    vvctre_settings_set_nickname = (vvctre_settings_set_nickname_t)required_functions[9];
}

VVCTRE_PLUGIN_EXPORT void InitialSettingsOpening() {
    vvctre_settings_set_audio_volume(0.6f);
    vvctre_settings_set_custom_textures(true);
    vvctre_settings_set_background_color_red(0.396078431372549);
    vvctre_settings_set_background_color_green(0.36470588235294116);
    vvctre_settings_set_background_color_blue(0.30980392156862746);
    vvctre_settings_set_resolution(0);
    vvctre_settings_set_layout(1);
    vvctre_settings_set_multiplayer_ip("10.0.0.25");
    vvctre_settings_set_multiplayer_port(24872);
    vvctre_settings_set_nickname("Sparrow");
}
