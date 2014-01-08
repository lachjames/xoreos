/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names can be
 * found in the AUTHORS file distributed with this source
 * distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 * The Infinity, Aurora, Odyssey, Eclipse and Lycium engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 */

/** @file graphics/cameraman.h
 *  A camera manager.
 */

#ifndef GRAPHICS_CAMERAMAN_H
#define GRAPHICS_CAMERAMAN_H

#include "common/singleton.h"

namespace Ogre {
	class RenderWindow;
	class Viewport;
	class Camera;
}

namespace Graphics {

class CameraManager : public Common::Singleton<CameraManager> {
public:
	CameraManager();
	~CameraManager();

	void init();
	void deinit();

	/** Create a viewport for the camera in that window. */
	Ogre::Viewport *createViewport(Ogre::RenderWindow *window);
	/** Adjust the aspect ratio of the camera. */
	void setAspectRatio(float aspect);

	/** Reset the position and orientation of the camera. */
	void reset();

	void getPosition(float &x, float &y, float &z) const;
	void getDirection(float &x, float &y, float &z) const;

	void setPosition(float x, float y, float z);
	void setDirection(float x, float y, float z);

	void lookAt(float x, float y, float z);

	void setOrientation(float radian, float x, float y, float z);

	void move(float x, float y, float z);
	void moveRelative(float x, float y, float z);

	void rotate(float radian, float x, float y, float z);

	void roll(float radian);
	void yaw(float radian);
	void pitch(float radian);

private:
	Ogre::Camera *_camera; ///< The OGRE camera.
};

} // End of namespace Graphics

/** Shortcut for accessing the camera manager. */
#define CameraMan Graphics::CameraManager::instance()

#endif // GRAPHICS_CAMERAMAN_H
