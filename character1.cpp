#include "character1.h"

Character1::Character1(float posX, float posY)
{
	position_.x = posX;
	position_.y = posY;

	//CreateTextureAndBitmask(textureIdle1_, "./textures/tiles/characters/knight/Idle/idle1.png");
	//CreateTextureAndBitmask(textureIdle2_, "./textures/tiles/characters/knight/Idle/idle2.png");
	//CreateTextureAndBitmask(textureIdle3_, "./textures/tiles/characters/knight/Idle/idle3.png");
	//CreateTextureAndBitmask(textureIdle4_, "./textures/tiles/characters/knight/Idle/idle4.png");
	//CreateTextureAndBitmask(textureIdle5_, "./textures/tiles/characters/knight/Idle/idle5.png");
	//CreateTextureAndBitmask(textureIdle6_, "./textures/tiles/characters/knight/Idle/idle6.png");
	//CreateTextureAndBitmask(textureIdle7_, "./textures/tiles/characters/knight/Idle/idle7.png");
	//CreateTextureAndBitmask(textureIdle8_, "./textures/tiles/characters/knight/Idle/idle8.png");
	//CreateTextureAndBitmask(textureIdle9_, "./textures/tiles/characters/knight/Idle/idle9.png");
	//CreateTextureAndBitmask(textureIdle10_, "./textures/tiles/characters/knight/Idle/idle10.png");
	//CreateTextureAndBitmask(textureIdle11_, "./textures/tiles/characters/knight/Idle/idle11.png");
	//CreateTextureAndBitmask(textureIdle12_, "./textures/tiles/characters/knight/Idle/idle12.png");

	textureIdle1_.loadFromFile("./textures/tiles/characters/knight/Idle/idle1.png");
	textureIdle2_.loadFromFile("./textures/tiles/characters/knight/Idle/idle2.png");
	textureIdle3_.loadFromFile("./textures/tiles/characters/knight/Idle/idle3.png");
	textureIdle4_.loadFromFile("./textures/tiles/characters/knight/Idle/idle4.png");
	textureIdle5_.loadFromFile("./textures/tiles/characters/knight/Idle/idle5.png");
	textureIdle6_.loadFromFile("./textures/tiles/characters/knight/Idle/idle6.png");
	textureIdle7_.loadFromFile("./textures/tiles/characters/knight/Idle/idle7.png");
	textureIdle8_.loadFromFile("./textures/tiles/characters/knight/Idle/idle8.png");
	textureIdle9_.loadFromFile("./textures/tiles/characters/knight/Idle/idle9.png");
	textureIdle10_.loadFromFile("./textures/tiles/characters/knight/Idle/idle10.png");
	textureIdle11_.loadFromFile("./textures/tiles/characters/knight/Idle/idle11.png");
	textureIdle12_.loadFromFile("./textures/tiles/characters/knight/Idle/idle12.png");

	//CreateTextureAndBitmask(textureRun1_, "./textures/tiles/characters/knight/Run/run1.png");
	//CreateTextureAndBitmask(textureRun2_, "./textures/tiles/characters/knight/Run/run2.png");
	//CreateTextureAndBitmask(textureRun3_, "./textures/tiles/characters/knight/Run/run3.png");
	//CreateTextureAndBitmask(textureRun4_, "./textures/tiles/characters/knight/Run/run4.png");
	//CreateTextureAndBitmask(textureRun5_, "./textures/tiles/characters/knight/Run/run5.png");
	//CreateTextureAndBitmask(textureRun6_, "./textures/tiles/characters/knight/Run/run6.png");
	//CreateTextureAndBitmask(textureRun7_, "./textures/tiles/characters/knight/Run/run7.png");
	//CreateTextureAndBitmask(textureRun8_, "./textures/tiles/characters/knight/Run/run8.png");

	textureRun1_.loadFromFile("./textures/tiles/characters/knight/Run/run1.png");
	textureRun2_.loadFromFile("./textures/tiles/characters/knight/Run/run2.png");
	textureRun3_.loadFromFile("./textures/tiles/characters/knight/Run/run3.png");
	textureRun4_.loadFromFile("./textures/tiles/characters/knight/Run/run4.png");
	textureRun5_.loadFromFile("./textures/tiles/characters/knight/Run/run5.png");
	textureRun6_.loadFromFile("./textures/tiles/characters/knight/Run/run6.png");
	textureRun7_.loadFromFile("./textures/tiles/characters/knight/Run/run7.png");
	textureRun8_.loadFromFile("./textures/tiles/characters/knight/Run/run8.png");

	//CreateTextureAndBitmask(textureJump1_, "./textures/tiles/characters/knight/Jump/jump1.png");
	//CreateTextureAndBitmask(textureJump2_, "./textures/tiles/characters/knight/Jump/jump2.png");
	//CreateTextureAndBitmask(textureJump3_, "./textures/tiles/characters/knight/Jump/jump3.png");
	//CreateTextureAndBitmask(textureJump4_, "./textures/tiles/characters/knight/Jump/jump4.png");
	//CreateTextureAndBitmask(textureJump5_, "./textures/tiles/characters/knight/Jump/jump5.png");
	//CreateTextureAndBitmask(textureJump6_, "./textures/tiles/characters/knight/Jump/jump6.png");
	//CreateTextureAndBitmask(textureJump7_, "./textures/tiles/characters/knight/Jump/jump7.png");

	textureJump1_.loadFromFile("./textures/tiles/characters/knight/Jump/jump1.png");
	textureJump2_.loadFromFile("./textures/tiles/characters/knight/Jump/jump2.png");
	textureJump3_.loadFromFile("./textures/tiles/characters/knight/Jump/jump3.png");
	textureJump4_.loadFromFile("./textures/tiles/characters/knight/Jump/jump4.png");
	textureJump5_.loadFromFile("./textures/tiles/characters/knight/Jump/jump5.png");
	textureJump6_.loadFromFile("./textures/tiles/characters/knight/Jump/jump6.png");
	textureJump7_.loadFromFile("./textures/tiles/characters/knight/Jump/jump7.png");

	//CreateTextureAndBitmask(textureFall1_, "./textures/tiles/characters/knight/Jump/jump6.png");

	textureFall1_.loadFromFile("./textures/tiles/characters/knight/Jump/jump6.png");

	textureAttack1_.loadFromFile("./textures/tiles/characters/knight/Attack/attack1.png");
	textureAttack2_.loadFromFile("./textures/tiles/characters/knight/Attack/attack2.png");
	textureAttack3_.loadFromFile("./textures/tiles/characters/knight/Attack/attack3.png");
	textureAttack4_.loadFromFile("./textures/tiles/characters/knight/Attack/attack4.png");

	textureRunAttack1_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack1.png");
	textureRunAttack2_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack2.png");
	textureRunAttack3_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack3.png");
	textureRunAttack4_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack4.png");
	textureRunAttack5_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack5.png");
	textureRunAttack6_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack6.png");
	textureRunAttack7_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack7.png");
	textureRunAttack8_.loadFromFile("./textures/tiles/characters/knight/Run_Attack/run_attack8.png");

	sprite_.setTexture(textureIdle1_);
	sprite_.setOrigin(textureRun1_.getSize().x / 2 - 0, textureRun1_.getSize().y / 2);

	life_ = true;
	jump_ = false;
	attack_ = false;
	runAttack_ = false;

	maxMoveSpeed = 500;
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentAttackFrame_ = 1;
	currentRunAttackFrame_ = 1;
	numberOfIdleFrames_ = 12;
	numberOfRunFrames_ = 8;
	numberOfJumpFrames_ = 6;
	numberOfFallFrames_ = 1;
	numberOfAttackFrames_ = 4;
	numberOfRunAttackFrames_ = 8;
	frameSpeed_ = 10;
	gravity_ = 1600.f;
	jumpForce_ = 700.f;
	currJumpAccel_ = 0.f;
	leftGap_ = 18;
	rightGap_ = 18;
	lowerGap_ = 45;
	upperGap_ = 5;
	currGravityAccel_ = jumpForce_;

	currSpriteSide_ = "right";
	state_ = "falling";
}
Character1::~Character1() {}

Sprite Character1::getSprite()
{
	return sprite_;
}

float Character1::getMaxMoveSpeed()
{
	return maxMoveSpeed;
}

float Character1::getGravity()
{
	return gravity_;
}

float Character1::getCurrGravityAccel()
{
	return currGravityAccel_;
}

float Character1::getFrameSpeed()
{
	return frameSpeed_;
}

float Character1::getCurrJumpAccel()
{
	return currJumpAccel_;
}

float Character1::getJumpForce()
{
	return jumpForce_;
}

int Character1::getCurrIdleFrame()
{
	return currentIdleFrame_;
}

int Character1::getUpperGap()
{
	return upperGap_;
}

int Character1::getLowerGap()
{
	return lowerGap_;
}

int Character1::getLeftGap()
{
	return leftGap_;
}

int Character1::getRightGap()
{
	return rightGap_;
}

Vector2f Character1::getCurrPosition()
{
	return position_;
}

bool Character1::getCharacterLife()
{
	return life_;
}

bool Character1::getAttackState()
{
	return attack_;
}

void Character1::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	sprite_.setPosition(x, y);
}

void Character1::setCurrIdleFrame(float increase)
{
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentRunAttackFrame_ = 1;
	
	currentIdleFrame_ += increase;

	runAttack_ = false;

	if (currentIdleFrame_ >= numberOfIdleFrames_)
		currentIdleFrame_ = 1;
}

void Character1::setCurrRunFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentJumpFrame_ = 1;
	currentFallFrame_ = 1;
	currentAttackFrame_ = 1;
	currentRunFrame_ += increase;

	attack_ = false;

	if (currentRunFrame_ >= numberOfRunFrames_)
		currentRunFrame_ = 1;
}

void Character1::setCurrJumpFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentFallFrame_ = 1;
	currentRunAttackFrame_ = 1;

	currentJumpFrame_ += (increase / 1.4);

	runAttack_ = false;

	if (currentJumpFrame_ >= numberOfJumpFrames_)
	{
		state_ = "falling";
		currGravityAccel_ = 0.f;
	}
}

void Character1::setCurrFallFrame(float increase)
{
	currentIdleFrame_ = 1;
	currentRunFrame_ = 1;
	currentJumpFrame_ = 1;
	currentRunAttackFrame_ = 1;

	currentFallFrame_ += increase;

	runAttack_ = false;

	if (currentFallFrame_ >= numberOfFallFrames_)
		currentFallFrame_ = numberOfFallFrames_;
}

void Character1::setCurrAttackFrame(float increase)
{
	currentRunAttackFrame_ = 1;

	currentAttackFrame_ += increase / 1.2;

	runAttack_ = false;

	if (currentAttackFrame_ >= numberOfAttackFrames_)
	{
		currentAttackFrame_ = 1;
		attack_ = false;
	}
}

void Character1::setCurrRunAttackFrame(float increase)
{
	currentRunAttackFrame_ += increase * 1.5;

	if (currentRunAttackFrame_ >= numberOfRunAttackFrames_)
	{
		currentRunAttackFrame_ = 1;
		runAttack_ = false;
	}
}

void Character1::spriteUpdateIdle()
{
	if (int(currentIdleFrame_) == 1)
		sprite_.setTexture(textureIdle1_);
	else if (int(currentIdleFrame_) == 2)
		sprite_.setTexture(textureIdle2_);
	else if (int(currentIdleFrame_) == 3)
		sprite_.setTexture(textureIdle3_);
	else if (int(currentIdleFrame_) == 4)
		sprite_.setTexture(textureIdle4_);
	else if (int(currentIdleFrame_) == 5)
		sprite_.setTexture(textureIdle5_);
	else if (int(currentIdleFrame_) == 6)
		sprite_.setTexture(textureIdle6_);
	else if (int(currentIdleFrame_) == 7)
		sprite_.setTexture(textureIdle7_);
	else if (int(currentIdleFrame_) == 8)
		sprite_.setTexture(textureIdle8_);
	else if (int(currentIdleFrame_) == 9)
		sprite_.setTexture(textureIdle9_);
	else if (int(currentIdleFrame_) == 10)
		sprite_.setTexture(textureIdle10_);
	else if (int(currentIdleFrame_) == 11)
		sprite_.setTexture(textureIdle11_);
	else 
		sprite_.setTexture(textureIdle12_);
}

void Character1::spriteUpdateRun(string spriteSide)
{
	if (int(currentRunFrame_) == 1)
		sprite_.setTexture(textureRun1_);
	else if (int(currentRunFrame_) == 2)
		sprite_.setTexture(textureRun2_);
	else if (int(currentRunFrame_) == 3)
		sprite_.setTexture(textureRun3_);
	else if (int(currentRunFrame_) == 4)
		sprite_.setTexture(textureRun4_);
	else if (int(currentRunFrame_) == 5)
		sprite_.setTexture(textureRun5_);
	else if (int(currentRunFrame_) == 6)
		sprite_.setTexture(textureRun6_);
	else if (int(currentRunFrame_) == 7)
		sprite_.setTexture(textureRun7_);
	else
		sprite_.setTexture(textureRun8_);

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
	}
}

void Character1::spriteUpdateJump(string spriteSide)
{
	if (int(currentJumpFrame_) == 1)
		sprite_.setTexture(textureJump1_);
	else if (int(currentJumpFrame_) == 2)
		sprite_.setTexture(textureJump2_);
	else if (int(currentJumpFrame_) == 3)
		sprite_.setTexture(textureJump3_);
	else if (int(currentJumpFrame_) == 4)
		sprite_.setTexture(textureJump4_);
	else if (int(currentJumpFrame_) == 5)
		sprite_.setTexture(textureJump5_);
	else if (int(currentJumpFrame_) == 6)
		sprite_.setTexture(textureJump6_);
	else 
		sprite_.setTexture(textureJump7_);

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
	}
}

void Character1::spriteUpdateFall(string spriteSide)
{
	if (int(currentJumpFrame_) == 1)
	{
		sprite_.setTexture(textureFall1_);
	}

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
	}
}

void Character1::spriteUpdateAttack(string spriteSide)
{
	if (int(currentAttackFrame_) == 1)
		sprite_.setTexture(textureAttack1_);
	else if (int(currentAttackFrame_) == 2)
		sprite_.setTexture(textureAttack2_);
	else if (int(currentAttackFrame_) == 3)
		sprite_.setTexture(textureAttack3_);
	else
		sprite_.setTexture(textureAttack4_);

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
	}
}

void Character1::spriteUpdateRunAttack(string spriteSide)
{
	if (int(currentRunAttackFrame_) == 1)
		sprite_.setTexture(textureRunAttack1_);
	else if (int(currentRunAttackFrame_) == 2)
		sprite_.setTexture(textureRunAttack2_);
	else if (int(currentRunAttackFrame_) == 3)
		sprite_.setTexture(textureRunAttack3_);
	else if (int(currentRunAttackFrame_) == 4)
		sprite_.setTexture(textureRunAttack4_);
	else if (int(currentRunAttackFrame_) == 5)
		sprite_.setTexture(textureRunAttack5_);
	else if (int(currentRunAttackFrame_) == 6)
		sprite_.setTexture(textureRunAttack6_);
	else if (int(currentRunAttackFrame_) == 7)
		sprite_.setTexture(textureRunAttack7_);
	else
		sprite_.setTexture(textureRunAttack8_);

	if (currSpriteSide_ != spriteSide)
	{
		if (spriteSide == "left")
			sprite_.setScale(-1.f, 1.f);
		else
			sprite_.setScale(1.f, 1.f);

		currSpriteSide_ = spriteSide;
	}
}

void Character1::setCurrGravityAccel(float value)
{
	currGravityAccel_ = value;
}

void Character1::setCurrJumpAccel(float value)
{
	currJumpAccel_ = value;
}

void Character1::setJumpState(bool flag)
{
	jump_ = flag;
}

void Character1::setAttackState(bool flag)
{
	attack_ = flag;
}

void Character1::setRunAttackState(bool flag)
{
	runAttack_ = flag;
}

void Character1::setState(string state)
{
	state_ = state;
}

bool Character1::getJumpState()
{
	return jump_;
}

bool Character1::getRunAttackState()
{
	return runAttack_;
}

string Character1::getCurrSpriteSide()
{
	return currSpriteSide_;
}

string Character1::getCurrState()
{
	return state_;
}