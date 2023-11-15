#pragma once

#include <halley.hpp>
using namespace Halley;

class GameSceneEditor : public SceneEditor, public IScreenServiceInterface
{
public:
	GameSceneEditor();
	virtual ~GameSceneEditor();

	std::shared_ptr<UIWidget> makeCustomUI() override;
	void onToolSet(String& tool, String& componentName, String& fieldName) override;
	void setupTools(UIList& toolList, ISceneEditorGizmoCollection& gizmoCollection) override;
	Vector<UIPopupMenuItem> getSceneContextMenu(const Vector2f& mousePos) const override;
	void onSceneContextMenuSelection(const String& id) override;
	void initializeEntityValidator(EntityValidator& validator) override;
	bool shouldDrawOutline(const Sprite& sprite) const override;
	void createServices(World& world, std::shared_ptr<const UIColourScheme> colourScheme, const Prefab& prefab) override;

	Vector2i getGameResolution() final;
	Vector2i getScreenResolution() const final;
	Vector2i getUIResolution() final;
	float getZoomLevel() const final;

protected:
	void onInit(std::shared_ptr<const UIColourScheme> colourScheme) override;

	void onEntitiesSelected(Vector<EntityId> entity) override;
	void setEntityFocus(Vector<EntityId> entityIds) override;

	Vector<EntityId> createCamera() override;

	Vector<EntityRef> getEntitiesAt(Rect4f area, bool allowUnselectable, EntityAtPositionSelectMode mode) const override;

	std::optional<Vector2f> getWorldOffset() const override;

	void drawOverlay(Painter& painter, Rect4f view) override;

private:
	std::shared_ptr<ScreenService> screenService;

};