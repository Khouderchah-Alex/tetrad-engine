#pragma once

#include "Config.h"

/** General Path Locations */
const std::string TEXTURE_PATH = ASSET_PATH + "textures/";
const std::string SHADER_PATH = ASSET_PATH + "shaders/";
const std::string FONT_PATH = ASSET_PATH + "fonts/";
const std::string MODEL_PATH = ASSET_PATH + "models/";

/** Textures */
const std::string FLOOR_PATH = TEXTURE_PATH + "Floor.tga";
const std::string BACKGROUND_PATH = TEXTURE_PATH + "Background.tga";
const std::string PAUSE_BACKGROUND_PATH = TEXTURE_PATH + "PauseGradient.tga";
const std::string ICON_PATH = TEXTURE_PATH + "Icon.tga";

/** Fonts */
const std::string STANDARD_FONT_PATH = FONT_PATH + "Standard.ttf";

/** Shaders */
const std::string TEST_VERTEX_PATH = SHADER_PATH + "testVert.glsl";
const std::string TEST_FRAG_PATH = SHADER_PATH + "testFrag.glsl";
const std::string UI_FRAG_PATH = SHADER_PATH + "uiFrag.glsl";
