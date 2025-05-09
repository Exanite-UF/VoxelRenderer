#pragma once

#include <memory>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/vec2.hpp>

#include <src/gameobjects/Component.h>
#include <src/graphics/Texture.h>

class SkyboxComponent : public Component
{
private:
    glm::vec3 sunDirection;
    float sunAngularSize = 0;
    float sunBrightnessMultiplier = 1;
    float skyBrightnessMultiplier = 1;
    float visualMultiplier = 1;

    std::shared_ptr<Texture> cubemap = nullptr;

public:
    SkyboxComponent() = default;

    // Indirect format
    /*
    right.jpg
    left.jpg
    top.jpg
    bottom.jpg
    front.jpg
    back.jpg
    */
    // Setting format
    /*
    sunDir.x
    sunDir.y
    sunDir.z
    sunAngularSize (in degrees)
    sunBrightnessMultiplier
    skyBrightnessMultiplier
    visualBrightnessMultiplier
    */
    SkyboxComponent(const std::string& cubemapFilePath, const std::string& skyboxSettingFilePath);

    std::shared_ptr<Texture> getCubemap();
    glm::vec3 getSunDirection() const;
    float getSunAngularSize() const;

    float getSunBrightnessMultiplier() const;
    float getSkyBrightnessMultiplier() const;
    float getVisualMultiplier() const;
};
