#pragma once
#include "Framework/Base/GameObject/GameObject.h"

class CWaveController final :
    public CGameObject
{
private :
    // �� ���̺긶�� ���� �� ���� ������ �������� ���� ������ ����ϴ�.
    vector<int> WaveInfos;
    vector<int>::iterator WaveIterator;

    // ��� ���̺� Ŭ������ ��Ÿ��
    bool bAllClear;

    // �� ���̺긶�� ������ �� ĳ���Ͱ� ����˴ϴ�.
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

