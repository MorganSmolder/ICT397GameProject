#pragma once

/**
* @class Singleton
* @brief A singleton data container.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
template <class T>
class Singleton
{
public:
	 /**
	 * @brief Get the instance.
	 *
	 * @return T* - The data.
	 */
	static T* getInstance();

private:
	static T* instance; /// The data.
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