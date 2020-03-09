#include "physxImplement.h"

Strategy* PhysxImplement::makeStrategy(int param, int charName)
{
	if (param == StrategyParams::angry)
	{
		if (charName == Characters::Character1_name)
		{
			return new StrategyAnger1();
		}
		else if (charName == Characters::CharacterBat_name)
		{
			return new StrategyAnger2;
		}
	}
	else if (param == StrategyParams::peacful)
	{
		if (charName == Characters::CharacterBat_name
			|| charName == Characters::Character1_name)
		{
			return new StrategyPeace1();
		}
	}
	//if (param == StrategyType::StrategyPeace1_type)
	//{
	//	if (charName == Characters::Character1_name
	//		|| charName == Characters::CharacterBat_name)
	//	{
	//		return new StrategyPeace1();
	//	}
	//}
}