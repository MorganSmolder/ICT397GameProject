function start(this,msgbus)

	if (this:getPos():x() > 50) then
		this:setState(0);
	end
	
	if (this:getPos():x() < -50) then
		this:setState(1);
	end

	if (this:getState() == 0) then
			this:setPos(vec3(this:getPos():x() - 0.1, this:getPos():y(), this:getPos():z()));
	else
			this:setPos(vec3(this:getPos():x() + 0.1, this:getPos():y(), this:getPos():z()));
	end
end
