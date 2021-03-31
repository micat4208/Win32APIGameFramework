#include "../Includes/Includes.h"

#include "../Single/GameInstance/GameInstance.h"
#include "../Single/SceneManager/SceneManager.h"
#include "../Single/CollisionManager/CollisionManager.h"

class CGameInstance* GameInstance;

// ���� �ý����� �����ϱ� ���� ���� ����
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

#pragma region ���� �ʱ�ȭ
	// ��ǥ ������
	int targetFPS = 144;

	// ��ǥ �������� ������ ���� ���� �ð� ����
	float targetDt = 1.0f / targetFPS;

	// ������ ���� ���� ���� �ð� ������ ������ ����� ����
	float totalDt = 0.0f;
	float functionCallDelta;

	// �ð��� ���ϱ� ���� ����
	LARGE_INTEGER Second;
	LARGE_INTEGER Time;

	QueryPerformanceFrequency(&Second);
	QueryPerformanceCounter(&Time);


#pragma endregion

#pragma region 1. ������ Ŭ���� ���� / �ʱ�ȭ
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

#pragma region 2. ������ Ŭ���� ���
	RegisterClass(&WndClass);
#pragma endregion

#pragma region 3. ������ â ����
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

#pragma region 4. ������ â Ȱ��ȭ / ǥ��
	ShowWindow(hWnd, nCmdShow);
#pragma endregion

#pragma region 5. �޽��� ���� ó��
	//while (GetMessage(&Msg, NULL, NULL, NULL))

	// FMOD ���� �ý��� ����
	FMOD_System_Create(&SoundSystem);

	// FMOD ���� �ý��� �ʱ�ȭ
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
			// ���� CPU Ŭ�� ���� ������ ����
			LARGE_INTEGER time;

			// ���� CPU Ŭ�� ���� ����ϴ�.
			QueryPerformanceCounter(&time);

			functionCallDelta = (time.QuadPart - Time.QuadPart) / (float)Second.QuadPart;
			Time = time;

			if (totalDt >= targetDt)
			{
				// �浹ü �˻�
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

		// �� �ý����� �ݽ��ϴ�.
		FMOD_System_Close(SoundSystem);

		// ���� �ý����� �����մϴ�.
		FMOD_System_Release(SoundSystem);


		DeleteObj(GameInstance);

		PostQuitMessage(0);
		return 0;
	}


	return DefWindowProc(hwnd, msg, wParam, lParam);
}
