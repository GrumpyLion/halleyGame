#include "game_scene_editor.h"

GameSceneEditor::GameSceneEditor()
{

}

GameSceneEditor::~GameSceneEditor()
{

}

std::shared_ptr<Halley::UIWidget> GameSceneEditor::makeCustomUI()
{
	return nullptr;
}

void GameSceneEditor::onToolSet(String& tool, String& componentName, String& fieldName)
{
	SceneEditor::onToolSet(tool, componentName, fieldName);
}

void GameSceneEditor::setupTools(UIList& toolList, ISceneEditorGizmoCollection& gizmoCollection)
{
	SceneEditor::setupTools(toolList, gizmoCollection);
}

Halley::Vector<Halley::UIPopupMenuItem> GameSceneEditor::getSceneContextMenu(const Vector2f& mousePos) const
{
	return SceneEditor::getSceneContextMenu(mousePos);
}

void GameSceneEditor::onSceneContextMenuSelection(const String& id)
{
	SceneEditor::onSceneContextMenuSelection(id);
}

void GameSceneEditor::initializeEntityValidator(EntityValidator& validator)
{
	SceneEditor::initializeEntityValidator(validator);
}

bool GameSceneEditor::shouldDrawOutline(const Sprite& sprite) const
{
	return SceneEditor::shouldDrawOutline(sprite);
}

void GameSceneEditor::createServices(World& world, std::shared_ptr<const UIColourScheme> colourScheme,
    const Prefab& prefab)
{
	screenService = std::make_shared<ScreenService>(this);

    world.addService(screenService);
}

void GameSceneEditor::onInit(std::shared_ptr<const UIColourScheme> colourScheme)
{
	SceneEditor::onInit(colourScheme);
}

void GameSceneEditor::onEntitiesSelected(Vector<EntityId> entity)
{
	SceneEditor::onEntitiesSelected(entity);
}

void GameSceneEditor::setEntityFocus(Vector<EntityId> entityIds)
{
	SceneEditor::setEntityFocus(entityIds);
}

Halley::Vector<Halley::EntityId> GameSceneEditor::createCamera()
{
	return SceneEditor::createCamera();
}

Halley::Vector<Halley::EntityRef> GameSceneEditor::getEntitiesAt(Rect4f area, bool allowUnselectable, EntityAtPositionSelectMode mode) const
{
	return SceneEditor::getEntitiesAt(area, allowUnselectable, mode);
}

std::optional<Halley::Vector2f> GameSceneEditor::getWorldOffset() const
{
	return SceneEditor::getWorldOffset();
}

void GameSceneEditor::drawOverlay(Painter& painter, Rect4f view)
{
	SceneEditor::drawOverlay(painter, view);
}

Vector2i GameSceneEditor::getGameResolution()
{
	return viewPort;
}

Vector2i GameSceneEditor::getScreenResolution() const
{
	return viewPort;
}

Vector2i GameSceneEditor::getUIResolution()
{
	return getGameResolution();
}

float GameSceneEditor::getZoomLevel() const
{
	return 1.0f;
}