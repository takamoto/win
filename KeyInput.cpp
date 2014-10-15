#include "keyinput.h"
#include <algorithm>

namespace win{
	static const int NumOfKeys = 256;

	KeyInput::KeyInput() : current_states(NumOfKeys), previous_states(NumOfKeys) {}

	void KeyInput::update() {
		std::swap(previous_states, current_states);
		GetKeyboardState(current_states.data());
	}

	bool KeyInput::isPushKey(BYTE key) { return current_states[key] & 0x80; }
	bool KeyInput::isJustPushKey(BYTE key) { return isPushKey(key) && !(previous_states[key] & 0x80); }
	bool KeyInput::isJustPullKey(BYTE key) { return !isPushKey(key) && (previous_states[key] & 0x80); }
}