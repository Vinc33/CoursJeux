#include "MagicBullet.h"
#include "TimeManager.h"
#include "MagicBulletCandy.h"
#include  <math.h>

MagicBullet::MagicBullet() 
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets/ToolAndMagic/MagicBullet.png");
	SetSprite(texture);
	position.setOrigin(3, 3);
	timer = 0.2f;

	position.setPosition(200, 200);

	degree = 0;
}

MagicBullet::~MagicBullet()
{
}

void MagicBullet::Update()
{
	
	degree += 1;

	if (degree > 360)
		degree = 0;

	float rad = (degree * 3.14159265358979323846) / 180.0;
	position.move( 10,0 );

	position.rotate(degree);

	timer -= TimeManager::DeltaTime;
	if (timer < 0) {
		AddParticle(new MagicBulletCandy(.5f,&position, 30));
		AddParticle(new MagicBulletCandy(.5f, &position, 50));
        AddParticle(new MagicBulletCandy(.5f, &position, 70));
		timer += 0.2f;
		
	}
	EntityParticleEmitter::Update();

}

void MagicBullet::Draw(sf::RenderTarget& target)
{
	EntityInanimate::Draw( target);
	EntityParticleEmitter::Draw( target);
}
