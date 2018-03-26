#pragma once

#include <map>
#include <queue>
#include "Message.h"
#include "Identifiers.h"
#include <iostream>

#define AUDIOENG_ID 1000000
#define SCENEMAN_ID 1000001

class MessagingBus
{
public:
	void postMessage(const Message & topost, const Identifiers & recipient);
	Message getMessage(const Identifiers & id);
	bool hasMessage(const Identifiers & id);

	void postIMessage(const Message & topost, unsigned recipientid);
	Message getIMessage(unsigned recipientid);
	bool hasIMessage(unsigned recipientid);

private:
	std::map<Identifiers, std::queue<Message> > messages;
	std::map<unsigned, std::queue<Message> > imessages;
};

