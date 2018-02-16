#ifndef TARGETTEXTURE_H
#define TARGETTEXTURE_H

#include "WindowResizeEvent.h"
#include "SHEventListener.h"

class TargetTexture : public EventListener
{
public:
	TargetTexture();
	virtual ~TargetTexture();

	static void resizeTest(WindowResizeEvent e);
	static void scrollTest(ScrollEvent e);
private:

};
#endif // !TARGETTEXTURE_H
