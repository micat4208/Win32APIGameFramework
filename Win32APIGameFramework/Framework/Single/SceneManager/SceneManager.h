#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

class CSceneManager final :
    public CManagerClassBase<CSceneManager>
{
private :
    // ���� ��
    class CScene* CurrentScene;

    // ���� ��
    class CScene* NextScene;

public :
    template<typename SceneType>
    void LoadScene()
    {
        // ��� ���� Ȯ��
        if (IsA<CScene, SceneType>())
        {
            LOG(TEXT("CScene ���İ� ��� ���谡 �ƴ� �����Դϴ�."));
            return;
        }

        // ���� ���� ��û�� ���� ������ ���
        if (NextScene != nullptr)
        {
            // �Ҵ�� �� ����
            delete NextScene;
            NextScene = nullptr;
        }

        // ���� ���� �����մϴ�.
        NextScene = new SceneType();
    }
};


