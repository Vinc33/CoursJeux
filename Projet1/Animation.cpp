#include "Animation.h"
#include "TimeManager.h"
#include <math.h>

Animation::Animation(Spritesheet ss)
{
	currentFrame = 0;
	currentTime = 0;
	spriteHeight = 0;
	spriteWidth = 0;

	spritesheet = ss;

	sprite = new sf::Sprite();
}

Animation::~Animation()
{
}

void Animation::addFrame(Coord index, int showTime)
{
	indexes.push_back(index);
	showTimes.push_back(showTime);
}

void Animation::update()
{
	if (showTimes[currentFrame] != -1)
	{
		currentTime += TimeManager::DeltaTime;
		if (currentTime >= (float)showTimes[currentFrame]/1000.0f)
		{
			currentTime -= (float)showTimes[currentFrame]/1000.0f;
			currentFrame++;

			if (currentFrame >= size(indexes)) 
				currentFrame = 0;
		}
	}
}

void Animation::updateHitbox()
{
	if (reversed)
	{
		uvRect.width = -spriteWidth;
		uvRect.left = (indexes[currentFrame].x + 1) * spriteWidth;
	}
	else
	{
		uvRect.width = spriteWidth;
		uvRect.left = indexes[currentFrame].x * spriteWidth;
	}
	uvRect.top = indexes[currentFrame].y * spriteHeight;
	sprite->setTextureRect(uvRect);
}

void Animation::restart()
{
	currentFrame = 0;
	currentTime = 0;
	uvRect.top = indexes[currentFrame].y * spriteHeight;
	sprite->setTextureRect(uvRect);
}

void Animation::jumpToFrame(unsigned int index)
{
	if (index < size(indexes))
		currentFrame = index;
}

void Animation::init(sf::Sprite* s)
{
	delete sprite;
	sprite = s;

	sprite->setTexture(*spritesheet.texture);

	spriteWidth = (int)floor((spritesheet.texture->getSize().x / float(spritesheet.nbColums)));
	spriteHeight = (int)floor((spritesheet.texture->getSize().y / float(spritesheet.nbRows)));

	uvRect.width = spriteWidth;
	uvRect.height = spriteHeight;
	sprite->setTextureRect(uvRect);
	sprite->setOrigin({ uvRect.width / 2.0f, uvRect.height / 2.0f });
}
