#include "Animation.h"
#include "TimeManager.h"
#include <math.h>

Animation::Animation(Spritesheet ss)
{
	currentFrame = 0;
	currentTime = 0;

	spritesheet = ss;

	currentSprite = new sf::Sprite();
	currentSprite->setTexture(*spritesheet.texture);
	currentSprite->setScale(2, 2);

	spriteWidth = (int)floor((spritesheet.texture->getSize().x / float(spritesheet.nbColums)));
	spriteHeight = (int)floor((spritesheet.texture->getSize().y / float(spritesheet.nbRows)));

	uvRect.width = spriteWidth;
	uvRect.height = spriteHeight;
	currentSprite->setTextureRect(uvRect);
	currentSprite->setOrigin({ uvRect.width / 2.0f, uvRect.height / 2.0f });
}

Animation::~Animation()
{
	//delete spritesheet.texture;
	delete currentSprite;
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
	currentSprite->setTextureRect(uvRect);
}

sf::Sprite* Animation::GetSprite()
{
	return currentSprite;
}

void Animation::restart()
{
	currentFrame = 0;
	currentTime = 0;
	uvRect.top = indexes[currentFrame].y * spriteHeight;
	currentSprite->setTextureRect(uvRect);
}

void Animation::JumpToFrame(unsigned int index)
{
	if (index < size(indexes))
		currentFrame = index;
}
