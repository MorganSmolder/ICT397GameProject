#pragma once

template <class T>
class Singleton
{
public:

	static T* getInstance();

private:
	static T* instance;
	Singleton() {};
};

template <class T>
T* Singleton<T>::instance = NULL;

template <class T>
T* Singleton<T>::getInstance() {
	if (instance != NULL) {
		return instance;
	}
	else {
		instance = new T;
		return instance;
	}
}