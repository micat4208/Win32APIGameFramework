#pragma once

#include "Framework/Includes/Includes.h"

// 하나의 스프라이트 애니메이션 정보를 나타냅니다.
struct FSpriteAnimInfo
{
    // 스프라이트 전환 딜레이
    float SpriteDelay;

    // 마지막으로 전환한 시간을 나타냅니다.
    float LastSpriteChangedTime;

    // 스프라이트 인덱스
    int SpriteIndex;

    // 스프라이트 Y 인덱스
    int SpriteYIndex;

    // 스프라이트 시작 / 끝 인덱스
    int SpriteStartIndex;
    int SpriteEndIndex;

    FSpriteAnimInfo();

    /// spriteDelay : 스프라이트 전환 시간 간격을 전달합니다.
    /// spriteStartIndex : 스프라이트 시작 인덱스를 전달합니다.
    /// spriteEndIndex : 스프라이트 끝 인덱스를 전달합니다.
    /// spriteYIndex : 스프라이트 Y 인덱스를 전달합니다.
    /// spriteIndex : 처음 이 애니메이션이 재생되었을 때 표시될 스프라이트 인덱스를 전달합니다.
    /// 만약 -1 이 전달되었다면 이 값은 spriteStartIndex 와 동일한 값으로 설정됩니다.
    FSpriteAnimInfo(
        float   spriteDelay, 
        int     spriteStartIndex, 
        int     spriteEndIndex,
        int     spriteYIndex, 
        int     spriteIndex = -1);

    // 다음 스프라이트 인덱스로 변경합니다.
    void Next();


};

