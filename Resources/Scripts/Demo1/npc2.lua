function n2msgrcvr(this, msgbus)
	while msgbus:hasMessage(this:getIdentifiers()) do
		local tmp = msgbus:getMessage(this:getIdentifiers());
		print("NPC " .. this:getID() .. " knows NPC 0 position is " .. tmp:getInstruction());
	end
	
	print("NPC " .. this:getID() .. " Has no more messages!");
	print();
end

function n2start(this, msgbus)	
	--Request NPC with name "bob" positon
	msgbus:postMessage( Message("pos"), Identifiers("NPC", "bob"));
	print();
end