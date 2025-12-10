#include "game_stage.h"

void GameStage::init()
{
    EntityStage::init();

    mainThreadExecutor = std::make_unique<Executor>(Executors::getMainUpdateThread());
    videoThreadExecutor = std::make_unique<Executor>(Executors::getMainRenderThread());

    world = createWorld("stages/game_world");

    const auto scriptingService = std::make_shared<ScriptingService>(std::make_unique<ScriptEnvironment>(getAPI(), *world, getResources(), std::make_unique<ScriptNodeTypeCollection>()), getResources(), "", getAPI().core->isDevMode());
    world->addService(scriptingService);

    devService = std::make_shared<DevService>();
    world->addService(devService);

    auto factory = EntityFactory(*world, getResources());
    factory.createScene(getResources().get<Scene>("hello_world"), true);
    factory.createEntity("camera");
}

void GameStage::onVariableUpdate(Time t)
{
    world->step(TimeLine::VariableUpdate, t);

    mainThreadExecutor->runPending();

    EntityStage::onVariableUpdate(t);
}

void GameStage::onFixedUpdate(Time t)
{
    world->step(TimeLine::FixedUpdate, t);
}

void GameStage::onRender(RenderContext& rc) const
{
    videoThreadExecutor->runPending();

    world->render(rc);
}
