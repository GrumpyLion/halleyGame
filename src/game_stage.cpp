#include "game_stage.h"

void GameStage::init()
{
    world = createWorld("stages/game_world");

    const auto scriptingService = std::make_shared<ScriptingService>(std::make_unique<ScriptEnvironment>(getAPI(), *world, getResources(), std::make_unique<ScriptNodeTypeCollection>()), getResources(), "", getAPI().core->isDevMode());
    world->addService(scriptingService);

    auto factory = EntityFactory(*world, getResources());
    factory.createScene(getResources().get<Scene>("hello_world"), true);
    factory.createEntity("camera");
}

void GameStage::onVariableUpdate(Time t)
{
    world->step(TimeLine::VariableUpdate, t);
}

void GameStage::onFixedUpdate(Time t)
{
    world->step(TimeLine::FixedUpdate, t);
}

void GameStage::onRender(RenderContext& rc) const
{
    world->render(rc);
}
