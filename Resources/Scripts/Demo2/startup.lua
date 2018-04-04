
--Local scoping; exists on Lua stack temporarily (within the scope of this file call)
local function loadScripts(LSM)
	--Load behaviour functions into lua state
	LSM:doScriptFromFile("./Resources/Scripts/Demo2/npc.lua");
end

local function loadResources(AMAN)
	if AMAN:addResource("./Resources/Audio/2.wav", "WAV", "sound1") then print("Successfully loaded Resource '2.wav'");
	else print("Failed to load Resource '2.wav'"); end	
end

--Initalises game
--Takes scene manager, script manager, and asset manager modules as arguments
--Will be expanded later
--This function is requred for a game to be created (the name "initGame" is hardcoded in c++)
function initGame(SM, LSM, AMAN)

	--call function to load lua code	
	loadScripts(LSM);

	loadResources(AMAN);
	
	print("Adding Scene 1");
	SM:addScene();
	SM:addObject(Identifiers("NPC"), 0, vec3(2,1,0), ResourceList("updatefunc", "start"));
	SM:addObject(Identifiers("CAM", "Camera"), 0, vec3(2,1,0), ResourceList());

	print("Adding Scene 2");
	SM:addScene();
	SM:addObject(Identifiers("NPC"), 1, vec3(0,1,0), ResourceList("updatefunc", "start"));
	SM:addObject(Identifiers("CAM", "Camera"), 1, vec3(2,1,0), ResourceList());
	
	print("Adding Scene 3");
	SM:addScene();
	SM:addObject(Identifiers("NPC"), 2, vec3(-2,1,0), ResourceList("updatefunc", "start"));
	SM:addObject(Identifiers("CAM", "Camera"), 2, vec3(2,1,0), ResourceList());
	
	SM:setCurrScene(0);

	AMAN:useResource("sound1");

	print("Data Loaded!");
	print();
end