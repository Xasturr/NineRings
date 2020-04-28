#include "characterBat.h"

CharacterBat::CharacterBat(float posX, float posY)
{
	bufferShoot_.loadFromFile("./audio/effects/magicShoot/shoot.ogg");
	soundShoot_.setBuffer(bufferShoot_);
	soundShoot_.setVolume(6);

	position_.x = posX;
	position_.y = posY;

	textureFly_.loadFromFile("./textures/characters/bat/bat.png");

	textureDeath_.loadFromFile("./textures/characters/bat/batDeath.png");

	textureHurt_.loadFromFile("./textures/characters/bat/batDamage.png");

	sprite_.setTexture(textureFly_);

	life_ = true;
	attack_ = false;
	runAttack_ = false;
	characterMadeDamage_ = false;
	damageDisabled_ = false;
	hurt_ = false;
	shoot_ = false;

	scaleFactor_ = 5;
	maxMoveSpeed_ = 300;
	currentFlyFrame_ = 1;
	currentDeathFrame_ = 1;
	currentHurtFrame_ = 1;
	numberOfFlyFrames_ = 3;
	numberOfDeathFrames_ = 3;
	numberOfHurtFrames_ = 3;
	frameSpeed_ = 8;
	leftGap_ = 6 * scaleFactor_; //from center to left edge
	rightGap_ = 6 * scaleFactor_;//from center to right edge
	//lowerGap_ = 23;
	//upperGap_ = 52;
	maxHealthPoints_ = currHealthPoints_ = 1000;
	maxStamina_ = currentStamina_ = 1000;
	maxMana_ = currentMana_ = 1000;
	attackDamage_ = 100;
	attackRange_ = 150;
	runAttackRange_ = 58;
	height_ = 15 * scaleFactor_; //height of character
	width_ = 10 * scaleFactor_; //width of caracter
	overview_ = 330;
	currFireBallAmount_ = 100;
	currAngle_ = 90;
	maxShotCoolDown_ = 2;
	currShotCoolDown_ = 0;
	manaRegen_ = 100;
	staminaRegen_ = 150;
	jumpStaminaCost_ = 150;
	attackStaminaCost_ = 200;
	killExp_ = 200;
	armor_ = 0;
	name_ = Characters::CharacterBat_name;

	sprite_.setOrigin(8, 15);
	sprite_.setScale(scaleFactor_, scaleFactor_);

	currSpriteSide_ = "right";
	state_ = "flying";
	currShellName_ = Shells::fireBallShell_name;
}

CharacterBat::~CharacterBat()
{
	cout << "In CharacterBat destructor" << endl;

	for (int i = 0; i < flyingShells_.size(); i++)
	{
		delete flyingShells_[i];
	}
}

Sprite CharacterBat::getSprite()
{
	return sprite_;
}

float CharacterBat::getMaxMoveSpeed()
{
	return maxMoveSpeed_;
}

float CharacterBat::getGravity()
{
	return gravity_;
}

float CharacterBat::getCurrGravityAccel()
{
	return currGravityAccel_;
}

float CharacterBat::getFrameSpeed()
{
	return frameSpeed_;
}

float CharacterBat::getCurrJumpAccel()
{
	return currJumpAccel_;
}

float CharacterBat::getJumpForce()
{
	return 0;
}

float CharacterBat::getCurrAttackFrame()
{
	return 0;
}

float CharacterBat::getCurrShotCoolDown()
{
	return currShotCoolDown_;
}

float CharacterBat::getMaxShotCoolDown()
{
	return maxShotCoolDown_;
}

float CharacterBat::getCurrStamina()
{
	return currentStamina_;
}

float CharacterBat::getCurrMana()
{
	return currentMana_;
}

float CharacterBat::getMaxMana()
{
	return maxMana_;
}

float CharacterBat::getCurrShellAngle()
{
	return currAngle_;
}

float CharacterBat::getCurrHealthPoints()
{
	return currHealthPoints_;
}

int CharacterBat::getCurrIdleFrame() {}

int CharacterBat::getMaxStamina()
{
	return maxStamina_;
}

int CharacterBat::getUpperGap()
{
	return upperGap_;
}

int CharacterBat::getLowerGap()
{
	return lowerGap_;
}

int CharacterBat::getLeftGap()
{
	return leftGap_;
}

int CharacterBat::getRightGap()
{
	return rightGap_;
}

int CharacterBat::getAttackRange()
{
	if (attack_)
	{
		return attackRange_;
	}
	else
	{
		return runAttackRange_;
	}
}

int CharacterBat::getMaxHealthPoints()
{
	return maxHealthPoints_;
}

float CharacterBat::getAttackDamage()
{
	return attackDamage_;
}

int CharacterBat::getNumberOfAttackFrames()
{
	return 0;
}

int CharacterBat::getHeight()
{
	return height_;
}

int CharacterBat::getWidth()
{
	return width_;
}

int CharacterBat::getOverview()
{
	return overview_;
}

int CharacterBat::getCurrFlyingShellAmount()
{
	return flyingShells_.size();
}

int CharacterBat::getCurrShellAmount()
{
	if (currShellName_ == Shells::fireBallShell_name)
	{
		return currFireBallAmount_;
	}

	return 0;
}

int CharacterBat::flyingShellsMakeDamage(Vector2f charPos, int charWidth, int charHeight)
{
	for (int i = 0; i < flyingShells_.size(); i++)
	{
		if (!flyingShells_[i]->getExplosed())
		{
			if (charPos.x - charWidth / 2 <= flyingShells_[i]->getPosition().x
				&& charPos.x + charWidth / 2 >= flyingShells_[i]->getPosition().x
				&& charPos.y - charHeight <= flyingShells_[i]->getPosition().y
				&& charPos.y >= flyingShells_[i]->getPosition().y)
			{
				//cout << "DAMAGED ENEMY" << endl;
				//flyingShells_[i]->setLife(false);
				flyingShells_[i]->setExplosed(true);
				//hurt_ = true;
				return flyingShells_[i]->getAlphaStrike();
			}
		}
	}

	return 0;
}

int CharacterBat::getManaRegen()
{
	return manaRegen_;
}

int CharacterBat::getStaminaRegen()
{
	return staminaRegen_;
}

int CharacterBat::getJumpStaminaCost()
{
	return jumpStaminaCost_;
}

int CharacterBat::getAttackStaminaCost()
{
	return attackStaminaCost_;
}

int CharacterBat::getKillExp()
{
	return killExp_;
}

int CharacterBat::getArmor()
{
	return armor_;
}

int CharacterBat::getName()
{
	return name_;
}

Vector2f CharacterBat::getCurrPosition()
{
	return position_;
}

bool CharacterBat::getCharacterLife()
{
	return life_;
}

bool CharacterBat::getAttackState()
{
	return attack_ || runAttack_;
}

void CharacterBat::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	sprite_.setPosition(x, y);
}

void CharacterBat::setCurrIdleFrame(float increase) {}

void CharacterBat::setCurrFlyFrame(float increase)
{
	currentFlyFrame_ += increase;

	runAttack_ = false;

	if (currentFlyFrame_ >= numberOfFlyFrames_)
		currentFlyFrame_ = 1;
}

void CharacterBat::setCurrRunFrame(float increase) {}

void CharacterBat::setCurrJumpFrame(float increase) {}

void CharacterBat::setCurrFallFrame(float increase) {}

void CharacterBat::setCurrAttackFrame(float increase) {}

void CharacterBat::setCurrRunAttackFrame(float increase) {}

void CharacterBat::setCurrDeathFrame(float increase)
{
	currentDeathFrame_ += increase / 10;

	if (currentDeathFrame_ > numberOfDeathFrames_)
	{
		life_ = false;
	}
}

void CharacterBat::setCurrHurtFrame(float increase)
{
	currentHurtFrame_ += increase / 3;
	//damageDisabled_ = true;
	//hurt_ = true;

	if (currentHurtFrame_ > numberOfHurtFrames_)
	{
		hurt_ = false;
		currentHurtFrame_ = 1;
		currentFlyFrame_ = 1;
		sprite_.setTexture(textureFly_);
		//damageDisabled_ = false;
	}
}

void CharacterBat::spriteUpdateIdle(string spriteSide) {}

void CharacterBat::updateSpriteSide(string spriteSide)
{
	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
		{
			sprite_.setScale(-1.f * scaleFactor_, 1.f * scaleFactor_);
			currAngle_ = -90;
		}
		else
		{
			sprite_.setScale(1.f * scaleFactor_, 1.f * scaleFactor_);
			currAngle_ = 90;
		}

		currSpriteSide_ = spriteSide;
	}
}

void CharacterBat::spriteUpdateFly(string spriteSide)
{
	sprite_.setTexture(textureFly_);

	if (int(currentFlyFrame_) == 1)
		sprite_.setTextureRect(IntRect(0, 0, 16, 18));
	else if (int(currentFlyFrame_) == 2)
		sprite_.setTextureRect(IntRect(16, 0, 16, 18));
	else
		sprite_.setTextureRect(IntRect(32, 0, 16, 18));

	updateSpriteSide(spriteSide);
}

void CharacterBat::spriteUpdateRun(string spriteSide) {}

void CharacterBat::spriteUpdateJump(string spriteSide) {}

void CharacterBat::spriteUpdateFall(string spriteSide) {}

void CharacterBat::spriteUpdateAttack(string spriteSide) {}

void CharacterBat::spriteUpdateRunAttack(string spriteSide) {}

void CharacterBat::spriteUpdateDeath(string spriteSide)
{
	sprite_.setTexture(textureDeath_);

	if (int(currentDeathFrame_) == 1)
		sprite_.setTextureRect(IntRect(0, 0, 16, 18));
	else if (int(currentDeathFrame_) == 2)
		sprite_.setTextureRect(IntRect(16, 0, 16, 18));
	else
		sprite_.setTextureRect(IntRect(32, 0, 16, 18));

	updateSpriteSide(spriteSide);
}

void CharacterBat::spriteUpdateHurt(string spriteSide)
{
	sprite_.setTexture(textureHurt_);

	if (int(currentHurtFrame_) == 1)
		sprite_.setTextureRect(IntRect(0, 0, 16, 18));
	else if (int(currentHurtFrame_) == 2)
		sprite_.setTextureRect(IntRect(16, 0, 16, 18));
	else
		sprite_.setTextureRect(IntRect(32, 0, 16, 18));

	updateSpriteSide(spriteSide);
}

void CharacterBat::setCurrGravityAccel(float value)
{
	currGravityAccel_ = value;
}

void CharacterBat::setCurrJumpAccel(float value)
{
	currJumpAccel_ = value;
}

void CharacterBat::setJumpState(bool flag) {}

void CharacterBat::setAttackState(bool flag)
{
	attack_ = flag;
}

void CharacterBat::setRunAttackState(bool flag)
{
	runAttack_ = flag;
}

void CharacterBat::setCurrHealthPoints(float currHealthPoints)
{
	currHealthPoints_ = currHealthPoints;
}

void CharacterBat::setCurrStamina(float currStamina)
{
	currentStamina_ = currStamina;
}

void CharacterBat::setCurrMana(float currMana)
{
	currentMana_ = currMana;
}

Shell* CharacterBat::addFlyingShell(int shellName, float angle)
{
	Shell* shell = nullptr;

	if (shellName == Shells::fireBallShell_name && currFireBallAmount_ > 0)
	{
		currFireBallAmount_ -= 1;

		shell = new ShellFireBall(position_.x + width_ / 2, position_.y - height_ / 2, angle, currSpriteSide_);
		soundShoot_.play();
		flyingShells_.push_back(shell);
	}

	return shell;
}

Shell* CharacterBat::addFlyingShell(int shellName, bool doubleDamage, float angle)
{
	Shell* shell = nullptr;

	if (shellName == Shells::fireBallShell_name && currFireBallAmount_ > 0)
	{
		currFireBallAmount_ -= 1;

		if (doubleDamage)
		{
			//shell = new DDMagicDecorator(new ShellFireBall(position_.x + width_ / 2, position_.y - height_ / 2, currAngle_, currSpriteSide_));
		}
		else
		{
			shell = new ShellFireBall(position_.x + width_ / 2, position_.y - height_ / 2, angle, currSpriteSide_);
		}
		soundShoot_.play();

		flyingShells_.push_back(shell);
	}

	return shell;
}

void CharacterBat::flyingShellsUpdateAndDraw(float elapsedTime, Map* map, RenderWindow* window)
{
	int eraseShell = -1;

	for (int i = 0; i < flyingShells_.size(); i++)
	{
		if (flyingShells_[i]->getLife())
		{
			flyingShells_[i]->updateAndDraw(elapsedTime, map, window);
		}
		else
		{
			eraseShell = i;
		}
	}

	if (eraseShell != -1)
	{
		Shell* shell = flyingShells_.at(eraseShell);
		flyingShells_.erase(flyingShells_.begin() + eraseShell);
		delete shell;
	}
}

void CharacterBat::setCurrShotCoolDown(float currShotCoolDown)
{
	currShotCoolDown_ = currShotCoolDown;
}

void CharacterBat::setCurrShellAgle(float angle)
{
	currAngle_ = angle;
}

void CharacterBat::setMaxHealthPoints(int healthPoints)
{
	maxHealthPoints_ = healthPoints;
}

void CharacterBat::setArmor(int armor)
{
	armor_ = armor;
}

void CharacterBat::setMaxMana(int mana)
{
	maxMana_ = mana;
}

void CharacterBat::setMaxStamina(int stamina)
{
	maxStamina_ = stamina;
}

void CharacterBat::setEnemyDamaged(bool flag)
{
	characterMadeDamage_ = flag;
}

void CharacterBat::setState(string state)
{
	state_ = state;
}

void CharacterBat::setName(int name)
{
	name_ = name;
}

void CharacterBat::setMaxMoveSpeed(float maxMoveSpeed)
{
	maxMoveSpeed_ = maxMoveSpeed;
}

void CharacterBat::setSpriteSide(string spriteSide)
{
	currSpriteSide_ = spriteSide;
}

void CharacterBat::setLife(float flag)
{
	life_ = flag;
}

void CharacterBat::setHurt(bool flag)
{
	hurt_ = flag;
}

bool CharacterBat::getJumpState()
{
	return false;
}

bool CharacterBat::getRunAttackState()
{
	return runAttack_;
}

bool CharacterBat::getLife()
{
	return life_;
}

bool CharacterBat::getCharacterMadeDamage()
{
	return characterMadeDamage_;
}

bool CharacterBat::getDamageDisabled()
{
	return damageDisabled_;
}

bool CharacterBat::getHurt()
{
	return hurt_;
}

bool CharacterBat::calculateAngryState(Vector2f playerPos)
{
	if (abs(playerPos.x - position_.x) <= overview_ && abs(playerPos.y - position_.y) <= 64 * 4) //!
	{
		return true;
	}

	return false;
}

string CharacterBat::getCurrSpriteSide()
{
	return currSpriteSide_;
}

string CharacterBat::getCurrState()
{
	return state_;
}

int CharacterBat::getCurrShellName()
{
	return currShellName_;
}