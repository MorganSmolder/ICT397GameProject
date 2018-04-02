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

/**
* @struct SoundSourceWrapper
* @brief Wrapper for holding information about active channels.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/

struct SoundSourceWrapper {
	///Wether or not channel uses 3d sound
	bool positional;
	///Game object SSW is bound too
	unsigned associatedgameobject;
	///Handle for channel (for use with BASS)
	int channel;
	///Position of the sound source
	vec3 pos;
	SoundSourceWrapper() : positional(false), channel(0), associatedgameobject(0) {};
	SoundSourceWrapper(int nchannel) : channel(nchannel), positional(false) {};
	SoundSourceWrapper(int nchannel, bool npos) : channel(nchannel), positional(npos) {};
};


/**
* @struct ListenerSourceWrapper
* @brief Wrapper for holding information about the global listener.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct ListenerSourceWrapper {
	///Bound game object id
	int id;
	///position of listener
	vec3 pos;
	ListenerSourceWrapper() : id(-1) {};
};

struct FFTData {
	bool empty;
	float data[8];
	FFTData() : empty(true) {};
};

/**
* @class AudioEngine
* @brief Class for handling, storing, and playing sound files
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/

class AudioEngine
{
public:
	AudioEngine();
	~AudioEngine();

	/**
	* @brief Initalises BASS library
	*
	* @return bool - Wether or not the library was successfully intalised.
	*/
	bool initalise();

	/**
	* @brief Sets the active channel subgroup
	*
	* @param nchannel - The subgroup to switch to.
	*/
	void setActiveChannelSubGroup(unsigned nchannel);

	/**
	* @brief Adds a channel subgroup
	*
	* @param groupno - The id to be associated with the subgroup
	*/
	void addChannelSubgroup(unsigned groupno);

	/**
	* @brief Loads a new sound into memory
	*
	* @param path - Location of the sound file on disk.
	* @param type - The type of sound file to load.
	* @param name - The handle to be used in calls to utilise sound.
	* @return bool - Wether or not the sound was loaded correctly.
	*/
	bool loadSound(std::string path, std::string type, std::string name);

	/**
	* @brief Binds a game object to the module as the listener.
	*
	* @param id - The id of the game object to be bound
	* @param startpos - The starting position of the game object
	*/
	void setListenerSource(unsigned id, vec3 startpos);

	/**
	* @brief Depreciated - Plays sound at origon (0,0,0)
	*
	* @param sound - The name of the sound to play.
	* @return bool - Wether or not the sound was played correctly.
	*/
	bool playSound(std::string sound);
	bool playSoundatSource(std::string sound, unsigned gameobject, vec3 & pos);
	bool stopSound(std::string sound);
	bool freeAllSounds();
	bool pauseActiveChannels();
	bool unpauseChannels();
	bool soundPlaying(std::string sound);
	FFTData performFFT(std::string sound);
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

