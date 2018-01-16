#ifndef PREVIEWSCENE_H
#define PREVIEWSCENE_H

#include "Scene.h"

class PreviewScene : public Scene {
public:
	PreviewScene();
	virtual ~PreviewScene();

	virtual void update();
};
#endif // !PREVIEWSCENE_H
