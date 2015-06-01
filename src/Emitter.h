#ifndef EMITTER_H_
#define EMITTER_H_

// This is an interface
/*
*	Emitters can send waves in the world.
*/

#include <SFML/System/Clock.hpp>


//FIXME : Problem of refresh rate to send waves. Maybe add a timeToSend in send, so the world can already place the wave at the correct position accounting for the time that has passed
class Emitter
{
private:
	sf::Time lastSendTime;
	bool sending;

	float currentAmplitude;
	float currentFrequency;	// This is in hertz
	float currentSpeed;

public:
	Emitter();

	virtual void initialise() = 0;	// Perform initialisation specific tasks
	virtual void send(float frequency, float amplitude, float speed = -1.0f);

	/**
	*	This will check if the emitter is sending, and if it is, if a new peak needs to be sent. (And if that is the case, it'll send it for you)
	*/
	virtual bool checkForSend(sf::Time currentTime);

	virtual bool isSending();
	virtual void stopSending();

	// Setters
	void setLastSendTime(sf::Time newLastSendTime);	// When newest peak has ben sent, the world will call this to notify the Emitter

	// Getters
	virtual sf::Time getLastSendTime();
	virtual float getCurrentAmplitude();
	virtual float getCurrentFrequency();
	virtual float getCurrentSpeed();

	// Static functions
	static sf::Time getTimeFromFrequency(float frequency);
};

#endif
