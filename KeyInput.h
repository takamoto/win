#pragma once
/*!
@file KeyInput.h
@brief Win32 API�ł̃L�[�{�[�h����
@author takamoto
@date 14/10/15
*/

#include <Windows.h>
#include <vector>

/*!
@namespace win
@brief Windows�Ǝ������Ɋւ���N���X��֐����܂ޖ��O���
*/
namespace win{

	/*!
	@class KeyInput
	*/
	class KeyInput{
	private:
		std::vector<BYTE> current_states;
		std::vector<BYTE> previous_states;
	public:
		KeyInput();
		void update();
		bool isPushKey(BYTE key);
		bool isJustPushKey(BYTE key);
		bool isJustPullKey(BYTE key);
	};
}