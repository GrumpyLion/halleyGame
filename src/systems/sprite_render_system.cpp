#include "systems/sprite_renderer_system.h"

using namespace Halley;

class SpriteRendererSystem final : public SpriteRendererSystemBase<SpriteRendererSystem>
{
public:
	void render(RenderContext& rc)
	{
		const auto test = getWorld().getEntities();

		spritePainter.start();
		for (const auto& camera : cameraFamily) {
			Camera cam(camera.transform2D.getGlobalPosition());
			cam.setZoom(camera.camera.zoom);
			rc.with(cam).bind([&](Painter& painter)
			{
				painter.clear(Colour(0, 0, 0, 1));

				for (const auto& sprite : spriteFamily) {
					sprite.sprite.sprite.setPosition(sprite.transform2D.getGlobalPosition());
					spritePainter.add(sprite.sprite.sprite, 1, sprite.sprite.layer, sprite.transform2D.getGlobalPosition().y);
				}

				spritePainter.draw(1, painter);
			});
		}
	}

private:
	SpritePainter spritePainter;
};

REGISTER_SYSTEM(SpriteRendererSystem)