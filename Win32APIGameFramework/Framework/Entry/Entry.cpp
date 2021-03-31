#include "../Includes/Includes.h"

#include "../Single/GameInstance/GameInstance.h"
#include "../Single/SceneManager/SceneManager.h"
#include "../Single/CollisionManager/CollisionManager.h"

class CGameInstance* GameInstance;

// 사운드 시스템을 생성하기 위한 변수 선언
struct FMOD_SYSTEM* SoundSystem;
HWND Hwnd;

float GameStartTime;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	srand(GameStartTime = GetTickCount64());

	HWND hWnd;
	MSG Msg;
	WNDCLASS WndClass;

#pragma region 게임 초기화
	// 목표 프레임
	int targetFPS = 144;

	// 목표 프레임이 나오기 위한 실행 시간 간격
	float targetDt = 1.0f / targetFPS;

	// 프레임 고정 전의 실행 시간 간격이 더해져 저장될 변수
	float totalDt = 0.0f;
	float functionCallDelta;

	// 시간을 구하기 위한 변수
	LARGE_INTEGER Second;
	LARGE_INTEGER Time;

	QueryPerformanceFrequency(&Second);
	QueryPerformanceCounter(&Time);


#pragma endregion

#pragma region 1. 윈도우 클래스 설정 / 초기화
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = TEXT("WndClass");
	WndClass.lpszMenuName = NULL;
#pragma endregion

#pragma region 2. 윈도우 클래스 등록
	RegisterClass(&WndClass);
#pragma endregion

#pragma region 3. 윈도우 창 생성
	Hwnd = hWnd = CreateWindow(
		WndClass.lpszClassName,
		TEXT("Window Title"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WND_WIDTH, WND_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
#pragma endregion

#pragma region 4. 윈도우 창 활성화 / 표시
	ShowWindow(hWnd, nCmdShow);
#pragma endregion

#pragma region 5. 메시지 루프 처리
	//while (GetMessage(&Msg, NULL, NULL, NULL))

	// FMOD 사운드 시스템 생성
	FMOD_System_Create(&SoundSystem);

	// FMOD 사운드 시스템 초기화
	FMOD_System_Init(SoundSystem, 32, FMOD_INIT_NORMAL, NULL);

	GameInstance = NewObj<CGameInstance>();

	Msg.message = WM_NULL;



	while (Msg.message != WM_QUIT)
	{
		if (PeekMessage(&Msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		else
		{
			// 현재 CPU 클럭 수를 저장할 변수
			LARGE_INTEGER time;

			// 현재 CPU 클럭 수를 얻습니다.
			QueryPerformanceCounter(&time);

			functionCallDelta = (time.QuadPart - Time.QuadPart) / (float)Second.QuadPart;
			Time = time;

			if (totalDt >= targetDt)
			{
				// 충돌체 검사
				CCollisionManager::Instance()->DoCollisionTest();

				CSceneManager::Instance()->Tick(totalDt);
				CSceneManager::Instance()->Render(GameInstance->GetDC());


				totalDt = 0.0f;
			}

			totalDt += functionCallDelta;
		}
	}
#pragma endregion

	return (int)Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:

		// 사운스 시스템을 닫습니다.
		FMOD_System_Close(SoundSystem);

		// 사운드 시스템을 해제합니다.
		FMOD_System_Release(SoundSystem);


		DeleteObj(GameInstance);

		PostQuitMessage(0);
		return 0;
	}


	return DefWindowProc(hwnd, msg, wParam, lParam);
}
