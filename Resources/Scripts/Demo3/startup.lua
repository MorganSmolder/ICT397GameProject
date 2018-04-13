
--Local scoping; exists on Lua stack temporarily (within the scope of this file call)
--Invisible to C++ interface
local function loadScripts(LSM)
	--Load behaviour functions into lua state
	LSM:doScriptFromFile("./Resources/Scripts/Demo3/npc.lua");
	LSM:doScriptFromFile("./Resources/Scripts/Demo3/controls.lua");
end

--Placeholder resource loading function
--Demos the program's ability to load textures and other files through a scripting interface, even if we aren't doing anything with them yet
local function loadResources(AMAN)
	print();

	if AMAN:addResource("./Resources/Models/RAW1.tdef", "RAWTRN", "Terrain") then print("Successfully loaded Resource 'Terrain'");
	else print("Failed to load Resource 'Terrain'"); end

	if AMAN:addResource("./Resources/Models/RAW2.tdef", "RAWTRN", "Terrain2") then print("Successfully loaded Resource 'Terrain2'");
	else print("Failed to load Resource 'Terrain2'"); end

	if AMAN:addModel("./Resources/Models/Iron_Man.obj", "IM", "Robot", vec3(8,8,8)) then print("Successfully loaded Resource 'Robot'");
	else print("Failed to load Resource 'Robot'"); end

	if AMAN:addModel("./Resources/Models/Rock.obj", "IM", "rock", vec3(8,8,8)) then print("Successfully loaded Resource 'rock'");
	else print("Failed to load Resource 'rock'"); end

	if AMAN:addResource("./Resources/Models/start.obj", "IM", "start") then print("Successfully loaded Resource 'start'");
	else print("Failed to load Resource 'start'"); end

	if AMAN:addResource("./Resources/Audio/2.wav", "WAV", "bgmusic") then print("Successfully loaded Resource 'bgmusic'");
	else print("Failed to load Resource 'bgmusic'"); end

	if AMAN:addResource("./Resources/Audio/30.wav", "WAV", "bgmusic1") then print("Successfully loaded Resource 'bgmusic1'");
	else print("Failed to load Resource 'bgmusic1'"); end
		
	print();
end

--Initalises game
--Takes scene manager, script manager, and asset manager modules as arguments
--Will be expanded later
--This function is requred for a game to be created (the name "initGame" is hardcoded in c++)
function initGame(SM, LSM, AMAN, AE)

	--call function to load lua code into memory
	loadScripts(LSM);

	--load game resources
	loadResources(AMAN);
	

	--Initalise Scene 1
	SM:addScene();

	SM:setCurrScene(0);

	SM:attachControls(0, ResourceList("keyCallback", "keys", "mouseCallback", "mouse"));

	SM:attachTerrain(Identifiers("TO", "Terrain"), 0, vec3(0,0,0), ResourceList("model", "Terrain"));

	for i = 10,1,-1 
	do 
		SM:addObject(Identifiers("SE"), 0, vec3(math.random()*(512-0) + 0, 0, math.random()*(512 - 0) + 0), ResourceList("model", "rock")); 
	end

	SM:addObject(Identifiers("CAM","Camera"), 0, vec3(20, 0, 10), ResourceList());

	SM:addObject(Identifiers("MO","Menu"), 0, vec3(0, 0, 0), ResourceList());

	--SM:addObject(Identifiers("NPC", "ted"), 0, vec3(0,0,0), ResourceList("model", "Robot"));

	SM:setSceneHeightMap(0, SM:GetGameObject("Terrain"));

	AE:setListenerSource(SM:GetGameObjectID("Camera"), vec3(0, 0, 0));
	
	--AE:playSoundatSource("bgmusic", SM:GetGameObjectID("Camera"), vec3(0, 0, 10));

	--Initalise Scene 2
	SM:addScene();

	SM:setCurrScene(1);
	
	SM:attachControls(1, ResourceList("keyCallback", "keys2", "mouseCallback", "mouse2"));

	SM:attachTerrain(Identifiers("TO", "Terrain2"), 1, vec3(0,0,0), ResourceList("model", "Terrain2"));

	SM:addObject(Identifiers("CAM","Camera2"), 1, vec3(0, 0, 0), ResourceList());

	SM:setSceneHeightMap(1, SM:GetGameObject("Terrain2"));

	AE:setListenerSource(SM:GetGameObjectID("Camera2"), vec3(0, 0, 0));
	
	AE:playSoundatSource("bgmusic1", SM:GetGameObjectID("Camera2"), vec3(0, 0, 0));

	--Set Starting Scene
	SM:setCurrScene(0);

	print("Data Loaded!");
	print();
end