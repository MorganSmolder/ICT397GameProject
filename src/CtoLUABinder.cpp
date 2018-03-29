#include "CtoLUABinder.h"


void CtoLUABinder::bindClasses(lua_State* lstate) {
	luabind::module(lstate)[
		luabind::class_<SceneManager>("SceneManager")
			.def(luabind::constructor<>())
			.def("addObject", &SceneManager::addObject)
			.def("addScene", &SceneManager::addScene)
			.def("setCurrScene", &SceneManager::setCurrScene)
			.def("GetGameObjectID", &SceneManager::GetGameObjectID)
			.def("GetGameObject", &SceneManager::GetGameObject)
			.def("setSceneHeightMap", &SceneManager::setSceneHeightMap)
	];
	luabind::module(lstate)[
		luabind::class_<vec3>("vec3")
			.def(luabind::constructor<>())
			.def(luabind::constructor<float, float, float>())
			.def("x", &vec3::sx)
			.def("y", &vec3::sy)
			.def("z", &vec3::sz)
			.def("x", &vec3::x)
			.def("y", &vec3::y)
			.def("z", &vec3::z)
	];
	luabind::module(lstate)[
		luabind::class_<LUAScriptManager >("LUAScriptManager")
			.def(luabind::constructor<>())
			.def("loadScript", &LUAScriptManager::loadScript)
			.def("doScriptFromFile", &LUAScriptManager::doScriptFromFile)
	];
	luabind::module(lstate)[
		luabind::class_<NPC>("NPC")
			.def(luabind::constructor<>())
			.def(luabind::constructor<Identifiers &, vec3, ResourceList>())
			.def("setPos", &NPC::setPos)
			.def("getPos", &NPC::getPos)
			.def("setState", &NPC::setState)
			.def("getState", &NPC::getState)
			.def("getID", &NPC::getID)
			.def("getIdentifiers", &NPC::getIdentifiers)
	];
	luabind::module(lstate)[
		luabind::class_<Identifiers>("Identifiers")
			.def(luabind::constructor<>())
			.def(luabind::constructor<std::string>())
			.def(luabind::constructor<std::string, std::string>())
			.def(luabind::constructor<std::string, std::string, std::string>())
			.def("setId", &Identifiers::setId)
			.def("setName", &Identifiers::setName)
			.def("setType", &Identifiers::setType)
			.def("setObjectname", &Identifiers::setObjectname)
			.def("getId", &Identifiers::getId)
			.def("getName", &Identifiers::getName)
			.def("getType", &Identifiers::getType)
			.def("getObjectname", &Identifiers::getObjectname)
	];
	luabind::module(lstate)[
		luabind::class_<MessagingBus>("MessagingBus")
			.def("getMessage", &MessagingBus::getMessage)
			.def("hasMessage", &MessagingBus::hasMessage)
			.def("postMessage", &MessagingBus::postMessage)
	];
	luabind::module(lstate)[
		luabind::class_<Message>("Message")
			.def(luabind::constructor<std::string>())
			.def("getInstruction", &Message::getInstruction)
			.def("setInstruction", &Message::setInstruction)
	];
	luabind::module(lstate)[
		luabind::class_<ResourceList>("ResourceList")
			.def(luabind::constructor<>())
			.def(luabind::constructor<std::string, std::string>())
			.def(luabind::constructor<std::string, std::string, std::string, std::string>())
			.def("hasResource", &ResourceList::hasResource)
			.def("getResource", &ResourceList::getResource)
			.def("addResource", &ResourceList::addResource)
	];
	luabind::module(lstate)[
		luabind::class_<AssetManager>("AssetManager")
			.def(luabind::constructor<>())
			.def("addResource", &AssetManager::addResource)
			.def("useResource", &AssetManager::useResource)
	];
	luabind::module(lstate)[
		luabind::class_<AudioEngine>("AudioEngine")
			.def("loadSound", &AudioEngine::loadSound)
			.def("playSoundatSource", &AudioEngine::playSoundatSource)
			.def("setListenerSource", &AudioEngine::setListenerSource)
	];
}