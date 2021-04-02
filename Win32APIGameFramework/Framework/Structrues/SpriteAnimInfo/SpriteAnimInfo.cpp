#include "SpriteAnimInfo.h"
#include "Framework/Structrues/Math/Math.h"

FSpriteAnimInfo::FSpriteAnimInfo() : 
	FSpriteAnimInfo(0, 0, 0, 0) { }

FSpriteAnimInfo::FSpriteAnimInfo(
	float	spriteDelay, 
	int		spriteStartIndex, 
	int		spriteEndIndex, 
	int		spriteYIndex, 
	int		spriteIndex)
{
	SpriteDelay = spriteDelay;
	LastSpriteChangedTime = 0.0f;
	SpriteStartIndex = spriteStartIndex;
	SpriteEndIndex = spriteEndIndex;

	SpriteIndex = (spriteIndex == -1) ? SpriteStartIndex : spriteIndex;
	SpriteIndex = FMath::Clamp(SpriteIndex, SpriteStartIndex, SpriteEndIndex);

	SpriteYIndex = spriteYIndex;

}

void FSpriteAnimInfo::Next()
{
	++SpriteIndex;
	SpriteIndex = (SpriteIndex > SpriteEndIndex) ? SpriteStartIndex : SpriteIndex;
}
