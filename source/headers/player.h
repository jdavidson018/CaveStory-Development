#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite
{
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/* moveLeft
	 * moves player left by -dx
	 */
	void moveLeft();

	/* moveRight
	 * moves player left dx
	 */
	void moveRight();

	/* stopMoving
	 * stops movement and plays idle animation for that direction
	 */
	void stopMoving();

	/* Getter functions
	 * for x and y
	 */
	const float getX() const;
	const float getY() const;

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle> &others);
private:
	float _dx, _dy;

	Direction _facing;

	bool _grounded;
};
#endif
