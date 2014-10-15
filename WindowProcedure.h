#pragma once
/*!
@file WindowProcedure.h
@brief �E�B���h�E�v���V�[�W���֘A
@author takamoto
@date 14/10/15
*/
#include <functional>
#include <Windows.h>

/*!
@namespace win
@brief Windows�Ǝ������Ɋւ���N���X��֐����܂ޖ��O���
*/
namespace win{
	void NoticeEnvironment(std::function<LRESULT(HWND, UINT, UINT, LONG)> observer);
	LRESULT CALLBACK DefaultProcedure(HWND hWnd, UINT msg, UINT wParam, LONG lParam);
}

