#pragma once

#include <halley.hpp>
using namespace Halley;

class HalleyGame : public Game {
public:
	void init(const Environment& env, const Vector<String>& args) override;
	int initPlugins(IPluginRegistry& registry) override;
	ResourceOptions initResourceLocator(const Path& gamePath, const Path& assetsPath, const Path& unpackedAssetsPath, ResourceLocator& locator) override;

	String getName() const override;
	String getDataPath(const Vector<String>& args) const override;
	bool isDevMode() const override;
	std::unique_ptr<Stage> startGame() override;

	std::unique_ptr<ISceneEditor> createSceneEditorInterface() override;

private:
	const HalleyAPI* api;
};
