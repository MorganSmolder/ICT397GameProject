#pragma once

#include <map>
#include <queue>
#include "Message.h"
#include "Identifiers.h"
#include "MessageTypes.h"
#include <iostream>

/**
* @class MessagingBus
*
* @brief System for sending the messages.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class MessagingBus
{
public:
	/**
	* @brief send the message.
	*
	* @param topos(const Message &) - The message to be sent.
	* @param recipient(const Identifiers &) - Where the message is being sent.
	* 
	* @return NONE.
	*/
	void postMessage(const Message & topost, const Identifiers & recipient);

	/**
	* @brief Get the message.
	*
	* @param id(Identifers &) - Where the message is from.
	*
	* @return Message - The message that was received.
	*/
	Message getMessage(const Identifiers & id);

	/**
	* @brief If the message was received.
	*
	* @param id(Identifiers &) - Where the message is from.
	*
	* @return bool - If it was received.
	*/
	bool hasMessage(const Identifiers & id);

	/**
	* @brief Post the message.
	*
	* @param topost(Message &) - The message that is to be posted.
	* @param recipientid(unsigned) - The reciepient id.
	*
	* @return NONE.
	*/
	void postIMessage(const Message & topost, unsigned recipientid);

	/**
	* @brief Get the id.
	*
	* @param recipientid(unsigned) - The recipient id.
	*
	* @return Message - The message.
	*/
	Message getIMessage(unsigned recipientid);

	/**
	* @brief Has the id.
	*
	* @param recipientid(unsigned) - The recipient id.
	*
	* @return Bool - If the message has been recieived.
	*/
	bool hasIMessage(unsigned recipientid);

private:
	std::map<Identifiers, std::queue<Message> > messages; /// The messages
	std::map<unsigned, std::queue<Message> > imessages; /// The messages recieived.
};

