#pragma once

#include "Framework/Includes/Includes.h"

// �ϳ��� ��������Ʈ �ִϸ��̼� ������ ��Ÿ���ϴ�.
struct FSpriteAnimInfo
{
    // ��������Ʈ ��ȯ ������
    float SpriteDelay;

    // ���������� ��ȯ�� �ð��� ��Ÿ���ϴ�.
    float LastSpriteChangedTime;

    // ��������Ʈ �ε���
    int SpriteIndex;

    // ��������Ʈ Y �ε���
    int SpriteYIndex;

    // ��������Ʈ ���� / �� �ε���
    int SpriteStartIndex;
    int SpriteEndIndex;

    FSpriteAnimInfo();

    /// spriteDelay : ��������Ʈ ��ȯ �ð� ������ �����մϴ�.
    /// spriteStartIndex : ��������Ʈ ���� �ε����� �����մϴ�.
    /// spriteEndIndex : ��������Ʈ �� �ε����� �����մϴ�.
    /// spriteYIndex : ��������Ʈ Y �ε����� �����մϴ�.
    /// spriteIndex : ó�� �� �ִϸ��̼��� ����Ǿ��� �� ǥ�õ� ��������Ʈ �ε����� �����մϴ�.
    /// ���� -1 �� ���޵Ǿ��ٸ� �� ���� spriteStartIndex �� ������ ������ �����˴ϴ�.
    FSpriteAnimInfo(
        float   spriteDelay, 
        int     spriteStartIndex, 
        int     spriteEndIndex,
        int     spriteYIndex, 
        int     spriteIndex = -1);

    // ���� ��������Ʈ �ε����� �����մϴ�.
    void Next();


};

