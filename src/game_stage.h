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
    std::shared_ptr<DevService> devService;

    std::unique_ptr<Executor> mainThreadExecutor;
    std::unique_ptr<Executor> videoThreadExecutor;
};
