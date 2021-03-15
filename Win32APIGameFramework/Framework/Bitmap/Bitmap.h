#pragma once

#include "../Includes/Includes.h"
#include "../Base/Object/Object.h"
#include "../Structrues/Vector2/Vector2.h"

class CBitmap final : 
	public CObject
{
private :
	HDC Hdc, MemDC;
	HBITMAP Bmp, OldBmp;
	FVector2 Size;

public :
	CBitmap();

	CBitmap(LPCTSTR path);

	virtual void Release() override;

public :
	CBitmap* LoadBmp(LPCTSTR path);

	FORCEINLINE FVector2 GetSize() const
	{ return Size; }

	FORCEINLINE HDC GetDC() const
	{ return MemDC; }
};

