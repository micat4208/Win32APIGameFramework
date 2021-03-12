#pragma once
#include "../ManagerClassBase/ManagerClassBase.h"

class CSceneManager final :
    public CManagerClassBase<CSceneManager>
{
private :
    // 현재 씬
    class CScene* CurrentScene;

    // 다음 씬
    class CScene* NextScene;

public :
    template<typename SceneType>
    void LoadScene()
    {
        // 상속 관계 확인
        if (IsA<CScene, SceneType>())
        {
            LOG(TEXT("CScene 형식과 상속 관계가 아닌 형식입니다."));
            return;
        }

        // 만약 전에 요청한 씬이 존재할 경우
        if (NextScene != nullptr)
        {
            // 할당된 씬 해제
            delete NextScene;
            NextScene = nullptr;
        }

        // 다음 씬을 설정합니다.
        NextScene = new SceneType();
    }
};


