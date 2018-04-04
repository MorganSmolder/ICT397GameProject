
function keys(key, action, MB)
	if key:equals("w") or key:equals("W") then 
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVF"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SFB"), Identifiers("", "Camera"));
		end 
	elseif key:equals("a") or key:equals("A") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVL"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SLR"), Identifiers("", "Camera"));	
		end 
	elseif key:equals("d") or key:equals("D") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVR"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SLR"), Identifiers("", "Camera"));
		end 
	elseif key:equals("s") or key:equals("S") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVB"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SFB"), Identifiers("", "Camera"));
		end 
	elseif key:equals("q") or key:equals("Q") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("LD"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SUD"), Identifiers("", "Camera"));
		end 
	elseif key:equals("e") or key:equals("E") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("LU"), Identifiers("", "Camera"));
		else
			MB:postMessage(Message("SUD"), Identifiers("", "Camera"));
		end 
	elseif key:equals("o") or key:equals("O") then
		if action:equals("press") then
			MB:postMessage(Message("CS"), Identifiers("", "SM"));
		end
	end
end

function keys2(key, action, MB)
	print("We can have multiple controls!");
	if key:equals("w") or key:equals("W") then 
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVF"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SFB"), Identifiers("", "Camera2"));
		end 
	elseif key:equals("a") or key:equals("A") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVL"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SLR"), Identifiers("", "Camera2"));	
		end 
	elseif key:equals("d") or key:equals("D") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVR"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SLR"), Identifiers("", "Camera2"));
		end 
	elseif key:equals("s") or key:equals("S") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("MVB"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SFB"), Identifiers("", "Camera2"));
		end 
	elseif key:equals("q") or key:equals("Q") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("LD"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SUD"), Identifiers("", "Camera2"));
		end 
	elseif key:equals("e") or key:equals("E") then
		if(action:equals("press") or action:equals("repeat")) then
			MB:postMessage(Message("LU"), Identifiers("", "Camera2"));
		else
			MB:postMessage(Message("SUD"), Identifiers("", "Camera2"));
		end 
	elseif key:equals("o") or key:equals("O") then
		if action:equals("press") then
			MB:postMessage(Message("CS"), Identifiers("", "SM"));
		end
	end
end