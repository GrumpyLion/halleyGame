#pragma once

#include <halley.hpp>
using namespace Halley;

class GameStage : public EntityStage {
public:
    void init() override;

    void onVariableUpdate(Time t) override;
    void onFixedUpdate(Time t) override;
    void onRender(RenderContext&) const override;

private:
    std::unique_ptr<World> world;
};
