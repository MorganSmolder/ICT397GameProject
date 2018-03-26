
function start(this, msgbus)	
	this:setState(this:getState() + 1);
	
	if this:getState() % 25 == 0 then
		print("NPC " .. this:getID() .. " is being updated.");
		print();
	end
	
	if(this:getState() > 100) then
		this:setState(0);
		msgbus:postMessage( Message("changescene"), Identifiers("", "SM"));
		print("Scene change requested!");
		print();
	end

end