#pragma once
#include "Framework/Base/GameObject/GameObject.h"

class CWaveController final :
    public CGameObject
{
private :
    // 각 웨이브마다 적을 몇 마리 생성할 것인지에 대한 정보를 담습니다.
    vector<int> WaveInfos;
    vector<int>::iterator WaveIterator;

    // 모든 웨이브 클리함을 나타냄
    bool bAllClear;

    // 각 웨이브마다 생성된 적 캐릭터가 저장됩니다.
    list<class CEnemyCharacter*> CreatedEnemyCharacter;


public :
    virtual void Initialize() override;
    virtual void Start() override;

private :
    void StartWave();
    class CEnemyCharacter* CreateEnemy();

public :
    void DestroyEnemy(class CEnemyCharacter* enemy);






};

