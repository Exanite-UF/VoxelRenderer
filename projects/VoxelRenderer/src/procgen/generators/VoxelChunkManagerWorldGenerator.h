#pragma once

#include <src/procgen/generators/WorldGenerator.h>

class VoxelChunkManagerWorldGenerator : public WorldGenerator
{
protected:
    void generateData(VoxelChunkData& data) override;

public:
    void showDebugMenu() override;
};
