#include "enemy.h"

Enemy::Enemy(string charName, float posX, float posY, PhysxImplement* physx)
{
	charName_ = charName;

	if (charName_ == "Character1")
	{
		character_ = new Character1(posX, posY);
	}
	else
	{
		cout << "Wrong character" << endl;
		exit(EXIT_FAILURE);
	}

	states_.leftPressed_ = false;
	states_.rightPressed_ = false;
	states_.upPressed_ = false;
	states_.downPressed_ = false;
	states_.attack_ = false;
	states_.runAttack_ = false;
	states_.angryState_ = false;
	states_.onEdge_ = false;

	//stayingTime_ = 0;
	//runningTime_ = 0;

	character_->setPosition(posX, posY);

	physx_ = physx;
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor" << endl;
	delete character_;
	delete physx_;
}

bool Enemy::getEnemyLife()
{
	return character_->getLife();
}

void Enemy::updatePosition(float elapsedTime)
{
	physx_->updatePosition(character_, &states_, elapsedTime);
}

void Enemy::draw(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	if (player->getCurrPosition().x + viewSize.x / 2 + 50 >= character_->getCurrPosition().x && player->getCurrPosition().x - viewSize.x / 2 - 50 <= character_->getCurrPosition().x)
	{
		if (player->getCurrPosition().y + viewSize.y / 2 + 50 >= character_->getCurrPosition().y && player->getCurrPosition().y - viewSize.y / 2 - 50 <= character_->getCurrPosition().y)
		{
			//if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && abs(player->getCurrPosition().y - character_->getCurrPosition().y) <= character_->getHeight())
			if (abs(player->getCurrPosition().x - character_->getCurrPosition().x) <= character_->getOverview() && player->getCurrPosition().y == character_->getCurrPosition().y)
			{
				states_.angryState_ = true;
				character_->setMaxMoveSpeed(300);
			}
			else
			{
				states_.angryState_ = false;
				states_.attack_ = false;
				character_->setMaxMoveSpeed(200);
				character_->setState("staying");
				//stayingTime_ = 0;
				//runningTime_ = 0;
			}
			////character_->setPosition(character_->getCurrPosition().x, character_->getCurrPosition().y + character_->getGravity() * elapsedTime);
			//character_->setCurrIdleFrame(character_->getFrameSpeed() * elapsedTime);
			//character_->spriteUpdateIdle();
			checkDamage(player);
			window->draw(character_->getSprite());
		}
	}
}

void Enemy::interactionWithMap(Vector2f oldEnemyPosition, Vector2f newEnemyPosition, Map* map, float elapsedTime)
{
	physx_->interactionWithMap(&states_, character_, oldEnemyPosition, map, elapsedTime);
}
	
void Enemy::decision(float elapsedTime, Player* player)
{
	physx_->decision(player, character_, &states_, elapsedTime);
}

//void Enemy::calculateVariables(float elapsedTime)
//{
//	if (character_->getCurrState() == "falling")
//	{
//		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
//	}
//	else if (character_->getCurrState() == "jumping")
//	{
//		character_->setCurrGravityAccel(character_->getCurrGravityAccel() + character_->getGravity() * elapsedTime);
//		character_->setCurrJumpAccel(character_->getCurrJumpAccel() - character_->getCurrGravityAccel() * elapsedTime);
//	}
//}

void Enemy::setCurrHealthPoints(int healthPoints)
{
	character_->setCurrHealthPoints(healthPoints);
}

void Enemy::setHurt(bool flag)
{
	character_->setHurt(flag);
}

int Enemy::getWidth()
{
	return character_->getWidth();
}

int Enemy::getHeight()
{
	return character_->getHeight();
}

int Enemy::getCurrHealthPoints()
{
	return character_->getCurrHealthPoints();
}

Vector2f Enemy::getPosition()
{
	return character_->getSprite().getPosition();
}

Sprite Enemy::getSprite()
{
	return character_->getSprite();
}

void Enemy::checkDamage(Player* player)
{
	if (player->getAttackState() && !player->getCharacterMadeDamage() && !player->getDamageDisabled() && character_->getCurrHealthPoints() > 0 && !character_->getHurt())
	{
		if (player->getCurrPosition().y - player->getHeight() < character_->getCurrPosition().y && player->getCurrPosition().y > character_->getCurrPosition().y - character_->getHeight())
		{
			if (player->getCurrSpriteSide() == "left")
			{
				if (player->getCurrPosition().x - player->getAttackRange() <= character_->getCurrPosition().x + character_->getWidth() / 2 && player->getCurrPosition().x > character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getCurrHealthPoints() << endl;
					character_->setHurt(true);
				}
			}
			else
			{
				if (player->getCurrPosition().x + player->getAttackRange() > character_->getCurrPosition().x - character_->getWidth() / 2 && player->getCurrPosition().x < character_->getCurrPosition().x)
				{
					player->setEnemyDamaged(true);
					character_->setCurrHealthPoints(character_->getCurrHealthPoints() - player->getAttackDamage());
					cout << "Enemy health: " << character_->getCurrHealthPoints() << endl;
					character_->setHurt(true);
				}
			}
		}
	}

	if (character_->getAttackState() && !character_->getCharacterMadeDamage() && !character_->getDamageDisabled() && player->getCurrHealthPoints() > 0 && !player->getHurt())
	{
		if (character_->getCurrPosition().y - character_->getHeight() < player->getCurrPosition().y && character_->getCurrPosition().y > player->getCurrPosition().y - player->getHeight())
		{
			if (character_->getCurrSpriteSide() == "left")
			{
				if (character_->getCurrPosition().x - character_->getAttackRange() <= player->getCurrPosition().x + player->getWidth() / 2 && character_->getCurrPosition().x > player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage());
					//cout << "Player health: " << player->getCurrHealthPoints() << endl;
					player->setHurt(true);
				}
			}
			else
			{
				if (character_->getCurrPosition().x + character_->getAttackRange() > player->getCurrPosition().x - player->getWidth() / 2 && character_->getCurrPosition().x < player->getCurrPosition().x)
				{
					character_->setEnemyDamaged(true);
					player->setCurrHealthPoints(player->getCurrHealthPoints() - character_->getAttackDamage());
					//cout << "Player health: " << player->getCurrHealthPoints() << endl;
					player->setHurt(true);
				}
			}
		}
	}
}