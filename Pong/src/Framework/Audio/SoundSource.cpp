#include "SoundSource.h"
#include <iostream>

SoundSource::SoundSource()
{
	alGenSources(1, &p_Source);
	alSourcef(p_Source, AL_PITCH, p_Pitch);
	alSourcef(p_Source, AL_GAIN, p_Gain);
	alSource3f(p_Source, AL_POSITION, p_Position[0], p_Position[1], p_Position[2]);
	alSource3f(p_Source, AL_VELOCITY, p_Velocity[0], p_Velocity[1], p_Velocity[2]);
	alSourcef(p_Source, AL_LOOPING, p_LoopSound);
	alSourcei(p_Source, AL_BUFFER, p_Buffer);
}


SoundSource::~SoundSource()
{
	alDeleteSources(1, &p_Source);
}


void SoundSource::Play(const ALuint bufferToPlay)
{
	if (bufferToPlay != p_Buffer) // only upload to buffer if changed
	{
		p_Buffer = bufferToPlay;
		alSourcei(p_Source, AL_BUFFER, (ALint)p_Buffer);
	}

	alSourcePlay(p_Source);
}
