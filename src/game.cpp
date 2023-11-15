#include "game.h"
#include "game_stage.h"

#include "editor/game_scene_editor.h"

void initMetalPlugin(IPluginRegistry &registry);
void initOpenGLPlugin(IPluginRegistry &registry);
void initSDLSystemPlugin(IPluginRegistry &registry, std::optional<String> cryptKey);
void initSDLAudioPlugin(IPluginRegistry &registry);
void initSDLInputPlugin(IPluginRegistry &registry);
void initDX11Plugin(IPluginRegistry &registry);
void initAsioPlugin(IPluginRegistry &registry);

void HalleyGame::init(const Environment& env, const Vector<String>& args)
{
}

int HalleyGame::initPlugins(IPluginRegistry& registry)
{
	initOpenGLPlugin(registry);
	initSDLSystemPlugin(registry, {});
	initSDLAudioPlugin(registry);
	initSDLInputPlugin(registry);

#ifdef WITH_METAL
	initMetalPlugin(registry);
#endif

#ifdef WITH_DX11
	initDX11Plugin(registry);
#endif
#ifdef WITH_ASIO
	initAsioPlugin(registry);
#endif

	return HalleyAPIFlags::Video | HalleyAPIFlags::Audio | HalleyAPIFlags::Input | HalleyAPIFlags::Network | HalleyAPIFlags::Platform;
}

ResourceOptions HalleyGame::initResourceLocator(const Path& gamePath, const Path& assetsPath, const Path& unpackedAssetsPath, ResourceLocator& locator)
{
	constexpr bool localAssets = false;
    if (localAssets) {
		locator.addFileSystem(unpackedAssetsPath);
	}
	else {
		struct PackId {
			String name;
			bool preLoad = false;
		};
		const bool preloadAll = isDevMode();
		const PackId packs[] = {
			{"gameplay.dat", true},
			{"world.dat", true},
			{"images.dat", preloadAll},
			{"imageData.dat", true},
			{"shaders.dat", true},
			{"ui.dat", preloadAll},
			{"config.dat", true},
			{"meshes.dat", preloadAll},
			//{"music.dat", preloadAll},
			//{"sfx.dat", preloadAll}
		};
		for (auto& pack : packs) {
			locator.addPack(Path(assetsPath) / pack.name, "", pack.preLoad);
		}

		constexpr bool isPC = getPlatform() == GamePlatform::Windows || getPlatform() == GamePlatform::Linux || getPlatform() == GamePlatform::MacOS || getPlatform() == GamePlatform::UWP;
		return ResourceOptions(isPC, isDevMode());
	}
}

String HalleyGame::getName() const
{
	return "Halley Game";
}

String HalleyGame::getDataPath() const
{
	return "Halley/HalleyGame";
}

bool HalleyGame::isDevMode() const
{
	return true;
}

std::unique_ptr<Stage> HalleyGame::startGame()
{
	bool vsync = true;

	getAPI().video->setWindow(WindowDefinition(WindowType::Window, Vector2i(1280, 720), getName()));
	getAPI().video->setVsync(vsync);
	getAPI().audio->startPlayback();
	return std::make_unique<GameStage>();
}


std::unique_ptr<Halley::ISceneEditor> HalleyGame::createSceneEditorInterface()
{
	return std::make_unique<GameSceneEditor>();
}

HalleyGame(HalleyGame);
