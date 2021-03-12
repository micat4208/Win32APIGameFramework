#pragma once

#ifndef LOG_DEFINE
#define LOG_DEFINE

// 로그 사용 여부
#define USE_LOG		true
#endif



#if USE_LOG == true
#pragma comment (linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#ifdef UNICODE
#define tcout	wcout
#else
#define tcout	cout
#endif

#define LOG(log) if (USE_LOG) { tcout << TEXT("Path : ") << __FILE__ << TEXT("[LINE ") << __LINE__ << TEXT("]\n") << log << endl; }