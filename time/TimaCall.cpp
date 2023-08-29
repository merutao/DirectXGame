#include "TimeCall.h"

TimeCall::TimeCall(std::function<void()> callBack, uint32_t time) {
	this->callback_ = callBack;
	this->time_ = time;
}

void TimeCall::Update() {
	if (isFinish) {
		return;
	}

	time_--;

	if (time_ <= 0) {
		isFinish = true;
		callback_();
	}
}