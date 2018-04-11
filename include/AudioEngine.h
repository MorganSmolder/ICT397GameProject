#pragma once
#include "bass.h"
#include <map>
#include <string>
#include <iostream>
//#include "vec3.h" // OLD CALL
#include "Maths.h"
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

/**
* @struct FFTData
* @brief Wrapper for holding information about FFT.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct FFTData {
	bool empty;
	float data[8];
	FFTData() : empty(true) {};
};

/**
* @class AudioEngine
* @brief Class for handling, storing, and playing sound files.
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
	*
	* @return NONE.
	*/
	bool initalise();

	/**
	* @brief Sets the active channel subgroup
	*
	* @param nchannel(unsigned) - The subgroup to switch to.
	*
	* @return NONE.
	*/
	void setActiveChannelSubGroup(unsigned nchannel);

	/**
	* @brief Adds a channel subgroup
	*
	* @param groupno(unsigned) - The id to be associated with the subgroup
	*
	* @return NONE.
	*/
	void addChannelSubgroup(unsigned groupno);

	/**
	* @brief Loads a new sound into memory
	*
	* @param path(string) - Location of the sound file on disk.
	* @param type(string) - The type of sound file to load.
	* @param name(string) - The handle to be used in calls to utilise sound.
	*
	* @return bool - Wether or not the sound was loaded correctly.
	*/
	bool loadSound(std::string path, std::string type, std::string name);

	/**
	* @brief Binds a game object to the module as the listener.
	*
	* @param id(unsigned) - The id of the game object to be bound
	* @param startpos(vec3) - The starting position of the game object
	*
	* @return NONE.
	*/
	void setListenerSource(unsigned id, vec3 startpos);

	/**
	* @brief Depreciated - Plays sound at origon (0,0,0)
	*
	* @param sound(string) - The name of the sound to play.
	*
	* @return bool - Wether or not the sound was played correctly.
	*/
	bool playSound(std::string sound);
	
	/**
	* @brief Plays sound at specified position.
	* 
	* @param sound(string) - The name of the sound to play.
	* @param gameobject(unsigned) - The ID of the game object the sound is linked to.
	* @param pos(vec3) - The position of the game object.
	*
	* @return bool - Wether of not the sound was played correctly.
	*/
	bool playSoundatSource(std::string sound, unsigned gameobject, vec3 & pos);

	/**
	* @brief Stop sound playing.
	*
	* @param sound(string) - The name of the sound playing.
	*
	* @return bool - If the sound stopped playing correctly
	*/
	bool stopSound(std::string sound);

	/**
	* @brief Clears all sound channels.
	*
	* @return bool - If the channels where cleared.
	*/
	bool freeAllSounds();

	/**
	* @brief Pause the sound playing from all active channels.
	*
	* @return bool - If the channels were paused.
	*/
	bool pauseActiveChannels();

	/**
	* @brief Resume paused channels.
	*
	* @return bool - If channels were resumed.
	*/
	bool unpauseChannels();

	/**
	* @brief Check to see if specified sound is playing.
	*
	* @param sound(string) - Name of the sound being checked.
	*
	* @return bool - If specified sound is playing.
	*/
	bool soundPlaying(std::string sound);

	/**
	* @brief Perform FFT.
	*
	* @param sound(string) - Name of the sound.
	*
	* @return FFTData - FFT data obtained.
	*/
	FFTData performFFT(std::string sound);

	/**
	* @brief Update sound channels.
	*
	* @return NONE.
	*/
	void update();

private:
	Identifiers id; /// Sound identification.
	std::map<std::string, int> loadedsounds; /// Map of loaded sounds.
	std::map<int, std::map<std::string, SoundSourceWrapper>> activechannels; /// Map of active channels.
	std::map<int, ListenerSourceWrapper> channellistenersources; /// Map of channel listeners.

	/**
	* @brief Callback for finished channel.
	*
	* @param handle(HYSNC) - Name of channel.
	* @param channel(DWORD) - Channel data.
	* @param data(DWORD) - Data or sound in channel.
	* @parm user(void*) - Pointer to object the sound belongs to.
	*
	* @return NONE.
	*/
	static void CALLBACK ChannelFinishedCallback(HSYNC handle, DWORD channel, DWORD data, void* user); 
	bool setListenerPosition(vec3 & pos);

	/** 
	* @brief Get position of listener.
	*
	* @return bool - If location was obtained.
	*/
	bool getListenerPosition();

	unsigned activesubgroup; /// ID for the active sub group.

	/**
	* @brief Update the position of the sound channel.
	*
	* @param sound(string) - The name of the sound
	*
	* @return bool - If the sound was updated.
	*/
	bool updateChannelPos(std::string sound);

	/**
	* @brief Receives messages using messenger class.
	*
	* @return NONE.
	*/
	void msgrcvr();

	/**
	* @brief Sends messages useing the messenger class.
	*
	* @return NONE.
	*/
	void msgsndr();
};

