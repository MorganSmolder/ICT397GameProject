#pragma once

#include <map>
#include <queue>
#include "Message.h"
#include "Identifiers.h"
#include "MessageTypes.h"
#include <iostream>


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

