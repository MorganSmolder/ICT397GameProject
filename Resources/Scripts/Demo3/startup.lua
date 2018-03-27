
--Local scoping; exists on Lua stack temporarily (within the scope of this file call)
--Invisible to C++ interface
local function loadScripts(LSM)
	--Load behaviour functions into lua state
	LSM:doScriptFromFile("./Resources/Scripts/Demo3/npc.lua");
end

--Placeholder resource loading function
--Demos the program's ability to load textures and other files through a scripting interface, even if we aren't doing anything with them yet
local function loadResources(AMAN)
	print();

	if AMAN:addResource("./Resources/Audio/2.wav", "WAV", "bgmusic") then print("Successfully loaded Resource 'bgmusic'");
	else print("Failed to load Resource 'bgmusic'"); end

	if AMAN:addResource("./Resources/Audio/1.wav", "WAV", "bgmusic1") then print("Successfully loaded Resource 'bgmusic1'");
	else print("Failed to load Resource 'bgmusic1'"); end
	
	print();
end

--Initalises game
--Takes scene manager, script manager, and asset manager modules as arguments
--Will be expanded later
--This function is requred for a game to be created (the name "initGame" is hardcoded in c++)
function initGame(SM, LSM, AMAN, AE)

	--call function to load lua code	
	loadScripts(LSM);

	--placeholder
	loadResources(AMAN);
	
	print("Adding Scene 1");
	
	--Initalise the scene used in this demo.
	SM:addScene();


	SM:addObject(Identifiers("NPC", "bob"), 0, vec3(-10,0,0), ResourceList("updatefunc", "start"));
	

	SM:addObject(Identifiers("NPC", "ted"), 0, vec3(10, 0, 0), ResourceList("updatefunc", "start"));
	

	SM:addObject(Identifiers("CAM","Camera"), 0, vec3(0, 0, 10), ResourceList());
	
	--Unecessary in this instance, but good practice 
	SM:setCurrScene(0);

	AE:setListenerSource(SM:GetGameObjectID("Camera"), vec3(0, 0, 0));
	
	AE:playSoundatSource("bgmusic", SM:GetGameObjectID("bob"), vec3(-10, 0, 0));

	print("Data Loaded!");
	print();
end