#pragma once

#include "CentsAudioHandler.h"

using namespace DirectX;

enum SoundEffectState { DelayStart = 0, Starting = 1, Playing = 2, Completed = 3 };

class CentsSoundEffect
{
public:
	CentsSoundEffect();
	CentsSoundEffect(CentsAudioHandler* AudioHandler, const wchar_t location);
	CentsSoundEffect(CentsAudioHandler* AudioHandler, const wchar_t location, bool loop);
	~CentsSoundEffect();

	void Update(float deltaTime, float totaltime);

	void Link(CentsSoundEffect* linkee);
	void Link(CentsSoundEffect* linkee, bool loop);

	void Play();
	void Play(float volume, float pitch, float pan);

	void Play(float totaltime);
	void Play(float volume, float pitch, float pan, float totaltime);

	void PlayOnUpdate();
	void PlayOnUpdate(float volume, float pitch, float pan);

	void SetLoop(bool loop);

	void Stop(bool immediate = true);
	void Set(float volume=1.0f, float pitch=0.0f, float pan=0.0f);

	bool IsComplete();

private:
	CentsAudioHandler * audioHandler;

	CentsSoundEffect * linked = nullptr;
	
	SoundEffectState state = Completed;

	float length;
	bool Loop = false;
	bool SetLoopDelayed = false;

	float startTime;
	float endTime;
	std::unique_ptr<SoundEffect> soundEffect;
	std::unique_ptr<SoundEffectInstance> soundEffectInstance;
};

