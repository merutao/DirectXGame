#pragma once

#include <functional>

class TimeCall {
public:
	TimeCall(std::function<void()> callback, uint32_t time);
	void Update();
	bool IsFinish() { return isFinish; }

private:
	std::function<void()> callback_;
	uint32_t time_;
	bool isFinish = false;
};