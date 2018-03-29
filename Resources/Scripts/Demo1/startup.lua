
--Local scoping; exists on Lua stack temporarily (within the scope of this file call)
--Invisible to C++ interface
local function loadScripts(LSM)
	--Load behaviour functions into lua state
	LSM:doScriptFromFile("./Resources/Scripts/Demo1/npc.lua");
	LSM:doScriptFromFile("./Resources/Scripts/Demo1/npc2.lua");
end

--Placeholder resource loading function
--Demos the program's ability to load textures and other files through a scripting interface, even if we aren't doing anything with them yet
local function loadResources(AMAN)
	print();

	if AMAN:addResource("./Resources/Textures/1.bmp", "BMP", "tex1") then print("Successfully loaded Resource '1.bmp'");
	else print("Failed to load Resource '1.bmp'"); end

	if AMAN:addResource("./Resources/Textures/2.tga", "TGA", "tex2") then print("Successfully loaded Resource '2.tga'");
	else print("Failed to load Resource '2.tga'"); end

	if AMAN:addResource("./Resources/Textures/3.bmp", "BMP", "tex3") then print("Successfully loaded Resource '3.bmp'");
	else print("Failed to load Resource '3.bmp'"); end

	if AMAN:addResource("./Resources/Audio/2.wav", "WAV", "bgmusic") then print("Successfully loaded Resource 'bgmusic'");
	else print("Failed to load Resource 'bgmusic'"); end

	--Test Asset Manager: load same file twice
	--Should return false and not load any new data
	if AMAN:addResource("./Resources/Textures/3.bmp", "BMP", "tex3") then print("Successfully loaded Resource '3.bmp'");
	else print("Failed to load Resource '3.bmp'"); end

	--Test Asset Manager: load file that does not exist
	--Should return false 
	if AMAN:addResource("./Resources/Textures/4.bmp", "BMP", "tex4") then print("Successfully loaded Resource '4.bmp'");
	else print("Failed to load Resource '4.bmp'"); end
	
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
	
	print("Adding Scene 1")
	--Initalise the scene used in this demo.
	SM:addScene();

	--
	--DATA STRUCTURES USED BELOW
	--
	--ResourceList()
	--Wrapper for the stl map.
	--Links resource names to values
	--In this example, used to specify lua behaviour functions
	--Will later be expanded to support other resources (models, textures, etc.)'
	--
	--Param1 - Key 1 name
	--Param2 - value 1 name
	--Param3 - Key 2 name
	--Param4 - value 2 name
	--
	--Identifiers()
	--Used to identify and instantiate objects
	--
	--Param1 - Object type
	--Necessary for game object factory calls (tells it what kind of game object you want)
	--
	--Param2 - Entity name
	--Used for posting and receiving messages
	--No name defined = impossible to communicate with
	--BE CAREFUL: There is nothing stopping you from giving two objects the same name!
	--In this case the object that checks for messages first will recieve both parties mail
	--
	--vec3()
	--Simple vector placeholder until Mat sorts out GLM

	--NPC1; will post position to NPC2 every cycle (upon request)
	SM:addObject(Identifiers("NPC", "bob"), 0, vec3(0,1,0), ResourceList("msgrcvr", "n1msgrcvr", "updatefunc", "n1start"));
	
	--NPC2; will request position from NPC1
	SM:addObject(Identifiers("NPC", "ted"), 0, vec3(0, 0, 0), ResourceList("msgrcvr", "n2msgrcvr", "updatefunc", "n2start"));
	
	--"Dumb" NPCs; no behaviour or name defined
	SM:addObject(Identifiers("NPC"), 0, vec3(245,98,462), ResourceList());
	SM:addObject(Identifiers("NPC"), 0, vec3(245,98,462), ResourceList());
	SM:addObject(Identifiers("NPC"), 0, vec3(245,98,462), ResourceList());
	
	--NPC5; no message reciever, but update mechanism defined. ie: No ability to recieve messages, but can still do stuff.
	--Reuses NPC1 behaviour (moves foward by 1 point on the x axis every cycle)
	SM:addObject(Identifiers("NPC"), 0, vec3(245,98,462), ResourceList("updatefunc", "n1start"));
	
	--Unecessary in this instance, but good practice 
	SM:setCurrScene(0);

	print("Data Loaded!");
	print();
end