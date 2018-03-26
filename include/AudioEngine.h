#pragma once
#include "bass.h"
#include <map>
#include <string>
#include <iostream>
#include "vec3.h"
#include "Singleton.h"
#include "MessagingBus.h"
#include "Identifiers.h"

#define DEBUGMODE true

struct SoundSourceWrapper {
	bool positional;
	unsigned associatedgameobject;
	int channel;
	vec3 pos;
	SoundSourceWrapper() : positional(false), channel(0), associatedgameobject(0) {};
	SoundSourceWrapper(int nchannel) : channel(nchannel), positional(false) {};
	SoundSourceWrapper(int nchannel, bool npos) : channel(nchannel), positional(npos) {};
};

struct ListenerSourceWrapper {
	int id;
	vec3 pos;
	ListenerSourceWrapper() : id(-1) {};
};

class AudioEngine
{
public:
	AudioEngine();
	~AudioEngine();
	bool initalise();
	void setActiveChannelSubGroup(unsigned nchannel);
	void addChannelSubgroup(unsigned groupno);
	bool loadSound(std::string path, std::string type, std::string name);
	void setListenerSource(unsigned id, vec3 startpos);
	bool playSound(std::string sound);
	bool playSoundatSource(std::string sound, unsigned gameobject, vec3 & pos);
	bool stopSound(std::string sound);
	bool freeAllSounds();
	bool pauseActiveChannels();
	bool unpauseChannels();
	bool soundPlaying(std::string sound);
	void update();

private:
	Identifiers id;
	std::map<std::string, int> loadedsounds;
	std::map<int, std::map<std::string, SoundSourceWrapper>> activechannels;
	std::map<int, ListenerSourceWrapper> channellistenersources;
	static void CALLBACK ChannelFinishedCallback(HSYNC handle, DWORD channel, DWORD data, void* user);
	bool setListenerPosition(vec3 & pos);
	bool getListenerPosition();

	unsigned activesubgroup;

	bool updateChannelPos(std::string sound);
	void msgrcvr();
	void msgsndr();
};

