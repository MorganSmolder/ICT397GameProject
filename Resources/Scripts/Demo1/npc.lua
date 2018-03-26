function n1msgrcvr(this,msgbus)
	while msgbus:hasMessage(this:getIdentifiers()) do
		local tmp = msgbus:getMessage(this:getIdentifiers());
		msgbus:postMessage(Message(this:getPos():x() .. " " .. this:getPos():y() .. " " .. this:getPos():z()), Identifiers("NPC", "ted"));
	end
	
	print("NPC " .. this:getID() .. " Has no more messages.");
	print();
end

function n1start(this,msgbus)
	print("NPC " .. this:getID() .. " is moving!");
	this:setPos(vec3(this:getPos():x() + 1, this:getPos():y(), this:getPos():z()));
	print("NPC " .. this:getID() .. " position is: " ..  this:getPos():x() .. " " .. this:getPos():y() .. " " .. this:getPos():z());
	print();	
end