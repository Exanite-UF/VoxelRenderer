#pragma once

#include <memory>
#include <src/procgen/synthesizers/TextureDataSynthesizer.h>

class TextureOctaveNoiseSynthesizer : public TextureDataSynthesizer
{
private:
    int seed;
    int octaves = 3;
    float persistence = 0.5;

public:
    TextureOctaveNoiseSynthesizer(int seed, int octaves, float persistence);
    void generate(std::shared_ptr<TextureDataA>& textureData) override;
    void showDebugMenu() override;
    std::function<float(float)> mapperTo01() override;
};
