#include "AudioEngine.h"



AudioEngine::AudioEngine()
{
	activesubgroup = 0;
	id.setName("AE");
	id.setId(AUDIOENG_ID);
}


AudioEngine::~AudioEngine()
{
}

void CALLBACK AudioEngine::ChannelFinishedCallback(HSYNC handle, DWORD channel, DWORD data, void* user) {
	std::cout << "Channel: " << channel << " has finished playing." << std::endl;
}

void AudioEngine::setActiveChannelSubGroup(unsigned nchannel) {
	pauseActiveChannels();

	activesubgroup = nchannel;

	if(channellistenersources[activesubgroup].id != -1) setListenerPosition(channellistenersources[activesubgroup].pos);
	unpauseChannels();
}

void AudioEngine::addChannelSubgroup(unsigned groupno) {
	std::map<std::string, SoundSourceWrapper> tmp;
	ListenerSourceWrapper tmpls;
	activechannels[groupno] = tmp;
	channellistenersources[groupno] = tmpls;
}

bool AudioEngine::pauseActiveChannels() {

	bool good = true;

	for (std::map<std::string, SoundSourceWrapper>::const_iterator mapit = activechannels.at(activesubgroup).begin(); mapit != activechannels.at(activesubgroup).end(); ++mapit) {
		if (!BASS_ChannelPause(mapit->second.channel)) {
			if (DEBUGMODE) std::cerr << "Error Pausing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
			good = false;
		}
	}

	return good;
}

bool AudioEngine::unpauseChannels() {
	bool good = true;

	for (std::map<std::string, SoundSourceWrapper>::const_iterator mapit = activechannels.at(activesubgroup).begin(); mapit != activechannels.at(activesubgroup).end(); ++mapit) {
		if (!BASS_ChannelPlay(mapit->second.channel, false)) {
			if (DEBUGMODE) std::cerr << "Error Pausing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
			good = false;
		}
	}

	return good;
}

bool AudioEngine::initalise(){
	if (!BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL)) {
		if (DEBUGMODE) std::cerr << "Error Initalising Audio Engine! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}

	return true;
}

bool AudioEngine::soundPlaying(std::string sound) {
	return activechannels[activesubgroup].count(sound) == 1;
}

bool AudioEngine::loadSound(std::string path, std::string type, std::string name) {
	if (type != "WAV") return false;
	HSAMPLE tmp = BASS_SampleLoad(false, path.c_str(), 0, 0, 10, BASS_SAMPLE_3D | BASS_SAMPLE_FLOAT);
	if (tmp != 0) {
		loadedsounds[name] = tmp;
	}
	else {
		if (DEBUGMODE) std::cerr << "Error Loading Sound! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}

	return true;
}

bool AudioEngine::playSound(std::string sound) {
	if (loadedsounds.count(sound) == 0) return false;

	HCHANNEL channel = BASS_SampleGetChannel(loadedsounds[sound], FALSE);
	if (channel == 0) {
		if (DEBUGMODE) std::cerr << "Error Creating Channel! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}
	else {
		if (BASS_ChannelPlay(channel, FALSE)) {
			activechannels[activesubgroup][sound] = SoundSourceWrapper(channel);
			return true;
		}
		else {
			if (DEBUGMODE) std::cerr << "Error Playing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
			return false;
		}
	}
}

bool AudioEngine::stopSound(std::string sound) {
	if (!BASS_ChannelStop(activechannels[activesubgroup][sound].channel)) {
		if (DEBUGMODE) std::cerr << "Error Stopping Channel! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}

	return true;
}

bool AudioEngine::playSoundatSource(std::string sound, unsigned gameobject, vec3 & pos) {

	if (loadedsounds.count(sound) == 0) return false;

	HCHANNEL channel = BASS_SampleGetChannel(loadedsounds[sound], FALSE);
	if (channel == 0) {
		if (DEBUGMODE) std::cerr << "Error Creating Channel! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}
	else {
		if (BASS_ChannelPlay(channel, FALSE)) {
			activechannels[activesubgroup][sound] = SoundSourceWrapper(channel, true);
		}
		else {
			if (DEBUGMODE) std::cerr << "Error Playing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
			return false;
		}
	}

	BASS_3DVECTOR tmppos(pos.x(), pos.y(), pos.z());

	activechannels[activesubgroup][sound].pos = pos;
	activechannels[activesubgroup][sound].associatedgameobject = gameobject;

	if (!BASS_ChannelSet3DPosition(channel, &tmppos, NULL, NULL)) {
		if (DEBUGMODE) std::cerr << "Error Playing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}

	return true;
}

bool AudioEngine::setListenerPosition(vec3 & pos) {
	BASS_3DVECTOR listnerpos(pos.x(), pos.y(), pos.z());

	if (!BASS_Set3DPosition(&listnerpos, NULL, NULL, NULL)) {
		if (DEBUGMODE) std::cerr << "Error Playing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}
	else BASS_Apply3D();

	return true;
}

bool AudioEngine::freeAllSounds() {

	bool good = true;

	for (std::map<std::string, int>::const_iterator mapit = loadedsounds.begin(); mapit != loadedsounds.end(); ++mapit) {
		if (!BASS_SampleFree(mapit->second)) {
			if (DEBUGMODE) std::cerr << "Error Freeing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
			good = false;
		}
	}

	loadedsounds.clear();
	activechannels.clear();

	return good;
}

void AudioEngine::setListenerSource(unsigned id, vec3 startpos){
	channellistenersources[activesubgroup].id = (int) id;
	setListenerPosition(startpos);
}

bool AudioEngine::getListenerPosition() {
	return true;
}

void AudioEngine::update() {
	msgrcvr();
	msgsndr();
}

bool AudioEngine::updateChannelPos(std::string sound) {
	BASS_3DVECTOR tmp(activechannels[activesubgroup][sound].pos.x(), activechannels[activesubgroup][sound].pos.y(), activechannels[activesubgroup][sound].pos.z());

	if (!BASS_ChannelSet3DPosition(activechannels[activesubgroup][sound].channel, &tmp, NULL, NULL)) {
		if (DEBUGMODE) std::cerr << "Error Playing Sound! Code: " << BASS_ErrorGetCode() << std::endl;
		return false;
	}
}

void AudioEngine::msgrcvr() {
	MessagingBus* tmpmsgbus = Singleton<MessagingBus>::getInstance();

	Message tmpmsg;

	while (tmpmsgbus->hasIMessage(AUDIOENG_ID)) {
		tmpmsg = tmpmsgbus->getIMessage(AUDIOENG_ID);

		if (tmpmsg.getInstruction() == "PR") {
			if (activechannels[activesubgroup].count(tmpmsg.getData().sdata) == 1) {
				activechannels[activesubgroup][tmpmsg.getData().sdata].pos = tmpmsg.getData().vdata;
				updateChannelPos(tmpmsg.getData().sdata);
			}
		}
		else
		if (tmpmsg.getInstruction() == "LPR") {
			if (channellistenersources[activesubgroup].id != -1) {
				channellistenersources[activesubgroup].pos = tmpmsg.getData().vdata;
				setListenerPosition(channellistenersources[activesubgroup].pos);
			}
		}
	}

	while (tmpmsgbus->hasMessage(this->id)) {
		tmpmsg = tmpmsgbus->getMessage(this->id);
		//Request to play sound at source
		if (tmpmsg.getInstruction() == "PSS") {
			playSoundatSource(tmpmsg.getData().sdata, tmpmsg.getData().idata, tmpmsg.getData().vdata);
		}
		else
		//Request to play sound without source defined
		//Avoid using - will play sound at position 0,0,0
		if (tmpmsg.getInstruction() == "PS") {
			playSound(tmpmsg.getData().sdata);
		}
	}

}

void AudioEngine::msgsndr() {
	MessagingBus* tmpmsgbus = Singleton<MessagingBus>::getInstance();
	Message tmpm;

	for (std::map<std::string, SoundSourceWrapper>::const_iterator mapit = activechannels.at(activesubgroup).begin(); mapit != activechannels.at(activesubgroup).end(); ++mapit) {
		if (mapit->second.positional) {
			tmpm.setInstruction("POS");
			tmpm.setData(mapit->first);
			tmpm.setFrom(id);
			tmpmsgbus->postIMessage(tmpm, mapit->second.associatedgameobject);
		}
	}

	if (channellistenersources[activesubgroup].id != -1) {
		tmpm.setInstruction("LPOS");
		tmpm.setFrom(id);
		tmpmsgbus->postIMessage(tmpm, channellistenersources[activesubgroup].id);
	}
}