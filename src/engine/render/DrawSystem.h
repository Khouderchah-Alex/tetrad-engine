#pragma once

#include "core/ConstVector.h"
#include "core/GlTypes.h"
#include "engine/ecs/System.h"
#include "engine/render/DrawComponent.h"
#include "engine/render/ShaderGlobals.h"
#include "engine/resource/ResourceManager.h"

namespace tetrad {

class Screen;
class TextComponent;
class UIViewport;

/** @brief System to perform the rendering of objects.
 *
 * Uses DrawableComponents and TransformComponents in order to
 * render objects as needed. Current implementation uses OpenGL,
 * but could be modified to use a diferent API if needed. The only
 * real coupling between OpenGL and non-rendering parts of this
 * software is the use of GLFW as a window manager.
 *
 * @TODO Much like with the PhysicsSystem, some sort of space
 * partitioning or sorting could help split up work and/or
 * require less work from the CPU.
 */
class DrawSystem : public System
{
 public:
  DrawSystem();

  void Tick(deltaTime_t dt) override;

 private:
  void RenderWorld(const Screen &screen, const UIViewport &viewport);
  void RenderUi(const Screen &screen);
  void RenderFreeText(const Screen &screen);

  void RenderTextComponent(const Screen &screen, const TextComponent &textComp);

  // Overrides from System.
  bool OnInitialize() override;
  void OnShutdown() override;

  bool SetupShaders();

 private:
  ConstVector<DrawComponent *> m_pDrawComponents;
  ConstVector<MaterialComponent *> m_pMaterialComponents;
  ConstVector<TextComponent *> m_pTextComponents;
  ConstVector<UIViewport *> m_pViewports;

  ModelResource m_UIPlane;

  GLuint m_WorldProgram;
  WorldShaderGlobals m_WorldUniforms;

  GLuint m_UIProgram;
  UIShaderGlobals m_UIUniforms;

  GLuint m_TextProgram;
  TextShaderGlobals m_TextUniforms;

  GLuint m_DitherTexture;
};

}  // namespace tetrad
